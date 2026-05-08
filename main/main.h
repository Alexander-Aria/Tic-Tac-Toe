#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <vector>
#define buffer cin.ignore(10000, '\n')
using namespace std;

bool Num_Check(char& num), Digit(string num), Draw();
void Game(char numb), Reset(), ShowBoard(), Easy_Bot(), Hard_Bot(), ScoreBoard(), SetScore(), GetScore(), DelScore();
char Winner();

char grid[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'X';
double O = 0, X = 0;

struct index{
    int a, b;
};

class Score{
    double sX, sO;
    string nX, nO;
    public:
    Score(double sa, double sb, string na, string nb) : sX(sa), sO(sb), nX(na), nO(nb){}
    int GetScore(char x){
        if(x == 'X') return sX;
        if(x == 'O') return sO;
        return 0;
    }
    string GetName(char x){
        if(x == 'X') return nX;
        if(x == 'O') return nO;
        return "-";
    }
};