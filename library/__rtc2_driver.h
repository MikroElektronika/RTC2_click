/*
    __rtc2_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __rtc2_driver.h
@brief    RTC_2 Driver
@mainpage RTC_2 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   RTC2
@brief      RTC_2 Click Driver
@{

| Global Library Prefix | **RTC2** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Nov 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _RTC2_H_
#define _RTC2_H_

/** 
 * @macro T_RTC2_P
 * @brief Driver Abstract type 
 */
#define T_RTC2_P    const uint8_t*

/** @defgroup RTC2_COMPILE Compilation Config */              /** @{ */

//  #define   __RTC2_DRV_SPI__                            /**<     @macro __RTC2_DRV_SPI__  @brief SPI driver selector */
   #define   __RTC2_DRV_I2C__                            /**<     @macro __RTC2_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __RTC2_DRV_UART__                           /**<     @macro __RTC2_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup RTC2_VAR Variables */                           /** @{ */


extern const uint8_t _RTC2_I2C_ADDRESS;
extern const uint8_t _RTC2_REG_TIME_SEC;
extern const uint8_t _RTC2_REG_TIME_MIN;
extern const uint8_t _RTC2_REG_TIME_HOUR;
extern const uint8_t _RTC2_REG_TIME_DAY_OF_THE_WEEK;
extern const uint8_t _RTC2_REG_TIME_DATE_DAY;
extern const uint8_t _RTC2_REG_TIME_DATE_MONTH;
extern const uint8_t _RTC2_REG_TIME_DATE_YEAR;
extern const uint8_t _RTC2_REG_CONTROL;
extern const uint8_t _RTC2_ENABLE_COUNTING;
extern const uint8_t _RTC2_DISABLE_COUNTING;
extern const uint8_t _RTC2_CONFIG_RATE_LOW;
extern const uint8_t _RTC2_CONFIG_RATE_HIGH;
extern const uint8_t _RTC2_CONFIG_RATE_SELECT_1_HZ;
extern const uint8_t _RTC2_CONFIG_RATE_SELECT_4_096_kHZ;
extern const uint8_t _RTC2_CONFIG_RATE_SELECT_8_192_kHZ;
extern const uint8_t _RTC2_CONFIG_RATE_SELECT_32_768_kHZ;

                                                                       /** @} */
/** @defgroup RTC2_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup RTC2_INIT Driver Initialization */              /** @{ */

