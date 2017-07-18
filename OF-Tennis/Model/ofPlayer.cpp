#include "ofPlayer.h"



ofPlayer::ofPlayer(string id, string name)
{
	this->id = id;
	this->name = name;
}

ofPlayer::~ofPlayer()
{

}


string ofPlayer::getId() 
{
	return this->id;
}

string ofPlayer::getSeed() 
{
	return this->seed;
}

string ofPlayer::getEntry() 
{
	return this->entry;
}

string ofPlayer::getName() 
{
	return this->name;
}

string ofPlayer::getHand() 
{
	return this->hand;
}

string ofPlayer::getHt() 
{
	return this->ht;
}

string ofPlayer::getIoc() {
	return this->ioc;
}

string ofPlayer::getAge() 
{
	return this->age;
}

string ofPlayer::getRank() 
{
	return this->rank;
}

string ofPlayer::getRank_points() 
{
	return this->rank_points;
}

string ofPlayer::getAce() 
{
	return this->ace;
}

string ofPlayer::getDf() 
{
	return this->df;
}

string ofPlayer::getSvpt() 
{
	return this->svpt;
}
string ofPlayer::getFstIn() 
{
	return this->fstIn;
}

string ofPlayer::getFstWon() 
{
	return this->fstWon;
}

string ofPlayer::getSndWon() 
{
	return this->sndWon;
}

string ofPlayer::getSvGms() 
{
	return this->SvGms;
}

string ofPlayer::getBpSaved() 
{
	return this->bpSaved;
}

string ofPlayer::getBpFaced() 
{
	return this->bpFaced;
}


/* Set */

void ofPlayer::setId(string value)
{
	this->id = value;
}

void ofPlayer::setSeed(string value)
{
	this->seed = value;
}

void ofPlayer::setEntry(string value)
{
	this->entry = value;
}

void ofPlayer::setName(string value)
{
	this->name = value;
}

void ofPlayer::setHand(string value)
{
	this->hand = value;
}

void ofPlayer::setHt(string value)
{
	this->ht = value;
}

void ofPlayer::setIoc(string value)
{
	this->ioc = value;
}

void ofPlayer::setAge(string value)
{
	this->age = value;
}

void ofPlayer::setRank(string value)
{
	this->rank = value;
}
void ofPlayer::setRank_points(string value)
{
	this->rank_points = value;
}

void ofPlayer::setAce(string value)
{
	this->ace = value;
}

void ofPlayer::setDf(string value)
{
	this->df = value;
}

void ofPlayer::setSvpt(string value)
{
	this->svpt = value;
}

void ofPlayer::setFstIn(string value)
{
	this->fstIn = value;
}

void ofPlayer::setFstWon(string value)
{
	this->fstWon = value;
}

void ofPlayer::setSndWon(string value)
{
	this->sndWon = value;
}

void ofPlayer::setSvGms(string value)
{
	this->SvGms = value;
}

void ofPlayer::setBpSaved(string value)
{
	this->bpSaved = value;
}

void ofPlayer::setBpFaced(string value)
{
	this->bpFaced = value;
}