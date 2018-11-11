const int REDpin = 3;
const int GREENpin = 5;
const int BLUEpin = 6;

void setup() {
  
}

void loop() {
  /*  Read potentiometers */
  
  int Ri = analogRead(A0);
  int R = map(Ri, 0, 1023, 0, 255);
  
  int Gi = analogRead(A1);
  int G = map(Gi, 0, 1023, 0, 255);
  
  int Bi = analogRead(A2);
  int B = map(Bi, 0, 1023, 0, 255);
  
  int globIn = analogRead(A3);
  int glob = map(globIn, 0, 1023, 255, 0);

  /*  Calculate values  */
  
  int percR = R * 100 / 255;
  int percG = G * 100 / 255;
  int percB = B * 100 / 255;
  
  int percRglob = glob * percR / 255;
  int percGglob = glob * percG / 255;
  int percBglob = glob * percB / 255;
  
  int RED = (percR - percRglob) *2.5;
  int GREEN = (percG - percGglob) *2.5;
  int BLUE = (percB - percBglob) *2.5;

  /*  Write PWM output  */

  analogWrite(REDpin, RED);
  analogWrite(GREENpin, GREEN);
  analogWrite(BLUEpin, BLUE);

  /*  Take a little break */
  delay(10);
}
