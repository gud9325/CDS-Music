#include "ofApp.h"

std::string str; 
std::vector<int> a2dA0, a2dA1, a2dA2, a2dA3, a2dA4; 
 
void serial2int(int byteRead) { 
     int myByte = byteRead;      
	 if (myByte == OF_SERIAL_NO_DATA) {     
		 cout << "no data was read" << endl;    
	 }    
	 else if (myByte == OF_SERIAL_ERROR) {     
		 cout << "en error occurred" << endl;    
	 } 
	 if (myByte >= '0' && myByte <= '9') {
		 str.push_back((char)myByte);
	 }
	 else if (myByte == 10 && !str.empty()) {
		 int num = std::stoi(str);
		 str.clear();
		 if (num < 1024)
			 a2dA0.push_back(num);
		 else if (num < 2048)
			 a2dA1.push_back(num - 1024);
		 else if (num < 3072)
			 a2dA2.push_back(num - 2048);
		 else if (num < 4096)
			 a2dA3.push_back(num - 3072);
		 else // num < 5120
			 a2dA4.push_back(num - 4096);
	 }
	 else {    
	 } 
}
//--------------------------------------------------------------
void ofApp::setup() {
	mySerial.listDevices(); 
	vector <ofSerialDeviceInfo> deviceList = mySerial.getDeviceList();      
	mySerial.setup("COM4", 57600);

	if (mySerial.isInitialized() == true) { 
		cout << "serial Initialized" << endl;     
		mySerial.flush(); 
	}
	else { 
		cout << "serial not Initialized" << endl;     return; 
	}
	//potValue = "analog pin:";

	//setup textfont
	font.load("Sudbury_Basin_3D.ttf", 20);

	//setup BGM
	backgroundMusic.load("BGM.wav");
	backgroundMusic.setVolume(0.5f);
	backgroundMusic.setLoop(true);

	//setup instruments
	Drum1.load("Drum1.wav");
	Drum1.setPan(-0.8f);
	Drum2.load("Drum2.wav");
	Drum2.setPan(-0.4f);
	Drum3.load("Drum3.wav");
	Drum3.setPan(0.0f);
	Drum4.load("Drum4.wav");
	Drum4.setPan(0.4f);
	Drum5.load("Drum5.wav");
	Drum5.setPan(0.8f);
	Hangdrum1.load("Hangdrum1.wav");
	Hangdrum1.setPan(-0.8f);
	Hangdrum2.load("Hangdrum2.wav");
	Hangdrum2.setPan(-0.4f);
	Hangdrum3.load("Hangdrum3.wav");
	Hangdrum3.setPan(0.0f);
	Hangdrum4.load("Hangdrum4.wav");
	Hangdrum4.setPan(0.4f);
	Hangdrum5.load("Hangdrum5.wav");
	Hangdrum5.setPan(0.8f);
	Marimba1.load("Marimba1.wav");
	Marimba1.setPan(-0.8f);
	Marimba2.load("Marimba2.wav");
	Marimba2.setPan(-0.4f);
	Marimba3.load("Marimba3.wav");
	Marimba3.setPan(0.0f);
	Marimba4.load("Marimba4.wav");
	Marimba4.setPan(0.4f);
	Marimba5.load("Marimba5.wav");
	Marimba5.setPan(0.8f);
	Woodblock1.load("Woodblock1.wav");
	Woodblock1.setPan(-0.8f);
	Woodblock2.load("Woodblock2.wav");
	Woodblock2.setPan(-0.4f);
	Woodblock3.load("Woodblock3.wav");
	Woodblock3.setPan(0.0f);
	Woodblock4.load("Woodblock4.wav");
	Woodblock4.setPan(0.4f);
	Woodblock5.load("Woodblock5.wav");
	Woodblock5.setPan(0.8f);

	//setup Images
	DrumImage.load("Drum.png");
	HangdrumImage.load("Hangdrum.png");
	MarimbaImage.load("Marimba.png");
	WoodblockImage.load("Woodblock.png");

	// replace the string below with the serial port for your Arduino board
	// you can get this from the Arduino application or via command line
	// for OSX, in your terminal type "ls /dev/tty.*" to get a list of serial devices
	//ard.connect("COM4", 57600);

	// listen for EInitialized notification. this indicates that
	// the arduino is ready to receive commands and it is safe to
	// call setupArduino()
	//ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
	//bSetupArduino = false;	// flag so we setup arduino when its ready, you don't need to touch this :)
}

