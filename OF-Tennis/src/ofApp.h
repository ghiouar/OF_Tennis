#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"
#include "ofxUI.h"

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
	void choiceOfPlayersEvent(ofxUIEventArgs &e);

	// Players Infos
	ofImage * left;
	ofImage * right;
	void playersInfos();
	void playersInfosHide();

	// Matchs Infos
	vector<ofxDatGuiComponent*> components;
	ofxDatGuiComponent* component;
	void matchsInfos();
	void matchsInfosHide();


	// Other
	ofTrueTypeFont * font;
	ofImage * img;
	ofxDatGuiValuePlotter* plotter;
	std::vector<std::string> * names;
	int x, y, p;

	


	void onButtonEvent(ofxDatGuiButtonEvent e);
	void onToggleEvent(ofxDatGuiToggleEvent e);
	void onSliderEvent(ofxDatGuiSliderEvent e);
	void onDropdownEvent(ofxDatGuiDropdownEvent e);
	void onMatrixEvent(ofxDatGuiMatrixEvent e);
	void onColorPickerEvent(ofxDatGuiColorPickerEvent e);
	void on2dPadEvent(ofxDatGui2dPadEvent e);
	void onTextInputEvent(ofxDatGuiTextInputEvent e);
	void onScrollViewEvent(ofxDatGuiScrollViewEvent e);


	

};
