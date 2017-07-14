
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>

#include "ofCSVReader.h"
#include "ofMain.h"



ofCSVReader::ofCSVReader(string filePath, char delimiter)
{
	this->filePath  = filePath;
	this->delimiter = delimiter;

	this->data = new vector<vector<string>>();

	ofFile file(filePath);

	if (!file.exists()) {
		ofLogError("The file " + filePath + " is missing");
	}
	buffer = ofBuffer(file);
	readData();

}

ofCSVReader::~ofCSVReader()
{
}

vector<vector<string>> * ofCSVReader::getData()
{
	return this->data;
}

void ofCSVReader::readData()
{
	for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
		string line = *it;
		vector<string> words = ofSplitString(line, delimiter);

		this->data->push_back(words);
	}

}


