/*
Example for RTC_2 Click

    Date          : Nov 2018.
    Author        : Nenad Filipovic

Test configuration PIC :
    
    MCU             : P18F87K22
    Dev. Board      : EasyPIC PRO v7
    PIC Compiler ver : v7.2.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes GPIO, I2C and LOG structures, set INT pin as input.
- Application Initialization - Initialization driver enable's - I2C,
     set start time and date, enable counting and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of RTC 2 Click board.
     RTC 2 Click communicates with register via I2C by write to register and read from register,
     set time and date, get time and date, enable and disable counting
     and set frequency by write configuration register.
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs write on usb uart changes for every 1 sec.

Additional Functions :

- void displayDayOfTheWeek( uint8_t dayOfTheWeek ) - Write day of the week log on USART terminal.
- void displayLogUart( uint8_t value ) - Write the value ( time or date ) of a two-digit number.

*/

#include "Click_RTC_2_types.h"
#include "Click_RTC_2_config.h"

uint8_t timeHours;
uint8_t timeMinutes;
uint8_t timeSeconds;
uint8_t dayOfTheWeek;
uint8_t dateDay;
uint8_t dateMonth;
uint16_t dateYear;
uint8_t timeSecondsNew = 0;
char logText[50];

void displayDayOfTheWeek( uint8_t dayOfTheWeek )
{
    if ( dayOfTheWeek == 1 )
        mikrobus_logWrite( "      Monday      ", _LOG_LINE );
    if ( dayOfTheWeek == 2 )
        mikrobus_logWrite( "      Tuesday     ", _LOG_LINE );
    if ( dayOfTheWeek == 3 )
        mikrobus_logWrite( "     Wednesday    ", _LOG_LINE );
    if ( dayOfTheWeek == 4 )
        mikrobus_logWrite( "     Thursday     ", _LOG_LINE );
    if ( dayOfTheWeek == 5 )
        mikrobus_logWrite( "      Friday      ", _LOG_LINE );
    if ( dayOfTheWeek == 6 )
        mikrobus_logWrite( "     Saturday     ", _LOG_LINE );
    if ( dayOfTheWeek == 7 )
        mikrobus_logWrite( "      Sunday      ", _LOG_LINE );
}

void displayLogUart( uint8_t value )
{
    IntToStr( value / 10, logText );
    ltrim( logText );
    mikrobus_logWrite( logText, _LOG_TEXT );
    IntToStr( value % 10, logText );
    ltrim( logText );
    mikrobus_logWrite( logText, _LOG_TEXT );
}

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );

    mikrobus_i2cInit( _MIKROBUS1, &_RTC2_I2C_CFG[0] );

    mikrobus_logInit( _LOG_USBUART, 9600 );

    Delay_100ms();
}

void applicationInit()
{
    rtc2_i2cDriverInit( (T_RTC2_P)&_MIKROBUS1_GPIO, (T_RTC2_P)&_MIKROBUS1_I2C, _RTC2_I2C_ADDRESS );

    mikrobus_logWrite( "-------------------", _LOG_LINE );
    mikrobus_logWrite( "    RTC 2 Click    ", _LOG_LINE );
    mikrobus_logWrite( "-------------------", _LOG_LINE );

    // Set Time: 23h, 59 min and 50 sec
    rtc2_setTime( 23, 59, 50 );
    // Set Date: 1 ( Day of the week ), 31 ( day ), 12 ( month ) and 2018 ( year )
    rtc2_setDate( 1, 31, 12, 2018 );
    // Start counting
    rtc2_enableCounting();
}

void applicationTask()
{
    rtc2_getTime( &timeHours, &timeMinutes, &timeSeconds );

    rtc2_getDate( &dayOfTheWeek, &dateDay, &dateMonth, &dateYear );

    if ( timeSecondsNew !=  timeSeconds )
    {
        mikrobus_logWrite( " Time : ", _LOG_TEXT );

        displayLogUart( timeHours );
        mikrobus_logWrite( ":", _LOG_TEXT );

        displayLogUart( timeMinutes );
        mikrobus_logWrite( ":", _LOG_TEXT );

        displayLogUart( timeSeconds );
        mikrobus_logWrite( "", _LOG_LINE );

        displayDayOfTheWeek( dayOfTheWeek );

        mikrobus_logWrite( " Date: ", _LOG_TEXT );

        displayLogUart( dateDay );
        mikrobus_logWrite( ".", _LOG_TEXT );

        displayLogUart( dateMonth );
        mikrobus_logWrite( ".", _LOG_TEXT );

        mikrobus_logWrite( "20", _LOG_TEXT );

        displayLogUart( dateYear );
        mikrobus_logWrite( ".", _LOG_LINE );

        mikrobus_logWrite( "-------------------", _LOG_LINE );

        timeSecondsNew =  timeSeconds;
    }
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}