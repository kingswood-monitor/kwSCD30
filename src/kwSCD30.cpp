#include "kwSCD30.h"

// kwSCD30 constructor
kwSCD30::kwSCD30() {}

void kwSCD30::start() { start( 0 ); }

// Start the sensor with maximum update frequency (2 seconds)
bool kwSCD30::start( float temperatureOffset )
{
  m_temperatureOffset = temperatureOffset;
  m_hasSCD30 = m_scd30.begin();

  if ( m_hasSCD30 )
  {
    m_scd30.setAutoSelfCalibration( true );
    m_scd30.setMeasurementInterval( 2 );
    m_scd30.setTemperatureOffset( 0 );
  }
  return m_hasSCD30;
}

bool kwSCD30::hasSCD30() { return m_hasSCD30; }

float kwSCD30::temperatureOffset() { return m_temperatureOffset; }

// Update the readings if available
bool kwSCD30::dataAvailable()
{
  if ( m_hasSCD30 && m_scd30.dataAvailable() )
  {
    m_payload.temperature = m_scd30.getTemperature() - m_temperatureOffset;
    m_payload.humidity = (int)m_scd30.getHumidity();
    m_payload.co2 = (int)m_scd30.getCO2();

    return true;
  } else
  {
    return false;
  }
}

// Readings
float    kwSCD30::temperature() { return m_payload.temperature; }
uint16_t kwSCD30::humidity() { return m_payload.humidity; }
uint16_t kwSCD30::co2() { return m_payload.co2; }