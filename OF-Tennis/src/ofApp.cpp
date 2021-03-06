#include "ofApp.h"
#include "ofxUI.h"
#include "CSV\ofCSVReader.h"
#include "CSV\ofDataProcessing.h"
#include "Model\ofMatch.h"
#include <string>
#include <iostream>
#include <stdlib.h> 


void ofApp::setup()
{
	x = 200; y = 150; p = 25;

	ofCSVReader csvData("atp2016.csv", ',');
	processedData = new ofDataProcessing(csvData.getData());
	names = processedData->getTournamentsNames();
	

	left = new ofImage();
	left->load("images/players/empty.png");
	left->resize(212, 148);
	left->draw(188, 202);

	right = new ofImage();
	right->load("images/players/empty.png");
	right->resize(212, 148);

	win = new ofImage();
	win->load("images/players/empty.png");
	win->resize(1, 1);
	
	

	image_header = new ofImage();
	image_header->load("images/Header.png");
	image_footer = new ofImage();
	image_footer->load("images/footers.png");

	header();
	choiceOfPlayers();
}

void ofApp::update()
{
	for (int i = 0; i < components.size(); i++) components[i]->draw();
	view->draw();
	img->draw(475, 125);
	left->draw(188, 202);
	right->draw(616, 202);
}

void ofApp::draw()
{
	for (int i = 0; i < components.size(); i++) components[i]->draw();
	view->draw();
	img->draw(475, 115);
	left->draw(188, 202);
	right->draw(616, 202);
	win->draw(360, 202);
	image_header->draw(0, 10);
	image_footer->draw(0, 615);
}


void ofApp::header()
{
	view = new ofxUISuperCanvas("");
	view->addSpacer();
	view_list = view->addDropDownList("Tournament", *names);
	view_list->setAutoClose(true);
	view_list->setAllowMultiple(false);
	view_list->setShowCurrentSelected(true);
	view->setHeight(48);
	view->setPosition(188, 60);
	view->setColorBack(ofxUIColor::darkOliveGreen);
	view->draw();
	ofAddListener(view->newGUIEvent, this, &ofApp::headerEvent);

	vector<string> rds = { " "," " };
	round_sc = new ofxUISuperCanvas("");
	round_sc->addSpacer();
	round_sc_list = round_sc->addDropDownList("Round", rds);
	round_sc_list->setAutoClose(true);
	round_sc_list->setAllowMultiple(false);
	round_sc_list->setShowCurrentSelected(true);
	round_sc_list->setColorFill(ofxUIColor::black);
	round_sc->setHeight(48);
	round_sc->setPosition(616, 60);
	round_sc->setColorBack(ofxUIColor::darkOliveGreen);
	round_sc->draw();
	ofAddListener(round_sc->newGUIEvent, this, &ofApp::roundEvent);


}



void ofApp::headerEvent(ofxUIEventArgs & e)
{
	string name = e.getName();
	if (name.compare("Tournament") == 0) {
		playersInfosHide();
		Players_left->setPosition(1000, 1000);
		Players_right->setPosition(1000, 1000);
		win->resize(1, 1);
	}
	else {
		round_sc_list->clearToggles();
		tr = processedData->getTournament(name);
		rounds = tr->getRounds();
		round_sc = new ofxUISuperCanvas("");
		round_sc->addSpacer();
		round_sc_list = round_sc->addDropDownList("Round", *rounds);
		round_sc_list->setAutoClose(true);
		round_sc_list->setAllowMultiple(false);
		round_sc_list->setShowCurrentSelected(true);
		round_sc_list->setColorFill(ofxUIColor::black);
		round_sc->setHeight(48);
		round_sc->setPosition(616, 60);
		round_sc->setColorBack(ofxUIColor::darkOliveGreen);
		round_sc->draw();
		ofAddListener(round_sc->newGUIEvent, this, &ofApp::roundEvent);

		left->draw(1000, 202);
		right->draw(1000, 202);

	}
}

void ofApp::roundEvent(ofxUIEventArgs & e) {
	string name = e.getName();
	if (name.compare("Round") == 0) {
		playersInfosHide();
		Players_left->setPosition(1000, 1000);
		Players_right->setPosition(1000, 1000);
		win->resize(1, 1);
	}
	else {
		tr->setRound(name);
		delete Players_left;
		Players_left = new ofxUISuperCanvas("");
		Players_left->addSpacer();
		player_left_list = Players_left->addDropDownList("Player 1", *tr->getPlayersNamesByRound());
		player_left_list->setAutoClose(true);
		player_left_list->setAllowMultiple(false);
		player_left_list->setShowCurrentSelected(true);
		player_left_list->setColorFill(ofxUIColor::black);
		Players_left->setHeight(48);
		Players_left->setPosition(188, 115);
		Players_left->setColorBack(ofxUIColor::darkOliveGreen);
		Players_left->draw();

		ofAddListener(Players_left->newGUIEvent, this, &ofApp::player_left_Event);
	}
}