#ifdef   __RTC2_DRV_SPI__
void rtc2_spiDriverInit(T_RTC2_P gpioObj, T_RTC2_P spiObj);
#endif
#ifdef   __RTC2_DRV_I2C__
void rtc2_i2cDriverInit(T_RTC2_P gpioObj, T_RTC2_P i2cObj, uint8_t slave);
#endif
#ifdef   __RTC2_DRV_UART__
void rtc2_uartDriverInit(T_RTC2_P gpioObj, T_RTC2_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void rtc2_gpioDriverInit(T_RTC2_P gpioObj);
                                                                       /** @} */
/** @defgroup RTC2_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Generic read byte of data function
 *
 * @param[in] regAddress                Register address
 *
 * Function read the 8-bit of data from the
 * target 8-bit register address of DS1307 chip on RTC 2 Click.
 */
uint8_t rtc2_readByte( uint8_t regAddress );

/**
 * @brief Generic write byte of data function
 *
 * @param[in] regAddress                Register address
 *
 * @param[in] writeData                 Byte of data to write
 *
 * Function write the 8-bit of data to the
 * target 8-bit register address of DS1307 chip on RTC 2 Click.
 */
void rtc2_writeByte( uint8_t regAddress, uint8_t writeData );

/**
 * @brief Enable counting function
 *
 * Function enable counting on RTC 2 Click.
 */
void rtc2_enableCounting();

/**
 * @brief Disable counting function
 *
 * Function disable counting on RTC 2 Click.
 */
void rtc2_disableCounting();

/**
 * @brief Get seconds function
 *
 * @return
 * Time seconds [ 0 sec - 59 sec ]
 *
 * Function gets seconds data from the target register address
 * ( 0x00 ) of DS1307 chip on RTC 2 Click.
 */
uint8_t rtc2_getTimeSeconds();

/**
 * @brief Set seconds function
 *
 * @param[in] seconds                   Time seconds [ 0 sec - 59 sec ]
 *
 * Function sets seconds data to the target register address
 * ( 0x00 ) of DS1307 chip on RTC 2 Click.
 */
void rtc2_setTimeSeconds( uint8_t seconds );

/**
 * @brief Get minutes function
 *
 * @return
 * Time minutes [ 0 min - 59 min ]
 *
 * Function gets minutes data from the target register address
 * ( 0x01 ) of DS1307 chip on RTC 2 Click.
 */
uint8_t rtc2_getTimeMinutes();

/**
 * @brief Set minutes function
 *
 * @param[in] minutes                   Time minutes [ 0 min - 59 min ]
 *
 * Function sets minutes data to the target register address
 * ( 0x01 ) of DS1307 chip on RTC 2 Click.
 */
void rtc2_setTimeMinutes( uint8_t minutes );

/**
 * @brief Get hours function
 *
 * @return
 * Time hours [ 0 h - 23 h ]
 *
 * Function gets hours data from the target register address
 * ( 0x02 ) of DS1307 chip on RTC 2 Click.
 */
uint8_t rtc2_getTimeHours();

/**
 * @brief Set hours function
 *
 * @param[in] hours                     Time hours [ 0 h - 23 h ]
 *
 * Function sets hours data to the target register address
 * ( 0x02 ) of DS1307 chip on RTC 2 Click.
 */
void rtc2_setTimeHours( uint8_t hours );

/**
 * @brief Get day of the week function
 *
 * @return
 * Day of the week [ 1 - 7 ]
 *
 * Function gets day of the week data from tne target register address
 * ( 0x03 ) of DS1307 chip on RTC 2 Click.
 */
uint8_t rtc2_getDayOfTheWeek();

/**
 * @brief Set day of the week function
 *
 * @param[in] wDay                      Day of the week data [ 1 - 7 ]
 *
 * Function sets day of the week data to the target register address
 * ( 0x03 ) of DS1307 chip on RTC 2 Click.
 */
void rtc2_setDayOfTheWeek( uint8_t wDay );

/**
 * @brief Get day function
 *
 * @return
 * Day [ 1 - 7 ]
 *
 * Function gets day data from the target register address
 * ( 0x04 ) of DS1307 chip on RTC 2 Click.
 */
uint8_t rtc2_getDateDay();

/**
 * @brief Set day function
 *
 * @param[in] dateDay                   Date day data [ 1 - 31 ]
 *
 * Function sets day data from the target register address
 * ( 0x04 ) of DS1307 chip on RTC 2 Click.
 */
void rtc2_setDateDay( uint8_t dateDay );

/**
 * @brief Get month function
 *
 * @return
 * Month [ 1 - 12 ]
 *
 * Function gets month data from the target register address
 * ( 0x05 ) of DS1307 chip on RTC 2 Click.
 */
uint8_t rtc2_getDateMonth();

/**
 * @brief Set month function
 *
 * @param[in] dateMonth                 Date month data [ 1 - 12 ]
 *
 * Function sets month data from the target register address
 * ( 0x05 ) of DS1307 chip on RTC 2 Click.
 */
void rtc2_setDateMonth( uint8_t dateMonth );

/**
 * @brief Get year function
 *
 * @return
 * Year [ 00 - 99 ]
 *
 * Function gets year data from the target register address
 * ( 0x06 ) of DS1307 chip on RTC 2 Click.
 */
uint8_t rtc2_getDateYear();

/**
 * @brief Set year function
 *
 * @param[in] dateYear                  Date year data [ 00 - 99 ]
 *
 * Function sets year data from the target register address
 * ( 0x06 ) of DS1307 chip on RTC 2 Click.
 */
void rtc2_setDateYear( uint16_t dateYear );

/**
 * @brief Set time hours, minutes and seconds function
 *
 * @param[in] timeHours                 Time hours [ 0 h - 23 h ]
 *
 * @param[in] timeMinutes               Time minutes [ 0 min - 59 min ]
 *
 * @param[in] timeSeconds               Time seconds [ 0 sec - 59 sec ]
 *
 * Function sets time: hours, minutes and seconds data to
 * the target register address ( 0x00, 0x01 & 0x02 ) of DS1307 chip on RTC 2 Click.
 */
void rtc2_setTime( uint8_t timeHours, uint8_t timeMinutes, uint8_t timeSeconds );

/**
 * @brief Get time hours, minutes and seconds function
 *
 * @param[out] timeHours                 pointer of time hours [ 0 h - 23 h ]
 *
 * @param[out] timeMinutes               pointer of time minutes [ 0 min - 59 min ]
 *
 * @param[out] timeSeconds               pointer of time seconds [ 0 sec - 59 sec ]
 *
 * Function gets time: hours, minutes and seconds data from
 * the target register address ( 0x00, 0x01 & 0x02 ) of DS1307 chip on RTC 2 Click.
 */
void rtc2_getTime( uint8_t *timeHours, uint8_t *timeMinutes, uint8_t *timeSeconds );

/**
 * @brief Set date hours, minutes and seconds function
 *
 * @param[in] dayOfTheWeek               Date of the week data [ 1 - 7 ]
 *
 * @param[in] dateDay                    Date day data [ 1 - 31 ]
 *
 * @param[in] dateMonth                  Date month data [ 1 - 12 ]
 *
 * @param[in] dateYear                   Date year data [ 0 - 99 ]
 *
 * Function sets date: day of the week, day, month and year data to
 * the target register address ( 0x03, 0x04, 0x05 & 0x06 ) of DS1307 chip on RTC 2 Click.
 */
void rtc2_setDate( uint8_t dayOfTheWeek, uint8_t dateDay, uint8_t dateMonth, uint16_t dateYear );

/**
 * @brief Get time hours, minutes and seconds function
 *
 * @param[out] dayOfTheWeek               pointer of date of the week data [ 1 - 7 ]
 *
 * @param[out] dateDay                    pointer of date day data [ 1 - 31 ]
 *
 * @param[out] dateMonth                  pointer of date month data [ 1 - 12 ]
 * 
 * @param[out] dateYear                   pointer of date year data [ 0 - 99 ]
 *
 * Function gets date: day of the week, day, month and year data from
 * the target register address ( 0x03, 0x04, 0x05 & 0x06 ) of DS1307 chip on RTC 2 Click.
 */
void rtc2_getDate( uint8_t *dayOfTheWeek, uint8_t *dateDay, uint8_t *dateMonth, uint16_t *dateYear );

/**
 * @brief Set frequency of square-wave output function
 *
 * @param[in] rateSelect               Rate selection of frequency of SQWE
 *
 * Function set frequency of square-wave output of DS1307 chip on RTC 2 Click.
 */
void rtc2_setFrequencySQWE( uint8_t rateSelect );




                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_RTC_2_STM.c
    @example Click_RTC_2_TIVA.c
    @example Click_RTC_2_CEC.c
    @example Click_RTC_2_KINETIS.c
    @example Click_RTC_2_MSP.c
    @example Click_RTC_2_PIC.c
    @example Click_RTC_2_PIC32.c
    @example Click_RTC_2_DSPIC.c
    @example Click_RTC_2_AVR.c
    @example Click_RTC_2_FT90x.c
    @example Click_RTC_2_STM.mbas
    @example Click_RTC_2_TIVA.mbas
    @example Click_RTC_2_CEC.mbas
    @example Click_RTC_2_KINETIS.mbas
    @example Click_RTC_2_MSP.mbas
    @example Click_RTC_2_PIC.mbas
    @example Click_RTC_2_PIC32.mbas
    @example Click_RTC_2_DSPIC.mbas
    @example Click_RTC_2_AVR.mbas
    @example Click_RTC_2_FT90x.mbas
    @example Click_RTC_2_STM.mpas
    @example Click_RTC_2_TIVA.mpas
    @example Click_RTC_2_CEC.mpas
    @example Click_RTC_2_KINETIS.mpas
    @example Click_RTC_2_MSP.mpas
    @example Click_RTC_2_PIC.mpas
    @example Click_RTC_2_PIC32.mpas
    @example Click_RTC_2_DSPIC.mpas
    @example Click_RTC_2_AVR.mpas
    @example Click_RTC_2_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __rtc2_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */