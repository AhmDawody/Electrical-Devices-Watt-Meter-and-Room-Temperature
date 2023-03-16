## Project Overview
This project is an IoT-based solution for monitoring room temperature and starting an alert when the temperature exceeds a certain threshold. The project uses a temperature sensor and a Wi-Fi module to transmit the data to a web-based user interface.
The system is designed to provide real-time temperature data through a web-based user interface. The user can view the current temperature of the working room.

## Hardware Components 
* Tiva™ C Board -**TM4C123GH6PM**
* **ESP8266** Wi-Fi module
* **HW-417** (USB to TTL) converter
* **LM35D** temperature and humidity sensor
* Breadboard, 2 push-buttons, 2 10K-resistors a 330 resistor, LED and jumper wires (M-M, M-F)

## Software Components
* Code Composer Studio™ IDE
* Arduino IDE

## Installation and Configuration
### 1- ESP8266 Wi-Fi module Installation and Configuration
The Wi-Fi module is configured to recieve data from the microcontroller and send it to the web-based user interface and it behaves as an access point.  
<br>1- Connect the Wi-Fi module to PC by using **HW-417** (USB to TTL) converter, the connection schematic as below. 
<div>
  <img src="https://user-images.githubusercontent.com/107086104/224859652-112e6a1c-70e5-447d-bc8a-963c55c9a97a.png" width="600">
</div>  

- It is not recommended to use the 3.3v pin of the converter as the circuit power supply, because it will cause instability to the Wi-Fi module.
- Connect GPIO2 pin to the 330 resistor and the LED to ground

<br>2- The **ESP8266** module is programmed using Arduino IDE, open Arduino IDE and go to **File->Preferences** and paste this URL "http://arduino.esp8266.com/stable/package_esp8266com_index.json" in **Additional boards manager URLs** text box, then press **OK** to download **ESP8266** library.
<br>3- To install the library go to **Tools->Board->Boards Manager** and type "ESP8266" then **ESP** library will appear, install it.
<br>4- Connect the "USB to TTL" converter to PC, then go to **select other board and port** on the right of the **debug** button and select the COM port of the converter and type "Generic ESP8266 Module" in **BOARDS** and select it.
<br>5- Paste the source code of the "server_data.ino" file.
<br>6- Before uploading the code the **ESP** module must be in **flash mode**, this is done by holding "reset" button then hold "flash" button, then release "reset" then release "flash".
<br>7- Now you can upload the code by pressing **upload** arrow on the top left, after the uploading is done press the "reset" button to start the module.

### 2-TM4C123G board Installation and Configuration
1- The temperature sensor pin 2 is connected to **PE2** (AIN1).
<br>2- The Wi-Fi module **(Tx-Rx)** is connected to **PB0-PB1** **(Rx-Tx)** (UART1) respectively.

## Important Notes
* To open the module website, first connect to its Wi-Fi by finding its name and password written in "server_data.ino"<br>
```
// Set the SSID and password for the access point
const char* ssid = "ESP8266AP";
const char* password = "password";
```
now find your IP address for me it was **192.168.4.2**, now open a web browser and type the IP of the access point itself for me it was **192.168.4.1**.<br>
You can find now the data sent by the microcontroller presenting the temperature.
* The system is designed to run at 80 MHz, if you want to change it you have to change the baud rate of **UART** and the values of **RELOAD** in the Systick wait routines.
* You can change the temperature threshold by changing the macro definition of it in the main program.<br>```#define THRESHOLD 30```
