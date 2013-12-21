#pragma systemfile
//list of commands
void dynamicDelay();
void countdown(int timeToWait);
//Constants for Screen coordinates
const int LEFT_X = 3;
const int RIGHT_X = 85;
const int BOTTOM_Y = 14;
const int TOP_Y = 60;

//Constants for button definitions
const int NO_BUTTON = -1;
const int RIGHT_BUTTON = 1;
const int LEFT_BUTTON = 2;
const int ORANGE_BUTTON = 3;
const int DARK_BUTTON = 0;

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

		if(nNxtButtonPressed == RIGHT_BUTTON){
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
		if(nNxtButtonPressed == LEFT_BUTTON){
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
		if(leftArrowDisplay == false){
			nxtDisplayClearTextLine(6);
			nxtDisplayClearTextLine(7);
			nxtDisplayBigStringAt(RIGHT_X, BOTTOM_Y, ">");
		}
		if(rightArrowDisplay == false){
			nxtDisplayClearTextLine(6);
			nxtDisplayClearTextLine(7);
			nxtDisplayBigStringAt(LEFT_X, BOTTOM_Y, "<");
		}
		wait1Msec(15);
		if(nNxtButtonPressed == ORANGE_BUTTON) break;
	}
	return timeToWait;
}

void countdown(int timeToWait){
	for(int i = 0; i < timeToWait; i++){
		PlaySound(soundBeepBeep);
		wait1Msec(1000);
	}
}
