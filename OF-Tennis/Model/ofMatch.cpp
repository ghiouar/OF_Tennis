#include "ofMatch.h"



ofMatch::ofMatch(ofPlayer * winner, ofPlayer * loser, string score, string best_of, string round, string minutes)
{
	this->winner = winner;
	this->loser = loser;
	this->score = score;
	this->best_of = best_of;
	this->round = round;
	this->minutes = minutes;
}


ofMatch::ofMatch(string score, string best_of, string round, string minutes)
{
	this->winner = new ofPlayer();
	this->loser = new ofPlayer();
}

ofMatch::~ofMatch()
{
	//delete this->winner;
	//delete this->loser;
}

ofPlayer * ofMatch::getWinner()
{
	return this->winner;
}

ofPlayer * ofMatch::getLoser()
{
	return this->loser;
}

string ofMatch::getScore()
{
	return this->score;
}

string ofMatch::getBest_of()
{
	return this->best_of;
}

string ofMatch::getRound()
{
	return this->round;
}

string ofMatch::getMinutes()
{
	return this->minutes;
}

string ofMatch::getId()
{
	return this->id;
}

void ofMatch::setWinner(ofPlayer * winner)
{
	this->winner = winner;
}

void ofMatch::setLoser(ofPlayer * loser)
{
	this->loser = loser;
}

void ofMatch::setScore(string score)
{
	this->score = score;
}

void ofMatch::setBest_of(string best_of)
{
	this->best_of = best_of;
}

void ofMatch::setRound(string round)
{
	this->round = round;
}

void ofMatch::setMinutes(string minutes)
{
	this->minutes = minutes;
}

void ofMatch::setId(string id)
{
	this->id = id;
}

