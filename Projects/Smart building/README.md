About

This is a smart building system. The goal of the system is to get information from the sensors and to activate the appropriate device, when needed.
All of the system's components are called 'Agents', and new agents can be added dynamically.
All smart building components are derived from two files. 
There are several kinds of sensors and controllers of devices.

The sensors send information using TCP comumnication protocol. 
Every device can subscribe to sensors compatible with it.

All sensors inherit from the Sensor base class, and all controllers inherit from the Controller base class.

There is a special kind of controller who can both receive and send information using TCP. In this project, it is used to implement a fire controller, which can 
communicate with the server and activate an alarm, in case of a fire inside the house.




