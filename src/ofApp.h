#pragma once

#include "ofMain.h"
#include "ofEvents.h"


class ofApp : public ofBaseApp {

public:

	void setup();
	void update();
	void draw();

	void keyPressed(int key);

	ofSoundPlayer backgroundMusic;
	ofSoundPlayer Drum1;
	ofSoundPlayer Drum2;
	ofSoundPlayer Drum3;
	ofSoundPlayer Drum4;
	ofSoundPlayer Drum5;
	ofSoundPlayer Hangdrum1;
	ofSoundPlayer Hangdrum2;
	ofSoundPlayer Hangdrum3;
	ofSoundPlayer Hangdrum4;
	ofSoundPlayer Hangdrum5;
	ofSoundPlayer Marimba1;
	ofSoundPlayer Marimba2;
	ofSoundPlayer Marimba3;
	ofSoundPlayer Marimba4;
	ofSoundPlayer Marimba5;
	ofSoundPlayer Woodblock1;
	ofSoundPlayer Woodblock2;
	ofSoundPlayer Woodblock3;
	ofSoundPlayer Woodblock4;
	ofSoundPlayer Woodblock5;

	ofImage DrumImage;
	ofImage HangdrumImage;
	ofImage MarimbaImage;
	ofImage WoodblockImage;

	ofTrueTypeFont	font;
	ofSerial      mySerial;

	int Counter1;
	int Counter2;


};