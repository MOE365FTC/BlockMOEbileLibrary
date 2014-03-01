#pragma systemfile

void scoreIRForward(){
	moveForwardInches(50, 1); //away from wall
	turn(g_PidTurn, 45); //turn to parallel with buckets
	clearEncoders(); //clears encoder for the next step

	const int totalTics = 7300; //6840 total tics from before IR to end-- DONT CHANGE!
	int ticsToIR;
	while(HTIRS2readACDir(IR) != 4){ //finds the beacon
		nxtDisplayCenteredTextLine(5,"Direction:%d",HTIRS2readACDir(IR));
		if(nMotorEncoder[leftDrive] >= totalTics-2000) break;
		startForward(27);
		ticsToIR = nMotorEncoder[leftDrive];
		nxtDisplayCenteredTextLine(6,"%d",ticsToIR);
	}
	//stopDrive();
	//PlaySound(soundBeepBeep);
	stopDrive();
	wait1Msec(300);
	while(HTIRS2readACDir (IR) != 5){ //slow down to look for basket
		startForward(15);
	}
	//while(true){}
	stopDrive();//stops robot

	//if(ticsToIR <= 3700){
	moveForwardInchesNoReset(30,5);
	//}

	servo[dumper] = 30;//dumps the block
	motor[lift]= 50;//starts the lift up
	wait1Msec(700);
	motor[lift]= 0;//stops lift
	servo[dumper] = servoRestPosition;//resets servo
}
