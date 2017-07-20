#include "ofApp.h"
#include "ofxUI.h"
#include "CSV\ofCSVReader.h"
#include "CSV\ofDataProcessing.h"


void ofApp::setup()
{
	font = new ofTrueTypeFont();
	font->load("ofxbraitsch/fonts/Verdana.ttf",9);
	x = 200;
	y = 150;
	p = 25;


	/*component = new ofxDatGuiLabel("Tournament");
	component->setLabelAlignment(ofxDatGuiAlignment::CENTER);
	component->setPosition(350, 10);
	component->setWidth(300, 0);
	components.push_back(component);*/


	ofCSVReader csvData("atp2016.csv", ',');
	vector<vector<string>> * data = csvData.getData();
	ofDataProcessing processedData(data);
	names = processedData.getTournamentsNames();

	header();
	choiceOfPlayers();
	playersInfos();
	matchsInfos();


}

void ofApp::update()
{

	for (int i = 0; i < components.size(); i++) components[i]->update();
	view->draw();
	left->draw(202, 202);
	img->draw(475, 125);
	right->draw(602, 202);
}

void ofApp::draw()
{
	for (int i = 0; i<components.size(); i++) components[i]->draw();
	view->draw();
	left->draw(188, 202);
	img->draw(475, 125);
	right->draw(616, 202);
}

/*
event listeners
*/

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e)
{
	cout << "onButtonEvent: " << e.target->getLabel() << endl;
}

void ofApp::onToggleEvent(ofxDatGuiToggleEvent e)
{
	cout << "onToggleEvent: " << e.target->getLabel() << "::" << e.target->getChecked() << endl;
}

void ofApp::onSliderEvent(ofxDatGuiSliderEvent e)
{
	cout << "onSliderEvent: " << e.value << "::" << e.scale << endl;
}

void ofApp::onDropdownEvent(ofxDatGuiDropdownEvent e)
{
	cout << "onDropdownEvent: " << e.child << endl;
}

void ofApp::onMatrixEvent(ofxDatGuiMatrixEvent e)
{
	cout << "onMatrixEvent: " << e.child << "::" << e.enabled << endl;
}

void ofApp::onColorPickerEvent(ofxDatGuiColorPickerEvent e)
{
	cout << "onColorPickerEvent: " << e.color << endl;
}

void ofApp::on2dPadEvent(ofxDatGui2dPadEvent e)
{
	cout << "on2dPadEvent: " << e.x << "::" << e.y << endl;
}

void ofApp::onTextInputEvent(ofxDatGuiTextInputEvent e)
{
	cout << "onButtonEvent: " << e.text << endl;
}



void ofApp::onScrollViewEvent(ofxDatGuiScrollViewEvent e)
{
	cout << e.target->getLabel() << " [index " << e.index << "] selected in [" << e.parent->getName() << "]" << endl;
}

void ofApp::header()
{
	/*view = new ofxDatGuiScrollView("Tounament", 3);
	view->setWidth(300);
	view->setPosition(350, 37);
	view->onScrollViewEvent(this, &ofApp::onScrollViewEvent);
	for (int i = 0; i<names.size(); i++) view->add(ofToString(names[i]));*/

	view = new ofxUISuperCanvas("");
	view->addSpacer();
	view_list = view->addDropDownList("Tournament", *names);
	view_list->setAutoClose(true);
	view_list->setAllowMultiple(false);
	view_list->setShowCurrentSelected(true);
	view->setHeight(48);
	view->setPosition(400, 10);
	view->setColorBack(ofxUIColor::darkOliveGreen);
	view->draw();
	ofAddListener(view->newGUIEvent, this, &ofApp::headerEvent);
}

void ofApp::headerEvent(ofxUIEventArgs & e)
{
	string name = e.getName();
	std::cout << name << std::endl;
	if (name.compare("Doha") == 0) {
		playersInfosHide();
	} else {
		playersInfos();
		matchsInfos();
	}
}

void ofApp::choiceOfPlayers()
{
	Players_left = new ofxUISuperCanvas("");
	Players_left->addSpacer();
	player_left_list = Players_left->addDropDownList("Player 1", *names);
	player_left_list->setAutoClose(true);
	player_left_list->setAllowMultiple(false);
	Players_left->setHeight(48);
	Players_left->setPosition(188, 125);
	Players_left->setColorBack(ofxUIColor::darkOliveGreen);
	Players_left->draw();

	img = new ofImage();
	img->load("D:/Ecole/ISIB/Master/1MA/1st Semester/Second session/Analysis & Data Visualization/Projet - Aout/OF-Tennis/OF-Tennis/bin/data/ball_ag.jpg");
	img->resize(50, 50);

	Players_right = new ofxUISuperCanvas("");
	Players_right->addSpacer();
	player_right_list = Players_right->addDropDownList("Player 2 ", *names);
	player_right_list->setAutoClose(true);
	player_right_list->setAllowMultiple(false);
	player_right_list->setShowCurrentSelected(true);
	//player_right_list->setColorBack(ofxUIColor::black);
	player_right_list->setColorFill(ofxUIColor::black);
	Players_right->setPosition(616, 125);
	Players_right->setHeight(48);
	Players_right->setColorBack(ofxUIColor::darkOliveGreen);
	Players_right->draw();

	ofAddListener(Players_left->newGUIEvent, this, &ofApp::choiceOfPlayersEvent);
	ofAddListener(Players_right->newGUIEvent, this, &ofApp::choiceOfPlayersEvent);
}

