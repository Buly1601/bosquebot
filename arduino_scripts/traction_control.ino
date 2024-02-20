#include <ros.h>
#include <std_msgs/String.h>

#define LEFT_MOTOR 3
#define RIGHT_MOTOR 4
/*
void ledCallback(const std_msgs::String& msg) {
  if (strcmp(msg.data, "ON") == 0) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED turned ON");
  } else if (strcmp(msg.data, "OFF") == 0) {
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED turned OFF");
  }
  Serial.println(msg.data);
}*/

void motorCallback(const std_msgs::String& msg) {
    /*
    This callback will receive 2 integers as velocity control that
    can be only three values, 0,1,2. If not an integer or
    out of bounds, return 1.
    - 0 for stop.
    - 1 for mid. 
    - 2 for top.
    TODO control speed
    */
   switch(msg) {
    case "00":
        digitalWrite(LEFT_MOTOR, LOW);
        digitalWrite(RIGHT_MOTOR, LOW);
        return 0;
    case "01":
        digitalWrite(LEFT_MOTOR, LOW);
        digitalWrite(RIGHT_MOTOR, HIGH);
        return 0;
    case "10":
        digitalWrite(LEFT_MOTOR, HIGH);
        digitalWrite(RIGHT_MOTOR, LOW);
        return 0;
    case "11":
        digitalWrite(LEFT_MOTOR, HIGH);
        digitalWrite(RIGHT_MOTOR, HIGH);
        return 0;
   }
    return 1;
}

ros::NodeHandle node_handle;
std_msgs::String led_msg;
ros::Subscriber<std_msgs::String> led_subscriber("led_control", ledCallback);

void setup() {
  pinMode(LED_PIN, OUTPUT);

  node_handle.initNode();
  node_handle.subscribe(led_subscriber);
}

void loop() {
  node_handle.spinOnce();
  delay(10);
}