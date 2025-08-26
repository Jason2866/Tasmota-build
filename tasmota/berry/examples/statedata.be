# Show hostname and IP address from MQTT STATE messages in GUI

import mqtt 
import string

class mqttdata_cls
  var list_buffer                                   # Buffer storing lines
  var line_cnt                                      # Number of lines

  def init()
    self.list_buffer = []                           # Init line buffer list
    self.line_cnt = 10                              # Number of lines to show

    if global.mqttdata_driver
      global.mqttdata_driver.stop()                 # Let previous instance bail out cleanly
    end
    tasmota.add_driver(global.mqttdata_driver := self)

    # Assume default Fulltopic (%prefix%/%topic%/) and Prefix3 (tele)
    mqtt.subscribe("tele/#", /topic, idx, data, databytes -> self.handle_state_data(topic, idx, data, databytes))
  end

  def handle_state_data(full_topic, idx, data, databytes)
    import json

    if string.find(full_topic, "STATE") > 0         # tele/wemos7/STATE
      var subtopic = string.split(full_topic, "/")  # Assume default Fulltopic (%prefix%/%topic%/)
      var topic = subtopic[1]                       # wemos7

      var line
      var state = json.load(data)
      if state
        var uptime = state['Uptime']
        if state.find('Hostname')
          var hostname = state['Hostname']
          var ipaddress = state['IPAddress']
          line = format("<tr><td><a target=_blank href='http://%s.'>%s</a></td><td><a target=_blank href='http://%s'>%s</a></td><td align='right'>%s</td></tr>",
                         hostname, hostname, ipaddress, ipaddress, uptime)
        else
          line = format("<tr><td>%s</td><td>&nbsp</td><td align='right'>%s</td></tr>",
                         topic, uptime)
        end
      end
      self.list_buffer.push(line)                   # Add as last entry
      if self.list_buffer.size() > self.line_cnt    # Max number of lines in buffer
        self.list_buffer.remove(0)                  # Remove first entry
      end
    end
    return true
  end

  def web_sensor()
    if self.list_buffer.size()
      var msg = format("</table>{t}")               # Terminate two column table and open new table
      for i: self.list_buffer.keys()
        msg += self.list_buffer[i]
      end
      msg += "</table>{t}"                          # Terminate three column table and open new table
      tasmota.web_send(msg)                         # Do not use tasmota.web_send_decimal() which will replace IPAddress dots
      tasmota.web_send_decimal("")                  # Force horizontal line
    end
  end
end

mqttdata = mqttdata_cls()
