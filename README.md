![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# RTC_2 Click

---

- **CIC Prefix**  : RTC2
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Nov 2018.

---

### Software Support

We provide a library for the RTC_2 Click on our [LibStock](https://libstock.mikroe.com/projects/view/1241/rtc3-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions to control RTC 2 Click board.
RTC 2 click communicates with the target board via I2C protocol. 
This library contains drivers for write and read data from DS1307 chip,
set time and date, get time and date, enable and disable counting
and set frequency by write configuration register. 

Key functions :

- ``` void rtc2_setTime( uint8_t timeHours, uint8_t timeMinutes, uint8_t timeSeconds ) ``` - Set time hours, minutes and seconds function
- ``` void rtc2_getTime( uint8_t *timeHours, uint8_t *timeMinutes, uint8_t *timeSeconds ) ``` - Get time hours, minutes and seconds function
- ``` void rtc2_getDate( uint8_t *dayOfTheWeek, uint8_t *dateDay, uint8_t *dateMonth, uint16_t *dateYear ) ``` - Get time hours, minutes and seconds function

**Examples Description**

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


```.c

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

```

Additional Functions :

- void displayDayOfTheWeek( uint8_t dayOfTheWeek ) - Write day of the week log on USART terminal.
- void displayLogUart( uint8_t value ) - Write the value ( time or date ) of a two-digit number.

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/1241/rtc3-click) page.

Other mikroE Libraries used in the example:

- I2C


**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
