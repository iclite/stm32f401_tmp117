#ifndef __TMP117_H
#define __TMP117_H

#include <stdint.h>

/**
 * @brief   TMP117 device address
 *
 */
#define TMP117_DEVICE_ID1               (0x48 << 1) //	GND
#define TMP117_DEVICE_ID2               (0x49 << 1) //	VCC
#define TMP117_DEVICE_ID3               (0x4A << 1) //	SDA
#define TMP117_DEVICE_ID4               (0x4B << 1) //	SCL

#define TMP117_DEVICE_ID                TMP117_DEVICE_ID1

/**
 * @brief   TMP117 register address
 *
 */
#define TMP117_TEMPERATURE_REGISTER     0x00
#define TMP117_CONFIGURATION_REGISTER   0x01
#define TMP117_TEMPERATURE_HIGH_LIMIT   0x02
#define TMP117_TEMPERATURE_LOW_LIMIT    0x03
#define TMP117_EEPROM_UCLOCK            0x04
#define TMP117_EEPROM1                  0x05
#define TMP117_EEPROM2                  0x06
#define TMP117_EEPROM3                  0x08
#define TMP117_TEMPERATURE_OFFSET       0x07
#define TMP117_ID_REGISTER              0x0F

/**
 * @brief   TMP117 function declaration
 *
 */

float TMP117_GetTemperature(I2C_HandleTypeDef i2c);

uint16_t TMP117_GetConfiguration(I2C_HandleTypeDef i2c);
uint16_t TMP117_GetHighLimit(I2C_HandleTypeDef i2c);
uint16_t TMP117_GetLowLimit(I2C_HandleTypeDef i2c);
uint16_t TMP117_GetEEPROMUnclock(I2C_HandleTypeDef i2c);
uint16_t TMP117_GetEEPROM1(I2C_HandleTypeDef i2c);
uint16_t TMP117_GetEEPROM2(I2C_HandleTypeDef i2c);
uint16_t TMP117_GetEEPROM3(I2C_HandleTypeDef i2c);
uint16_t TMP117_GetTemperatureOffset(I2C_HandleTypeDef i2c);
uint16_t TMP117_GetIDRegister(I2C_HandleTypeDef i2c);

void TMP117_SetConfiguration(I2C_HandleTypeDef i2c,uint8_t first,uint8_t second);
void TMP117_SetHighLimit(I2C_HandleTypeDef i2c,uint8_t first,uint8_t second);
void TMP117_SetLowLimit(I2C_HandleTypeDef i2c,uint8_t first,uint8_t second);
void TMP117_SetEEPROMUnlock(I2C_HandleTypeDef i2c,uint8_t first,uint8_t second);
void TMP117_SetEEPROM1(I2C_HandleTypeDef i2c,uint8_t first,uint8_t second);
void TMP117_SetEEPROM2(I2C_HandleTypeDef i2c,uint8_t first,uint8_t second);
void TMP117_SetEEPROM3(I2C_HandleTypeDef i2c,uint8_t first,uint8_t second);
void TMP117_SetTemperatureOffset(I2C_HandleTypeDef i2c,uint8_t first,uint8_t second);
void TMP117_Initialization(I2C_HandleTypeDef i2c);
void TMP117_InitializationDefault(I2C_HandleTypeDef i2c);

#endif /* __TMP117_H */
