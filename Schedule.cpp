#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Schedule.hpp"
using namespace std;
namespace ex6{
void Schedule::createSchedule(){
   
    for(uint i=1; i<21; i++){
        for(uint j=1; j<21; j++){
           if(i==j){
               continue;
           }
           else{
                Team* team1 = league->getTeams()[i-1];
                Team* team2 = league->getTeams()[j-1];
                cout<<j+1<<". "<<team1->getName()<<" vs "<<team2->getName()<<endl;
                Game* game = new Game(team1,team2);
                
                games.push_back(game);
           }
        }
        cout<<"cycle "<<i<<" is done"<<endl;
    }
    cout<<"the schedule is done"<<endl;
}
void Schedule::startTheGame(){
    for(uint i=0; i<games.size(); i++){
        // cout<<games[i]->getTeam1()->getName()<<" vs "<<games[i]->getTeam2()->getName()<<endl;
        // cout<<games[i]->getTeam1()->getResult_list().size()<<endl;
        games.at(i)->play(); 
    }
    int choice;
    cout<<"If you would like to see the statistics of the game, please enter 1, otherwise enter 0"<<endl;
    cin>>choice;
    if(choice==1){
        statistics();
    }
    else{
        cout<<"Thank you for playing"<<endl;
    }
}

void Schedule::statistics(){
    cout << "Those are the statistics of the league:" << endl;
    league->sortTeams();
    cout<< "-------------Ratio of wins and losses--------------"<<endl;
    for(uint i=0; i<league->getTeams().size(); i++){
        cout<<i+1<<". "<<league->getTeams()[i]->getName()<<
        "Number Of Winning: "<<league->getTeams()[i]->getNumOfVictories()<<"  |  "<<
        "Number of Losses: "<<league->getTeams()[i]->getNumOfDefeats()<<endl;
    }
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"\n";
    cout<< "-------------Ratio between the points we achieved and the number of points we received--------------"<<endl;
    cout<<"\n";
    for(uint i=0; i<league->getTeams().size(); i++){
        cout<<i+1<<". "<<league->getTeams()[i]->getName()<<
        "Number Of Points We Achieved : "<<league->getTeams()[i]->getTotalScore()<<"  |  "<<
        "Number of Points We Received : "<<league->getTeams()[i]->getTotalScoreAgainst()<<"\n"<<
        "Ratio: "<<league->getTeams()[i]->getTotalScore()-league->getTeams()[i]->getTotalScoreAgainst()<<endl;
    }
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"\n";
    cout<< " ------------TOP 5 TEAMS IN THE LEAGUE------------"<<endl;
    cout<<"\n";
    league->sortTeams();
    for(uint i=0; i<5; i++){
        cout<<i+1<<". "<<league->getTeams()[i]->getName()<<" "<<league->getTeams()[i]->getTotalScore()<<endl;
    }
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"\n";
    cout<< " ------------BOTTOM 5 TEAMS IN THE LEAGUE------------"<<endl;
    cout<<"\n";
    for(uint i=league->getTeams().size()-1; i>league->getTeams().size()-6; i--){
        cout<<i+1<<". "<<league->getTeams()[i]->getName()<<" "<<league->getTeams()[i]->getTotalScore()<<endl;
    }
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"\n";
    cout<< " ------------Longest streak of wins------------"<<endl;
    cout<<"\n";
    int tempMax = 0;
    string tempName = "";
    for(uint i=0; i<league->getTeams().size(); i++){
        league->getTeams()[i]->findLongestStreak();
        if(league->getTeams()[i]->getLongestStreak() > tempMax){
            tempMax = league->getTeams()[i]->getLongestStreak();
            tempName = league->getTeams()[i]->getName();
        }
    }
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"\n";
    cout<<"The team with the longest streak of wins is: "<<tempName
    <<" which have streak of "<<tempMax<<" victories!" <<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"\n";
    cout<< " ------------Longest streak of defeats------------"<<endl;
    cout<<"\n";
    int tempMin = 0;
    tempName = "";
    for(uint i=0; i<league->getTeams().size(); i++){
        league->getTeams()[i]->findLongestLosingStreak();
        if(league->getTeams()[i]->getLongestLosingStreak() > tempMin){
            tempMin = league->getTeams()[i]->getLongestLosingStreak();
            tempName = league->getTeams()[i]->getName();
        }
    }
    cout<<"The team with the longest streak of defeats is: "<<tempName
    <<" which have streak of "<<tempMin<<" defeats!" <<endl;
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"\n";

    cout<< " ------------Number of Teams which score more than the average score------------"<<endl;
    cout<<"\n";
    int tempNum = 0;
    //computing the avarage score
    int sum = 0;
    vector <string> tempNames;
    for(uint i=0; i<league->getTeams().size(); i++){
        sum += league->getTeams()[i]->getTotalScore();
    }
    int average = sum/league->getTeams().size();
    for(uint i=0; i<league->getTeams().size(); i++){
        if(league->getTeams()[i]->getTotalScore() > average){
            tempNum++;
            tempNames.push_back(league->getTeams()[i]->getName());
        }
    }
    cout<< "The average score is: "<<average<<endl;
    cout<<"There are "<<tempNum<<" teams which score more than the average score!"<<"\n"
    <<"They are: "<<endl;
    for(uint i=0; i<tempNames.size(); i++){
        cout<<tempNames[i]<<endl;
    }
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"\n";

    cout<< " ------------Number of Teams which score less than the average score------------"<<endl;
    cout<<"\n";
    tempNum = 0;
    tempNames.clear();
    for(uint i=0; i<league->getTeams().size(); i++){
        if(league->getTeams()[i]->getTotalScore() < average){
            tempNum++;
            tempNames.push_back(league->getTeams()[i]->getName());
        }
    }
    cout<< "The average score is: "<<average<<endl;
    cout<<"There are "<<tempNum<<" teams which score less than the average score!"<<
    "They are: "<<endl;
    for(uint i=0; i<tempNames.size(); i++){
        cout<<tempNames[i]<<endl;
    }
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"\n";

    cout<< " ------------Number of Teams that score more than they receive------------"<<endl;
    cout<<"\n";
    tempNum = 0;
    tempNames.clear();
    for(uint i=0; i<league->getTeams().size(); i++){
        if(league->getTeams()[i]->getTotalScore() > league->getTeams()[i]->getTotalScoreAgainst()){
            tempNum++;
            tempNames.push_back(league->getTeams()[i]->getName());
        }
    }
    cout<<"There are "<<tempNum<<" teams which score more than they receive!"<<
    "They are: "<<endl;
    for(uint i=0; i<tempNames.size(); i++){
        cout<<tempNames[i]<<endl;
    }
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    cout<<"\n";
    cout<<"That was the end of the league statistics!"<<endl;

}

}