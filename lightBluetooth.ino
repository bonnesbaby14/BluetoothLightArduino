#include <SoftwareSerial.h>
SoftwareSerial miBT(10,11);
bool light1=false;
bool light2=false;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("LISTO");
  miBT.begin(9600);

  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  if(miBT.available()){
        char dato=miBT.read();
    if(dato=='1'){
    light1=!light1;
    if(light1){
      digitalWrite(3,HIGH);
      }else{
        digitalWrite(3,LOW);
        }
    
      }else
       if(dato=='2'){
        light2=!light2;
    if(light2){
      digitalWrite(4,HIGH);
      }else{
        digitalWrite(4 ,LOW);
        }
      }
    
    
    }
    if(Serial.available()){
      miBT.write(Serial.read());
      }

}
