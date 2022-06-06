#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "Team.hpp"
using namespace std;

namespace ex6{

/*
this class will represent a league of basketball teams,
inside the league there will be 20 team, the teams will be stored inside
a vector of teams, and will create the league int 3 different ways:
1. the user will enter the teams names
2. the teams will be generated randomly
3. the teams will be generated randomly and the user will choose some of them
*/

class League{
    private:
    vector<Team*> teams={};
    int numOfTeams;
    public:
    League(){
        numOfTeams = 20;

    }
    void generateTeams();
    void chooseTeams();
    void chooseandGenerateTeams();
    Team* getTeam(uint i);
    vector<Team*> &getTeams();
    League sortTeams();
    vector<string> teamsToChoose= {"Lakers",
                           "Warriors",
                           "Cavaliers",
                           "Heat", 
                           "Rockets",
                           "Spurs", 
                           "Clippers", 
                           "Kings", 
                           "Jazz", 
                           "Nets", 
                           "Pacers", 
                           "Hornets", 
                           "Timberwolves", 
                           "Mavericks", 
                           "Grizzlies", 
                           "Pelicans", 
                           "Raptors", 
                           "Thunder", 
                           "Trail Blazers", 
                           "Nuggets", 
                           "76ers", 
                           "Suns", 
                           "Magic", 
                           "Wizards",
                           "Knicks",
                           "Bulls",
                           "Celtics",
                           "Hawks",};





};







}