void ofApp::choiceOfPlayers()
{
	Players_left = new ofxUISuperCanvas("");
	Players_left->addSpacer();
	vector<string> vec = { " "," " };
	player_left_list = Players_left->addDropDownList("Player 1", vec);
	player_left_list->setAutoClose(true);
	player_left_list->setAllowMultiple(false);
	player_left_list->setShowCurrentSelected(true);
	player_left_list->setColorFill(ofxUIColor::black);
	Players_left->setHeight(48);
	Players_left->setPosition(188, 115);
	Players_left->setColorBack(ofxUIColor::darkOliveGreen);
	Players_left->draw();

	img = new ofImage();
	img->load("ball_ag.jpg");
	img->resize(50, 50);

	Players_right = new ofxUISuperCanvas("");
	Players_right->addSpacer();
	vector<string> vector = { " "," " };
	player_right_list = Players_right->addDropDownList("Player 2 ", vector);
	player_right_list->setAutoClose(true);
	player_right_list->setAllowMultiple(false);
	player_right_list->setShowCurrentSelected(true);
	player_right_list->setColorFill(ofxUIColor::black);
	Players_right->setPosition(616, 115);
	Players_right->setHeight(48);
	Players_right->setColorBack(ofxUIColor::darkOliveGreen);
	Players_right->draw();

	ofAddListener(Players_left->newGUIEvent, this, &ofApp::player_left_Event);
	ofAddListener(Players_right->newGUIEvent, this, &ofApp::player_right_Event);
}

void ofApp::player_left_Event(ofxUIEventArgs & e)
{
	string name = e.getName();
	if (name.compare("Player 1") == 0) {
		playersInfosHide();
		win->resize(1, 1);
	}
	else {
		name_left = name;
		player_right_list->clearToggles();
		nameopp = tr->getOpponents(name);
		delete Players_right;
		Players_right = new ofxUISuperCanvas("");
		Players_right->addSpacer();
		player_right_list = Players_right->addDropDownList("Player 2 ", *nameopp);
		player_right_list->setAutoClose(true);
		player_right_list->setAllowMultiple(false);
		player_right_list->setShowCurrentSelected(true);
		player_right_list->setColorFill(ofxUIColor::black);
		Players_right->setPosition(616, 115);
		Players_right->setHeight(48);
		Players_right->setColorBack(ofxUIColor::darkOliveGreen);
		Players_right->draw();
		ofAddListener(Players_right->newGUIEvent, this, &ofApp::player_right_Event);
	}
}

void ofApp::player_right_Event(ofxUIEventArgs & e)
{
	string name = e.getName();
	//if (!(name.compare(" "))) {

	if (!(std::find(nameopp->begin(), nameopp->end(), name) == nameopp->end()))
	{
		std::cout << name << std::endl;
		match = tr->getMatch(name_left, name);
		playersInfos();
		matchsInfos();
		left->draw(188, 202);
		right->draw(616, 202);
	}
	//}
}

