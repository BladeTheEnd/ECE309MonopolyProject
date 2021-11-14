#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <time.h> 

using namespace std;

class Board{
public: 
string boardSpaces[40];

Board(){
boardSpaces[0] = "Go!";
boardSpaces[1] = "Mediterannean Avenue";
boardSpaces[2] = "Community Chest 1";
boardSpaces[3] = "Baltic Avenue";
boardSpaces[4] = "Income Tax";
boardSpaces[5] = "Reading Railroad";
boardSpaces[6] = "Oriental Avenue";
boardSpaces[7] = "Chance 1";
boardSpaces[8] = "Vermont Avenue";
boardSpaces[9] = "Connecticut Avenue";
boardSpaces[10] = "Jail";
boardSpaces[11] = "St. Charles Place";
boardSpaces[12] = "Electric Company";
boardSpaces[13] = "States Avenue";
boardSpaces[14] = "Virginia Avenue";
boardSpaces[15] = "Pennsylvania Railroad";
boardSpaces[16] = "St. James Place";
boardSpaces[17] = "Community Chest 2";
boardSpaces[18] = "Tenessee Avenue";
boardSpaces[19] = "New York Avenue";
boardSpaces[20] = "Free Parking";
boardSpaces[21] = "Kentucky Avenue";
boardSpaces[22] = "Chance 2";
boardSpaces[23] = "Indiana Avenue";
boardSpaces[24] = "Illinois Avenue";
boardSpaces[25] = "B. & O Railroad";
boardSpaces[26] = "Atlantic Avenue";
boardSpaces[27] = "Ventnor Avenue";
boardSpaces[28] = "Water Works";
boardSpaces[29] = "Marvin Gardens";
boardSpaces[30] = "Go to Jail!";
boardSpaces[31] = "Pacific Avenue";
boardSpaces[32] = "North Carolina Avenue";
boardSpaces[33] = "Community Chest 3";
boardSpaces[34] = "Pennsylvania Avenue";
boardSpaces[35] = "Short Line Railroad";
boardSpaces[36] = "Chance 3";
boardSpaces[37] = "Park Place";
boardSpaces[38] = "Luxury Tax";
boardSpaces[39] = "Boardwalk";
}

};

class Player{
private:
    int position;
    int balance;

public:

    int turnsJail; // turns potentially spent in jail
    int jailOut; // has a get out of jail free card
    int jailFree;
    bool isComputer;
    int numDoubles;
    int numHouses;
    int numHotels;

    void getBalance(Player &positionPlayer)
    {
        cout << "position balance is: " << positionPlayer.balance << endl;
    }

void getPosition(Board &positionBoard)
{
	cout << positionBoard.boardSpaces[position] << endl;
}

void setComputer()
{
  isComputer = 1;
}

void rollDice(Board &positionBoard, int numPlayers, Player allPlayers[])
{
    int diceRoll1 = rand() % 6 + 1;
    int diceRoll2 = rand() % 6 + 1;
    
    if(diceRoll1 == diceRoll2)
    {
      numDoubles++;
    }
    else numDoubles = 0;
    
    if(numDoubles == 3)
    {
      position = 10;
      cout << "Three doubles rolled, go to jail!" << endl;
      numDoubles = 0;
    }
    else
    {
    position = position + diceRoll1 + diceRoll2;
    if(position >= 40)
    { 
      position = position - 40;
      balance = balance + 200;
    }
    }
    
    turnsJail =  jailCheck(currentBoard);
    getPosition(currentBoard);
    
    if(numDoubles) rollDice(positionBoard, numPlayers, allPlayers);
    
}

int jailCheck(Board &currentBoard) {
        if (position == 30) {
            position = 10;
            if (jailOut == 1) {
                jailOut = 0;
                return 0;
            }
            else{
                if(turnsJail != 0){
                    turnsJail = turnsJail - 1;
                    return turnsJail;
                }
                else
                    return 3;
            }
        }
        else
            return 0;
    }

void chanceCard(int numPlayers, Player allPlayers[])
{
  int chanceIndex = rand() % 16 + 1;
  
  switch(chanceIndex)
  {
      case 0:
      position = 39;
      break;
      
      case 1:
      position = 0;
      balance = balance + 200;
      break;
      
      case 2:
      if(position >= 25) balance = balance + 200;
      position = 24;
      break;
      
      case 3:
      if(position >= 12) balance = balance + 200;
      position = 11;
      break;
      
      case 4:
      if(position < 5 || position > 35)
      {
       position = 5;
       balance = balance + 200;
      }
      else if(position >= 5 && position < 15) position = 15;
      else if(position >= 15 && position < 25) position = 25;
      else position = 35;
      break;
      
      case 5:
      if(position < 5 || position > 35)
      {
       position = 5;
       balance = balance + 200;
      }
      else if(position >= 5 && position < 15) position = 15;
      else if(position >= 15 && position < 25) position = 25;
      else position = 35;
      break;
      
      case 6:
      if(position < 12) position = 12;
      else if(position >= 28)
      {
        position = 12;
        balance = balance + 200;
      }
      else position = 28;
      break;
      
      case 7:
      balance = balance + 50;
      break;
      
      case 8:
      jailFree = jailFree + 1;
      break;
      
      case 9:
      position = position - 3;
      break;
      
      case 10:
      position = 10;
      break;
      
      case 11:
      balance = balance - numHouses * 25;
      balance = balance - numHotels * 100;
      break;
      
      case 12:
      balance = balance - 15;
      break;
      
      case 13:
      if(position >= 6) balance = balance + 200;
      position = 5;
      break;
      
      case 14:
      for(int i = 0; i<numPlayers; i++)
      {
        allPlayers[i].balance = allPlayers[i].balance + 50;
      }
      balance = balance - 50*(numPlayers);
      break;
      
      case 15:
      balance = balance + 100;
      break;
  }
}

void chestCard(int numPlayers, Player allPlayers[])
{
  int chestIndex = rand() % 16 + 1;
  
  switch(chestIndex)
  {
      case 0:
      position = 0;
      balance = balance + 200;
      break;
      
      case 1:
      balance = balance + 200;
      break;
      
      case 2:
      balance = balance - 50;
      break;
      
      case 3:
      balance = balance + 50;
      break;
      
      case 4:
      jailFree = jailFree + 1;
      break;
      
      case 5:
      position = 10;
      break;
      
      case 6:
      balance = balance + 200;
      break;
      
      case 7:
      balance = balance + 20;
      break;
      
      case 8:
      for(int i = 0; i<numPlayers; i++)
      {
        allPlayers[i].balance = allPlayers[i].balance - 10;
      }
      balance = balance + 10*(numPlayers);
      break;
      
      case 9:
      balance = balance + 100;
      break;
      
      case 10:
      balance = balance - 100;
      break;
      
      case 11:
      balance = balance - 50;
      break;
      
      case 12:
      balance = balance - 25;
      break;
      
      case 13:
      balance = balance - numHouses * 40;
      balance = balance - numHotels * 115;
      break;
      
      case 14:
      balance = balance + 10;
      break;
      
      case 15:
      balance = balance + 100;
      break;
  }
  
}

Player()
{
  isComputer = 0;
  position = 0;
  numDoubles = 0;
  balance = 1500;
  numHotels = 0;
  numHouses = 0;
  jailFree = 0;
}
};











