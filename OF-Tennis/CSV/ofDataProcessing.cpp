#include "ofDataProcessing.h"
#include <string>



ofDataProcessing::ofDataProcessing(vector<vector<string>>  * data)
{
	this->data = data;
	this->tournament = new vector<ofTournament>();
	tournament_name = new vector<string>();

	transform();

	/* Test view infos
	std::cout << this->tournament[0][0].getName() << " : " << std::endl;
	for (size_t i = 0; i < 10; i++)
	{
	
		std::cout << this->tournament[0][1].getMatchs()[0][i].getWinner()->getName() << " (w) - ";
		std::cout << this->tournament[0][1].getMatchs()[0][i].getLoser()->getName() << " (l) " << "\t -----> ";
		std::cout << this->tournament[0][1].getMatchs()[0][i].getScore() << std::endl;
	}*/
	
	
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
	return  new ofTournament("Unknown", "Unknown");
}


vector<ofTournament> * ofDataProcessing::getTournamentAll()
{
	return tournament;
}

vector<string>* ofDataProcessing::getTournamentsNames()
{
	return this->tournament_name;
}

void ofDataProcessing::transform()
{
	ofTournament tourn = ofTournament();

	string name_prev = " ";

	// the first line is the header of csv, then start at 1
	for (unsigned i = 1; i < (*data).size(); i++)
	{

		string name = (*data)[i][1];
		if (name.compare(name_prev) != 0) {
			tournament->push_back(tourn);
			tourn = ofTournament();
			tourn.setID((*data)[i][0]);
			tourn.setName((*data)[i][1]);
			tourn.setSurface((*data)[i][2]);
			tourn.setLevel((*data)[i][3]);
			tourn.setDate((*data)[i][4]);
			name_prev = name;
			tournament_name->push_back(name);
			tourn.addMatch(getMatch(&(*data)[i]));
		}
		else {
			tourn.addMatch(getMatch(&(*data)[i]));
		}
	}
}

ofMatch  ofDataProcessing::getMatch(vector<string> * info)
{

	ofMatch match =  ofMatch();
	ofPlayer * winner = new ofPlayer();
	ofPlayer * loser = new ofPlayer();

	//std::cout << (*info)[10] << " - " << (*info)[20] << std::endl;
	for (unsigned i = 0; i < (*info).size(); i++)
	{
		/* 		6			  27		   28		 29		  30
			match_num		score		best_of		round	minutes
		*/
		match.setId((*info)[6]);
		match.setScore((*info)[27]);
		match.setBest_of((*info)[28]);
		match.setRound((*info)[29]);
		match.setMinutes((*info)[30]);

		playerInfo_firstPart(info, winner,7,16);
		playerInfo_secondPart(info, winner, 31, 39);

		playerInfo_secondPart(info, loser, 40, 48);
		playerInfo_firstPart(info, loser, 17, 26);

		match.setWinner(winner);
		match.setLoser(loser);
	}

	return match;
}

void ofDataProcessing::playerInfo_firstPart(vector<string>* info, ofPlayer * player, int indiceStart, int indiceEnd)
{
	
	for (unsigned i = indiceStart; i < indiceEnd; i++)
	{
		
		/*
			winner_id(7) winner_seed(8)	winner_entry(9)	winner_name(10)	winner_hand(11)
			winner_ht(12) winner_ioc(13) winner_age(14)  winner_rank(15) winner_rank_points(16);

			loser_id(17) loser_seed(18)	loser_ntry(19)	loser_name(20)	loser_hand(21)
			loser_ht(22) loser_ioc(23) loser_ge(24)  loser_rank(25) loser_rank_points(26)
		*/
		switch (i)
		{
		case 7:
		case 17: player->setId((*info)[i]); break;
		case 8:
		case 18: player->setSeed((*info)[i]); break;
		case 9:
		case 19: player->setEntry((*info)[i]); break;
		case 10:
		case 20: player->setName((*info)[i]); break;
		case 11:
		case 21: player->setHand((*info)[i]); break;
		case 12:
		case 22: player->setHt((*info)[i]); break;
		case 13:
		case 23: player->setIoc((*info)[i]); break;
		case 14:
		case 24: player->setAge((*info)[i]); break;
		case 15:
		case 25: player->setRank((*info)[i]); break;
		case 16:
		case 26: player->setRank_points((*info)[i]); break;
		default:
			break;
		}	
	}
}

void ofDataProcessing::playerInfo_secondPart(vector<string>* info, ofPlayer * player, int indiceStart, int indiceEnd)
{
	for (unsigned i = indiceStart; i < indiceEnd; i++)
	{
		/*
			w_ace(31) w_df(32) w_svpt(33) w_1stIn(34) w_1stWon(35)	w_2ndWon(36)
			w_SvGms(37)	w_bpSaved(38) w_bpFaced(39)

			l_ace(40) l_df(41) l_svpt(42) l_1stIn(43) l_1stWon(44) l_2ndWon(45)	
			l_SvGms(46)	l_bpSaved(47)	l_bpFaced(48)
		*/
		switch (i)
		{
		case 31:
		case 40: player->setAce((*info)[i]); break;
		case 32:
		case 41: player->setDoubleFaults((*info)[i]); break;
		case 33:
		case 42: player->setSvpt((*info)[i]); break;
		case 34:
		case 43: player->setFstIn((*info)[i]); break;
		case 35:
		case 44: player->setFstWon((*info)[i]); break;
		case 36:
		case 45: player->setSndWon((*info)[i]); break;
		case 37:
		case 46: player->setSvGms((*info)[i]); break;
		case 38:
		case 47: player->setBpSaved((*info)[i]); break;
		case 39:
		case 48: player->setBpFaced((*info)[i]); break;
		default:
			break;
		}
	}
}
