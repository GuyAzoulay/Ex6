#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Game.hpp"

using namespace std;
namespace ex6{

    Team* &Game::getTeam1(){
                return team1;
            }
    Team* &Game::getTeam2(){
                return team2;
            }


    int Game::goldenBall(Team* team) {
        // in case of tie, the golden ball will be the one with the highest score
        // every team will throw the ball 3 times and the team with the highest score will get the golden ball
        // the golden ball will be the one with the highest score

        int score = 0;
        for(int i=0; i<3; i++){
            score += rand()%2;
        }
        return score;
    }       
    void Game::play(){
        if(team1->getIsHomeTeam() == true && team1->getTalent() > team2->getTalent()){
                int randome_score_team1 = team1->randomScoreHome();
                int randome_score_team2 = team2->randomScoreNotHome();
                team1->setTotalScore(team1->getTotalScore()+randome_score_team1+10); // need to check if it is relevant
                team2->setTotalScore(team2->getTotalScore()+randome_score_team2);
                team1->setTotalScoreAgainst(team1->getTotalScoreAgainst()+randome_score_team2);
                team2->setTotalScoreAgainst(team2->getTotalScoreAgainst()+randome_score_team1);
                if(randome_score_team1 + 10 > randome_score_team2){
                    team1->setNumOfVictories(team1->getNumOfVictories()+1);
                    team2->setNumOfDefeats(team2->getNumOfDefeats()+1);  
                    team1->setResult(1);
                    team2->setResult(0);
                    
                   

                }
                else if(randome_score_team1 + 10 == randome_score_team2){
                    int golden_ball_team1 = goldenBall(team1);
                    int golden_ball_team2 = goldenBall(team2);
                    if(golden_ball_team1 > golden_ball_team2){
                        team1->setNumOfVictories(team1->getNumOfVictories()+1);
                        team2->setNumOfDefeats(team2->getNumOfDefeats()+1);
                        team1->setResult(1);
                        team2->setResult(0);
                    }
                    else if(golden_ball_team1 < golden_ball_team2){
                        team1->setNumOfDefeats(team1->getNumOfDefeats()+1);
                        team2->setNumOfVictories(team2->getNumOfVictories()+1);
                        team1->setResult(0);
                        team2->setResult(1);
                    }
                    else{
                        //if after the teams throw the ball, they have the same score
                        // than both of them will lose in the game
                        team1->setNumOfDefeats(team1->getNumOfDefeats()+1);
                        team2->setNumOfDefeats(team1->getNumOfDefeats()+1);
                        team1->setResult(0);
                        team2->setResult(0);
                    }
                    
                }
                else{
                    team1->setNumOfDefeats(team1->getNumOfDefeats()+1);
                    team2->setNumOfVictories(team2->getNumOfVictories()+1);
                    team1->setResult(0);
                    team2->setResult(1);
                }
                
            }

            else if(team1->getIsHomeTeam() == true && team1->getTalent() < team2->getTalent()){
                int randome_score_team1 = team1->randomScoreHome();
                int randome_score_team2 = team2->randomScoreNotHome();
                team1->setTotalScore(team1->getTotalScore()+randome_score_team1);
                team2->setTotalScore(team2->getTotalScore()+randome_score_team2+10);
                 team1->setTotalScoreAgainst(team1->getTotalScoreAgainst()+randome_score_team2);
                team2->setTotalScoreAgainst(team2->getTotalScoreAgainst()+randome_score_team1);
                if(randome_score_team1 > randome_score_team2+10){
                    team1->setNumOfVictories(team1->getNumOfVictories()+1);
                    team2->setNumOfDefeats(team2->getNumOfDefeats()+1); 
                    team1->setResult(1);
                    team2->setResult(0);
                }
                else if(randome_score_team1 == randome_score_team2+10){
                    int golden_ball_team1 = goldenBall(team1);
                    int golden_ball_team2 = goldenBall(team2);
                    if(golden_ball_team1 > golden_ball_team2){
                        team1->setNumOfVictories(team1->getNumOfVictories()+1);
                        team2->setNumOfDefeats(team2->getNumOfDefeats()+1);
                        team1->setResult(1);
                        team2->setResult(0);
                    }
                    else if(golden_ball_team1 < golden_ball_team2){
                        team1->setNumOfDefeats(team1->getNumOfDefeats()+1);
                        team2->setNumOfVictories(team2->getNumOfVictories()+1);
                        team1->setResult(0);
                        team2->setResult(1);
                    }
                    else{
                        //if after the teams throw the ball, they have the same score
                        // than both of them will lose in the game
                        team1->setNumOfDefeats(team1->getNumOfDefeats()+1);
                        team2->setNumOfDefeats(team1->getNumOfDefeats()+1);
                        team1->setResult(0);
                        team2->setResult(0);
                    }
                    
                }
                else{
                    team1->setNumOfDefeats(team1->getNumOfDefeats()+1);
                    team2->setNumOfVictories(team2->getNumOfVictories()+1);
                    team1->setResult(0);
                    team2->setResult(1);
                }
                
            }

            else if(team1->getIsHomeTeam() == false && team1->getTalent()>team2->getTalent()){
                int randome_score_team1 = team1->randomScoreNotHome();
                int randome_score_team2 = team2->randomScoreHome();
                team1->setTotalScore(team1->getTotalScore()+randome_score_team1+10);
                team2->setTotalScore(team2->getTotalScore()+randome_score_team2);
                 team1->setTotalScoreAgainst(team1->getTotalScoreAgainst()+randome_score_team2);
                team2->setTotalScoreAgainst(team2->getTotalScoreAgainst()+randome_score_team1);
                if(randome_score_team1+10 > randome_score_team2){
                    team1->setNumOfVictories(team1->getNumOfVictories()+1);
                    team2->setNumOfDefeats(team2->getNumOfDefeats()+1);
                    team1->setResult(1);
                    team2->setResult(0);

                }
                 else if(randome_score_team1+10 == randome_score_team2){
                    int golden_ball_team1 = goldenBall(team1);
                    int golden_ball_team2 = goldenBall(team2);
                    if(golden_ball_team1 > golden_ball_team2){
                        team1->setNumOfVictories(team1->getNumOfVictories()+1);
                        team2->setNumOfDefeats(team2->getNumOfDefeats()+1);
                        team1->setResult(1);
                        team2->setResult(0);
                    }
                    else if(golden_ball_team1 < golden_ball_team2){
                        team1->setNumOfDefeats(team1->getNumOfDefeats()+1);
                        team2->setNumOfVictories(team2->getNumOfVictories()+1);
                        team1->setResult(0);
                        team2->setResult(1);
                    }
                    else{
                        //if after the teams throw the ball, they have the same score
                        // than both of them will lose in the game
                        team1->setNumOfDefeats(team1->getNumOfDefeats()+1);
                        team2->setNumOfDefeats(team1->getNumOfDefeats()+1);
                        team1->setResult(0);
                        team2->setResult(0);
                    }
               
                 }
                else{
                    team1->setNumOfDefeats(team1->getNumOfDefeats()+1);
                    team2->setNumOfVictories(team2->getNumOfVictories()+1);
                    team1->setResult(0);
                    team2->setResult(1);


                }
            }
            else if(team1->getIsHomeTeam() == false && team1->getTalent()<team2->getTalent()){
                int randome_score_team1 = team1->randomScoreNotHome();
                int randome_score_team2 = team2->randomScoreHome();
                team1->setTotalScore(team1->getTotalScore()+randome_score_team1);
                team2->setTotalScore(team2->getTotalScore()+randome_score_team2+10);
                 team1->setTotalScoreAgainst(team1->getTotalScoreAgainst()+randome_score_team2);
                team2->setTotalScoreAgainst(team2->getTotalScoreAgainst()+randome_score_team1);
                if(randome_score_team1 > randome_score_team2+10){
                    team1->setNumOfVictories(team1->getNumOfVictories()+1);
                    team2->setNumOfDefeats(team2->getNumOfDefeats()+1); 
                    team1->setResult(1);
                    team2->setResult(0);
     
                }
                 else if(randome_score_team1 == randome_score_team2+10){
                    int golden_ball_team1 = goldenBall(team1);
                    int golden_ball_team2 = goldenBall(team2);
                    if(golden_ball_team1 > golden_ball_team2){
                        team1->setNumOfVictories(team1->getNumOfVictories()+1);
                        team2->setNumOfDefeats(team2->getNumOfDefeats()+1);
                        team1->setResult(1);
                        team2->setResult(0);
                    }
                    else if(golden_ball_team1 < golden_ball_team2){
                        team1->setNumOfDefeats(team1->getNumOfDefeats()+1);
                        team2->setNumOfVictories(team2->getNumOfVictories()+1);
                        team1->setResult(0);
                        team2->setResult(1);
                    }
                    else{
                        //if after the teams throw the ball, they have the same score
                        // than both of them will lose in the game
                        team1->setNumOfDefeats(team1->getNumOfDefeats()+1);
                        team2->setNumOfDefeats(team1->getNumOfDefeats()+1);
                        team1->setResult(0);
                        team2->setResult(0);
                    }
               
                  
                 }
                else{
                    team1->setNumOfDefeats(team1->getNumOfDefeats()+1);
                    team2->setNumOfVictories(team2->getNumOfVictories()+1);
                    team1->setResult(0);
                    team2->setResult(1);
   
                }
            }

            else if(team1->getIsHomeTeam() == true && team1->getTalent()==team2->getTalent()){

                int randome_score_team1 = team1->randomScoreHome();
                int randome_score_team2 = team2->randomScoreNotHome();
                team1->setTotalScore(team1->getTotalScore()+randome_score_team1);
                team2->setTotalScore(team2->getTotalScore()+randome_score_team2);
                 team1->setTotalScoreAgainst(team1->getTotalScoreAgainst()+randome_score_team2);
                team2->setTotalScoreAgainst(team2->getTotalScoreAgainst()+randome_score_team1);
                if(randome_score_team1 > randome_score_team2){
                    team1->setNumOfVictories(team1->getNumOfVictories()+1);
                    team2->setNumOfDefeats(team2->getNumOfDefeats()+1); 
                    team1->setResult(1);
                    team2->setResult(0);
     
                }
                 else if(randome_score_team1 == randome_score_team2){
                    int golden_ball_team1 = goldenBall(team1);
                    int golden_ball_team2 = goldenBall(team2);
                    if(golden_ball_team1 > golden_ball_team2){
                        team1->setNumOfVictories(team1->getNumOfVictories()+1);
                        team2->setNumOfDefeats(team2->getNumOfDefeats()+1);
                        team1->setResult(1);
                        team2->setResult(0);
                    }
                    else if(golden_ball_team1 < golden_ball_team2){
                        team1->setNumOfDefeats(team1->getNumOfDefeats()+1);
                        team2->setNumOfVictories(team2->getNumOfVictories()+1);
                        team1->setResult(0);
                        team2->setResult(1);
                    }
                    else{
                        //if after the teams throw the ball, they have the same score
                        // than both of them will lose in the game
                        team1->setNumOfDefeats(team1->getNumOfDefeats()+1);
                        team2->setNumOfDefeats(team1->getNumOfDefeats()+1);
                        team1->setResult(0);
                        team2->setResult(0);
                    }
               
                  
             
                 }
                else{
                    team1->setNumOfDefeats(team1->getNumOfDefeats()+1);
                    team2->setNumOfVictories(team2->getNumOfVictories()+1);
                    team1->setResult(0);
                    team2->setResult(1);
    
                }
            }
            else if(team1->getIsHomeTeam() == false && team1->getTalent()==team2->getTalent()){
                int randome_score_team1 = team1->randomScoreNotHome();
                int randome_score_team2 = team2->randomScoreHome();
                team1->setTotalScore(team1->getTotalScore()+randome_score_team1);
                team2->setTotalScore(team2->getTotalScore()+randome_score_team2);
                 team1->setTotalScoreAgainst(team1->getTotalScoreAgainst()+randome_score_team2);
                team2->setTotalScoreAgainst(team2->getTotalScoreAgainst()+randome_score_team1);
                if(randome_score_team1 > randome_score_team2){
                    team1->setNumOfVictories(team1->getNumOfVictories()+1);
                    team2->setNumOfDefeats(team2->getNumOfDefeats()+1); 
                    team1->setResult(1);
                    team2->setResult(0);
    
                }
                 else if(randome_score_team1 == randome_score_team2){
                    int golden_ball_team1 = goldenBall(team1);
                    int golden_ball_team2 = goldenBall(team2);
                    if(golden_ball_team1 > golden_ball_team2){
                        team1->setNumOfVictories(team1->getNumOfVictories()+1);
                        team2->setNumOfDefeats(team2->getNumOfDefeats()+1);
                        team1->setResult(1);
                        team2->setResult(0);
                    }
                    else if(golden_ball_team1 < golden_ball_team2){
                        team1->setNumOfDefeats(team1->getNumOfDefeats()+1);
                        team2->setNumOfVictories(team2->getNumOfVictories()+1);
                        team1->setResult(0);
                        team2->setResult(1);
                    }
                    else{
                        //if after the teams throw the ball, they have the same score
                        // than both of them will lose in the game
                        team1->setNumOfDefeats(team1->getNumOfDefeats()+1);
                        team2->setNumOfDefeats(team1->getNumOfDefeats()+1);
                        team1->setResult(0);
                        team2->setResult(0);
                    }
                 }
                else{
                    team1->setNumOfDefeats(team1->getNumOfDefeats()+1);
                    team2->setNumOfVictories(team2->getNumOfVictories()+1);
                    team1->setResult(0);
                    team2->setResult(1);
  
                } 

            }
    }        

}