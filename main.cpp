#include "Monopoly.h"

int main ()
{

srand(time(NULL));

Board currentBoard;
int numPlayers;
bool computerGame = 0;

cout << "Welcome to Monopoly: ECE 309 version! Please enter the number of players that will be playing." << endl << "There will be a PC player who joins you. If you want to spectate a game of 4 PC players, enter 0." << endl;
cin >> numPlayers;

if(numPlayers == 0) 
{
numPlayers = 4;
computerGame = 1;
}
else numPlayers++;

Player allPlayers[numPlayers];

if(computerGame)
{
  for(int i = 0; i<numPlayers; i++)
  {
    allPlayers[i].setComputer();
  }
}
else allPlayers[numPlayers-1].setComputer();

for(int i = 0; i<numPlayers; i++)
{
  allPlayers[i].assignedNumber = i+1;
}

for(int i = 0; i<1000; i++)
{
  for(int j = 0; j<numPlayers; j++)
  {
    if(allPlayers[j].isComputer == 1) cout << "This is a computer!" << endl;
    else cout << "This is player " << j+1 << "!" << endl;
    allPlayers[j].rollDice(currentBoard, numPlayers, allPlayers);
    allPlayers[j].actionMenu(currentBoard, allPlayers[j]);
  }
}

return 0;
}