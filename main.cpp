#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//#include "Team.hpp"
//#include "Game.hpp"
//#include "League.hpp"
#include "Schedule.hpp"
using namespace std;
using namespace ex6;
int main(){

    League* league;
    league = new League();
    //league->chooseTeams();
    league->generateTeams();
    for(int i=0; i<league->getTeams().size(); i++){
        cout<<league->getTeams()[i]->getName()<<endl;
    }
    league->sortTeams();
    cout<<"\n"<<endl;
    Schedule* schedule;
    schedule = new Schedule(league);
    cout<<"start the game"<<endl;
    schedule->createSchedule();
    
    schedule->startTheGame();
    
    cout<<"the final score of the league is: "<<endl;
    for(uint i=0; i<league->getTeams().size(); i++){
        cout<<i+1<<". "<<league->getTeams()[i]->getName()<<" "<<league->getTeams()[i]->getTotalScore()<<endl;
    }
    return 0;



}