# greenhouse_controller
Arduino and Linux based sensor and control network
As part of a belated Devember


This project is to design and implement a distributed sensor and control system to automate an indoors growing environment.

As the network is designed to automate high volume growing enviroments. Each growing bed utalises its own slave unit which manages and records the data from that bed while passing the data back to the main controller for logging. While also reciving data back from the controller to control the actuators on that bed.

The system will be designed to be expandable very quickly and easily, by adding new 'beds' to the network.


---Slave board---

--Sensors--
Light (intensity and colour)
soil moisture
Soil temperature
Air temperature
RTC (Real Time Clock)

--Control--
Growing lights (LED, RGB)
Sprinklers (Three per bed)
Emergancy Stop
Heater

--Conectivity--
USB (mainly for debug and programming)
Ethernet (Comunicating with the controller)


---Controller Board---
Recive sensor data from slave boards, and send changes in paramaters back.
Most likely Python script
ROS?
Recive changes in parameters from user and distribute relevant commands to slave units.


The slave unit is based off the ATMEGA 1284 chip, using a 3rd party arduino bootloader.

The slave is programed thanks to the use of the bootloader found here: http://www.leonardomiliani.com/repository/package_leonardomiliani.com_index.json


