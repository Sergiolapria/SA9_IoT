#include "sensor.h"
#include "Wire.h"
#include "SHT31.h"

#define SHT31_ADDRESS 0x44
//INCLUDE LIBS
sensor::sensor(int type){
    //1-sht31
    //2-AHT10
    //3-BMP80
    //4-BMP180
    //5-BME680
    switch (type)
    {
    case 1/* constant-expression */:
        //constructor for SHT31
        SHT31 sht;
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
        //constructor for SHT31
        SHT31 sht;
        /* code */
        sensor::begin_sensor(1);
        break;
    default:
        break;
    }
}
void sensor::read_sensor(int type){
    
}
