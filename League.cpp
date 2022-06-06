#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "League.hpp"
//#include "Team.hpp"
#include "Game.hpp"
#include<bits/stdc++.h>
using namespace std;

namespace ex6{

Team* League::getTeam(uint i){
        return teams[i];
    }

vector<Team*> &League::getTeams(){
        return teams;
    }

League League::sortTeams(){
        sort(teams.begin(), teams.end(), [](Team* a, Team* b){
            return a->getTotalScore() > b->getTotalScore();
        });
        return *this;
    }

void League::generateTeams(){
    vector<string> tempTeams = this->teamsToChoose;
    for(int i=0; i<this->numOfTeams; i++){
        int random = rand()%tempTeams.size();
        string name = tempTeams[random];
        //cout<<i+1<<". Name: "<<name<<endl;
        Team* team = new Team(name);
        vector<string>::iterator it = find(tempTeams.begin(), tempTeams.end(), name);
        tempTeams.erase(it);
        this->getTeams().push_back(team);
    }
   
}
void League::chooseTeams(){
    cout<< "Welcome to our league, please choose your teams: "<<endl;
    for(int i = 0 ; i < this->teamsToChoose.size(); i++){
        cout<<i+1<<". "<<this->teamsToChoose[i]<<endl;
    }
    cout<< "please enter the main number which appear before the team name: "<<endl;
    int num;
    for(int i = 0 ; i < this->numOfTeams; i++){
        cin>>num;
        string name = this->teamsToChoose[num-1];
        Team* team = new Team(name);
        teams.push_back(team);
    }
}

void League::chooseandGenerateTeams(){
    vector<string> tempTeams = this->teamsToChoose;
    cout<< "Welcome to our league, please choose 10 teams: "<<endl;
    for(int i = 0 ; i < this->teamsToChoose.size(); i++){
        cout<<i+1<<". "<<this->teamsToChoose[i]<<endl;
    }
    cout<< "please enter the main number which appear before the team name: "<<endl;
    int num;
    for(int i = 0 ; i < 10; i++){
        cin>>num;
        string name = tempTeams[num-1];
        Team* team = new Team(name);
        vector<string>::iterator it = find(tempTeams.begin(), tempTeams.end(), name);
        tempTeams.erase(it);
        teams.push_back(team);
    }
    
    for(int i=0; i<10; i++){
        int random = rand()%numOfTeams;
        string name = tempTeams[random];
        Team* team = new Team(name);
        vector<string>::iterator it = find(tempTeams.begin(), tempTeams.end(), name);
        tempTeams.erase(it);
        teams.push_back(team);
    }
}








}