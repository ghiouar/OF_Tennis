#pragma once

#include <iostream>
#include <vector>
#include "ofMatch.h"
using namespace std;

class ofTournament
{
public:
	ofTournament(	string id = " ", string name = " ", string surface = " " ,
					string level = " ", string date = " ");
	~ofTournament();

	string getID();
	string getName();
	string getLevel();
	string getSurface();
	string getDate();
	vector<string> * getPlayersNames();
	vector <string> * getOpponents(string name);
	vector<ofMatch> * getMatchs();
	ofMatch * getMatch(string name_winner, string name_loser);
	void addMatch(ofMatch  match);

	void setID(string id);
	void setName(string name);
	void setLevel(string level);
	void setSurface(string surface);
	void setDate(string date);

	string toString();

private:
	string id;
	string name;
	string level;
	string surface;
	string date;
	vector<ofMatch> * matchs;
	vector<string> * playersNames;
	vector <string> * opponents;

	
		


};

