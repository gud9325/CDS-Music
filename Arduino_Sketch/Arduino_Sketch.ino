void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(analogRead(A0));
  Serial.println(analogRead(A1) + 1024);
  Serial.println(analogRead(A2) + 2048);
  Serial.println(analogRead(A3) + 3072);
  Serial.println(analogRead(A4) + 4096);
 
}
