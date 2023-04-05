#include "Arduino.h"
#include "Sumo.h"

Sensor::Sensor(uint8_t Pin, bool sensType = Digital, int Limit = 1) {
  pin = Pin;
  SensType = sensType;
  limit = Limit;
  this->Sensor::Setup();
}
void Sensor::Setup() {
  pinMode(pin, INPUT);
}
bool Sensor::Read() {
  if (SensType == Digital) {
    return digitalRead(pin);
  } else if (SensType == Analog) {
    return analogRead(pin) >= limit;
  }
  return;
}

//----------------------------

Module::Module(uint8_t Pin, bool sensType) {
  pin = Pin;
  SensType = sensType;
  this->Setup();
}
void Module::Setup() {
  pinMode(pin, OUTPUT);
}
void Module::write(uint8_t value){
  if (SensType == Digital){digitalWrite(pin, value);}
  else if(SensType == Analog){analogWrite(pin, value);}
}
void Module::open(int Delay = 100){
  analogWrite(pin, 255);
  delay(Delay);                
  analogWrite(pin, 0);
}

//----------------------------------

Motor::Motor(uint8_t ENA, uint8_t ENB){
  ena = ENA;
  enb = ENB;
  this->Setup();
}
void Motor::Setup(){
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
}
void Motor::drive(int speed){
  if (speed<0){
    digitalWrite(ena, LOW);
    analogWrite(enb, abs(speed));
  }
  else if (speed>0){
    digitalWrite(enb, LOW);
    analogWrite(ena, speed);
  }
  else{
    digitalWrite(ena, HIGH);
    digitalWrite(enb, HIGH);
  }
}
