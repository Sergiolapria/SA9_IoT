#ifndef SENSOR_H
#define SENSOR_H
#include "Arduino.h"
//IONCLUDE libs
class sensor{
    public:
        sensor(int type);
        void read_sensor(int type);
    private:
        void begin_sensor(int type);
};
#endif