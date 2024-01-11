#include "sensor.h"
#include "Wire.h"
#include "SHT31.h"

#define SHT31_ADDRESS 0x44
//INCLUDE LIBS
//constructor for SHT31
SHT31 sht;
int val1;
int val2;
sensor::sensor(int type){
    //1-sht31
    //2-AHT10
    //3-BMP80
    //4-BMP180
    //5-BME680
    switch (type)
    {
    case 1/* constant-expression */:

        /* code */
        sensor::begin_sensor(1);
        break;
    
    default:
        break;
    }
}
void sensor::begin_sensor(int type){
    switch (type)
    {
    case 1/* constant-expression */:
        /* code */
        sensor::begin_sensor(1);
        break;
    default:
        break;
    }
}
void sensor::read_sensor(int type){
    switch (type)
    {
    case 1/* constant-expression */:
        sht.read();
        val1=sht.getTemperature()*10;
        val2=sht.getHumidity()*10;
        return val1;
        return val2;
        break;
    
    default:
        break;
    }
}