//--------------------------------------------------------------
void ofApp::update() {

	//updateArduino();
	if (mySerial.available() > 0) { 
		const int bufSize = 1024;     
		unsigned char buf[bufSize]; 
		int bufReq = mySerial.available() > bufSize ? bufSize : mySerial.available();         
		mySerial.readBytes(buf, bufReq);        
		
		for (int i = 0; i < bufReq; i++) { 
			serial2int(buf[i]); 
		} 
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
/*
	if (a2dA0.empty() && a2dA1.empty() && a2dA2.empty() && a2dA3.empty() && a2dA4.empty()) {
		printf("a2d empty\n");     
		return; 
*/
	int valA0 = a2dA0.back();
	int valA1 = a2dA1.back();
	int valA2 = a2dA2.back();
	int valA3 = a2dA3.back();
	int valA4 = a2dA4.back();

	//printf("%d	%d	%d	%d	%d\n", valA0, valA1, valA2, valA3, valA4);

	float widthDiv = ofGetWidth() / 5.0f;

	if (Drum1.isPlaying() && Drum1.getPosition() < 0.02 ||
		Hangdrum1.isPlaying() && Hangdrum1.getPosition() < 0.02 ||
		Marimba1.isPlaying() && Marimba1.getPosition() < 0.02 ||
		Woodblock1.isPlaying() && Woodblock1.getPosition() < 0.02)
		ofSetColor(255, 255, 255);
	else
		ofSetColor(90, 0, 0);
	ofDrawRectangle(0, 0, widthDiv, ofGetHeight());

	if (Drum2.isPlaying() && Drum2.getPosition() < 0.02 ||
		Hangdrum2.isPlaying() && Hangdrum2.getPosition() < 0.02 ||
		Marimba2.isPlaying() && Marimba2.getPosition() < 0.02 ||
		Woodblock2.isPlaying() && Woodblock2.getPosition() < 0.02)
		ofSetColor(255, 255, 255);
	else
		ofSetColor(60, 30, 0);
	ofDrawRectangle(widthDiv, 0, widthDiv * 2, ofGetHeight());

	if (Drum3.isPlaying() && Drum3.getPosition() < 0.02 ||
		Hangdrum3.isPlaying() && Hangdrum3.getPosition() < 0.02 ||
		Marimba3.isPlaying() && Marimba3.getPosition() < 0.02 ||
		Woodblock3.isPlaying() && Woodblock3.getPosition() < 0.02)
		ofSetColor(255, 255, 255);
	else
		ofSetColor(30, 60, 30);
	ofDrawRectangle(widthDiv * 2, 0, widthDiv * 3, ofGetHeight());

	if (Drum4.isPlaying() && Drum4.getPosition() < 0.02 ||
		Hangdrum4.isPlaying() && Hangdrum4.getPosition() < 0.02 ||
		Marimba4.isPlaying() && Marimba4.getPosition() < 0.02 ||
		Woodblock4.isPlaying() && Woodblock4.getPosition() < 0.02)
		ofSetColor(255, 255, 255);
	else
		ofSetColor(0, 90, 60);
	ofDrawRectangle(widthDiv * 3, 0, widthDiv * 4, ofGetHeight());

	if (Drum5.isPlaying() && Drum5.getPosition() < 0.02 ||
		Hangdrum5.isPlaying() && Hangdrum5.getPosition() < 0.02 ||
		Marimba5.isPlaying() && Marimba5.getPosition() < 0.02 ||
		Woodblock5.isPlaying() && Woodblock5.getPosition() < 0.02)
		ofSetColor(255, 255, 255);
	else
		ofSetColor(0, 0, 90);
	ofDrawRectangle(widthDiv * 4, 0, ofGetWidth(), ofGetHeight());

	string str1 = "Press [Enter(return)] to turn On/Off Background Music";
	string str2 = "Press [Space Bar] to change instrumnet";

	ofSetColor(255, 255, 255);
	font.drawString(str1, 0, 100);

	if (backgroundMusic.isPlaying()) {
		ofSetColor(255, 255, 255);
		font.drawString("BGM is ON", 0, 150);
	}
	else {
		ofSetColor(255, 255, 255);
		font.drawString("BGM is OFF", 0, 150);
	}

	font.drawString(str2, 0, 300);
	font.drawString("Instrument : ", 0, 350);

	switch (Counter1 % 4) /* instrumentNum */ {
	case 0:
		DrumImage.draw(400, 300, 300, 300);
		font.drawString("Drum", 250, 350);
		break;
	case 1:
		HangdrumImage.draw(400, 300, 300, 300);
		font.drawString("Hangdrum", 250, 350);
		break;
	case 2:
		MarimbaImage.draw(400, 300, 300, 300);
		font.drawString("Marimba", 250, 350);
		break;
	case 3:
		WoodblockImage.draw(400, 300, 300, 300);
		font.drawString("Woodblock", 250, 350);
		break;
	}
	
	if (valA0 > 900) {
		switch (Counter1 % 4) {
			case 0:
				if(!Drum1.isPlaying() || Drum1.getPosition() > 0.04)
					Drum1.play();
				break;
			case 1:
				if (!Hangdrum1.isPlaying() || Hangdrum1.getPosition() > 0.04)
					Hangdrum1.play();
				break;
			case 2:
				if (!Marimba1.isPlaying() || Marimba1.getPosition() > 0.04)
					Marimba1.play();
					break;
			case 3:
				if(!Woodblock1.isPlaying() || Woodblock1.getPosition() > 0.04)
					Woodblock1.play();
				break;
		}
	}
	if (valA1 > 900) {
		switch (Counter1 % 4) {
		case 0:
			if (!Drum2.isPlaying() || Drum2.getPosition() > 0.04)
				Drum2.play();
			break;
		case 1:
			if (!Hangdrum2.isPlaying() || Hangdrum2.getPosition() > 0.04)
				Hangdrum2.play();
			break;
		case 2:
			if (!Marimba2.isPlaying() || Marimba2.getPosition() > 0.04)
				Marimba2.play();
			break;
		case 3:
			if (!Woodblock2.isPlaying() || Woodblock2.getPosition() > 0.04)
				Woodblock2.play();
			break;
		}
	}
	if (valA2 > 800) {
		switch (Counter1 % 4) {
		case 0:
			if (!Drum3.isPlaying() || Drum3.getPosition() > 0.04)
				Drum3.play();
			break;
		case 1:
			if (!Hangdrum3.isPlaying() || Hangdrum3.getPosition() > 0.04)
				Hangdrum3.play();
			break;
		case 2:
			if (!Marimba3.isPlaying() || Marimba3.getPosition() > 0.04)
				Marimba3.play();
			break;
		case 3:
			if (!Woodblock3.isPlaying() || Woodblock3.getPosition() > 0.04)
				Woodblock3.play();
			break;
		}
	}
	if (valA3 > 850) {
		switch (Counter1 % 4) {
		case 0:
			if (!Drum4.isPlaying() || Drum4.getPosition() > 0.04)
				Drum4.play();
			break;
		case 1:
			if (!Hangdrum4.isPlaying() || Hangdrum4.getPosition() > 0.04)
				Hangdrum4.play();
			break;
		case 2:
			if (!Marimba4.isPlaying() || Marimba4.getPosition() > 0.04)
				Marimba4.play();
			break;
		case 3:
			if (!Woodblock4.isPlaying() || Woodblock4.getPosition() > 0.04)
				Woodblock4.play();
			break;
		}
	}
	if (valA4 > 800) {
		switch (Counter1 % 4) {
		case 0:
			if (!Drum5.isPlaying() || Drum5.getPosition() > 0.04)
				Drum5.play();
			break;
		case 1:
			if (!Hangdrum5.isPlaying() || Hangdrum5.getPosition() > 0.04)
				Hangdrum5.play();
			break;
		case 2:
			if (!Marimba5.isPlaying() || Marimba5.getPosition() > 0.04)
				Marimba5.play();
			break;
		case 3:
			if (!Woodblock5.isPlaying() || Woodblock5.getPosition() > 0.04)
				Woodblock5.play();
			break;
		}
	}

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	int instrumentNum = Counter1 % 4;
	int onoff = Counter2 % 2 + 1;


	if (key == 13) {
		Counter2++;
		if (onoff == 1) {
			//printf("BGM is on\n");
			backgroundMusic.play();
		}
		else /* (onoff == 0) */ {
			//printf("BGM is off\n");
			backgroundMusic.stop();
		}
	}

	if (key == 32) {
		Counter1++;
		// printf("instrumentNum = %d\n", instrumentNum);
	}
	if (instrumentNum == 0) {
		switch (key) {
		case 'a':
			Drum1.play();
			break;
		case 's':
			Drum2.play();
			break;
		case 'd':
			Drum3.play();
			break;
		case 'f':
			Drum4.play();
			break;
		case 'g':
			Drum5.play();
			break;
		}
	}
	else if (instrumentNum == 1) {
		switch (key) {
		case 'a':
			Hangdrum1.play();
			break;
		case 's':
			Hangdrum2.play();
			break;
		case 'd':
			Hangdrum3.play();
			break;
		case 'f':
			Hangdrum4.play();
			break;
		case 'g':
			Hangdrum5.play();
			break;
		}
	}
	else if (instrumentNum == 2) {
		switch (key) {
		case 'a':
			Marimba1.play();
			break;
		case 's':
			Marimba2.play();
			break;
		case 'd':
			Marimba3.play();
			break;
		case 'f':
			Marimba4.play();
			break;
		case 'g':
			Marimba5.play();
			break;
		}
	}
	else {
		switch (key) {
		case 'a':
			Woodblock1.play();
			break;
		case 's':
			Woodblock2.play();
			break;
		case 'd':
			Woodblock3.play();
			break;
		case 'f':
			Woodblock4.play();
			break;
		case 'g':
			Woodblock5.play();
			break;
		}
	}

}
//--------------------------------------------------------------

