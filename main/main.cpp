
#include "main.h"

vector<Score> score;

int main(){
    srand(time(0));
    while(1){
        char numa, numb;
        GetScore();
        cout << "=============================\nTIC-TAC-TOE\n";
        cout << "Select gamemode : \n1.|Play\n2.|Play with a bot\n3.|Scoreboard\n4.|Exit\n\n- ";
        numa = char(getchar());
        buffer;
        switch(numa){
            case '1':
                Game('0');
                break;
            case '2':
                cout << "=============================\nTIC-TAC-TOE\n";
                cout << "1.|Easy Bot\n2.|Hard Bot\n3.|Back\n\n- ";
                numb = char(getchar());
                buffer;
                if(numb == '1' || numb == '2') Game(numb);
                break;
            case '3':
                ScoreBoard();
                break;
            case '4':
                return 0;
        }
        SetScore();
    }
}

void Game(char bot){
    bool status = 1;
    char winner, opt, gridnum;
    string pX, pO;
    while(status){
        winner = 0;
        ShowBoard();
        if(bot == '1' || bot == '2') cout << "\nIt's your turn : ";
        else cout << "\n" << turn << "'s turn : ";
        gridnum = char(getchar());
        buffer;
        if(isdigit(gridnum) && Num_Check(gridnum)){
            winner = Winner();
            if(bot == '1' || bot == '2'){
                if(winner == 0 && !Draw()){
                    if(bot == '1') Easy_Bot();
                    else Hard_Bot();
                    winner = Winner();
                }
            }
            else{
                if(turn == 'X') turn = 'O';
                else turn = 'X';
            }
        }
        else{
            cout << "\nPlease choose a number on the grid!\n";
            gridnum = '0';
        }
        if(Draw() || winner != 0){
            cout << '\n';
            ShowBoard();
            Reset();
            if(winner == 'X') X++;
            if(winner == 'O') O++;
            if(winner != 0) cout << "\nPlayer " << winner << " wins."; 
            else{
                X += 0.5;
                O += 0.5;
                cout << "\nIt's a draw.";
            }
            cout << "\nDo you want to play again? y/n\n- ";
            opt = char(getchar());
            buffer;
            if(opt != 'y'){
                opt = 0;
                cout << "\nDo you want to save the score? y/n\n- ";
                opt = char(getchar());
                buffer;
                if(opt == 'y'){
                    if(bot == '0'){
                    cout << "\nInsert Player X's name : ";
                    getline(cin, pX);
                    cout << "\nInsert Player O's name : ";
                    getline(cin, pO);
                    }
                    else{
                        cout << "\nInsert Player's name : ";
                        getline(cin, pX);
    	                if(bot == '1') pO = "Easy Bot";
                        else if(bot == '2') pO = "Hard Bot";
                        else pO = "Bot";
                    }
                    score.push_back({X, O, pX, pO});
                    cout << "\nScore saved!\n";
                }
                X = 0;
                O = 0;
                status = 0;
            }
        }
    }
}

void ShowBoard(){
    cout << "\n=============================\nTIC-TAC-TOE\n";
    cout << "| O : " << O << " | X : " << X << " |\n\n";
    for(int i = 0; i < 3; i++){
        for(int l = 0; l < 3; l++){
            cout << grid[i][l];
            if(l != 2) cout << " | ";
            else cout << "\n";
        }
        if(i != 2) cout << "--+---+--\n";
    }
}

void Reset(){
    char num = '1';
    for(auto& i : grid){
        for(auto& k : i){
            k = num;
            num++;
        }
    }
    turn = 'X';
}

bool Num_Check(char& gridnum){
    int num = int(gridnum - '0');
    bool valid;
    try{
        if(num == 0) throw "\nInvalid number!\n";
        for(auto& i : grid){
            for(auto& k : i){
                if(num == k - '0') {
                    k = turn;
                    valid = 1;
                }
            }
        }
        if(!valid){
            string err = "\nThe grid is taken!\n";
            throw err;
        }
        return 1;
    }
    catch(string err) {cout << err;}
    return 0;
}

char Winner(){
    for(int i = 0; i < 3; i++){
        if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) return grid[i][0];
        if(grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) return grid[0][i];
    }
    if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) return grid[1][1];
    if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) return grid[1][1];
    return 0;
}

bool Draw(){
    for(auto& i : grid){
        for(auto& k : i){
            if(isdigit(k)) return 0;
        }
    }
    return 1;
}

void Easy_Bot(){
    int choice, loop = 1;
    while(loop == 1){
        choice = (rand() % 9) + 1;
        for(auto& i : grid){
            for(auto& k : i){
                if(choice == k - '0') {
                    k = 'O';
                    loop = 0;
                }
            }
        }
    }
}

