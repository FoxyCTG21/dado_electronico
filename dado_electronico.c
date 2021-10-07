/*
 * File:   Dado-electronico.c
 * Author: Usuario
 *
 * Created on 7 de octubre de 2021, 13:09
 */


#include <xc.h>
#pragma config PLLDIV = 5
#pragma config CPUDIV = OSC1_PLL2
#pragma config FOSC = HSPLL_HS
#pragma config LVP = OFF
#define _XTAL_FREQ 48000000

void display(int num){
    LATB = 0b0000000;
    
    if(num == 0){
        LATB = 0b0111111;
    }
    if(num == 1){
        LATB = 0b0000110;
    }
    if(num == 2){
        LATB = 0b1011011;
    }
    if(num == 3){
        LATB = 0b1001111;
    }
    if(num == 4){
        LATB = 0b1100110;
    }
    if(num == 5){
        LATB = 0b1101101;
    }
    if(num == 6){
        LATB = 0b1111101;
    }
    if(num == 7){
        LATB = 0b0000111;
    }
    if(num == 8){
        LATB = 0b1111111;
    }
    if(num == 9){
        LATB = 0b1100111;
    }
    if(num > 9){
        LATB = 0b1110001;
    }
}

void delay(int time){
    if(time == 0){
        __delay_ms(5);
    }
    if(time == 1){
        __delay_ms(100);
    }
    if(time == 2){
        __delay_ms(150);
    }
}

void main(void) {
    
    int resultado = 0;
    ADCON1 = 0x0F; //Utilizamos esto para desabilitar los puertos analogicos
    TRISB=0b00000000; //Asignamos salida los puertos B
    TRISCbits.TRISC0 = 1; // Asignamos el pulsador de dado
    TRISAbits.TRISA3 = 1; //Asignamos los puertos A como entrada
    TRISAbits.TRISA4 = 1; //Estos asignan el delay de aleatorio
    TRISAbits.TRISA5 = 1;
    
    while(1){
        //Valor aleatorio del dado
        resultado = resultado + 1;
        if(resultado == 7){
            resultado = 1;
        }
        if(PORTCbits.RC0 == 0){
            display(resultado);
        }
        
        //Ajuste del delay
        if(PORTAbits.RA5 == 0){
            delay(0);
        }
        if(PORTAbits.RA4 == 0){
            delay(1);
        }
        if(PORTAbits.RA3 == 0){
            delay(2);
        }
    }
    
}