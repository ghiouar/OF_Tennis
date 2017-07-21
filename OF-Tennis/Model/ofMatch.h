#pragma once

#include "ofPlayer.h"
class ofMatch
{
public:
	ofMatch(ofPlayer * winner, ofPlayer * loser, string score = " ", 
			string best_of = " ", string round = " ", string minutes = " ");

	ofMatch(string score = " ",string best_of = " ", string round = " ", string minutes = " ");
	~ofMatch();

	ofPlayer * getWinner();
	ofPlayer * getLoser();
	string getScore();
	string getBest_of();
	string getRound();
	string getMinutes();
	string getId();

	void setWinner(ofPlayer * winner);
	void setLoser(ofPlayer * loser);
	void setScore(string score);
	void setBest_of(string best_of);
	void setRound(string round);
	void setMinutes(string minutes);
	void setId(string id);

private:
	ofPlayer * winner;
	ofPlayer * loser;
	string id;
	string score;
	string best_of;
	string round;
	string minutes;
};

