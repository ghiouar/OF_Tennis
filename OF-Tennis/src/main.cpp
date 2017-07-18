#include "ofMain.h"
#include "ofApp.h"

/* Test class */
#include <conio.h>

//========================================================================
int main( ){
	ofSetupOpenGL(1000, 700, OF_WINDOW);			// <-------- setup the GL context
	ofBackground(255);
	//ofSetColor(0);
	//
	
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofApp * app = new ofApp(); 
	app->sizeWindow(750);
	ofRunApp(app);

	
}
