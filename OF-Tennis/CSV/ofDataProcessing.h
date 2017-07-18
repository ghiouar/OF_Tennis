#pragma once

#include <iostream>
#include <vector>
#include "ofMain.h"
#include "Model/ofTournament.h"

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
	vector<string> * tournament_name;
	void transform();
	ofMatch getMatch(vector<string> * info);

	void playerInfo_firstPart(vector<string> * info, ofPlayer * player, int indiceStart, int indiceEnd);
	void playerInfo_secondPart(vector<string> * info, ofPlayer * player, int indiceStart, int indiceEnd);

};

