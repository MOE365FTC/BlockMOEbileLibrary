#pragma systemfile
#include "display.h"
//list of commands
void dynamicDelay();
void countdown(int timeToWait);


int requestTimeToWait(){
//Variables for program
int timeToWait = 0;
bool rightArrowDisplay = true;
bool leftArrowDisplay = false;

	disableDiagnosticsDisplay();
	eraseDisplay();
	nxtDisplayCenteredBigTextLine(4,"Delay:%d", timeToWait);
	while(true)
	{
		if(timeToWait != 0) nxtDisplayBigStringAt(LEFT_X, BOTTOM_Y, "<");
		if(timeToWait != 20) nxtDisplayBigStringAt(RIGHT_X, BOTTOM_Y, ">");
		nxtDisplayCenteredTextLine(0, "ProgramName");

		nxtDisplayCenteredTextLine(2, "NXT Batt:%4.1f V", nAvgBatteryLevel / (float) 1000);   // Display NXT Battery Voltage

		 if ( externalBatteryAvg < 0)
        nxtDisplayCenteredTextLine(3, "Ext Batt: OFF");       //External battery is off or not connected
      else
        nxtDisplayCenteredTextLine(3, "Ext Batt:%4.1f V", externalBatteryAvg / (float) 1000);

		if(nNxtButtonPressed == RIGHT_BUTTON){//increase time to wait and display
			timeToWait ++;
			leftArrowDisplay = true;
			rightArrowDisplay = true;
			if(timeToWait >= 20){
				timeToWait = 20;
				rightArrowDisplay = false;
			}
			nxtDisplayCenteredBigTextLine(4,"Delay:%d", timeToWait);
			wait1Msec(250);
		}
		if(nNxtButtonPressed == LEFT_BUTTON){//decrease time to wait and display
			timeToWait --;
			leftArrowDisplay = true;
			rightArrowDisplay = true;
			if(timeToWait <= 0){
				timeToWait = 0;
				leftArrowDisplay = false;
			}
			nxtDisplayCenteredBigTextLine(4,"Delay:%d", timeToWait);
			wait1Msec(250);
		}
		if(leftArrowDisplay == false){//turns off left arrow when time = 0
			nxtDisplayClearTextLine(6);
			nxtDisplayClearTextLine(7);
			nxtDisplayBigStringAt(RIGHT_X, BOTTOM_Y, ">");
		}
		if(rightArrowDisplay == false){//turns off right arrow when time = 20
			nxtDisplayClearTextLine(6);
			nxtDisplayClearTextLine(7);
			nxtDisplayBigStringAt(LEFT_X, BOTTOM_Y, "<");
		}
		wait1Msec(15);//refreshing screen
		if(nNxtButtonPressed == ORANGE_BUTTON) break;//ends selection, goes to waitforstart
	}
	eraseDisplay();
	return timeToWait;
}

void countdown(int timeToWait){
	for(int i = 0; i < timeToWait; i++){
		PlaySound(soundBeepBeep);
		wait1Msec(1000);
	}
}
