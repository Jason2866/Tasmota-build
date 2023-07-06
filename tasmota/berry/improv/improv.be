#------------------------------------------------------------------------------
- Improv-Wifi and PIN secured command input - needs custom build with 
-
- starts a BLE server that allows to send Wi-Fi credentials to the ESP32
- implements the Improv standard - see https://www.improv-wifi.com
- should be adapted for personal needs - it is impossible to have "one fits all"
- is typically loaded from an `autoexec.be` in Tasmota file system

- the command input with PIN secure is a non standardized example, that
- can be used with generic smartphone apps to write to characteristic FFF2
- and listen to FFF1
-------------------------------------------------------------------------------#

import BLE
var cbuf = bytes(-255)

class IMPROV : Driver
    var current_func, next_func
    var pin_ready
    var ssid, pwd, imp_state, msg_buffer
    static PIN = "123456" # 🤫

    def init()
        var cbp = tasmota.gen_cb(/e,o,u,h->self.cb(e,o,u,h))
        BLE.serv_cb(cbp,cbuf)
        BLE.set_svc("00467768-6228-2272-4663-277478268000")
        self.current_func = /->self.add_8001()
        print("BLE: wifi-improv ready for connection")
        self.pin_ready = false
        self.msg_buffer = []
        self.imp_state = 0x01 # Awaiting authorization via physical interaction.
    end

    def every_50ms()
        self.current_func()
    end

    def wait()
    end

    def then(func)
        # save function pointers for callback, typically expecting a closure
        self.next_func = func
        self.current_func = /->self.wait()
    end

    def chksum(buf)
        var checksum = 0
        for i:0..size(buf)-1
            checksum += buf[i]
            checksum = checksum & 255
        end
        return checksum
    end

    def parseRPC()
        # parses the response from the sender of the credentials
        # no real error handling yet
        var data = cbuf[1..(cbuf[0])]
        if size(self.msg_buffer) > 0
        self.msg_buffer += data
        else
            self.msg_buffer = data
        end
        if self.msg_buffer[1]+3 != size(self.msg_buffer) # +3 <- cmnd + length of message + checksum
            print("need more data in RPC",self.msg_buffer[1]+3,size(self.msg_buffer))
            return
        end
        print("msg_buffer complete with size", size(self.msg_buffer))
        var cmd = self.msg_buffer[0]
        var len = self.msg_buffer[1]

        var chksum = self.chksum(self.msg_buffer[0..len+1])
        if chksum != self.msg_buffer[len+2]
            print("Wrong checksum!!",chksum,self.msg_buffer[len+2]) # still not sure what range to compute
        end
        var ssid_len = self.msg_buffer[2]
        self.ssid = (self.msg_buffer[3..3+ssid_len-1]).asstring()
        var pwd_len = self.msg_buffer[3+ssid_len]
        self.pwd = (self.msg_buffer[4+ssid_len..4+ssid_len+pwd_len-1]).asstring()
        self.then(/->self.provisioning())
    end

    def identify()
        #----------------------------------------------------------------------------------
        - This is the only place, where you can secure the ESP32 device from the outside
        - by forcing a pysical user interaction with the device, i.e. a button press.
        - It is totally impossible to provide a generic way for every possible ESP32 device.
        - Thus the next code line (for Node-MCU C3-32S user-defined button) is 
        - commented out and continues to the next step, pretending all is fine.
        ------------------------------------------------------------------------------------#
        # if (gpio.digital_read(9) == 1) return end
        print("User authorization done!") # But we do not care for this demo
        self.imp_state = 2;
        BLE.set_svc("00467768-6228-2272-4663-277478268000")
        BLE.set_chr("00467768-6228-2272-4663-277478268001")
        cbuf.setbytes(0,bytes("0102"))
        BLE.run(211)
        self.then(/->self.wait())
    end

    def provisioning(step)
        # attempt connection with given credentials
        tasmota.cmd("Wifitest2 "+self.ssid+"+"+self.pwd)
        BLE.set_svc("00467768-6228-2272-4663-277478268000")
        BLE.set_chr("00467768-6228-2272-4663-277478268001")
        cbuf.setbytes(0,bytes("0103"))
        BLE.run(211)
        self.imp_state = 3;
        self.then(/->self.provisioned(1))
    end

    def provisioned(step)
         # test if credentials are working
        if step < 255 # some kind of timeout (255 * 50 millis), could be adapted
            var w = tasmota.wifi()
            var ip = nil
            try
                ip = w['ip']
                print(ip)
            except ..
                self.current_func = /->self.provisioned(step + 1)
                return
            end
            if ip != '0.0.0.0'
                print("IP address",ip)
                BLE.set_svc("00467768-6228-2272-4663-277478268000")
                BLE.set_chr("00467768-6228-2272-4663-277478268001")
                tasmota.cmd("Backlog SSId1 "+self.ssid+"; Password1 "+self.pwd) # set and reboot
                # print("Backlog SSID1 "+self.ssid+"; Password1 "+self.pwd)
                cbuf.setbytes(0,bytes("0104"))
                BLE.run(211)
                self.imp_state = 4;
                self.then(/->self.wait())
            end
        end
    end

    def execCmd(c)
        var resp
        if self.pin_ready == true
            resp = tasmota.cmd(c).tostring()
            print(c,"->",resp)
            if size(resp) > size(cbuf) - 2
                print("message too large!! ... will cut it",size(resp))
                resp = resp[0..254]
            end
        else
            if c == self.PIN
                resp = "PIN accepted ... enter commands"
                self.pin_ready = true
            else
                resp = "Wrong PIN!!"
                print(c,self.PIN)
            end
        end
        BLE.set_svc("FFF0")
        BLE.set_chr("FFF1")
        cbuf[0] = size(resp)
        var r_buf = bytes().fromstring(resp)
        print(r_buf)
        cbuf.setbytes(1,r_buf)
        print(cbuf)
        BLE.run(211)

        self.then(/->self.wait())
    end

    def cb(error,op,uuid,handle)
        print(error,op,uuid,handle)
        if op == 201
            print("Handles:",cbuf[1..cbuf[0]])
        end
        if op == 221
            if handle == 6 # the last handle that improv-wifi is reading on connection
                if self.imp_state == 1
                    self.then(/->self.identify()) # now request our "identify"
                end
            end
        end
        if op == 222
            if handle == 9
                self.parseRPC()
                print(cbuf[1..cbuf[0]])
            end
            if handle == 22
                self.then(/->self.execCmd((cbuf[1..cbuf[0]]).asstring()))
            end
        end
        if op == 227
            print("MAC:",cbuf[1..cbuf[0]])
        end
        if op == 228
            print("Disconnected")
            self.pin_ready = false
            self.imp_state = 1;
        end
        if op == 229
            print("Status:",cbuf[1..cbuf[0]])
        end
        if error == 0
            self.current_func = self.next_func
        end
    end

    # improv wifi section
    def add_8001() # Current State
        BLE.set_chr("00467768-6228-2272-4663-277478268001")
        var payload = bytes("0100")
        payload[1] = self.imp_state
        cbuf.setbytes(0,payload)
        BLE.run(211)
        self.then(/->self.add_8002())
    end
    def add_8002() # Error state
        BLE.set_chr("00467768-6228-2272-4663-277478268002")
        cbuf.setbytes(0,bytes("0100"))
        BLE.run(211)
        self.then(/->self.add_8003())
    end
    def add_8003() # RPC Command
        BLE.set_chr("00467768-6228-2272-4663-277478268003")
        cbuf.setbytes(0,bytes("020400"))
        BLE.run(211)
        self.then(/->self.add_8004())
    end
    def add_8004() # Identify
        BLE.set_chr("00467768-6228-2272-4663-277478268004")
        cbuf.setbytes(0,bytes("0101"))
        BLE.run(211)
        self.then(/->self.add_8005())
    end
    def add_8005() # Capabilities
        BLE.set_chr("00467768-6228-2272-4663-277478268005")
        cbuf.setbytes(0,bytes("0101"))
        BLE.run(211)
        self.then(/->self.add_fff1())
    end
    # custom section
    def add_fff1()
        BLE.set_svc("FFF0")
        BLE.set_chr("FFF1")
        cbuf.setbytes(0,bytes("0100"))
        BLE.run(211)
        self.then(/->self.add_fff2())
    end
    def add_fff2()
        BLE.set_chr("FFF2")
        var b = bytes().fromstring("Please enter PIN first.")
        cbuf.setbytes(1,b)
        cbuf[0] = size(b)
        BLE.run(211)
        self.then(/->self.add_ADV())
        # if you want to add a local name in the advertisement use the following line instead
        # self.then(/->self.add_ScanResp())
    end
    # services and characteristics are set, now start the server with first set of advertisement data
    def add_ADV()
        var payload = bytes("0201061107") + bytes("00467768622822724663277478268000").reverse() # flags and improv svc uuid
        cbuf[0] = size(payload)
        cbuf.setbytes(1,payload)
        BLE.run(201)
        self.then(/->self.wait())
    end
    # unused example function, could be called from add_fff2()
    def add_ScanResp()
        var local_name = "Tasmota BLE" # just for demonstration, makes not so much sense in this context
        var payload = bytes("0201060008") + bytes().fromstring(local_name) # 00 before 08  is a placeholder
        payload[3] = size(local_name) + 1 # ..set size of name
        cbuf[0] = size(payload)
        cbuf.setbytes(1,payload)
        BLE.run(202)
        self.then(/->self.add_ADV())
    end

end

var improv = IMPROV()
tasmota.add_driver(improv)
