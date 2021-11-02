#ifndef kwSCD30_H
#define kwSCD30_H

#include "SparkFun_SCD30_Arduino_Library.h"

typedef struct {
  float temperature;
  uint8_t humidity;
  uint16_t co2;
} __attribute__((__packed__))payload_t;

class kwSCD30
{
public:

    kwSCD30();

    bool start( float temperatureOffset );
    bool dataAvailable();
    bool hasSCD30();
    float temperatureOffset();

    float temperature();
    uint16_t humidity();
    uint16_t co2();

    bool m_hasSCD30 = false;
  
protected:

    SCD30 m_scd30;
    payload_t m_payload;
    float m_temperatureOffset;
};

#endif