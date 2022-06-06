#include <iostream>
#include <string>
#include <vector>
#include "Team.hpp"
using namespace std;
namespace ex6{

// int Team::getRunningIndex(){
//     return runningIndex;
// }
// void Team::setRunningIndex(){
//     this->runningIndex++;
// }


int Team::randomScoreNotHome(){
    int score;
    score = rand()%51+50;
    return score;
    }
    
int Team::randomScoreHome(){
    int talent;
    talent = rand()%46+55;
    return talent;
        }

float Team::randomTalent(){
    return rand()%11/10.0;
    }


string Team::getName(){
        return name;
    }
    float Team::getTalent(){
        return talent;
    }
    void Team::setTalent(float talent){
        this->talent = talent;
    }

    int Team::getNumOfVictories(){
        return numOfVictories;
    }
    void Team::setNumOfVictories(int numOfVictories){
        this->numOfVictories = numOfVictories;
    }

    int Team::getNumOfDefeats(){
        return numOfDefeats;
    }
    void Team::setNumOfDefeats(int numOfDefeats){
        this->numOfDefeats = numOfDefeats;
    }
    
   
    
    bool Team::getIsHomeTeam(){
        return isHomeTeam;
    }
    void Team::setIsHomeTeam(bool ishomeTeam){
        this->isHomeTeam = ishomeTeam;
    }
    
    int Team::getTotalScore(){
        return TotalScore;
    }
    void Team::setTotalScore(int TotalScore){
        this->TotalScore = TotalScore;
    }
    vector<uint> Team::getResult_list(){
        return result_list;
    }
    
    void Team::setResult(uint result_list){
        this->result_list.push_back(result_list);
    }    
    int Team::getTotalScoreAgainst(){
        return TotalScoreAgainst;
    }
    void Team::setTotalScoreAgainst(int TotalScoreAgainst){
        this->TotalScoreAgainst = TotalScoreAgainst;
    }

    int Team::getLongestStreak(){
        return longestStreak;
    }
    void Team::setLongestStreak(int longestStreak){
        this->longestStreak = longestStreak;
    }
    int Team::getLongestLosingStreak(){
        return longestLosingStreak;
    }
    void Team::setLongestLosingStreak(int longestLosingStreak){
        this->longestLosingStreak = longestLosingStreak;
    }



    void Team::findLongestStreak(){
        int longestStreak = 0;
        int longestLosingStreak = 0;
        int currentStreak = 0;
        int currentLosingStreak = 0;
        for(int i = 0; i < result_list.size(); i++){
            if(result_list[i] == 1){
                currentStreak++;
                if(currentStreak > longestStreak){
                    longestStreak = currentStreak;
                }
                currentLosingStreak = 0;
            }
            else{
                currentStreak = 0;
                currentLosingStreak++;
                if(currentLosingStreak > longestLosingStreak){
                    longestLosingStreak = currentLosingStreak;
                }
            }
        }
        this->setLongestStreak(longestStreak);
    }
    void Team::findLongestLosingStreak(){
        int longestStreak = 0;
        int longestLosingStreak = 0;
        int currentStreak = 0;
        int currentLosingStreak = 0;
        for(int i = 0; i < result_list.size(); i++){
            if(result_list[i] == 1){
                currentStreak++;
                if(currentStreak > longestStreak){
                    longestStreak = currentStreak;
                }
                currentLosingStreak = 0;
            }
            else{
                currentStreak = 0;
                currentLosingStreak++;
                if(currentLosingStreak > longestLosingStreak){
                    longestLosingStreak = currentLosingStreak;
                }
            }
        }
        this->setLongestLosingStreak(longestLosingStreak);
    }

    
}