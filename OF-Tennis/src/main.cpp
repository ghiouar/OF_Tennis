#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main() {
	ofSetupOpenGL(1024, 655, OF_WINDOW);			
	ofBackground(255);
	ofSetWindowTitle("Men's Professional Tennis | ATP World Tour");
	ofRunApp(new ofApp());
}
