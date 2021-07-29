#include "config.h"
#include "delay.h"

void tempo(unsigned int num_ms)
{
    volatile unsigned int j, k, i;
    
    for(i=0; i<num_ms; i++){
        for(j = 0; j < 41; j++){
            for(k = 0; k < 3; k++);  
        }  
    }
}
