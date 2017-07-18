#include "ofTournament.h"



ofTournament::ofTournament(string id , string name, string surface, string level, string date)
{
	this->id = id;
	this->name = name;
	this->level = level;
	this->surface = surface;
	this->date = date;
	this->matchs = new vector<ofMatch>();

}


ofTournament::~ofTournament()
{
	this->matchs = new vector<ofMatch>();
}

string ofTournament::getID()
{
	return id;
}

string ofTournament::getName()
{
	return name;
}

string ofTournament::getLevel()
{
	return level;
}

string ofTournament::getSurface()
{
	return surface;
}

string ofTournament::getDate()
{
	return date;
}

vector<ofMatch>* ofTournament::getMatchs()
{
	return matchs;
}

void ofTournament::addMatch(ofMatch match)
{
	this->matchs->push_back(match);
}

void ofTournament::setID(string id)
{
	this->id = id;
}

void ofTournament::setName(string name)
{
	this->name = name;
}

void ofTournament::setLevel(string level)
{
	this->level = level;
}

void ofTournament::setSurface(string surface)
{
	this->surface = surface;
}

void ofTournament::setDate(string date)
{
	this->date = date;
}

string ofTournament::toString()
{
	return id + " " + name + " " + level + " " + surface + " " + date;
}
