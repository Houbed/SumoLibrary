#ifndef Sumo_h
#define Sumo_h

#include "Sumo.h"

#define Analog 0
#define Digital 1

//--------------------------------

struct Sensor {

  public:
    uint8_t pin;
    bool SensType;
    int limit;

    Sensor(uint8_t Pin, bool sensType, int Limit);
    bool Read();

  private:
    void Setup();
};

//--------------------------------

struct Module {

  public:
    uint8_t pin;
    bool SensType;
    Module(uint8_t Pin, bool sensType);
    void write(uint8_t value);
    void open(int Delay);
  private:
    void Setup();
};

//--------------------------------

struct Motor{
  public:
    uint8_t ena;
    uint8_t enb;
    Motor(uint8_t ENA, uint8_t ENB);
    void drive(int speed);
  private:
    void Setup();
};

//--------------------------------
#endif
