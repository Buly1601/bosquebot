# bosquebot

## Communication protocol between nodes
This section explains how the nodes, specially Arduino-Ros connection is made and what is expected to be sent and received.

### motorCallback
To be received: String: velocity intensity of two motors. Example: "01" Left motor stopped, right at mid-speed. Range: 0-2.

## Arduino Mega Pinout
3 - left motor
4 - right motor

## Usage:
To run the arduino code, run: `rosrun rosserial_python serial_node.py /dev/ttyACM0`, change `ttyACM0` to the port that the arduino is connected to.

## TO REVIEW
http://wiki.ros.org/ROS/Tutorials/CreatingMsgAndSrv
https://github.com/leggedrobotics/darknet_ros
https://www.pololu.com/product/2821



