#include "ofApp.h"
#include "ofCSVReader.h"

//--------------------------------------------------------------
void ofApp::setup(){
	font.load("frabk.ttf", 122);
	ofCSVReader csvData("test.csv", ',');
	vector<vector<string>> data = csvData.getData();
	dynamixel_move.setup();
	dynamixel_move.setName("Info CSV");
	dynamixel_move.setSize(250, dynamixel_move.getHeight());
	dynamixel_move.add(nom.setup("Symbol", ofToString(data[0][0]), 250));
	dynamixel_move.add(model_number.setup("Code", ofToString(data[0][1]), 250));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	dynamixel_move.draw();
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
