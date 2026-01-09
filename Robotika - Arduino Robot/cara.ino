//new
//W: 274 - 68 - 76 - 143
//B: 806 - 693 - 760 - 750

int pTrig = 12;
int pEcho = 13;
int pServo = 9;
long odezva, vzdalenost;
int mLs = 7; //směr levý
int mLp = 5; //výkon levý
int mRs = 8; //směr pravý
int mRp = 6; //výkon pravý
bool direction = 1;

void left(int x) {
  digitalWrite(mLs, HIGH);
  analogWrite(mLp, 0);
  digitalWrite(mRs, LOW);
  analogWrite(mRp, 255);
  delay(x);
}

void right(int x) {
  digitalWrite(mLs, LOW);
  analogWrite(mLp, 255);
  digitalWrite(mRs, HIGH);
  analogWrite(mRp, 0);
  delay(x);
}

void forward(int x) {
  digitalWrite(mLs, LOW);
  analogWrite(mLp, 255);
  digitalWrite(mRs, LOW);
  analogWrite(mRp, 255);
  delay(x);
}

void stop(int x) {
  digitalWrite(mLs, LOW);
  analogWrite(mLp, 0);
  digitalWrite(mRs, LOW);
  analogWrite(mRp, 0);
  delay(x); 
}

void setup() {
  pinMode (mLp,OUTPUT); //pwm L
  pinMode (mLs,OUTPUT); //direction L
  pinMode (mRp,OUTPUT); //pwm R
  pinMode (mRs,OUTPUT); //direction R
  pinMode (pTrig, OUTPUT); //trigger
  pinMode (pEcho, INPUT);  //echo
 
  }
void loop() {
  digitalWrite(pTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pTrig, HIGH);
  delayMicroseconds(5);
  digitalWrite(pTrig, LOW);
  odezva = pulseIn(pEcho, HIGH, 5000);  // maximální délku pulzu v mikrosekundách (us)
  vzdalenost = int(odezva / 58.31);

  if ((vzdalenost <= 5)&&(vzdalenost > 0)){
    //upravit
    stop(200);
    right(350);
    forward(900);
    stop(200);
    left(350);
    forward(1000);
    stop(200);
    left(350);
    forward(900);
  }
  else {
    while ((100.0* (analogRead(A2)-76.0)/(760.0-76.0))<50){
      digitalWrite (mLs,LOW); //smer LOW -> dopredu | smer HIGH -> dozadu
      analogWrite (mLp,0);    //rychlost motoru 255 0V MIN |0 5V MAX
      digitalWrite (mRs,LOW);
      analogWrite (mRp,255);
    }
    while ((100.0*(analogRead(A1)-68.0)/(693.0-68.0))<50){
      digitalWrite (mLs,LOW);
      analogWrite (mLp,255);
      digitalWrite (mRs,LOW);
      analogWrite (mRp,0);
    }
  }
}