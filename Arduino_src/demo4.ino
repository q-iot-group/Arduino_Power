int timeCount = 0;
int moneyCount = 0;
int pushButton = 7;
int beforeState = 0;
int buttonState = 0;
int buttonCount = 0;
int a = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(pushButton,INPUT);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sersorValue = analogRead(A0);
  a = map(sersorValue,0,1023,0,100);
  buttonState = digitalRead(pushButton);
  if(buttonState == 1 and beforeState ==0){
    buttonCount = buttonCount +1;  
  }
  if(buttonCount % 2 ==0){
    digitalWrite(13,LOW);
    timeCount = 0;
    moneyCount = 0;  
  }
  else{
    digitalWrite(13,HIGH);
    timeCount = timeCount +1;
    if(timeCount % 5 == 0){
      moneyCount = moneyCount + 1;
      Serial.print("#str 1 Cost:");
      Serial.print(moneyCount);  
      Serial.print("RMB\r");
    }
    else{
      Serial.print("#var CELLVARA ");
      Serial.print(a);
      Serial.print("\r");  
    }
  }
  beforeState = buttonState;
  delay(1000);
}
