// TI example code

#include <msp430g2553.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  ADC10CTL0 = ADC10SHT_3 + ADC10ON + ADC10IE; // ADC10ON, interrupt enabled
  P1DIR |= 0x01;
  P1DIR |= BIT6;
  ADC10CTL1 |= ADC10SSEL1|ADC10SSEL0;                // Select SMCLK

  ADC10CTL1 = INCH_4;
  ADC10AE0 |= BIT4;




  for (;;)
  {
	  //ADC10CTL1 = INCH_5;                       // input A4
	  //ADC10AE0 |= BIT5;                         // PA.1 ADC option select
	  ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
    __bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
    if (ADC10MEM < 0x1FF) {
      P1OUT &= ~0x01;                       // Clear P1.0 LED off
    } else {
      P1OUT |= 0x01;                        // Set P1.0 LED on
    }


	  //ADC10CTL1 = INCH_5;                       // input A4
	  //ADC10AE0 |= BIT5;                         // PA.1 ADC option select
	  //ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start
  //__bis_SR_register(CPUOFF + GIE);        // LPM0, ADC10_ISR will force exit
  //if (ADC10MEM < 0x1FF) {
    //P1OUT &= ~BIT6;                       // Clear P1.0 LED off
  //} else {
    //P1OUT |= BIT6;                        // Set P1.0 LED on
  //}

  }

    return 0;
}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}
