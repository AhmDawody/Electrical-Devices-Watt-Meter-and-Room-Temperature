# IoT Room Temperature and Power Meter
This project is a simple and affordable way to monitor room temperature and the power consumption of electrical devices using a single microcontroller board. The system is designed to measure the real-time power consumption of devices, allowing users to analyze and optimize their energy usage patterns.
## Project Overview
The project is based on the **TM4C123GH6PM** microcontroller board with **ESP8266** WiFi module, the board is connected to a current sensor and a temperature sensor. The current sensor is used to measure the current flowing through the electrical device, while the temperature sensor is used to measure the ambient room temperature.

The system is designed to provide real-time power consumption data through a web-based user interface. The user can view the current temperature and power consumption of connected devices.
## Installation and Configuration
### 1- ESP8266 Installation and Configuration
The wifi module is configured to recieve data from the microcontroller and to connect to home wifi and it behaves as access point.  
<br>1- Connect the module to PC by using **HW-417** (USB to TTL) converter, the connection schematic as below. 
<div>
  <img src="https://user-images.githubusercontent.com/107086104/224859652-112e6a1c-70e5-447d-bc8a-963c55c9a97a.png" width="600">
</div>  

- It is not recommended to use the 3.3v pin of the converter as the circuit power supply, because it will cause instability to **ESP8266**.<br>

<br>2- The **ESP8266** module is programmed using Arduino IDE, open Arduino IDE and go to File->Preferences and paste this URL "http://arduino.esp8266.com/stable/package_esp8266com_index.json" in "Additional boards manager URLs" text box, then press OK to download **ESP8266** library.
<br>3- To install the library go to Tools->Board->Boards Manager and type **ESP8266** then the **ESP** library will appear, install it.
<br>4- Connect the "USB to TTL" converter to PC, then go to "select other board and port" on the right of the "debug" button and select the COM port of the converter and type "Generic ESP8266 Module" in BOARDS and select it.
<br>5- Paste the source code of the "server_data.ino" file.
<br>6- Before uploading the code the **ESP** module must be in flash mode, this is done by holding "reset" button then hold "flash" button, then release "reset" then release "flash".
<br>7- Now you can upload the code by pressing upload on the top left, after the uploading is done press the "reset" button.<br>

### 2-TM4C board Installation and Configuration
The board is connected with : Current sensor **ACS712** 5A, Temperature sensor **LM35D** and Wifi module **ESP8266**.
<br>1- The current sensor is connected to **PE3** (AIN0).
<br>2- The temperature sensor is connected to **PE2** (AIN1).
<br>3- The Wifi module is connected to **PB0-PB1** (UART1).
