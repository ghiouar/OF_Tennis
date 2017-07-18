#include "ofApp.h"
#include "CSV/ofCSVReader.h"
#include "CSV/ofDataProcessing.h"


//--------------------------------------------------------------
void ofApp::setup(){
	//this->sizeWindow(200);
	img = new ofImage();
	img->load("D:/Ecole/ISIB/Master/1MA/1st Semester/Second session/Analysis & Data Visualization/Projet - Aout/OF-Tennis/OF-Tennis/bin/data/ball_ag.jpg");
	img->resize(50, 50);
	
	font.load("frabk.ttf", 122);

	/*
		ofCSVReader csvData("atp2016.csv", ',');
		vector<vector<string>> * data = csvData.getData();
		infocsv.setup();
		infocsv.setName("Info CSV");
		infocsv.setSize(350, infocsv.getHeight());
		ofDataProcessing dataproc(data);
		infocsv.add(champ1.setup("1", ofToString(dataproc.getTournamentAll()[0][0].toString()), 350));
		//infocsv.add(champ2.setup("2", ofToString(dataproc.getTournamentAll()[0][1].toString()), 350));
		//infocsv.add(champ3.setup("toggle"), 350);
		infocsv.add(champ4.setup("4", ofToString(dataproc.getTournamentAll()[0][3].toString()), 350));
		infocsv.add(champ5.setup(100));
		//infocsv.add(champ6.setup("6", ofToString(dataproc.getTournamentAll()[0][5].toString()), 350));
	*/

	//ofTournament * tr = dataproc.getTournament("Vienna");
	//infocsv.add(champ7.setup("7", ofToString((*tr).toString()), 350));

	//infocsv.setPosition(200, 200);
	//info

	header();


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	img->draw(475, 75);
	infocsv.draw();
	headerC->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

void ofApp::sizeWindow(int size)
{
	this->size = size;
}


//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


// Methods Agh
void ofApp::header()
{
	/* Choice of Tournament */

	font.drawString("ATP World Tour Stats", 350, 0);
		headerC = new ofxUISuperCanvas("");
		headerC->setWidth(250);
		// Change to automatically fill from getTournamentName();
		std::vector<string> names = {	"Brisbane", "Chennai", "Doha", "Canada Masters", "Atlanta", "Los Cabos", "Olympics",
										"Cincinnati Masters","Winston - Salem","Us Open","Metz","Chengdu","Shenzhen",
										"St.Petersburg","Beijing","Tokyo","Shanghai Masters","Antwerp","Moscow","Stockholm",
										"Basel","Vienna","Paris Masters","London" };
		 headerC->addSpacer();
		 tournament = headerC->addDropDownList("Tournament", names);
		 tournament->setAutoClose(true);
		 tournament->setAllowMultiple(false);
		 std::cout << "size : " << size << std::endl;
		 ofSetColor(255);
		 headerC->setPosition(375, 10);
		 headerC->setWidth(249);
		 headerC->setHeight(48);
		 headerC->setColorBack(ofxUIColor::black);


		/* Choice Players */
		 std::vector<string> player_names = { "Brisbane", "Chennai", "Doha",
			 "Canada Masters", "Atlanta", "Los Cabos", "Olympics",
			 "Cincinnati Masters","Winston - Salem","Us Open", };
		 Players_left = new ofxUISuperCanvas("");
		 Players_left->addSpacer();
		 player_left_list = Players_left->addDropDownList("Player 1", player_names);
		 player_left_list->setAutoClose(true);
		 //player_left_list->setAllowMultiple(false);

		 //Players_left->setWidth(249);
		 Players_left->setHeight(48);
		 Players_left->setPosition(200, 75);
		 //ofSetColor(0, 255, 0);
		 Players_left->setColorBack(ofxUIColor::black);
		 Players_left->draw();

		/* image_vs = new ofxUICanvas(" ");
		 ofImage * loser_ima = new ofImage();
		 loser_ima->load("D:/Ecole/ISIB/Master/1MA/1st Semester/Second session/Analysis & Data Visualization/Projet - Aout/OF-Tennis/OF-Tennis/bin/data/images/ball.png");
		 loser_ima->resize(100, 100);
		 loser_ima->draw(300, 60);
		 image_vs->addImage("Left", loser_ima, false);
		 image_vs->setPosition(400, 120);
		 image_vs->draw();*/

		 //ofxGuiSetTextColor(ofxUIColor::black);
		 Players_right = new ofxUISuperCanvas("");
		 Players_right->addSpacer();
		 player_right_list = Players_right->addDropDownList("Player 2 ", player_names);
		 player_right_list->setAutoClose(true);
		 player_right_list->setAllowMultiple(false);
		 player_right_list->setShowCurrentSelected(true);


		 //Players_right->setWidth(249);
		 Players_right->setHeight(48);
		 Players_right->setPosition(600, 75);
		 //Players_right->setWidgetColor(1, ofxUIColor::white);
		 Players_right->setColorBack(ofxUIColor::black);
		 Players_right->draw();
		 


		/* Players_infos */
		 Players_infos_left = new ofxUISuperCanvas("Roger Federer");
		 Players_infos = new ofxUISuperCanvas("");
		 Players_infos_right = new ofxUISuperCanvas("Roger Federer");


		 // Left
		 Players_infos_left->addSpacer();
		 ofImage * winner_image = new ofImage("images/bikers.jpg");
		 winner_image->draw(185, 120);
		 winner = Players_infos_left->addImage("Left", winner_image, false);
		 winner_rank = Players_infos_left->addLabel("Rank : 5", 1);
		 winner_rank->setColorBack(ofxUIColor::black);
		 Players_infos_left->addSpacer();
		 winner_rank = Players_infos_left->addLabel("Rank : 5", 1);

		 Players_infos_left->setPosition(200, 135);
		 Players_infos_left->setColorBack(ofxUIColor::black);
		 //ofSetColor(0, 255, 0);
		 Players_infos_left->draw();
		

		 // middle Matchs results
		// Players_infos->addSpacer();
		 score = Players_infos->addLabel("        Roger Federer", 1);
		 best_of = Players_infos->addLabel("        Roger Federer", 1);
		 Round = Players_infos->addLabel("        Roger Federer", 1);
		 duree = Players_infos->addLabel("        Roger Federer", 1);
		 Players_infos->setPosition(400, 135);
		 Players_infos->setColorBack(ofxUIColor::black);
		 Players_infos->centerWidgetsOnCanvas();
		 Players_infos->draw();

		 // Right
		 Players_infos_right->addSpacer();
		 ofImage * loser_image = new ofImage("images/bikers.jpg");
		 loser_image->draw(515, 100);

		 loser = Players_infos_right->addImage("Left", loser_image, false);
		 loser_rank = Players_infos_right->addLabel("Rank : 5", 1);
		 Players_infos_right->addSpacer();
		

		 Players_infos_right->setPosition(600, 135);
		 Players_infos_right->setColorBack(ofxUIColor::black);
		 Players_infos_right->draw();


}

void ofApp::PlayersInfos()
{
}

void ofApp::MatchsStats()
{
}