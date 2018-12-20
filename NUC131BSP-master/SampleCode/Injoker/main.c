/******************************************************************************
 * @file     main.c
 * @version  V1.00
 * $Revision: 3 $
 * $Date: 14/06/30 4:51p $
 * @brief    Software Development Template.
 * @note
 * Copyright (C) 2014 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include <stdio.h>
#include "NUC131.h"


void SYS_Init(void)
{
    /* Enable IP clock */
    CLK->APBCLK = CLK_APBCLK_UART0_EN_Msk;

    /* Update System Core Clock */
    /* User can use SystemCoreClockUpdate() to calculate SystemCoreClock and cyclesPerUs automatically. */
    SystemCoreClockUpdate();

    /* Set GPB multi-function pins for UART0 RXD and TXD */
    SYS->GPB_MFP &= ~(SYS_GPB_MFP_PB0_Msk | SYS_GPB_MFP_PB1_Msk);
    SYS->GPB_MFP |= (SYS_GPB_MFP_PB0_UART0_RXD | SYS_GPB_MFP_PB1_UART0_TXD);
}


int ScanKey(){
	//Colum 1	
	if (PB11==0){
			 PA10=1;
				if (PB11==1) {
						CLK_SysTickDelay(2000000);
						return 1;
				} else{
							PA11=1;
							if (PB11==1) {
									CLK_SysTickDelay(2000000);
									return 4;
						} else {
								PA15=1;
								if (PB11==1) {
										CLK_SysTickDelay(2000000);
										return 7;
								}	else {
									PE5=1;
									if (PB11==1) {
										CLK_SysTickDelay(2000000);
										return 10;}
								}
						}
				}
		};
		//Colum 2
		if (PA14==0){
			 PA10=1;
				if (PA14==1) {
						CLK_SysTickDelay(2000000);
						return 2;
				} else{
							PA11=1;
							if (PA14==1) {
									CLK_SysTickDelay(2000000);
									return 5;
						} else {
								PA15=1;
								if (PA14==1) {
										CLK_SysTickDelay(2000000);
										return 8;
								}	else {
									PE5=1;
									if (PB11==1) {
										CLK_SysTickDelay(2000000);
										return 11;}
						}
				}
		}};
		
		//Colum 3
		if (PA13==0){
			 PA10=1;
				if (PA13==1) {
						CLK_SysTickDelay(2000000);
						return 3;
				} else{
							PA11=1;
							if (PA13==1) {
									CLK_SysTickDelay(2000000);
									return 6;
						} else {
								PA15=1;
								if (PA13==1) {
										CLK_SysTickDelay(2000000);
										return 9;
								}	else {
									PE5=1;
									if (PB11==1) {
										CLK_SysTickDelay(2000000);
										return 12;}
						}
				}
		}};
		
		//Colum 4
		if (PA12==0){
			 PA10=1;
				if (PA12==1) {
						CLK_SysTickDelay(2000000);
						return 4;
				} else{
							PA11=1;
							if (PA12==1) {
									CLK_SysTickDelay(2000000);
									return 8;
						} else {
								PA15=1;
								if (PA12==1) {
										CLK_SysTickDelay(2000000);
										return 12;
								}	else {
									PE5=1;
									if (PA11==1) {
										CLK_SysTickDelay(2000000);
										return 16;}
						}
				}
		}
		};
		
		return 99;
}
void keypad(){
			//rows
		PA10=0;
		PA11=0;
		PA15=0;
		PE5=0;
		
		//cols
		PB11=1;
		PA14=1;
		PA13=1;
}

void configWifi(){
    printf("AT\r\n");
		CLK_SysTickDelay(2000000);
		printf("AT+CWMODE=1\r\n");
		CLK_SysTickDelay(2000000);
		
		printf("AT+CIPMUX=0\r\n");
		CLK_SysTickDelay(2000000);
		
		printf("AT+CWJAP=\"UIT Public\",\"\"\r\n");
		CLK_SysTickDelay(90000000);
		
		printf("AT+CIPSTART=\"TCP\",\"68.183.233.38\",8000\r\n");
		CLK_SysTickDelay(5000000);

};

int main()
{
    int8_t button;

    /* Unlock protected registers */
    SYS_UnlockReg();

    SYS_Init();

    /* Lock protected registers */
    SYS_LockReg();

    /* Init UART0 to 115200-8n1 for print message */
    UART_Open(UART0, 115200);
		
		configWifi();
		keypad();
    while(1){
			button=ScanKey();
			CLK_SysTickDelay(300000);
			if (button !=99) {
				printf("%d",button);
				keypad();
			};
		};
}

/*** (C) COPYRIGHT 2014 Nuvoton Technology Corp. ***/

