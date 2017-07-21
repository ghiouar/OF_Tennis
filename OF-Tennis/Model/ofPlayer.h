#pragma once

#include <iostream>

using namespace std;

class ofPlayer
{
public:
	ofPlayer(string id = " ", string name = " ");
	~ofPlayer();

	string getId();
	string getSeed();
	string getEntry();
	string getName();
	string getHand();
	string getHt();
	string getIoc();
	string getAge();
	string getRank();
	string getRank_points();
	string getAce();
	string getDoubleFaults();
	string getSvpt();
	string getFstIn();
	string getFstWon();
	string getSndWon();
	string getSvGms();
	string getBpSaved();
	string getBpFaced();

	void setId(string value);
	void setSeed(string value);
	void setEntry(string value);
	void setName(string value);
	void setHand(string value);
	void setHt(string value);
	void setIoc(string value);
	void setAge(string value);
	void setRank(string value);
	void setRank_points(string value);
	void setAce(string value);
	void setDoubleFaults(string value);
	void setSvpt(string value);
	void setFstIn(string value);
	void setFstWon(string value);
	void setSndWon(string value);
	void setSvGms(string value);
	void setBpSaved(string value);
	void setBpFaced(string value);
private:
	string id;
	string seed;
	string entry;
	string name;
	string hand;
	string ht;
	string ioc;
	string age;
	string rank;
	string rank_points;

	string ace;
	string doubleFaults;
	string svpt;
	string fstIn;
	string fstWon;
	string sndWon;
	string SvGms;
	string bpSaved;
	string bpFaced;
};

