
// // CONNECTIONS:
// // DS1302 CLK/SCLK --> 5
// // DS1302 DAT/IO --> 4
// // DS1302 RST/CE --> 2
// // DS1302 VCC --> 3.3v - 5v
// // DS1302 GND --> GND

// #include <ThreeWire.h>  
// #include <RtcDS1302.h>

// ThreeWire myWire(8,7,9); // DAT, CLK, RST
// RtcDS1302<ThreeWire> Rtc(myWire);

// #define countof(a) (sizeof(a) / sizeof(a[0]))

// void printDateTime(const RtcDateTime& dt)
// {
//     char datestring[20];

//     snprintf_P(datestring, 
//             countof(datestring),
//             PSTR("%02u/%02u %02u:%02u:%02u"),
//             dt.Month(),
//             dt.Day(),
//             dt.Hour(),
//             dt.Minute(),
//             dt.Second() );
//     lcd.print(datestring);
// }

