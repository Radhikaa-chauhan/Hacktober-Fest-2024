#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string computerChoice(){
    int randomNum=rand()%3;
    string choices[] = {"rock","paper","scissors"};
    return choices[randomNum];
}

string determineWinner(string player, string computer){
    if(player==computer){
        return "It is a tie!";
    }
    else if ((player=="rock"&&computer=="scissors")||(player=="paper"&&computer=="rock")||(player=="scissors"&&computer=="paper")){
        return "you win!";
    }
    else{
        return "computer wins!";
    }
}

int main(){
    srand(time(0));
    string playerChoice;
    string computerChoiceStr;
    cout << "Rock, Paper, Scissors!" << endl;
    cout << "Enter your choice (rock, paper or scissors): ";
    cin >> playerChoice;
    computerChoiceStr=computerChoice();
    cout << "Computer chose: " << computerChoiceStr << endl;
    string result=determineWinner(playerChoice, computerChoiceStr);
    cout << result << endl;
    return 0;
}