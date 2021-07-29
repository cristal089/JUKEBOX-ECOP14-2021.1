#include "config.h"
#include "bits.h"
#include "keypad.h"
#include "lcd.h"
#include "delay.h"
#include "ssd.h"
#include "pwm.h"
#include <pic18f4520.h>

#define L1 0x80
#define L2 0xC0
#define L3 0x90
#define L4 0xD0
#define CLR 0x01
#define ON 0x0F

void notaLogo_1(void);
void discoLogo_1(void);
void discoLogo_2(void);
void discoLogo_3(void);
void apresentaMenu(int infoSom);
void musicaLenta(void);
void musicaMedia(void);
void musicaRapida(void);

void main(void) {
    unsigned int tecla1 = 16, tecla2 = 16;
    unsigned char i;
    int som = 1111;
    
    //ADCON1 = 0x06;
    TRISD = 0x00;
    PORTD = 0x00;
    TRISE = 0x00;    
    
    TRISA = 0xC3;
    TRISB = 0x03;
    TRISC = 0x01;
    
    lcdInit();
    kpInit();   
    pwmInit();
    ssdInit();
    lcdCommand(ON);
    lcdCommand(0x0C); //desliga o cursor
        
    // Tela inicial
    for(i=0; i<4; i++){
        discoLogo_1();        
        lcdString(" JUKEBOX");  
        tempo(250);
        discoLogo_2();       
        lcdString(" JUKEBOX");
        tempo(250);   
        discoLogo_3();
        lcdString(" JUKEBOX");
        tempo(250);
    }
    discoLogo_1();
    lcdString(" JUKEBOX");
    tempo(250);
    
    // Menu para inserir o dinheiro
    lcdCommand(CLR);
    lcdCommand(L2);
    lcdString("Insira as moedas");
    lcdPosition(3, 3);
    lcdString("(Aperte *)");
    tempo(100);        
    
    for(;;){
        kpDebounce();       
        
        if (kpRead() != tecla1){
            tecla1 = kpRead();          
            
            if (bitTst(kpRead(), 0)) //asterisco
            {     
                // buzzer ao apertar a tecla
                pwmSet2(50);
                tempo(50);      
                pwmSet2(0);                
                
                apresentaMenu(som);    
                                            
                for(;;){
                    kpDebounce();       
        
                    if (kpRead() != tecla2){
                        tecla2 = kpRead(); 
                        
                        if (bitTst(kpRead(), 0)){ //asterisco
                            apresentaMenu(som);
                        } //bitTst 0 (asterisco) 2
                        
                        if (bitTst(kpRead(), 3)){ //número 1
                            pwmSet1(30);
                            lcdCommand(CLR);             
                            lcdPosition(1, 5);
                            lcdString("Lenta");
                            notaLogo_1();
                            if(som == 0000) tempo(6000);
                            else musicaLenta();
                            pwmSet1(0);
                            lcdPosition(4, 4);
                            lcdString("(*):Menu");
                        } //bitTst 3 (número 1)
                        
                        if (bitTst(kpRead(), 7)){ //número 2
                            pwmSet1(30);
                            lcdCommand(CLR);  
                            lcdPosition(1, 5);
                            lcdString("Media");
                            notaLogo_1(); 
                            if(som == 0000) tempo(4200);
                            else musicaMedia();
                            pwmSet1(0);
                            lcdPosition(4, 4);
                            lcdString("(*):Menu");
                        } //bitTst 7 (número 2)
                        
                        if (bitTst(kpRead(), 11)){ //número 3
                            pwmSet1(30);
                            lcdCommand(CLR);  
                            lcdPosition(1, 5);
                            lcdString("Rapida");
                            notaLogo_1();
                            if(som == 0000) tempo(2250);
                            else musicaRapida();
                            pwmSet1(0);
                            lcdPosition(4, 4);
                            lcdString("(*):Menu");
                        } //bitTst 11 (número 3)
                        
                        if (bitTst(kpRead(), 8)){ //hashtag
                            if(som == 1111) som = 0000;                                  
                            else som = 1111;   
                            apresentaMenu(som);
                        } //bitTst 8 (hashtag)
                    } //kpRead menu de músicas   
                    ssdDigit((som/1)    %10, 3);
                    ssdDigit((som/10)   %10, 2);
                    ssdDigit((som/100)  %10, 1);
                    ssdDigit((som/1000) %10, 0);
        
                    ssdUpdate();
                    tempo(1);
                    //timerWait();
                } //segundo for(;;)
            } //bitTst 0 (asterisco) 1
        } //primeiro kpRead       
     } //primeiro for(;;)
} //main

