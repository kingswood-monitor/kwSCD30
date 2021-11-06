#ifndef kwSCD30_H
#define kwSCD30_H

#include <esp32-hal.h>

#include "SparkFun_SCD30_Arduino_Library.h"

typedef struct {
  float    temperature;
  uint8_t  humidity;
  uint16_t co2;
} __attribute__( ( __packed__ ) ) payload_t;

class kwSCD30 {
 public:
  kwSCD30();
  float    temperature();
  uint16_t humidity();
  uint16_t co2();
  void     start();
  bool     start( float temperatureOffset );
  bool     dataAvailable();
  bool     hasSCD30();
  float    temperatureOffset();

 protected:
  SCD30     m_scd30;
  payload_t m_payload;
  bool      m_hasSCD30 = false;
  float     m_temperatureOffset = 0;
};

#endif