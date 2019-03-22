const int IR_Sensor = 32;
const int limitSW_1 = 33;
const int RelayCH_1 = 18; //ดึงขึ้น
const int RelayCH_2 = 19; //ดึงลง
const int Led_BT = 17;
void setup() {
  Serial.begin(9600);
 pinMode(18,OUTPUT);
 pinMode(19,OUTPUT);
 pinMode(32,INPUT);
 pinMode(33,INPUT_PULLUP);
 //pinMode(17,OUTPUT);
}

void loop() {
 // Serial.println(digitalRead(limitSW_1));
  int sensorValue = analogRead(36);
  if(sensorValue>500&&digitalRead(limitSW_1)==1){
    digitalWrite(RelayCH_1, 1);
    digitalWrite(RelayCH_2, 0);
  }else if(sensorValue<450&&digitalRead(IR_Sensor)==1){
    digitalWrite(RelayCH_1, 0);
    digitalWrite(RelayCH_2, 1);
  }else{
    digitalWrite(RelayCH_1, 0);
    digitalWrite(RelayCH_2, 0);
  }
 Serial.println(sensorValue);
 // delay(100);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
//  if (digitalRead(limitSW_1) == LOW) {
//    // turn LED on:
//    digitalWrite(Led_BT, LOW);
//  } else {
//    // turn LED off:
//    digitalWrite(Led_BT, HIGH);
//  }

}
