#pragma once

#include <iostream>
#include <vector>
#include "ofMain.h"
#include "ofTournament.h"

class ofDataProcessing
{
public:
	ofDataProcessing(vector<vector<string>> * data);
	~ofDataProcessing();
	ofTournament * getTournament(std::string name);
	vector<ofTournament> * getTournamentAll();
	

private:
	vector<vector<string>> * data;
	vector<ofTournament> * tournament;
	void transform();

};