void Hard_Bot(){
    int choice, loop = 1;
    try{
        for(int i = 0; i < 3; i++){
            if(grid[i][1] == grid[i][2] && isdigit(grid[i][0])) throw index {i,0};
            if(grid[i][0] == grid[i][2] && isdigit(grid[i][1])) throw index {i,1};
            if(grid[i][0] == grid[i][1] && isdigit(grid[i][2])) throw index {i,2};
            if(grid[1][i] == grid[2][i] && isdigit(grid[0][i])) throw index {0,i};
            if(grid[0][i] == grid[2][i] && isdigit(grid[1][i])) throw index {1,i};
            if(grid[0][i] == grid[1][i] && isdigit(grid[2][i])) throw index {2,i};
        }
        if(grid[1][1] == grid[2][2] && isdigit(grid[0][0])) throw index {0,0};
        if(grid[0][0] == grid[2][2] && isdigit(grid[1][1])) throw index {1,1};
        if(grid[0][0] == grid[1][1] && isdigit(grid[2][2])) throw index {2,2};
        if(grid[1][1] == grid[2][0] && isdigit(grid[0][2])) throw index {0,2};
        if(grid[0][2] == grid[2][0] && isdigit(grid[1][1])) throw index {1,1};
        if(grid[0][2] == grid[1][1] && isdigit(grid[2][0])) throw index {2,0};
        while(loop == 1){
            choice = (rand() % 9) + 1;
            for(auto& i : grid){
                for(auto& k : i){
                    if(choice == k - '0') {
                        k = 'O';
                        loop = 0;
                    }
                }
            }
        }
    }
    catch(struct index& i){
        grid[i.a][i.b] = 'O';
    }
}

void ScoreBoard(){
    char opt, answer;
    int num = 0;
    cout << "\n=============================\n";
    if(score.size() != 0){
        for(Score& i : score){
            num++;
            cout << num << ".| " << i.GetName('X') << " (X) | " << i.GetScore('X') << " : " << i.GetScore('O') << " | (O) " << i.GetName('O') << endl;
        }
        cout << "_________________\n";
        cout << "1.|Delete Score\n2.|Clear Score\n3.|Back\n\n- ";
        opt = char(getchar());
        buffer;
        switch(opt){
            case '1':
                DelScore();
                break;
            case '2':
                cout << "\nAre you sure you want to clear the scoreboard? y/n\n- ";
                answer = char(getchar());
                buffer;
                if(answer == 'y') score.clear();
        }
    }
    else cout << "There is no saved score!\n\n";
}

void SetScore(){
    fstream sX, sO, nX, nO;
    vector<Score>::iterator it = score.begin();
    sX.open("Score/tScore_X.txt", ios::out);
    sO.open("Score/tScore_O.txt", ios::out);
    nX.open("Score/tName_X.txt", ios::out);
    nO.open("Score/tName_O.txt", ios::out);
    for(Score& i : score){
        if(it != score.begin()){
            sX << endl;
            sO << endl;
            nX << endl;
            nO << endl;
        }
        sX << i.GetScore('X');
        sO << i.GetScore('O');
        nX << i.GetName('X');
        nO << i.GetName('O');
        it++;
    }
    sX.close();
    sO.close();
    nX.close();
    nO.close();
    remove("Score/Score_X.txt");
    remove("Score/Score_O.txt");
    remove("Score/Name_X.txt");
    remove("Score/Name_O.txt");
    rename("Score/tScore_X.txt", "Score/Score_X.txt");
    rename("Score/tScore_O.txt", "Score/Score_O.txt");
    rename("Score/tName_X.txt", "Score/Name_X.txt");
    rename("Score/tName_O.txt", "Score/Name_O.txt");
}

void GetScore(){
    vector<string> sX, sO, nX, nO;
    fstream FsX, FsO, FnX, FnO;
    string TsX, TsO, TnX, TnO;
    score.clear();
    FsX.open("Score/Score_X.txt", ios::in);
    FsO.open("Score/Score_O.txt", ios::in);
    FnX.open("Score/Name_X.txt", ios::in);
    FnO.open("Score/Name_O.txt", ios::in);
    while(getline(FsX, TsX)) sX.push_back(TsX);
    while(getline(FsO, TsO)) sO.push_back(TsO);
    while(getline(FnX, TnX)) nX.push_back(TnX);
    while(getline(FnO, TnO)) nO.push_back(TnO);
    for(int i = 0; i < sX.size(); i++) score.push_back({stod(sX[i]), stod(sO[i]), nX[i], nO[i]});
}

void DelScore(){
    string num;
    cout << "Enter the number of the score : ";
    num = char(getchar());
    buffer;
    if(Digit(num)){
        if(stoi(num) > 0 && stoi(num) <= score.size() + 1){
            score.erase(score.begin() + stoi(num) - 1);
        }
    }
}

bool Digit(string num){
    for(char& i : num){
        if(!isdigit(i)) return 0;
    }
    return 1;
}