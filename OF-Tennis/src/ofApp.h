#pragma once

#include "ofMain.h"
#include "ofxGui/src/ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofTrueTypeFont font;
		ofxPanel infocsv;
		ofxLabel champ1;
		ofxLabel champ2;
		ofxLabel champ3;
		ofxLabel champ4;
		ofxLabel champ5;
		ofxLabel champ6;
		ofxLabel champ7;
		
};
