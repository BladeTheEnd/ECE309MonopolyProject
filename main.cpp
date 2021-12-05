/*
-------------------------------------------------------------------
                      ECE 309 Final Project
-------------------------------------------------------------------
Authors: Neal Desai, Jackson Norris
Purpose: This is our submission for the ECE 309 Final Project. Our
objective was to allow the user to play a game of Monopoly through
the command line. This was a large venture, so we made some 
simplifications, which are:
*The chance and chest deck are shuffled after each use.
*A player may only make actions AFTER they have
expended all possible moves.
*The number of hotels/houses is limited like a real Monopoly game.

At several times, the user is required to input commands to take.
We have tried to be as clear as possible, but there are still 
somethings that may be a little confusing. The README included
in the repository will help to clear some things up that we
believe may still be confusing.
-------------------------------------------------------------------
*/

#include "Monopoly.h"

int main ()
{

//Start the time seed
srand(time(NULL));


Board currentBoard; //Declares the board object that the game takes place on.
int numPlayers; //Number of participants.
bool computerGame = 0; //Used later to determine if the game will be played by only computers.

//Prompt the user for input. We are expecting them to input 0 or a positive number. In the case of an invalid input, it will just play a PC game. 
cout << "Welcome to Monopoly: ECE 309 version! Please enter the number of players that will be playing." << endl << "There will be a PC player who joins you. If you want to spectate a game of 4 PC players, enter 0. If input is invalid, a PC game will occur." << endl;
cin >> numPlayers;

//Lets us know we need to make a game of 4 computer players.
if(numPlayers == 0 || numPlayers < 0) 
{
cout << "Preparing Computer Game." << endl;
numPlayers = 4;
computerGame = 1;
}
else numPlayers++; //If the game is not a PC game, there is one PC player that will tag along with the other 

Player allPlayers[numPlayers]; //creates our player array.

if(computerGame) //if the game is a computer game, this sets the computer bit on all players in the array.
{
  for(int i = 0; i<numPlayers; i++)
  {
    allPlayers[i].setComputer();
  }
}
else allPlayers[numPlayers-1].setComputer(); //sets the computer bit on the last player in the array.

for(int i = 0; i<numPlayers; i++) //We have two methods of ownership that we use. One is an assigned number, the other is a stored vector. This will help us for later when indexing into the player array, as well as setting up ownership.
{
  allPlayers[i].assignedNumber = i+1;
}

for(int i = 0; i<1000; i++) //this is the loop that facilitates gameplay. It will go on until there is just one character whose game over boolean is not set.
{
  for(int j = 0; j<numPlayers; j++)
  {
    cout << "It is player " << j+1 << "'s turn!" << endl;
    allPlayers[j].rollDice(currentBoard, numPlayers, allPlayers); //This function houses everything that matters when it comes to interacting with the board and moving.
    allPlayers[j].actionMenu(currentBoard, allPlayers[j], allPlayers, numPlayers); //This function gives the player the option to do several actions you may take in a turn of Monopoly.
  }
}

return 0;
}