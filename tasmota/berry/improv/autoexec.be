# example that only allows Improv-Wifi via BLE, when the system is open anyway
if tasmota.cmd("SSId1")["SSId1"] == "" && tasmota.cmd("SSId2")["SSId2"] == ""
    # this is the state after first flash or reset 1
    tasmota.cmd("so115 1") # make sure BLE is on
    tasmota.set_timer(10000, /->load("improv.be")) # let the system do some booting
end
