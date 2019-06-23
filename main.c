/*
 * File:   main.c
 * Author: Oliver
 *
 * Created on 16 December 2018, 13:17
 */

#include "mcc_generated_files/mcc.h"

#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include "fontt_resources.h"
#include "glcd128x64/glcd_lib.h"
#define samplefont Tahoma12x16_Regular
/* GLCD details for EasyPIC
 * 
 *  1	CS1	RB0	Active low
 *  2	CS2	RB1	Active low
 *  3	GND
 *  4	VCC
 *  5	Vo
 *  6	RS	RB2	0=Control
 *  7	R/W	RB3	0=Write
 *  8	E	RB4	Active High
 *  9	D0	RD0
 *  10	D1	RD1
 *  11	D2	RD2
 *  12	D3	RD3
 *  13	D4	RD4
 *  14	D5	RD5
 *  15	D6	RD6
 *  16	D7	RD7
 *  17	RST	RB5	Active Low
 *  18	VEE	
 *  19	LED+
 *  20	LED-
 */
char buf[20];
void main(void) {
//    ANSELD=0;
    //OSCCON NEEDED FOR PIC18F45K22
//#ifdef OSCCON
//    OSCCON=0X72;
//#endif
    SYSTEM_Initialize();
    /*
     * Initialize glcd
     */
    glcd_reset();
    __delay_ms(100);
    glcd_on();
    glcd_clear();
    for(uint8_t aa=10;aa<=100;aa+=10)
    {
        glcd_line(aa,10,10,53,1);
    }
    glcd_adv_systext(14,20,"GLCD Draw library",17);
    glcd_systext(28,32,"Oliver Broad",12);
    for(uint8_t d=0;d<=50;d++)
    {
        __delay_ms(100);
    }
    glcd_clear();
    uint8_t high;
    high=samplefont[0x06];
    uint8_t len;
    len=sprintf(buf,"Height %i",high);
    glcd_systext(64-len*3,8,buf,len);
    const char test[]="test string!!";
    uint8_t c=0;
    uint8_t x2=0;
    while(test[c]) {
        uint16_t i = (test[c] - samplefont[2])*4 + 8;
        uint8_t wide = samplefont[i];
        const char * bitmap;
        bitmap = samplefont + (samplefont[i + 1]+(samplefont[i + 2] << 8));
        len = sprintf(buf, "Width %i", wide);
        glcd_systext(64 - len * 3, 24, buf, len);
        uint8_t w2 = (wide + 7) / 8;
        for (uint8_t y = 0; y < high; y++) {
            for (uint8_t x = 0; x < wide; x++) {
                glcd_setpixel(x+x2, y+32, bitmap[x / 8] & (1 << (x & 7)));
            }
            bitmap += w2;
        }
        x2+=wide;
        x2++;
        c++;
    }

    for(uint8_t d=0;d<=50;d++)
    {
        __delay_ms(100);
    }
    glcd_clear();
    for(uint8_t aa=10;aa<=100;aa+=10)
    {
        glcd_line(aa,10,10,53,1);
    }
    //glcd_line(73,10,54,53,1);
    __delay_ms(200);
    __delay_ms(200);
    __delay_ms(200);
    __delay_ms(200);
    __delay_ms(200);
    __delay_ms(200);
    __delay_ms(200);
    __delay_ms(200);
    __delay_ms(200);
    __delay_ms(200);
    __delay_ms(200);
    glcd_clear();
    glcd_fill_donut(64,32,30,20,1);
    for(uint8_t l=1;l<=64;l++)
    {
        glcd_set_start_line(l);
            __delay_ms(100);
    }
    __delay_ms(200);
    __delay_ms(200);
    __delay_ms(200);
    __delay_ms(200);
    __delay_ms(200);
    __delay_ms(200);
    __delay_ms(200);
    __delay_ms(200);
    __delay_ms(200);
    __delay_ms(200);
    __delay_ms(200);
    glcd_clear();
    for(uint8_t r=5;r<=30;r+=5)
    {
        glcd_circle(64,32,r,1);
    }
    TRISD=0x00;
    while (1)
    {
        PORTD=0x55;
        __delay_ms(200);
        PORTD=~PORTD;
        __delay_ms(200);
    }
    
    return;
}
