#define _TMP117_C_

#include <stdint.h>
#include "main.h"
#include "tmp117.h"

/*
   @Brief         Get temperature basically
   @Description   Function gives to us ambient temperature
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
   @Return value  Float
 */
float TMP117_GetTemperature(I2C_HandleTypeDef i2c)
{
    static uint8_t buf[2];

    HAL_I2C_Mem_Read(&i2c, TMP117_DEVICE_ID, TMP117_TEMPERATURE_REGISTER, 1, buf, 2, 100);

    return ((((buf[0]<<8)|buf[1]))*0.0078125);
}

/*
   @Brief         Get Configuration
   @Description   Get Configuration Register Value
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
   @Return value  uint16_t
 */
uint16_t TMP117_GetConfiguration(I2C_HandleTypeDef i2c)
{
    static uint8_t buf[2];

    HAL_I2C_Mem_Read(&i2c, TMP117_DEVICE_ID, TMP117_CONFIGURATION_REGISTER, 1, buf, 2, 100);

    return ((buf[0]<<8)|buf[1]);
}

/*
   @Brief         Set Configuration
   @Description   Set Configuration Register for Features
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
                  uint8_t first     ->  [15:8]
                  uint8_t second    ->  [7:0]
   @Return value  void
 */
void TMP117_SetConfiguration(I2C_HandleTypeDef i2c,uint8_t first,uint8_t second)
{
    static uint8_t buf[2];
    buf[0]=first;
    buf[1]=second;

    HAL_I2C_Mem_Write(&i2c, TMP117_DEVICE_ID, TMP117_CONFIGURATION_REGISTER, 1, buf, 2, 100);
}

/*
   @Brief         Set HighLimit
   @Description   Set HighLimit for Alert
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
                  uint8_t first     ->  [15:8]
                  uint8_t second    ->  [7:0]
   @Return value  void
 */
void TMP117_SetHighLimit                (I2C_HandleTypeDef i2c,uint8_t first,uint8_t second)
{
    static uint8_t buf[2];
    buf[0]=first;
    buf[1]=second;

    HAL_I2C_Mem_Write(&i2c, TMP117_DEVICE_ID, TMP117_TEMPERATURE_HIGH_LIMIT, 1, buf, 2, 100);
}

/*
   @Brief         Get Highlimit
   @Description   Get Highlimit Register Value
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
   @Return value  uint16_t
 */
uint16_t TMP117_GetHighLimit         (I2C_HandleTypeDef i2c)
{
    static uint8_t buf[2];

    HAL_I2C_Mem_Read(&i2c, TMP117_DEVICE_ID, TMP117_TEMPERATURE_HIGH_LIMIT, 1, buf, 2, 100);

    return ((buf[0]<<8)|buf[1]);
}

/*
   @Brief         Set LowLimit
   @Description   Set LowLimit for Alert
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
                  uint8_t first     ->  [15:8]
                  uint8_t second    ->  [7:0]
   @Return value  void
 */
void TMP117_SetLowLimit                 (I2C_HandleTypeDef i2c,uint8_t first,uint8_t second)
{
    static uint8_t buf[2];
    buf[0]=first;
    buf[1]=second;

    HAL_I2C_Mem_Write(&i2c, TMP117_DEVICE_ID, TMP117_TEMPERATURE_LOW_LIMIT, 1, buf, 2, 100);
}

/*
   @Brief         Get LowLimit
   @Description   Get Lowlimit Register Value
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
   @Return value  uint16_t
 */
uint16_t TMP117_GetLowLimit(I2C_HandleTypeDef i2c)
{
    static uint8_t buf[2];

    HAL_I2C_Mem_Read(&i2c, TMP117_DEVICE_ID, TMP117_TEMPERATURE_LOW_LIMIT, 1, buf, 2, 100);

    return ((buf[0]<<8)|buf[1]);
}

/*
   @Brief         Get EEPROM Unlock Register Value
   @Description   Check EEPROM for Unlock/Lock
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
   @Return value  uint16_t
 */
uint16_t TMP117_GetEEPROMUnclock(I2C_HandleTypeDef i2c)
{
    static uint8_t buf[2];

    HAL_I2C_Mem_Read(&i2c, TMP117_DEVICE_ID, TMP117_EEPROM_UCLOCK, 1, buf, 2, 100);

    return ((buf[0]<<8)|buf[1]);
}

/*
   @Brief         Set EEPROM Unlock Register Value
   @Description   Active/Inactive for EEPROM read/write situation
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
                  uint8_t first     ->  [15:8]
                  uint8_t second    ->  [7:0]
   @Return value  void
 */
void TMP117_SetEEPROMUnlock(I2C_HandleTypeDef i2c,uint8_t first,uint8_t second)
{
    static uint8_t buf[2];
    buf[0]=first;
    buf[1]=second;

    HAL_I2C_Mem_Write(&i2c, TMP117_DEVICE_ID, TMP117_EEPROM_UCLOCK, 1, buf, 2, 100);
}

/*
   @Brief
   @Description
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
                  uint8_t first     ->  [15:8]
                  uint8_t second    ->  [7:0]
   @Return value  void
 */
