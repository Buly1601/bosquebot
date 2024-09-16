import serial
import rospy
from std_msgs.msg import String

class Bosquebot:

    def __init__(self):
        self.node = rospy.init_node("bosquebot", anonymous=False)
        self.motors = rospy.Publisher("motor_control", String, queue_size=10)
    
    def traction_control(self):
        """
        Method to control the traction control of the robot publishind the following:
        - 0 for stop.
        - 1 for mid. 
        - 2 for top.
        ! make controlled
        """
        while True:
            self.motors.publish("01")
    

if __name__ == "__main__":
    bosquebot = Bosquebot()
    bosquebot.traction_control()


