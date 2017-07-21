#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"
#include "ofxUI.h"
#include "CSV\ofDataProcessing.h"
#include "Model\ofMatch.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	// Header
	ofxUISuperCanvas * view;
	ofxUIDropDownList * view_list;
	void header();
	void headerEvent(ofxUIEventArgs &e);

	// choice Of Players
	ofxUISuperCanvas * Players_left;
	ofxUIDropDownList * player_left_list;
	ofxUICanvas * image_vs;
	ofxUISuperCanvas * Players_right;
	ofxUIDropDownList * player_right_list;
	void choiceOfPlayers();
	void player_left_Event(ofxUIEventArgs &e);
	void player_right_Event(ofxUIEventArgs &e);

	// Players Infos
	ofImage * left;
	ofImage * right;
	void playersInfos();
	void playersInfosHide();

	// Matchs Infos
	vector<ofxDatGuiComponent*> components;
	ofxDatGuiComponent* component;
	void matchsInfos();
	vector<string> getInfoVector(ofPlayer * player);
	ofxDatGuiComponent* getNewComponent(string label, int x, int y, ofColor colorBack, ofColor colorLabel);
	ofImage *  addNewImage(string name);

	// Other
	ofTrueTypeFont * font;
	ofImage * img;
	ofImage * image_footer;
	ofImage * image_header;
	ofxDatGuiValuePlotter* plotter;
	std::vector<std::string> * names;
	int x, y, p;
	vector<string> * nameopp;

	// CSV data 
	ofDataProcessing * processedData;
	ofTournament * tr;
	string name_left;
	ofMatch * match;
	
};