void TMP117_SetEEPROM1(I2C_HandleTypeDef i2c,uint8_t first,uint8_t second)
{

    static uint8_t buf[2];
    buf[0]=first;
    buf[1]=second;

    HAL_I2C_Mem_Write(&i2c, TMP117_DEVICE_ID, TMP117_EEPROM1, 1, buf, 2, 100);
}

/*
   @Brief
   @Description
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
   @Return value  uint16_t
 */
uint16_t TMP117_GetEEPROM1(I2C_HandleTypeDef i2c)
{
    static uint8_t buf[2];

    HAL_I2C_Mem_Read(&i2c, TMP117_DEVICE_ID, TMP117_EEPROM1, 1, buf, 2, 100);

    return ((buf[0]<<8)|buf[1]);
}

/*
   @Brief
   @Description
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
                  uint8_t first     ->  [15:8]
                  uint8_t second    ->  [7:0]
   @Return value  void
 */
void TMP117_SetEEPROM2(I2C_HandleTypeDef i2c,uint8_t first,uint8_t second)
{
    static uint8_t buf[2];
    buf[0]=first;
    buf[1]=second;

    HAL_I2C_Mem_Write(&i2c, TMP117_DEVICE_ID, TMP117_EEPROM2, 1, buf, 2, 100);
}

/*
   @Brief
   @Description
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
   @Return value  uint16_t
 */
uint16_t TMP117_GetEEPROM2(I2C_HandleTypeDef i2c)
{
    static uint8_t buf[2];

    HAL_I2C_Mem_Read(&i2c, TMP117_DEVICE_ID, TMP117_EEPROM2, 1, buf, 2, 100);

    return ((buf[0]<<8)|buf[1]);
}

/*
   @Brief
   @Description
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
                  uint8_t first     ->  [15:8]
                  uint8_t second    ->  [7:0]
   @Return value  void
 */
void TMP117_SetEEPROM3(I2C_HandleTypeDef i2c,uint8_t first,uint8_t second)
{
    static uint8_t buf[2];
    buf[0]=first;
    buf[1]=second;

    HAL_I2C_Mem_Write(&i2c, TMP117_DEVICE_ID, TMP117_EEPROM3, 1, buf, 2, 100);
}

/*
   @Brief         Get EEPROM3 Value
   @Description
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
   @Return value  uint16_t
 */
uint16_t TMP117_GetEEPROM3(I2C_HandleTypeDef i2c)
{
    static uint8_t buf[2];

    HAL_I2C_Mem_Read(&i2c, TMP117_DEVICE_ID, TMP117_EEPROM3, 1, buf, 2, 100);

    return ((buf[0]<<8)|buf[1]);
}

/*
   @Brief         Set Temperature Offset Value
   @Description   Set Temperature Offset Value for Calibrating
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
                  uint8_t first     ->  [15:8]
                  uint8_t second    ->  [7:0]
   @Return value  void
 */
void TMP117_SetTemperatureOffset(I2C_HandleTypeDef i2c,uint8_t first,uint8_t second)
{
    static uint8_t buf[2];
    buf[0]=first;
    buf[1]=second;

    HAL_I2C_Mem_Write(&i2c, TMP117_DEVICE_ID, TMP117_TEMPERATURE_OFFSET, 1, buf, 2, 100);
}

/*
   @Brief         Get Temperature Offset Value
   @Description   Get Temperature Offset Value for Calibrating
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
   @Return value  uint16_t
 */
uint16_t TMP117_GetTemperatureOffset(I2C_HandleTypeDef i2c)
{
    static uint8_t buf[2];

    HAL_I2C_Mem_Read(&i2c, TMP117_DEVICE_ID, TMP117_TEMPERATURE_OFFSET, 1, buf, 2, 100);

    return ((buf[0]<<8)|buf[1]);
}

/*
   @Brief         Get ID Register
   @Description   Check Device ID for Error Handler
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
   @Return value  uint16_t
 */
uint16_t TMP117_GetIDRegister(I2C_HandleTypeDef i2c)
{
    static uint8_t buf[2];

    HAL_I2C_Mem_Read(&i2c, TMP117_DEVICE_ID, TMP117_ID_REGISTER, 1, buf, 2, 100);

    return ((buf[0]<<8)|buf[1]);
}

/*
   @Brief         Custom Initialization
   @Description   Custom Parameters for Sensor
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
   @Return value  void
 */
void TMP117_Initialization(I2C_HandleTypeDef i2c)
{
      TMP117_SetConfiguration(i2c,0x02,0x20);
      TMP117_SetTemperatureOffset(i2c,0x00,0x00); //Default Value
      TMP117_SetLowLimit(i2c,0x12,0x80);           //Set 10 Celcius
      TMP117_SetHighLimit(i2c,0x51,0x20);          //Set 40 Celcius
}

/*
   @Brief         Default Initialization
   @Description   Default Parameters for Sensor
   @Parameter     I2C_HandleTypeDef ->  HAL_I2C Handle
   @Return value  void
 */
void TMP117_InitializationDefault(I2C_HandleTypeDef i2c)
{
      TMP117_SetConfiguration(i2c,0x02,0x20);
      TMP117_SetTemperatureOffset(i2c,0x00,0x00);
      TMP117_SetLowLimit(i2c,0x80,0x00);
      TMP117_SetHighLimit(i2c,0x60,0x00);
      TMP117_SetEEPROMUnlock(i2c,0x00,0x00);
}