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
	vector<string>* getRounds();
	vector<string> * getPlayersNames();
	vector<string> * getPlayersNamesByRound();
	vector <string> * getOpponents(string name);
	vector<ofMatch> * getMatchs();
	ofMatch * getMatch(string name_winner, string name_loser);
	void addMatch(ofMatch  match);

	void setID(string id);
	void setName(string name);
	void setLevel(string level);
	void setSurface(string surface);
	void setDate(string date);

	string getRound();
	void setRound(string round);
	string toString();

private:
	string id;
	string name;
	string winner_tournement;
	string second_place;
	string level;
	string surface;
	string date;
	vector<ofMatch> * matchs;
	string round;
	//vector<ofMatch> * matchs_sf;
	//vector<ofMatch> * matchs_qf;
	//vector<ofMatch> * matchs_r16;
	//vector<ofMatch> * matchs_r32;
	//vector<ofMatch> * matchs_r64;
	//vector<ofMatch> * matchs_r128;
	ofMatch * matchs_final;

	vector<string> * playersNames;
	vector<string> * playersNamesByRound;
	vector <string> * opponents;
	vector <string> * rounds;

	

	
		


};

