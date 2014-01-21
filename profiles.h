#pragma systemfile
#include "joystickdriver.c"
//list of commands
int requestPrimaryProfile();
int requestSecondaryProfile();
void loadPreferences();
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

int primaryProfile = 0;
string primaryProfileString = "";
int secondaryProfile = 0;
string secondaryProfileString = "";
bool rightArrowDisplay = true;
bool leftArrowDisplay = false;

int requestPrimaryProfile(){
	if(primaryProfile == 0) primaryProfileString = "Matt";
	else if (primaryProfile == 1) primaryProfileString = "Emma";
	else if (primaryProfile == 2) primaryProfileString = "Sam";
	else if (secondaryProfile == 3) primaryProfileString = "Kyle";

	disableDiagnosticsDisplay();
	eraseDisplay();
	nxtDisplayCenteredBigTextLine(4,"Delay:%d", primaryProfileString);
	while(true){
		if(primaryProfile != 0) nxtDisplayBigStringAt(LEFT_X, BOTTOM_Y, "<");
		if(primaryProfile != 3) nxtDisplayBigStringAt(RIGHT_X, BOTTOM_Y, ">");

		if(nNxtButtonPressed == RIGHT_BUTTON){//increase primary profile number and update display
			primaryProfile ++;
			leftArrowDisplay = true;
			rightArrowDisplay = true;
			if(primaryProfile >= 3){
				primaryProfile = 3;
				rightArrowDisplay = false;
			}
			nxtDisplayCenteredBigTextLine(4,"Delay:%d", primaryProfileString);
			wait1Msec(250);
		}

		if(nNxtButtonPressed == LEFT_BUTTON){//decrease primary profile number and update display
			primaryProfile --;
			leftArrowDisplay = true;
			rightArrowDisplay = true;
			if(primaryProfile <= 0){
				primaryProfile = 0;
				leftArrowDisplay = false;
			}
			nxtDisplayCenteredBigTextLine(4,"Delay:%d", primaryProfileString);
			wait1Msec(250);
		}
		if(leftArrowDisplay == false){//turns off left arrow when time = 0
			nxtDisplayClearTextLine(6);
			nxtDisplayClearTextLine(7);
			nxtDisplayBigStringAt(RIGHT_X, BOTTOM_Y, ">");
		}
		if(rightArrowDisplay == false){//turns off right arrow when time = 2
			nxtDisplayClearTextLine(6);
			nxtDisplayClearTextLine(7);
			nxtDisplayBigStringAt(LEFT_X, BOTTOM_Y, "<");
		}
		wait1Msec(15);//refreshing screen
		if(nNxtButtonPressed == ORANGE_BUTTON) break;//ends selection, goes to delay select
	}
	eraseDisplay();
	return primaryProfile;
}
int requestSecondaryProfile(){
	if(secondaryProfile == 0) secondaryProfileString = "Arnav";
	else if (secondaryProfile == 1) secondaryProfileString = "Josh";
	else if (secondaryProfile == 2) secondaryProfileString = "Noah";
	else if (secondaryProfile == 3) secondaryProfileString = "Jack";

	disableDiagnosticsDisplay();
	eraseDisplay();
	nxtDisplayCenteredBigTextLine(4,"Delay:%d", secondaryProfileString);
	while(true){
		if(secondaryProfile != 0) nxtDisplayBigStringAt(LEFT_X, BOTTOM_Y, "<");
		if(secondaryProfile != 3) nxtDisplayBigStringAt(RIGHT_X, BOTTOM_Y, ">");

		if(nNxtButtonPressed == RIGHT_BUTTON){//increase primary profile number and update display
			secondaryProfile ++;
			leftArrowDisplay = true;
			rightArrowDisplay = true;
			if(secondaryProfile >= 3){
				secondaryProfile = 3;
				rightArrowDisplay = false;
			}
			nxtDisplayCenteredBigTextLine(4,"Delay:%d", secondaryProfileString);
			wait1Msec(250);
		}

		if(nNxtButtonPressed == LEFT_BUTTON){//decrease primary profile number and update display
			secondaryProfile --;
			leftArrowDisplay = true;
			rightArrowDisplay = true;
			if(secondaryProfile <= 0){
				secondaryProfile = 0;
				leftArrowDisplay = false;
			}
			nxtDisplayCenteredBigTextLine(4,"Delay:%d", secondaryProfileString);
			wait1Msec(250);
		}
		if(leftArrowDisplay == false){//turns off left arrow when time = 0
			nxtDisplayClearTextLine(6);
			nxtDisplayClearTextLine(7);
			nxtDisplayBigStringAt(RIGHT_X, BOTTOM_Y, ">");
		}
		if(rightArrowDisplay == false){//turns off right arrow when time = 2
			nxtDisplayClearTextLine(6);
			nxtDisplayClearTextLine(7);
			nxtDisplayBigStringAt(LEFT_X, BOTTOM_Y, "<");
		}
		wait1Msec(15);//refreshing screen
		if(nNxtButtonPressed == ORANGE_BUTTON) break;//ends selection, goes to delay select
	}
	eraseDisplay();
	return secondaryProfile;
}

void loadPreferences(){
	if (primaryProfile == 0)//Matt's preferences
	{
		//variables here
	}
	else if (primaryProfile == 1)//Emma's preferences
	{
		//variables here
	}
	else if (primaryProfile == 2)//Sam's preferences
	{
		//variables here
	}
	else if (primaryProfile == 3)//Kyle's preferences
	{
		//variables here
	}
	if (secondaryProfile == 0)//Arnav's preferences
	{
		//variables here
	}
	else if (secondaryProfile == 1)//Josh's preferences
	{
		//variables here
	}
	else if (secondaryProfile == 2)//Noah's preferences
	{
		//variables here
	}
	else if (secondaryProfile == 3)//Jack's preferences
	{
		//variables here
	}
}
