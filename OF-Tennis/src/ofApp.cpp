#include "ofApp.h"
#include "ofCSVReader.h"
#include "ofDataProcessing.h"

//--------------------------------------------------------------
void ofApp::setup(){
	font.load("frabk.ttf", 122);
	ofCSVReader csvData("atp2016.csv", ',');
	vector<vector<string>> * data = csvData.getData();
	infocsv.setup();
	infocsv.setName("Info CSV");
	infocsv.setSize(350, infocsv.getHeight());
	ofDataProcessing dataproc(data);
	infocsv.add(champ1.setup("1", ofToString(dataproc.getTournamentAll()[0][0].toString()), 350));
	infocsv.add(champ2.setup("2", ofToString(dataproc.getTournamentAll()[0][1].toString()), 350));
	infocsv.add(champ3.setup("3", ofToString(dataproc.getTournamentAll()[0][2].toString()), 350));
	infocsv.add(champ4.setup("4", ofToString(dataproc.getTournamentAll()[0][3].toString()), 350));
	infocsv.add(champ5.setup("5", ofToString(dataproc.getTournamentAll()[0][4].toString()), 350));
	infocsv.add(champ6.setup("6", ofToString(dataproc.getTournamentAll()[0][5].toString()), 350));

	ofTournament * tr = dataproc.getTournament("Vienna");
	infocsv.add(champ7.setup("7", ofToString((*tr).toString()), 350));

	/*infocsv.add(champ1.setup("Symbol", ofToString((*data)[1][0]), 250));
	infocsv.add(champ2.setup("Code", ofToString((data)[0][1][0]), 250));
	infocsv.add(champ3.setup("Symbol", ofToString((*data)[1][2]), 250));
	infocsv.add(champ4.setup("Code", ofToString((*data)[1][3]), 250));
	infocsv.add(champ5.setup("Symbol", ofToString((*data)[1][4]), 250));
	infocsv.add(champ6.setup("Code", ofToString((*data)[1][5]), 250));*/
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	infocsv.draw();
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

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
