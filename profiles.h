#pragma systemfile
#include "display.h"
#include "joystickdriver.c";
//list of commands
int requestPrimaryProfile();
int requestSecondaryProfile();
void getPrimaryDriverName();
void getSecondaryDriverName();
void loadPreferences();
//Profile name variables
int primaryProfile = 0;
string primaryProfileString = "";
int secondaryProfile = 0;
string secondaryProfileString = "";
bool rightArrowDisplay = true;
bool leftArrowDisplay = false;
//Variables for drive control
//
//
//
//
//
//
int requestPrimaryProfile(){
	disableDiagnosticsDisplay();
	eraseDisplay();
	getPrimaryDriverName();
	nxtDisplayCenteredBigTextLine(4,primaryProfileString);
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
			getPrimaryDriverName();
			nxtDisplayCenteredBigTextLine(4,primaryProfileString);
			wait1Msec(500);
		}

		if(nNxtButtonPressed == LEFT_BUTTON){//decrease primary profile number and update display
			primaryProfile --;
			leftArrowDisplay = true;
			rightArrowDisplay = true;
			if(primaryProfile <= 0){
				primaryProfile = 0;
				leftArrowDisplay = false;
			}
			getPrimaryDriverName();
			nxtDisplayCenteredBigTextLine(4,primaryProfileString);
			wait1Msec(500);
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
		if(nNxtButtonPressed == ORANGE_BUTTON){
			while(nNxtButtonPressed == ORANGE_BUTTON){}//waits for orange button press and release
			break; //ends selection, goes to secondary driver select
		}
	}
	eraseDisplay();
	return primaryProfile;
}
int requestSecondaryProfile(){
	disableDiagnosticsDisplay();
	eraseDisplay();
	getSecondaryDriverName();
	nxtDisplayCenteredBigTextLine(4,secondaryProfileString);
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
			getSecondaryDriverName();
			nxtDisplayCenteredBigTextLine(4,secondaryProfileString);
			wait1Msec(500);
		}

		if(nNxtButtonPressed == LEFT_BUTTON){//decrease primary profile number and update display
			secondaryProfile --;
			leftArrowDisplay = true;
			rightArrowDisplay = true;
			if(secondaryProfile <= 0){
				secondaryProfile = 0;
				leftArrowDisplay = false;
			}
			getSecondaryDriverName();
			nxtDisplayCenteredBigTextLine(4,secondaryProfileString);
			wait1Msec(500);
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
		if(nNxtButtonPressed == ORANGE_BUTTON){
			while(nNxtButtonPressed == ORANGE_BUTTON){}//waits for orange button press and release
			break; //ends selection, goes to delay select
		}
	}
	eraseDisplay();
	return secondaryProfile;
}


void getPrimaryDriverName(){
	if(primaryProfile == 0) primaryProfileString = "Emma";
	else if (primaryProfile == 1) primaryProfileString = "Kyle";
	else if (primaryProfile == 2) primaryProfileString = "Matt";
	else if (primaryProfile == 3) primaryProfileString = "Sam";
}

void getSecondaryDriverName(){
	if(secondaryProfile == 0) secondaryProfileString = "Arnav";
	else if (secondaryProfile == 1) secondaryProfileString = "Jack";
	else if (secondaryProfile == 2) secondaryProfileString = "Josh";
	else if (secondaryProfile == 3) secondaryProfileString = "Noah";
}
void loadPreferences(){
	nxtDisplayCenteredBigTextLine(1,primaryProfileString);
	nxtDisplayCenteredBigTextLine(5,secondaryProfileString);
	wait1Msec(3000);
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
