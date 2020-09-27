//uint8_t myVoice;
const int nose = 0;  //A0 input

const int pushButton = 4;
bool buttonState = HIGH;

const int folicle1 = 7;  //A0 input
const int folicle2 = 6;  //A0 input
const int folicle3 = 5;  //A0 input
const int folicle4 = 4;  //A0 input

int folicles[4] = { folicle1, folicle2, folicle3, folicle4 };

//20*5*number
//20Hz - 655Hz

void checkButton() {
  buttonState = digitalRead(pushButton);
}

int readFolicle(int folicle)
{
  int val = analogRead(folicle);
  uint8_t reading = (uint8_t) (map(val, 0, 1023, 0, 127));
//  if (Serial) {
//    Serial.print("readFolicle result: ");
//    Serial.println(reading);
//  }
  return reading;
}

//String getValueForMessage() {
//  int val = analogRead(nose);
//  //return "dial it in";
//  return String((uint8_t) (map(val, 0, 1023, 0, 127)));
//}
