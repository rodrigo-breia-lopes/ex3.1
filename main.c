#include <msp430.h>
#include "fsm.h"
#include "light.h"

void PORT1_ISR_HOOK(void);

void main(int argc, char *argv[])
{


    //Config do WDT
    WDTCTL = WDTTMSEL + WDTIS0 +  WDTPW + WDTHOLD;              //0000 1001 -> SMCLK SOURCE + INTERVAL TIMER MODE + DIV8192
    IE1   |= WDTIE;                                             //xxx0 xxx1 -> WDT Interrupt Enable

    //IFG1 = xxx0 xxx0 (default porque não é um registo de configuração)
	//WDTCTL =  WDTPW | WDTHOLD;		        // stop watchdog timer

	// DCOconfig  DCOx=2, MODx=0, and RSELx=11 bits= 4 MHz
	//Verificar osciloscopio digital (dco=5?)

	//Config dos CLKs
	BCSCTL1 = RSEL0 + RSEL1 + RSEL3;         //0x0B = 0000 1011
	DCOCTL  = DCO2 + MOD0;                   //0010 0000
	BCSCTL2 = SELM_0 + DIVM_0 + DIVS_0;
	BCSCTL3 = LFXT1S_2;                     //0000 0101 -> XCAP_1 = 1 (DEFAULT)

	//Config Timer0_A2
	TACTL   = TASSEL1 + MC_1 + TAIE;           //xxxx xx10 0001 X010
	TACCTL0 = CCIE;                            //0000 0000 0001 0000 (interrupção ocorre a cada 418 ciclos de CLK)
	TACCR0  = 418;                             //compare value

	//Config GPIO
	P1DIR = 0xF7;
	P1IE  = BIT3;
	P1REN = BIT3;




	// ACLK output @ port 1 pin 0
    //P1DIR |= 0x00;
	//P1SEL |= 0x00;
    __enable_interrupt();           // Set global interrupt enable //ERRO AQUI (INTERRUPÇÃO ESPONTÂNEA IFG P1.3)
	while(1);
}

#pragma vector=PORT1_VECTOR
__interrupt void PORT1_ISR_HOOK(void)
{
    int i = 1;
    i +=1 ;
    while(1);

    /* Port 1 Interrupt Handler */
   // Switch_Handler();

    /* No change in operating mode on exit */
}

//void PORT1_ISR_HOOK(void);

