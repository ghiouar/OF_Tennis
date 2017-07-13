#pragma once

#include <iostream>
#include <vector>
#include "ofMain.h"

using namespace std;

class ofCSVReader
{
public:
	ofCSVReader(string filePath, char delimiter = ',');
	~ofCSVReader();
	vector<vector<string>> getData();

private:
	vector<vector<string>> data;
	string delimiter, filePath;
	ofBuffer buffer;
	void readData();
	
};

