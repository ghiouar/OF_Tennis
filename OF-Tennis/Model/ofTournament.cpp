#include "ofTournament.h"
#include <algorithm>
#include <iostream>
#include <string>


ofTournament::ofTournament(string id , string name, string surface, string level, string date)
{
	this->id = id;
	this->name = name;
	this->level = level;
	this->surface = surface;
	this->date = date;
	this->matchs = new vector<ofMatch>();
	this->playersNames = new vector<string>();
	this->opponents = new vector<string>();
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

vector<string>* ofTournament::getPlayersNames()
{
	return this->playersNames;
}

vector<string>* ofTournament::getOpponents(string name)
{
	opponents->clear();

	for each (ofMatch match in *matchs)
	{
		if (match.getWinner()->getName().compare(name) == 0) 
		{
			opponents->push_back(match.getLoser()->getName());
		}

		if (match.getLoser()->getName().compare(name) == 0)
		{
			opponents->push_back(match.getWinner()->getName());
		}
	}
	return opponents;
}

vector<ofMatch>* ofTournament::getMatchs()
{
	return matchs;
}

ofMatch * ofTournament::getMatch(string name_winner, string name_loser)
{
	ofMatch * mt = new ofMatch();
	bool found = false;
	int i = 0;
		
	while (!found && i <  (*matchs).size()) {
		if (((*matchs)[i].getWinner()->getName().compare(name_winner) == 0 && 
			(*matchs)[i].getLoser()->getName().compare(name_loser) == 0)
			||
			((*matchs)[i].getWinner()->getName().compare(name_loser) == 0 && 
			(*matchs)[i].getLoser()->getName().compare(name_winner) == 0)) {

			mt =  &(*matchs)[i];
			found = true;
		}
		
		i++;
	}

	return mt;

}

void ofTournament::addMatch(ofMatch match)
{
	this->matchs->push_back(match);

	if (match.getRound().compare("F")) {
		winner_tournement = match.getWinner()->getName();
		second_place = match.getLoser()->getName();
	}
	if (std::find(playersNames->begin(), playersNames->end(), 
		match.getWinner()->getName()) == playersNames->end())
	{
		playersNames->push_back(match.getWinner()->getName());
	}

	if (std::find(playersNames->begin(), playersNames->end(),
		match.getLoser()->getName()) == playersNames->end())
	{
		playersNames->push_back(match.getLoser()->getName());
	}
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
