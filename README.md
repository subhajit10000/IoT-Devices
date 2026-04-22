Project Description: HomiQ – IoT Based Home Automation System

HomiQ is a modular home automation system that lets users control lights, fans, appliances, and sensors from a phone or voice assistant while keeping the wiring and cost simple. It is built for apartments, independent houses, and small offices where people want comfort and energy savings without rewiring the entire home. The design focus is reliable local control first, cloud features second, so the house still works even if the internet goes down.

Problem We Address
Most smart home products lock users into one brand, need a hub that fails if Wi-Fi drops, or force cloud dependence for a simple light switch. Electricians are also hesitant because retrofit boards are bulky and do not fit Indian switch boxes. HomiQ solves this by using small ESP32 based modules that sit behind existing switch plates, talk to each other over MQTT on the local network, and only use the cloud for remote access and logs.

Hardware Architecture
Node Modules: Each room gets a 4 channel or 2 channel relay module based on ESP32. The board is 55 by 55 mm so it fits inside a standard 2 module box. It switches 10A loads using sugar cube relays with RC snubbers for fan and motor safety. A HLK-PM01 provides isolated 5V supply. Manual tactile buttons on the board connect to the same GPIOs, so the physical switches keep working even without Wi-Fi. A current sensor on each channel measures power to the nearest watt.

Sensor Nodes: Separate compact nodes handle environment sensing. A DHT22 or BME280 reads temperature and humidity. A PIR module detects motion for auto lights. A door sensor uses a reed switch. An LDR measures ambient light so the system can avoid turning on lamps in daylight. All sensor nodes run ESP32-C3 for lower power and report over Wi-Fi or ESP-NOW to the nearest relay node.

Central Gateway: An optional Raspberry Pi runs Mosquitto MQTT, Node-RED, and InfluxDB. It stores logs locally, runs automations, and bridges to the cloud. If the gateway is absent, relay nodes can still talk peer to peer using ESP-NOW and retain basic schedules saved in flash.

Safety and Wiring: Boards use a flame retardant FR4 PCB with proper creepage distance between mains and low voltage sides. Varistors and fuses are present on the line input. Firmware supports zero cross detection for fan speed control using triacs in a separate dimmer variant.

Software and Cloud
Local First Control: The mobile app built in Flutter talks to the gateway over LAN by default. Taps send MQTT messages and the relay responds in under 200 ms. Schedules and scenes are stored on the device so alarms still trigger without internet.

Remote Access: When the user is outside, the gateway opens a secure MQTT over TLS tunnel to a cloud broker. The same app then works anywhere. Google Assistant and Alexa integration is done through cloud functions so voice commands reach the local nodes through the broker.

Automation Engine: Node-RED on the gateway provides a visual rule builder. Examples include turn on bathroom light if motion after sunset, switch off AC if no motion for 20 minutes, or send alert if main door opens at night. Users can also write simple if this then that rules in the app without touching Node-RED.

Energy and Insights: Each relay channel logs kilowatt hours to InfluxDB. The dashboard shows daily and monthly usage per room, idle loads, and suggestions like replace fan regulator with smart dimmer to save 12 percent power. A budget mode can auto cut non essential loads when the monthly cap is reached.

Setup and User Experience
Installation: An electrician replaces the old switch with a HomiQ module in ten minutes. No neutral wire is required for the relay variant because it uses a tiny buck and latching relays that hold state without coil power. The app uses BLE to provision Wi-Fi credentials, then the device appears in the room list.

Multi User and Permissions: The owner can add family members with roles. Kids can control only their room. Guests get a temporary QR code that expires in 24 hours.

Privacy: All voice processing stays on Google or Alexa servers only when the user invokes it. Camera feeds are never stored. Data stays on the local gateway unless the user enables cloud backup.

Use Cases
A user sets a Good Night scene that turns off all lights, dims the bedroom to 10 percent, sets AC to 26C, and arms door sensors. In the morning, a sunrise routine opens curtains using a Wi-Fi curtain motor, starts the geyser at 6:30, and stops it at 6:50. If a water leak sensor under the sink triggers, the main valve relay shuts and the app calls the owner.

Roadmap
Phase 1: Relay and dimmer modules, basic app, local MQTT.  
Phase 2: Energy metering, IR blaster for AC and TV, and solar integration to run heavy loads only on surplus power.  
Phase 3: Matter support for cross brand compatibility and a wall display panel for central control.

HomiQ makes automation feel like an electrical fitting upgrade instead of a tech project. It keeps manual control, adds intelligence, and works with the internet rather than relying on it.
