#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;
fstream file;
string firstPName = "Guest1", secondPName= "Guest2", matchTitle= "Dart Mutch";

int 
firstPScore=501, //first player score
secondPScore=501, //second player score
someOfDarts=0, //some of darts of every player 3 shot
ruleFirstTo=5, //rule first to (max of legs)
playFirstLeg=0, //who play first
playFirst=0,
leg=1, //number of leg (first leg, second leg...)
firstPLegWin=0, //legs wins by first player
secondPLegWin=0; //legs wins by second player

void newLeg(string& pNameFirstGameOn) {
        firstPScore = 501;
        secondPScore = 501;
        cout << "----------Leg " << leg << "-----------\n";
        cout << "Leg " << leg << " " << pNameFirstGameOn << " is first game on.\n";
        cout << firstPName << " score is " << firstPScore << endl;
        cout << secondPName << " score is " << secondPScore << endl;
}

void PSome(string& pName, int& pScore, int& pLegWin)
{
    cout << "some of darts of " << pName << " is: ";
    cin >> someOfDarts;
    cin.ignore(1000,'\n');
    if((pScore-someOfDarts) > 0 && (pScore-someOfDarts)  != 1)
    {
        pScore -= someOfDarts;
        cout << pName << " score is " << pScore << endl;
    }
    else if ((pScore-someOfDarts) == 1 || (pScore-someOfDarts) < 0)
    {
        cout << " No score " << endl;
        cout << pName << " score is " << pScore << endl;
    }
    else if ((pScore-someOfDarts) == 0)
    {
        pLegWin += 1;
        cout << "Game shot " <<"Leg " << leg << " " << pName << ".\n";
        
        leg += 1;
        if (playFirstLeg == 1)
        {
            if (leg &1) {playFirst = 1; newLeg(firstPName);}
            else {playFirst = 2; newLeg(secondPName);}
        }
        else if (playFirstLeg == 2)
        {
            if (leg &1) {playFirst = 2; newLeg(secondPName);}
            else {playFirst = 2; newLeg(firstPName);}
        }
    }
}

void startPlay()
{
    playFirst = playFirstLeg;
    
    while (ruleFirstTo != firstPLegWin && ruleFirstTo != secondPLegWin)
    {
        if(playFirst==1) 
        {
            playFirst=2;
            PSome(firstPName, firstPScore, firstPLegWin);
        } 
        else if (playFirst==2)
        {
            playFirst=1;
            PSome(secondPName, secondPScore, secondPLegWin);
        } 
        else 
        {
            cout << "you write wrong play first!";
        }
    }
    
    if(ruleFirstTo == firstPLegWin) cout << "Game shot and match " << firstPName << "\n";
    if(ruleFirstTo == secondPLegWin) cout << "Game shot and match " << secondPName << "\n";
}



int main(int argc, char const *argv[])
{
    string fName, sName;
    file.open("dartmutch.txt",ios::app);
    file << "if you found me in a file.txt so you win \n";
    if(!file) { cout<<"Error in creating file!!!";  return 0;} 
    file.close();
    cout << "Please enter the mutch title: ";
    getline(cin, matchTitle);
    cout << "\n";
    file.open("dartmutch.txt",ios::app);
    file << "--------- " << matchTitle << " ---------\n";
    if(!file) { cout<<"Error in creating file!!!"; return 0;} 
    file.close();
    cout << "Please enter the Rule First to: ";
    cin >> ruleFirstTo;
    cin.ignore(1000, '\n');
    cout << "\n";
    cout << "please enter first player name: \n";
    getline(cin, fName);
    if(fName != "") firstPName = fName;
    cout << "\n";
    cout << "please enter second player name: \n";
    getline(cin, secondPName);
    if(sName != "") secondPName = sName;
    cout << "\n";
    cout << "Who plays first? \n";
    cout << "If " << firstPName << " will play first please type 1:\n";
    cout << "If " << secondPName << " will play first please type 2:\n";
    cin >> playFirstLeg;
    cin.ignore(1000, '\n');
    cout << "\n";
    startPlay();
    
    return 0;
}
