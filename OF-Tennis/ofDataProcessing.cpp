#include "ofDataProcessing.h"
#include <string>



ofDataProcessing::ofDataProcessing(vector<vector<string>>  * data)
{
	this->data = data;
	this->tournament = new vector<ofTournament>();
	transform();
}


ofDataProcessing::~ofDataProcessing()
{
}

ofTournament * ofDataProcessing::getTournament(std::string name)
{
	for (unsigned i = 0; i < (*data).size(); i++)
	{
		string name_ = (tournament)[0][i].getName();
		if (name_.compare(name) == 0) {
			return &(tournament)[0][i];
		}
	}
	return  new ofTournament();
}


vector<ofTournament> * ofDataProcessing::getTournamentAll()
{
	return tournament;
}

void ofDataProcessing::transform()
{
	ofTournament tourn = ofTournament();

	/* Tmp, to be updated to inlcude matchs */
	string name_prev = " ";

	// the first line is the header of csv, then start at 1
	for (unsigned i = 1; i < (*data).size(); i++)
	{

		/* Tmp, to be updated to inlcude matchs */
		string name = (data)[0][i][1];
		if (name.compare(name_prev) != 0) {
			tourn.setID((*data)[i][0]);
			tourn.setName((*data)[i][1]);
			tourn.setSurface((*data)[i][2]);
			tourn.setLevel((*data)[i][3]);
			tourn.setDate((*data)[i][4]);
			name_prev = name;
			tournament->push_back(tourn);
		}
		
	}
}
