#include <ros.h>
#include <std_msgs/String.h>


#define LEFT_MOTOR 4  // Pin 4 (PWM)
#define RIGHT_MOTOR 5 // Pin 5 (PWM)
#define LEFT_POS 0 // left encoder
#define RIGHT_POS 0 // right encoder
#define DRILL 6 // Pin 6 (PWM)
#define PISTON_UP 7 // Pin 7 (PWM)
#define PISTON_DOWN 8 // Pin 8 (PWM)

// PWM values for different speeds
#define SPEED_STOP 0
#define SPEED_MID 128
#define SPEED_TOP 255


// Motor speed variables
int left_speed = SPEED_STOP;
int right_speed = SPEED_STOP;
int drill_speed = SPEED_STOP;
int piston_up_speed = SPEED_STOP;
int piston_down_speed = SPEED_STOP;


// Instructions
void motorCallback(const std_msgs::String& msg) {
    /*
    This callback will receive 2 integers as velocity control that
    can be only three values, 0,1,2. If not an integer or
    out of bounds, return 1.
    - 0 for stop.
    - 1 for mid. 
    - 2 for top.
    - u for piston up
    - d for piston down
    - h for drill on
    - l for drill off
    */

    if (strcmp(msg.data, "10") == 0) {
      left_speed = SPEED_MID;
      right_speed = SPEED_STOP;
    } else if (strcmp(msg.data, "01") == 0) {
      right_speed = SPEED_MID;
      left_speed = SPEED_STOP;
    } else if (strcmp(msg.data, "11") == 0) {
      left_speed = SPEED_MID;
      right_speed = SPEED_MID;
    } else if (strcmp(msg.data, "00") == 0) {
      left_speed = SPEED_STOP;
      right_speed = SPEED_STOP;
    } else if (strcmp(msg.data, "20") == 0) {
      left_speed = SPEED_TOP;
      right_speed = SPEED_STOP;
    } else if (strcmp(msg.data, "21") == 0) {
      left_speed = SPEED_TOP;
      right_speed = SPEED_MID;
    } else if (strcmp(msg.data, "02") == 0) {
      left_speed = SPEED_STOP;
      right_speed = SPEED_TOP;
    } else if (strcmp(msg.data, "12") == 0) {
      left_speed = SPEED_MID;
      right_speed = SPEED_TOP;
    } else if (strcmp(msg.data, "u") == 0) {
      piston_up_speed = SPEED_TOP;
      piston_down_speed = SPEED_STOP;
    } else if (strcmp(msg.data, "d") == 0) {
      piston_up_speed = SPEED_STOP;
      piston_down_speed = SPEED_TOP;
    } else if (strcmp(msg.data, "s") == 0) {
      piston_up_speed = SPEED_STOP;
      piston_down_speed = SPEED_STOP;
    }
}

// ROS Node
ros::NodeHandle node_handle;
std_msgs::String motor_msg;
ros::Subscriber<std_msgs::String> motor_subscriber("motor_control", motorCallback);


void setup() {
  pinMode(LEFT_MOTOR, OUTPUT);
  pinMode(RIGHT_MOTOR, OUTPUT);
  pinMode(PISTON_UP, OUTPUT);
  pinMode(PISTON_DOWN, OUTPUT);

  node_handle.initNode();
  node_handle.subscribe(motor_subscriber);
}

void loop() {
  // Set motor speeds
  analogWrite(LEFT_MOTOR, left_speed);
  analogWrite(RIGHT_MOTOR, right_speed);
  analogWrite(PISTON_UP, piston_up_speed);
  analogWrite(PISTON_DOWN, piston_down_speed);

  node_handle.spinOnce();
  delay(10);
}
