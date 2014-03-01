#pragma systemfile

void IRScoreBackward(){
	clearEncoders();
	wait1Msec(50);
	const int totalTics = 7600;//total tics from before IR to end-- DONT CHANGE!

	while(HTIRS2readACDir(IR) > 6){ //finds the beacon
		nxtDisplayCenteredTextLine(1,"Direction: %d", HTIRS2readACDir(IR));

		nxtDisplayCenteredTextLine(6,"%d",nMotorEncoder[leftDrive]);
		//if(abs(nMotorEncoder[leftDrive]) >= totalTics-500) break;
		startBackward(35);
	}
	stopDrive();
	wait1Msec(300);
	while(HTIRS2readACDir (IR)!= 5){
		startBackward(15);
	}
	moveBackwardInchesNoReset(30, 8.75);//reverse back a small amount to correct for IR inaccuracy

	stopDrive();//stops robot
	servo[dumper] = 30;//dumps the block
	motor[lift]= 50;//starts the lift up
	wait1Msec(700);
	motor[lift]= 0;//stops lift
	servo[dumper] = servoRestPosition;//resets servo
}
