//uint8_t myVoice;
const int nose = 0;  //A0 input

const int pushButton = 4;
const bool trueState = LOW;
bool buttonState = false;

const int folicleCount = 4;
const int folicle1 = 7;  //A0 input
const int folicle2 = 6;  //A0 input
const int folicle3 = 5;  //A0 input
const int folicle4 = 4;  //A0 input

int folicles[folicleCount] = { folicle1, folicle2, folicle3, folicle4 };
int folicleReadings[folicleCount] = { 0, 0, 0, 0 };

//20*5*number
//20Hz - 655Hz

void checkButton() {
  if (trueState == digitalRead(pushButton)) {
    buttonState = true;
  } else {
    buttonState = false;
  }
}


int readFolicle(int folicle) {
  //  if (Serial) {
  //    Serial.print("readFolicle ");
  //    Serial.print(folicle);
  //    Serial.print(" result: ");
  //  }

  int val = analogRead(folicle);
  uint8_t reading = (uint8_t) (map(val, 0, 1023, 0, 127));
  //  if (Serial) {
  //    Serial.println(reading);
  //  }
  return reading;
}

void updateFolicleData() {
  for (int i = 0; i < folicleCount; i++) {
    folicleReadings[i] = readFolicle(folicles[i]);
  }
}

void printFolicleData() {
  for (int i = 0; i < folicleCount; i++) {
    if (Serial) {
      Serial.print("readFolicle ");
      Serial.print(i);
      Serial.print(" result: ");
      Serial.println(folicleReadings[i]);
    }
  }
}

float average (int nums[], int sizeOfArray) {
  long sum = 0;
  for (int i = 0 ; i < sizeOfArray ; i++) {
    sum += nums[i];
  }
  return  ((float) sum) / sizeOfArray ;  // average will be fractional, so float may be appropriate.
}

float averageFolicleData() {
  return average(folicleReadings, folicleCount);
}

void printFolicleAverage() {
     if (Serial) {
      Serial.print("Folicle Average: ");
      Serial.println(averageFolicleData());
    }
}

//String getValueForMessage() {
//  int val = analogRead(nose);
//  //return "dial it in";
//  return String((uint8_t) (map(val, 0, 1023, 0, 127)));
//}
