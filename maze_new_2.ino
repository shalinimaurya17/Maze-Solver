int const M11 = 5;
int const M12 = 6;
int const M21 = 10;
int const M22 = 11;
int IR1 = 2;
int IR2 = 7;
int IR3 = 4;
int val_IR1;int val_IR2;int val_IR3;
int speed_ = 160;
int speed_t = 160;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(M11,OUTPUT);
  pinMode(M12,OUTPUT);
  pinMode(M21,OUTPUT);
  pinMode(M22,OUTPUT);
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);
}
void Forward(){
            
     analogWrite(M11,0);
    analogWrite(M12,speed_);
            analogWrite(M21,0);
            analogWrite(M22,speed_);
            delay(10);

}
void Left(){
  analogWrite(M11,speed_t);
  analogWrite(M12,0);
  analogWrite(M21,0);
  analogWrite(M22,speed_t);
  delay(90);
}
void Right(){
  
  analogWrite(M11,0);
    analogWrite(M12,speed_t);
    analogWrite(M21,speed_t);
    analogWrite(M22,0);
     delay(90);
}
void U_Turn(){
  analogWrite(M11,0);
    analogWrite(M12,speed_t);
    analogWrite(M21,speed_t);
    analogWrite(M22,0);
    delay(200);
}
void Stop(){
  analogWrite(M11,0);
  analogWrite(M12,0);
  analogWrite(M21,0);
  analogWrite(M22,0);
  delay(90);
}

void loop() 
{
  while(1){
    val_IR1 = digitalRead(IR1);
  val_IR2 = digitalRead(IR2);
  val_IR3 = digitalRead(IR3);

  if (val_IR1 == LOW && val_IR2 == HIGH && val_IR3 == LOW)
    {
     Forward();
    }

  if (val_IR1 == HIGH && val_IR2 == LOW && val_IR3 == LOW)
    {
     Right();
    }

  if (val_IR1 == LOW && val_IR2 == LOW && val_IR3 == HIGH)
    {
      Left();
    }

  if (val_IR1 == HIGH && val_IR2 == LOW && val_IR3 == HIGH)
    {
      Forward(); 
    }

  if (val_IR1 == HIGH && val_IR2 == HIGH && val_IR3 == LOW)
    {
      Right();
    }

  if (val_IR1 == LOW && val_IR2 == HIGH && val_IR3 == HIGH)
    {
     Forward();
    }

  if (val_IR1 == LOW && val_IR2 ==LOW && val_IR3 == LOW)//Dead End
    {
     U_Turn(); 
    }

  if (val_IR1 == HIGH && val_IR2 == HIGH && val_IR3 == HIGH)//4 Lane intersection
    {
     Right(); 
    }

  if (val_IR1 == HIGH && val_IR2 == HIGH && val_IR3 == HIGH)//End of Maze
    {
     Stop(); 
    }  
  }
}