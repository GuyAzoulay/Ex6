#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include "Team.hpp"
//#pragma once
using namespace std;

namespace ex6{
    //class Team;
    /*
    this class represents a Game between two teams 
    and the winning team wil be the one with the highest score
    */
    class Game{
        private:
            Team* team1= new Team();
            Team* team2= new Team();
        public:

            Game(Team* team1, Team* team2){ // the first team will be the home team
                this->team1->setIsHomeTeam(true);
                this->team1=team1;
                this->team2=team2;
                
            }
           
            
                
            
                
            
            Team* &getTeam1();
            Team* &getTeam2();
            int goldenBall(Team* team);
            
            
            void play(); // in this funtion we will play the game and update the score of the teams
                         // maybe we will need to add some parameters to this function   
            
    
    };





}