int const M11 = 5;
int const M12 = 6;
int const M21 = 10;
int const M22 = 11;
int ir_l = 2;
int ir_r = 4;
int ir_m = 7;
int speed_ = 160;
int speed_t = 255;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(M11,OUTPUT);
  pinMode(M12,OUTPUT);
  pinMode(M21,OUTPUT);
  pinMode(M22,OUTPUT);
  pinMode(ir_l,INPUT);
  pinMode(ir_r,INPUT);
  pinMode(ir_m,INPUT);
}
void forward(){
  analogWrite(M11,0);
  analogWrite(M12,speed_);
  analogWrite(M21,0);
  analogWrite(M22,speed_);
  delay(50);
}
//void backward(){
//    digitalWrite(M11,LOW);
//    digitalWrite(M12,HIGH);
//    digitalWrite(M21,LOW);
//    digitalWrite(M22,HIGH);
//    delay(10);
void left(){
  analogWrite(M11,speed_t);
  analogWrite(M12,0);
  analogWrite(M21,0);
  analogWrite(M22,speed_t);
  delay(90);
}
void sleft(){
  analogWrite(M11,speed_t);
  analogWrite(M12,0);
  analogWrite(M21,0);
  analogWrite(M22,speed_t);
  delay(10);
}
void right(){
  
  analogWrite(M11,0);
    analogWrite(M12,speed_t);
    analogWrite(M21,speed_t);
    analogWrite(M22,0);
    delay(90);
}
void sright(){
  
  analogWrite(M11,0);
    analogWrite(M12,speed_t);
    analogWrite(M21,speed_t);
    analogWrite(M22,0);
    delay(10);
}
void rotate(){
   analogWrite(M11,0);
    analogWrite(M12,speed_t);
    analogWrite(M21,speed_t);
    analogWrite(M22,0);
    delay(300);
}
void loop() {
  // put your main code here, to run repeatedly:
  while(1){
    int val_ir_l = digitalRead(ir_l);
    int val_ir_r = digitalRead(ir_r);
    int val_ir_m = digitalRead(ir_m);
    if(val_ir_l == 0 && val_ir_r == 0 && val_ir_m == 1){
      forward();
    }
    else if(val_ir_l == 1 && val_ir_r == 0){
      right();
    }
    else if(val_ir_l == 0 && val_ir_r == 1){
      left();
    }
    else if(val_ir_l == 0 && val_ir_r == 1 && val_ir_m == 1){
      sleft();
    }
    else if(val_ir_l == 1 && val_ir_r == 0 && val_ir_m == 1){
      sright();
    }
   
    else if(val_ir_l == 1 && val_ir_r == 1){
      right();
    }
    
    else if(val_ir_l == 0 && val_ir_r == 1){
      rotate();
    }
    else if(val_ir_l == 0 && val_ir_r == 0 && val_ir_m == 0){
      rotate();
    }
  }
}