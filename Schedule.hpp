#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
//#include "Team.hpp"
#include "Game.hpp"
#include "League.hpp"
using namespace std;

namespace ex6{

/* this class will represnt a league of basketball teams,
    there are 19 cycles of the league, every team will play only once in each cycle
    if two teams play in the same cycle, they will play in the next cycle also but once 
    in every house, the choosung will use the round robin algorithm
*/


class Schedule{
  vector<Game*> games;
  vector<Team*> teams;
  League* league;
  int cycle=1;
  const int numberOfGames=190;
  const int numOfCycles = 19;

    public:
Schedule(League *league){
        this->league = league;
    }
void createSchedule();
void startTheGame();
void statistics();    
};

}