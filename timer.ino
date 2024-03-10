
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int s = 0, m = 0;
  int password;
 if (s > 0 && s < 60){
  Serial.print("TIME = "); Serial.print(m); Serial.print("m");Serial.print(s); Serial.println("s");
  delay(100);
  s ++;
 }
  if (s>60) {
    s == 0;
  m++;
  }
}


 

