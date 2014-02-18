#pragma systemFile

#define LEFTENCODER false
#define RIGHTENCODER true

//conversion of encoder tics to inches
//111 motor tics = 1 inch  WITH PID TURNED ON!!
//114.6 motor tics = 1 inch with PID turned OFF.

const float encoderTicsPerInch = 111;

//list of prototypes
void clearEncoders();
void startForward(int speed);
void startBackward(int speed);
void stopDrive();
void moveForwardInches(int speed, int inches);
void moveBackwardInches(int speed, int inches);


void clearEncoders(){
	nMotorEncoder[rightDrive] = 0;
	nMotorEncoder[leftDrive] = 0;
}

void startForward(int speed){
	motor[rightDrive] = speed;
	motor[leftDrive] = speed;
}

void startBackward(int speed){
	motor[rightDrive] = -speed;
	motor[leftDrive] = -speed;
}

void stopDrive(){
	motor[rightDrive] = 0;
	motor[leftDrive] = 0;
}

// Turning code located in pidturn.h

void moveForwardInches(int speed, int inches, bool isReversed = false, bool encoder = RIGHTENCODER){
	nMotorPIDSpeedCtrl[leftDrive] = mtrSpeedReg;
	nMotorPIDSpeedCtrl[rightDrive] = mtrSpeedReg;
	clearEncoders();
	int ticsToMove = encoderTicsPerInch * inches;
	int encoderPosition = 0;
	wait1Msec(50);

	if(encoder == RIGHTENCODER) while(encoderPosition<= ticsToMove){
		encoderPosition = nMotorEncoder[rightDrive];
		if(isReversed) encoderPosition = -encoderPosition;
		startForward(speed);
	}
	else while(encoderPosition<= ticsToMove){
		encoderPosition = nMotorEncoder[leftDrive];
		if(isReversed) encoderPosition = -encoderPosition;
		startForward(speed);
	}
	stopDrive();
}


void moveForwardInchesNoReset(int speed, int inches, bool isReversed = false, bool encoder = RIGHTENCODER){
	nMotorPIDSpeedCtrl[leftDrive] = mtrSpeedReg;
	nMotorPIDSpeedCtrl[rightDrive] = mtrSpeedReg;

	int initialPosition = 0;
	if(encoder == RIGHTENCODER) initialPosition = nMotorEncoder[rightDrive];
	else if(encoder == LEFTENCODER) initialPosition = nMotorEncoder[leftDrive];

	int ticsToMove = encoderTicsPerInch * inches;
	int encoderPosition = 0;

	if(encoder == RIGHTENCODER) while(encoderPosition<= ticsToMove){
		encoderPosition = nMotorEncoder[rightDrive] - initialPosition;
		if(isReversed) encoderPosition = -encoderPosition;
		startForward(speed);
	}
	else while(encoderPosition<= ticsToMove){
		encoderPosition = nMotorEncoder[leftDrive] - initialPosition;
		if(isReversed) encoderPosition = -encoderPosition;
		startForward(speed);
	}
	stopDrive();
}

void moveBackwardInches(int speed, int inches, bool isReversed = false, bool encoder = RIGHTENCODER){
	nMotorPIDSpeedCtrl[leftDrive] = mtrSpeedReg;
	nMotorPIDSpeedCtrl[rightDrive] = mtrSpeedReg;
	clearEncoders();
	wait1Msec(50);
	int ticsToMove = encoderTicsPerInch * inches;
	int encoderPosition = 0;

	if(encoder == RIGHTENCODER) while(encoderPosition >= -ticsToMove){

		encoderPosition = nMotorEncoder[rightDrive];
		if(isReversed) encoderPosition = -encoderPosition;
		startBackward(speed);
	}
	else while(encoderPosition >= -ticsToMove){
		encoderPosition = nMotorEncoder[leftDrive];
		if(isReversed) encoderPosition = -encoderPosition;
		startBackward(speed);
	}
	stopDrive();
}


void moveBackwardInchesNoReset(int speed, int inches, bool isReversed = false, bool encoder = RIGHTENCODER){
	nMotorPIDSpeedCtrl[leftDrive] = mtrSpeedReg;
	nMotorPIDSpeedCtrl[rightDrive] = mtrSpeedReg;

	int initialPosition = 0;
	if(encoder == RIGHTENCODER) initialPosition = nMotorEncoder[rightDrive];
	else if(encoder == LEFTENCODER) initialPosition = nMotorEncoder[leftDrive];

	int ticsToMove = encoderTicsPerInch * inches;
	int encoderPosition = 0;

	if(encoder == RIGHTENCODER) while(encoderPosition >= -ticsToMove){
		encoderPosition = nMotorEncoder[rightDrive] - initialPosition;
		if(isReversed) encoderPosition = -encoderPosition;
		startBackward(speed);
	}
	else while(encoderPosition >= -ticsToMove){
		encoderPosition = nMotorEncoder[leftDrive] - initialPosition;
		if(isReversed) encoderPosition = -encoderPosition;
		startBackward(speed);
	}
	stopDrive();
}

void moveForwardTics(int speed, int ticsToMove, bool isReversed = false, bool encoder = RIGHTENCODER){
	nMotorPIDSpeedCtrl[leftDrive] = mtrSpeedReg;
	nMotorPIDSpeedCtrl[leftDrive] = mtrSpeedReg;
	clearEncoders();
	wait1Msec(50);
	int encoderPosition = 0;

	if(encoder == RIGHTENCODER) while(encoderPosition<= ticsToMove){
		encoderPosition = nMotorEncoder[rightDrive];
		if(isReversed) encoderPosition = -encoderPosition;
		startForward(speed);
	}
	else while(encoderPosition<= ticsToMove){
		encoderPosition = nMotorEncoder[leftDrive];
		if(isReversed) encoderPosition = -encoderPosition;
		startForward(speed);
	}
	stopDrive();
}

void moveBackwardTics(int speed, int ticsToMove, bool isReversed = false, bool encoder = RIGHTENCODER){
	nMotorPIDSpeedCtrl[leftDrive] = mtrSpeedReg;
	nMotorPIDSpeedCtrl[rightDrive] = mtrSpeedReg;
	clearEncoders();
	wait1Msec(50);
	encoder = RIGHTENCODER;
	int encoderPosition = 0;

	if(encoder == RIGHTENCODER) while(encoderPosition >= -ticsToMove){

		encoderPosition = nMotorEncoder[rightDrive];
		if(isReversed) encoderPosition = -encoderPosition;
		startBackward(speed);
	}
	else while(encoderPosition >= -ticsToMove){
		encoderPosition = nMotorEncoder[leftDrive];
		//if(isReversed) encoderPosition = -encoderPosition;
		startBackward(speed);
	}
	stopDrive();
}





//a const that motor tics times the number of inches

//114.6 motor tics = 1 inch