void ofApp::choiceOfPlayersEvent(ofxUIEventArgs & e)
{
}

void ofApp::playersInfos()
{

	// left  image
	component = new ofxDatGuiLabel("Andy Murray");
	component->setLabelAlignment(ofxDatGuiAlignment::CENTER);
	component->setPosition(186, 175);
	component->setWidth(214, 0);
	components.push_back(component);

	left = new ofImage();
	left->load("D:/Ecole/ISIB/Master/1MA/1st Semester/Second session/Analysis & Data Visualization/Projet - Aout/DatGuiEx/DatGuiEx/bin/data/images/Andy Murray.png");
	left->resize(212, 148);


	component = new ofxDatGuiLabel("Rank : 5 ");
	component->setLabelAlignment(ofxDatGuiAlignment::CENTER);
	component->setPosition(186, 351);
	component->setWidth(214, 0);
	components.push_back(component);

	// 
	component = new ofxDatGuiLabel("2-6 7-6(4) 6-4");
	component->setLabelAlignment(ofxDatGuiAlignment::CENTER);
	component->setPosition(400, 225);
	component->setWidth(214, 0);
	components.push_back(component);

	component = new ofxDatGuiLabel("R16");
	component->setLabelAlignment(ofxDatGuiAlignment::CENTER);
	component->setPosition(400, 250);
	component->setWidth(214, 0);
	components.push_back(component);
	component = new ofxDatGuiLabel("3");
	component->setLabelAlignment(ofxDatGuiAlignment::CENTER);
	component->setPosition(400, 275);
	component->setWidth(214, 0);
	components.push_back(component);

	component = new ofxDatGuiLabel("1h 35min");
	component->setLabelAlignment(ofxDatGuiAlignment::CENTER);
	component->setPosition(400, 300);
	component->setWidth(214, 0);
	components.push_back(component);


	// right  image
	component = new ofxDatGuiLabel("Roger Federer");
	component->setLabelAlignment(ofxDatGuiAlignment::CENTER);
	component->setPosition(614, 175);
	component->setWidth(214, 0);
	components.push_back(component);

	right = new ofImage();
	right->load("D:/Ecole/ISIB/Master/1MA/1st Semester/Second session/Analysis & Data Visualization/Projet - Aout/DatGuiEx/DatGuiEx/bin/data/images/Roger Federer.png");
	right->resize(212, 148);

	component = new ofxDatGuiLabel("Rank : 2");
	component->setLabelAlignment(ofxDatGuiAlignment::CENTER);
	component->setPosition(614, 351);
	component->setWidth(214, 0);
	components.push_back(component);
}

void ofApp::playersInfosHide()
{
	for (int i = 0; i < components.size(); i++) components[i]->setPosition(1002, 800);

}

void ofApp::matchsInfos()
{

	std::vector<string> stats = { "11", "8", "60%", "71%","56%", "14", "50%","50%", "49%" };
	std::vector<string> stats_names = { "Aces", "Double Faults", "1st Service", "1st Service Won",
		"2nd Service Won", "Service Games Played", "Break Points Saved",
		"Break Points Faced", "Total Service Points" };
	// gauche 
	for (size_t i = 0; i < 9; i++)
	{
		component = new ofxDatGuiLabel(stats[i]);
		component->setLabelAlignment(ofxDatGuiAlignment::CENTER);
		component->setPosition(186, 385 + (i * p));
		component->setWidth(214, 0);
		component->onButtonEvent(this, &ofApp::onButtonEvent);
		components.push_back(component);

	}
	// milieu

	for (size_t i = 0; i < 9; i++)
	{
		component = new ofxDatGuiLabel(stats_names[i]);
		component->setLabelAlignment(ofxDatGuiAlignment::CENTER);
		component->setPosition(400, 385 + (i * p));
		component->setWidth(214, 0);
		component->onButtonEvent(this, &ofApp::onButtonEvent);
		components.push_back(component);

	}
	// droite

	for (size_t i = 0; i < 9; i++)
	{
		component = new ofxDatGuiLabel(stats[i]);
		component->setLabelAlignment(ofxDatGuiAlignment::CENTER);
		component->setPosition(614, 385 + (i * p));
		component->setWidth(214, 0);
		component->onButtonEvent(this, &ofApp::onButtonEvent);
		components.push_back(component);

	}
}

void ofApp::matchsInfosHide()
{
}


