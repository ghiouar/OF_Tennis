#pragma once

#include "ofMain.h"
#include "ofxGui/src/ofxGui.h"
#include "ofxUI.h"

class ofApp : public ofBaseApp{

private:
	int size;

public:
		
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void sizeWindow(int size);

		ofTrueTypeFont font;

		/* Header */
			ofxUISuperCanvas * headerC;
			ofxUIDropDownList * tournament;
			/*ofxUILabelButton * load;

			ofxUIDropDownList * player_left;
			ofImage * vsBall;
			ofxUIDropDownList * player_right;
			ofxUILabelButton * h2h;*/

		/* Choice Players */
		ofxUISuperCanvas * Players_left;
		ofxUIDropDownList * player_left_list;

		ofxUICanvas * image_vs;
		ofxUISuperCanvas * Players_right;
		ofxUIDropDownList * player_right_list;

		/* Players infos */
		ofxUISuperCanvas * Players_infos_left;
		ofxUISuperCanvas * Players_infos;
		ofxUISuperCanvas * Players_infos_right;
			// Left
			ofxUIImage * winner;
			ofxUILabel * winner_name;
			ofxUILabel * winner_rank;

			// middle Matchs results
			ofxUILabel * score;
			ofxUILabel * best_of;
			ofxUILabel * Round;
			ofxUILabel * duree;

			// Right
			ofxUIImage * loser;
			ofxUILabel * loser_name;
			ofxUILabel * loser_rank;

		/* Matchs stats*/
			ofxUILabel * aces_left; ofxUILabel * aces; ofxUILabel * aces_right;
			ofxUILabel * double_faults_left; ofxUILabel * double_faults; ofxUILabel * double_faults_right;
			ofxUILabel * fst_Serve_in_left; ofxUILabel * fst_Serve_in; ofxUILabel * fst_Serve_in_right;
			ofxUILabel * fst_Serve_points_won_left; ofxUILabel * fst_Serve_points_won; ofxUILabel * fst_Serve_points_won_right;
			ofxUILabel * snd_Serve_points_won_left; ofxUILabel * snd_Serve_points_won; ofxUILabel * snd_Serve_points_won_right;
			ofxUILabel * service_games_played_left; ofxUILabel * service_games_played; ofxUILabel * service_games_played_right;
			ofxUILabel * break_points_saved_left; ofxUILabel * break_points_saved; ofxUILabel * break_points_saved_right;
			ofxUILabel * break_points_faced_left; ofxUILabel * break_points_faced; ofxUILabel * break_points_faced_right;
			ofxUILabel * total_serve_points_left; ofxUILabel * total_serve_points; ofxUILabel * total_serve_points_right;


		/* Test */
		ofxPanel infocsv;
		ofxGuiGroup info;
		ofxLabel champ1;
		ofxLabel champ2;
		ofxLabel champ3;
		ofxLabel champ4;
		ofxIntSlider champ5;
		//ofxSlider * champ6;
		//ofx champ7;
		ofImage * img;
		ofImage * loser_image;
		ofImage * winner_image;
		
		

		/* Method */
		void header();
		void PlayersInfos();
		void MatchsStats();
};