void notaLogo_1(void){
    lcdCommand(0x40);
    
    char logo[48] = {
    0x00, 0x0F, 0x0F, 0x0F, 0x03, 0x03, 0x03, 0x03, 
    0x00, 0x1F, 0x1F, 0x1F, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x1E, 0x1E, 0x1E, 0x06, 0x06, 0x06, 0x06, 
    0x03, 0x03, 0x0F, 0x1F, 0x1F, 0x0E, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 
    0x06, 0x06, 0x1E, 0x1E, 0x1E, 0x1C, 0x00, 0x00 
    };
    
    lcdCommand(0x40);
    
    for(unsigned char i=0; i<48; i++)
        lcdData(logo[i]);
    
    lcdPosition(2, 6);
    lcdData(0);
    lcdData(1);
    lcdData(2);
    lcdPosition(3, 6);
    lcdData(3);
    lcdData(4);
    lcdData(5);
}

void discoLogo_1(void){
    lcdCommand(0x40);
    
    char logo[48] = {
    0x00, 0x00, 0x01, 0x02, 0x04, 0x09, 0x0A, 0x0A, 
    0x00, 0x1F, 0x00, 0x00, 0x1F, 0x00, 0x0E, 0x11, 
    0x00, 0x00, 0x10, 0x08, 0x04, 0x02, 0x02, 0x02, 
    0x08, 0x08, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00, 
    0x11, 0x0E, 0x00, 0x1F, 0x00, 0x00, 0x1F, 0x00, 
    0x0A, 0x0A, 0x12, 0x04, 0x08, 0x10, 0x00, 0x00 
    };
    
    lcdCommand(0x40);
    
    for(unsigned char i=0; i<48; i++)
        lcdData(logo[i]);
    
    lcdPosition(2, 1);
    lcdData(0);
    lcdData(1);
    lcdData(2);
    lcdPosition(3, 1);
    lcdData(3);
    lcdData(4);
    lcdData(5);
}

void discoLogo_2(void){
    lcdCommand(0x40);
    
    char logo[48] = {
    0x00, 0x00, 0x01, 0x02, 0x04, 0x08, 0x08, 0x08, 
    0x00, 0x1F, 0x00, 0x00, 0x1F, 0x00, 0x0E, 0x11, 
    0x00, 0x00, 0x10, 0x08, 0x04, 0x12, 0x0A, 0x0A, 
    0x0A, 0x0A, 0x09, 0x04, 0x02, 0x01, 0x00, 0x00, 
    0x11, 0x0E, 0x00, 0x1F, 0x00, 0x00, 0x1F, 0x00, 
    0x02, 0x02, 0x02, 0x04, 0x08, 0x10, 0x00, 0x00 
    };
    
    lcdCommand(0x40);
    
    for(unsigned char i=0; i<48; i++)
        lcdData(logo[i]);
    
    lcdPosition(2, 1);
    lcdData(0);
    lcdData(1);
    lcdData(2);
    lcdPosition(3, 1);
    lcdData(3);
    lcdData(4);
    lcdData(5);
}

void discoLogo_3(void){
    lcdCommand(0x40);
    
    char logo[48] = {
    0x00, 0x00, 0x01, 0x02, 0x04, 0x09, 0x0A, 0x0A, 
    0x00, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x11, 
    0x00, 0x00, 0x10, 0x08, 0x04, 0x12, 0x0A, 0x0A, 
    0x0A, 0x0A, 0x09, 0x04, 0x02, 0x01, 0x00, 0x00, 
    0x11, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x00,
    0x0A, 0x0A, 0x12, 0x04, 0x08, 0x10, 0x00, 0x00  
    };
    
    lcdCommand(0x40);
    
    for(unsigned char i=0; i<48; i++)
        lcdData(logo[i]);
    
    lcdPosition(2, 1);
    lcdData(0);
    lcdData(1);
    lcdData(2);
    lcdPosition(3, 1);
    lcdData(3);
    lcdData(4);
    lcdData(5);
}

void apresentaMenu(int infoSom){
    tempo(50);
    lcdCommand(CLR);
    tempo(50);
    lcdCommand(L1);
    lcdString("(1):Lenta");
    tempo(50);
    lcdCommand(L2);                
    lcdString("(2):Media");
    tempo(50);
    lcdCommand(L3);
    lcdString("(3):Rapida");
    tempo(50);
    lcdCommand(L4);
    if(infoSom == 1111) lcdString("(#):Mutar som");  
    else lcdString("(#):Ativar som");
}

void musicaLenta(void)
{
    for(int i=0; i<4; i++){
        pwmSet2(50);
        tempo(500);      
        pwmSet2(0);
        tempo(1000);      
    }
}

void musicaMedia(void)
{
    for(int i=0; i<6; i++){
        pwmSet2(50);
        tempo(200);      
        pwmSet2(0);
        tempo(500);          
    }
}

void musicaRapida(void)
{
    for(int i=0; i<15; i++){
        pwmSet2(50);
        tempo(50);      
        pwmSet2(0);
        tempo(100);      
    }
}