# IoT Room Temperature and Power Meter
This project is a simple and affordable way to monitor room temperature and the power consumption of electrical devices using a single microcontroller board. The system is designed to measure the real-time power consumption of devices, allowing users to analyze and optimize their energy usage patterns.
## Project Overview
The project is based on the TM4C123GH6PM microcontroller board with esp8266 WiFi module, the board is connected to a current sensor and a temperature sensor. The current sensor is used to measure the current flowing through the electrical device, while the temperature sensor is used to measure the ambient room temperature.

The system is designed to provide real-time power consumption data through a web-based user interface. The user can view the current temperature and power consumption of connected devices.
## Installation and Configuration
### 1- esp8266 Installation and Configuration
The wifi module is configured to recieve data from the microcontroller and to connect to home wifi and it behaves as access point.  
First, I connected the module to Pc by using HW-417 (USB to TTL) converter, the connection schematic as below:  
<div>
  <img src="https://user-images.githubusercontent.com/107086104/224852000-d44a9da6-eb99-49ae-8691-aa5e7a2dba0c.jpg" width="500">
