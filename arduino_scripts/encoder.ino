// Encoder pins
#define ENCODER_PIN_A 2
#define ENCODER_PIN_B 3

volatile long encoderCount = 0;

void setup() {
  pinMode(ENCODER_PIN_A, INPUT);
  pinMode(ENCODER_PIN_B, INPUT);

  // Attach interrupts to encoder pins
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_A), handleEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_B), handleEncoder, CHANGE);
}

void loop() {
  // Your main loop code here
}

void handleEncoder() {
  static boolean A_set = false;
  static boolean B_set = false;

  // Read the state of the encoder pins
  boolean A = digitalRead(ENCODER_PIN_A);
  boolean B = digitalRead(ENCODER_PIN_B);

  // Update encoder count based on state changes
  if (A != A_set || B != B_set) {
    if (A == B) {
      encoderCount++;
    } else {
      encoderCount--;
    }
    A_set = A;
    B_set = B;
  }
}

long readEncoder() {
  // Return the current encoder count
  return encoderCount;
}
