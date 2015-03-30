#ifndef ___SHT25_H___
#define ___SHT25_H___
#include <Wire.h>
#include <stdint.h>

// this is the 7-bit I2C address
#define SHT25_7_BIT_I2C_ADDRESS        0x40 

// these are expressed as the temperature resolution
// relative humidity resolution is implied by Table 8 in the datasheet
#define SHT25_RESOLUTION_14BIT         0x00  // 12-bit %RH
#define SHT25_RESOLUTION_13BIT         0x02  // 10-bit %RH
#define SHT25_RESOLUTION_12BIT         0x01  //  8-bit %RH
#define SHT25_RESOLUTION_11BIT         0x03  // 11-bit %RH

class SHT25{
  public:
    SHT25();
    void begin(uint8_t temperature_resolution_code = SHT25_RESOLUTION_14BIT);
    float getTemperature(void);
    float getRelativeHumidity(void);
    void  getSerialNumber(uint8_t * buf);
    uint8_t getUserData(boolean emit_stop = true);
    void  setMeasurementResolution(uint8_t temperature_resolution_code);   
    void softReset(void); 
  private:
    boolean checkCRC(uint8_t * data, uint8_t num_bytes, uin8_t checksum);
    boolean getTempHumidityRequestCommon(uint8_t cmd, uint8_t * buf);
    boolean requestReadAndReceiveBytes(uint8_t buf, uint8_t num_bytes, emit_stop = true);
}

#endif