void ofApp::playersInfos()
{
	string rank_cw = "Rank : " + match->getWinner()->getRank();
	string rank_cl = "Rank : " + match->getLoser()->getRank();
	int time_i = std::stoi(match->getMinutes());
	int  hours, minutes;
	hours = time_i / 60;
	minutes = time_i % 60;
	std::ostringstream time;
	time << hours << ":" << minutes<< "";

	std::string score = match->getScore();
	std::string delimiter = " ";
	istringstream iss(score);
	vector<string> tokens;
	copy(istream_iterator<string>(iss),
		istream_iterator<string>(),
		back_inserter(tokens));

	string out = "Score :  " + tokens[0] + " | " + tokens[1];
	if (tokens.size() > 2)  out += " | " + tokens[2];

	components.push_back(getNewComponent(match->getWinner()->getName(), 186, 175, ofColor::sandyBrown, ofColor::black));
	components.push_back(getNewComponent(rank_cw, 186, 351, ofColor::sandyBrown, ofColor::black));
	components.push_back(getNewComponent(out, 400, 250, ofColor::sandyBrown, ofColor::black));
	
	//components.push_back(getNewComponent(" Winner ", 400, 225, ofColor::greenYellow, ofColor::black));
	string round = match->getRound();
	std::cout << round << std::endl;
	if (round.compare("F") == 0) round = "Final";
	if (round.compare("SF") == 0) round = "Semi-Final";
	if (round.compare("QF") == 0) round = "Quarter-Final";

	components.push_back(getNewComponent("Round : " + round, 400, 275, ofColor::sandyBrown, ofColor::black));
	components.push_back(getNewComponent("Match Time : " + time.str(), 400, 300, ofColor::sandyBrown, ofColor::black));
	components.push_back(getNewComponent(match->getLoser()->getName(), 614, 175, ofColor::sandyBrown, ofColor::black));
	components.push_back(getNewComponent(rank_cl, 614, 351, ofColor::sandyBrown, ofColor::black));

	left = addNewImage(match->getWinner()->getName());
	right = addNewImage(match->getLoser()->getName());
	left->draw(188, 202);
	right->draw(616, 202);

	win->load("images/win.png");
	win->resize(40, 40);
}


void ofApp::playersInfosHide()
{
	for (int i = 0; i < components.size(); i++) components[i]->setPosition(1002, 800);
	right->load("images/players/empty.png");
	right->resize(1, 1);
	left->load("images/players/empty.png");
	left->resize(1, 1);
}

void ofApp::matchsInfos()
{
	vector<string> stats_winner = getInfoVector(match->getWinner());
	vector<string> stats_loser = getInfoVector(match->getLoser());
	vector<string> stats_names = { "Aces", "Double Faults", "1st Service", "1st Service Won",
									"2nd Service Won", "Service Games Played", "Break Points Saved",
									"Break Points Faced", "Total Service Points" };
	for (size_t i = 0; i < 9; i++)
	{
		components.push_back(getNewComponent(stats_winner[i], 186, 380 + (i * p), ofColor::sandyBrown, ofColor::black));
		components.push_back(getNewComponent(stats_names[i], 400, 380 + (i * p), ofColor::sandyBrown, ofColor::black));
		components.push_back(getNewComponent(stats_loser[i], 614, 380 + (i * p), ofColor::sandyBrown, ofColor::black));

	}
}


vector<string> ofApp::getInfoVector(ofPlayer * player)
{
	vector<string> data = vector<string>();
	data.push_back(player->getAce());
	data.push_back(player->getDoubleFaults());
	data.push_back(player->getFstIn());
	data.push_back(player->getFstWon());
	data.push_back(player->getSndWon());
	data.push_back(player->getSvGms());
	data.push_back(player->getBpSaved());
	data.push_back(player->getBpFaced());
	data.push_back(player->getSvpt());
	return data;
}

ofxDatGuiComponent * ofApp::getNewComponent(string label, int x, int y, ofColor colorBack, ofColor colorLabel)
{
	ofxDatGuiComponent * component = new ofxDatGuiLabel(label);
	component->setLabelAlignment(ofxDatGuiAlignment::CENTER);
	component->setPosition(x, y);
	component->setBackgroundColor(colorBack);
	component->setLabelColor(colorLabel);
	component->setWidth(214, 0);
	component->setLabelUpperCase(false);
	return component;
}

ofImage * ofApp::addNewImage(string name)
{
	ofImage * image_tmp = new ofImage();
	string image_name_right = "images/players/";
	image_name_right += name;
	image_name_right += ".png";
	if (!(image_tmp->load(image_name_right))) {
		image_tmp->load("images/players/no-image.png");
	}
	image_tmp->resize(212, 148);
	return image_tmp;
}


ofApp::~ofApp() {
	if (view != NULL) delete view;
	if (round_sc != NULL)delete round_sc;
	if (Players_left != NULL)delete Players_left;
	if (image_vs != NULL)delete image_vs;
	if (Players_right != NULL)delete Players_right;
	if (left != NULL)delete left;
	if (right != NULL)delete right;
	if (component != NULL)delete component;
	if (font != NULL)delete font;
	if (img != NULL)delete img;
	if (image_footer != NULL)delete image_footer;
	if (image_header != NULL)delete image_header;
	if (plotter != NULL)delete plotter;
	if (names != NULL)delete names;
	if (rounds != NULL)delete rounds;
	if (nameopp != NULL)delete nameopp;
	if (processedData != NULL)delete processedData;
	//std::exit(0);
}


