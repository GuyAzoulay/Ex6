#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <time.h>
#pragma once
using namespace std;


namespace ex6{
// this class will represent a basketball team, every team will have unique name and talent level
//class Game; 
class Team {
    private:
    float talent;
    string name;
    int numOfVictories;
    int numOfDefeats;
    bool isHomeTeam;
    int TotalScore;
    int TotalScoreAgainst;
    int longestStreak;
    int longestLosingStreak;
    //int runningIndex = 0; // maybe I will add another parameter which will say that we are in 20 games
    vector<uint> result_list;
    public:
    Team(){
        this->name = "";
        this->talent = 0;
        this->numOfVictories = 0;
        this->numOfDefeats = 0;
        this->isHomeTeam = false;
        this->TotalScore = 0;
        this->result_list.reserve(20);
        this->TotalScoreAgainst = 0;
    }
    Team(string name){
        this->name = name;
        this->talent = this->randomTalent();
        this->numOfVictories = 0;
        this->numOfDefeats = 0;
        this->TotalScore = 0;
        bool isHomeTeam = false;
        this->result_list.reserve(20);
        this->TotalScoreAgainst = 0;
    }
    string getName();
    float getTalent();
    void setTalent(float talent);

    int getNumOfVictories();
    void setNumOfVictories(int numOfVictories);

    int getNumOfDefeats();
    void setNumOfDefeats(int numOfDefeats);
    
    
    bool getIsHomeTeam();
    void setIsHomeTeam(bool ishomeTeam);
    
    int getTotalScore();
    void setTotalScore(int TotalScore);

    vector<uint> getResult_list();
    void setResult(uint result_list);
    int getTotalScoreAgainst();
    void setTotalScoreAgainst(int TotalScoreAgainst);
   

 // write a function which will random score between 50 100
    int randomScoreNotHome();
    //write a function which will return random score between 55 and 100
    int randomScoreHome();
    float randomTalent();

    int getLongestStreak();
    void setLongestStreak(int longestStreak);
    int getLongestLosingStreak();
    void setLongestLosingStreak(int longestLosingStreak);
    void findLongestStreak();
    void findLongestLosingStreak();



};
}
