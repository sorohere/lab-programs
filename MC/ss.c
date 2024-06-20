#include <stdio.h>																											 
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Seven_Segment.h"
#include "DrvGPIO.h"
#include "DrvSYS.h"
#include "NUC1xx-LB_002\LCD_Driver.h"

void seg_display(int16_t value){
  int8_t digit;
	digit = value / 1000;
	close_seven_segment();
	show_seven_segment(3,digit);
	DrvSYS_Delay(5000);
			
	value = value - digit * 1000;
	digit = value / 100;
	close_seven_segment();
	show_seven_segment(2,digit);
	DrvSYS_Delay(5000);

	value = value - digit * 100;
	digit = value / 10;
	close_seven_segment();
	show_seven_segment(1,digit);
	DrvSYS_Delay(5000);

	value = value - digit * 10;
	digit = value;
	close_seven_segment();
	show_seven_segment(0,digit);
	DrvSYS_Delay(5000);
}

int main(void)
{
	int value = 1111 ;
	char text[16] = "value :       ";
	
	UNLOCKREG();
	DrvSYS_Open(48000000);
	LOCKREG();
	
	
	Initial_panel();
	clr_all_panel();
	
	OpenKeyPad();
	
	
	
	while(1)
	{
		seg_display(value);
		sprintf(text+8, "%d", value);
		print_lcd(0, text);
		DrvSYS_Delay(10000);
		value--;
	}
}
