#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <time.h> 

using namespace std;

class Property{
public:
    string name;
    int price;
    string color;
    int rent;
    int rent1House;
    int rent2House;
    int rent3House;
    int rent4House;
    int rentHotel;
    bool isMortgaged;
    int mortgageValue;
    bool isChest;
    bool isChance;
    bool isTax;
    bool isParking;
    bool isGo;
    bool isRailroad;
    bool isUtility;
    bool isJail;
    int buyHouse;
    int numHouses;
    int numHotels;
    int ownerNumber;

    Property(){
         price = 0;
         isMortgaged = 0;
         mortgageValue = 0;
         isChest = 0;
         isChance = 0;
         isTax = 0;
         isParking = 0;
         isGo = 0;
         isRailroad = 0;
         isUtility = 0;
         isJail = 0;
         rent = 0;
         rent1House = 0;
         rent2House = 0;
         rent3House = 0;
         rent4House = 0;
         rentHotel = 0;
         buyHouse = 0;
         numHotels = 0;
         ownerNumber = 0;
    }
};


class Board: Property{
public:
    Property BoardSpaces[40];

    Board(){
        BoardSpaces[0].name = "Go!";
        BoardSpaces[0].isGo = 1;

        BoardSpaces[1].name = "Mediterranean Avenue";
        BoardSpaces[1].price = 60;
        BoardSpaces[1].color = "Brown";
        BoardSpaces[1].mortgageValue = 30;
        BoardSpaces[1].rent = 2;
        BoardSpaces[1].rent1House = 10;
        BoardSpaces[1].rent2House = 30;
        BoardSpaces[1].rent3House = 90;
        BoardSpaces[1].rent4House = 160;
        BoardSpaces[1].rentHotel = 250;
        BoardSpaces[1].buyHouse = 50;

        BoardSpaces[2].name = "Community Chest 1";
        BoardSpaces[2].isChest = 1;

        BoardSpaces[3].name = "Baltic Avenue";
        BoardSpaces[3].price = 60;
        BoardSpaces[3].color = "Brown";
        BoardSpaces[3].mortgageValue = 30;
        BoardSpaces[3].rent = 4;
        BoardSpaces[3].rent1House = 20;
        BoardSpaces[3].rent2House = 60;
        BoardSpaces[3].rent3House = 180;
        BoardSpaces[3].rent4House = 320;
        BoardSpaces[3].rentHotel = 450;
        BoardSpaces[3].buyHouse = 50;

        BoardSpaces[4].name = "Income Tax";
        BoardSpaces[4].isTax = 1;

        BoardSpaces[5].name = "Reading Railroad";
        BoardSpaces[5].price = 200;
        BoardSpaces[5].mortgageValue = 100;
        BoardSpaces[5].rent = 25;
        BoardSpaces[5].isRailroad = 1;

        BoardSpaces[6].name = "Oriental Avenue";
        BoardSpaces[6].price = 100;
        BoardSpaces[6].color = "Light Blue";
        BoardSpaces[6].mortgageValue = 50;
        BoardSpaces[6].rent = 6;
        BoardSpaces[6].rent1House = 30;
        BoardSpaces[6].rent2House = 90;
        BoardSpaces[6].rent3House = 270;
        BoardSpaces[6].rent4House = 400;
        BoardSpaces[6].rentHotel = 550;
        BoardSpaces[6].buyHouse = 50;


        BoardSpaces[7].name = "Chance 1";
        BoardSpaces[7].isChance = 1;

        BoardSpaces[8].name = "Vermont Avenue";
        BoardSpaces[8].price = 100;
        BoardSpaces[8].color = "Light Blue";
        BoardSpaces[8].mortgageValue = 50;
        BoardSpaces[8].rent = 6;
        BoardSpaces[8].rent1House = 30;
        BoardSpaces[8].rent2House = 90;
        BoardSpaces[8].rent3House = 270;
        BoardSpaces[8].rent4House = 400;
        BoardSpaces[8].rentHotel = 550;
        BoardSpaces[8].buyHouse = 50;

        BoardSpaces[9].name = "Connecticut Avenue";
        BoardSpaces[9].price = 120;
        BoardSpaces[9].color = "Light Blue";
        BoardSpaces[9].mortgageValue = 60;
        BoardSpaces[9].rent = 8;
        BoardSpaces[9].rent1House = 40;
        BoardSpaces[9].rent2House = 100;
        BoardSpaces[9].rent3House = 300;
        BoardSpaces[9].rent4House = 450;
        BoardSpaces[9].rentHotel = 600;
        BoardSpaces[9].buyHouse = 50;

        BoardSpaces[10].name = "Jail";
        BoardSpaces[10].isJail = 1;

        BoardSpaces[11].name = "St. Charles Place";
        BoardSpaces[11].price = 140;
        BoardSpaces[11].color = "Pink";
        BoardSpaces[11].mortgageValue = 70;
        BoardSpaces[11].rent = 10;
        BoardSpaces[11].rent1House = 50;
        BoardSpaces[11].rent2House = 150;
        BoardSpaces[11].rent3House = 450;
        BoardSpaces[11].rent4House = 625;
        BoardSpaces[11].rentHotel = 750;
        BoardSpaces[11].buyHouse = 100;

        BoardSpaces[12].name = "Electric Company";
        BoardSpaces[12].price = 150;
        BoardSpaces[12].mortgageValue = 75;
        BoardSpaces[12].rent = 0; // calculate rent based on dice roll
        BoardSpaces[12].isUtility = 1;

        BoardSpaces[13].name = "States Avenue";
        BoardSpaces[13].price = 140;
        BoardSpaces[13].color = "Pink";
        BoardSpaces[13].mortgageValue = 70;
        BoardSpaces[13].rent = 10;
        BoardSpaces[13].rent1House = 50;
        BoardSpaces[13].rent2House = 150;
        BoardSpaces[13].rent3House = 450;
        BoardSpaces[13].rent4House = 625;
        BoardSpaces[13].rentHotel = 750;
        BoardSpaces[13].buyHouse = 100;

        BoardSpaces[14].name = "Virginia Avenue";
        BoardSpaces[14].price = 160;
        BoardSpaces[14].color = "Pink";
        BoardSpaces[14].mortgageValue = 80;
        BoardSpaces[14].rent = 12;
        BoardSpaces[14].rent1House = 60;
        BoardSpaces[14].rent2House = 180;
        BoardSpaces[14].rent3House = 500;
        BoardSpaces[14].rent4House = 700;
        BoardSpaces[14].rentHotel = 900;
        BoardSpaces[14].buyHouse = 100;

        BoardSpaces[15].name = "Pennsylvania Railroad";
        BoardSpaces[15].price = 200;
        BoardSpaces[15].mortgageValue = 100;
        BoardSpaces[15].rent = 25;
        BoardSpaces[15].isRailroad = 1;

        BoardSpaces[16].name = "St. James Place";
        BoardSpaces[16].price = 180;
        BoardSpaces[16].color = "Orange";
        BoardSpaces[16].mortgageValue = 90;
        BoardSpaces[16].rent = 14;
        BoardSpaces[16].rent1House = 70;
        BoardSpaces[16].rent2House = 200;
        BoardSpaces[16].rent3House = 550;
        BoardSpaces[16].rent4House = 750;
        BoardSpaces[16].rentHotel = 950;
        BoardSpaces[16].buyHouse = 100;

        BoardSpaces[17].name = "Community Chest 2";
        BoardSpaces[17].mortgageValue = 30;
        BoardSpaces[17].isChest = 1;

        BoardSpaces[18].name = "Tennessee Avenue";
        BoardSpaces[18].price = 180;
        BoardSpaces[18].color = "Orange";
        BoardSpaces[18].mortgageValue = 90;
        BoardSpaces[18].rent = 14;
        BoardSpaces[18].rent1House = 70;
        BoardSpaces[18].rent2House = 200;
        BoardSpaces[18].rent3House = 550;
        BoardSpaces[18].rent4House = 750;
        BoardSpaces[18].rentHotel = 950;
        BoardSpaces[18].buyHouse = 100;

        BoardSpaces[19].name = "New York Avenue";
        BoardSpaces[19].price = 200;
        BoardSpaces[19].color = "Orange";
        BoardSpaces[19].mortgageValue = 100;
        BoardSpaces[19].rent = 16;
        BoardSpaces[19].rent1House = 80;
        BoardSpaces[19].rent2House = 220;
        BoardSpaces[19].rent3House = 600;
        BoardSpaces[19].rent4House = 800;
        BoardSpaces[19].rentHotel = 1000;
        BoardSpaces[19].buyHouse = 100;

        BoardSpaces[20].name = "Free Parking";
        BoardSpaces[20].isParking = 1;

        BoardSpaces[21].name = "Kentucky Avenue";
        BoardSpaces[21].price = 220;
        BoardSpaces[21].color = "Red";
        BoardSpaces[21].mortgageValue = 110;
        BoardSpaces[21].rent = 18;
        BoardSpaces[21].rent1House = 90;
        BoardSpaces[21].rent2House = 250;
        BoardSpaces[21].rent3House = 700;
        BoardSpaces[21].rent4House = 875;
        BoardSpaces[21].rentHotel = 1050;
        BoardSpaces[21].buyHouse = 150;

        BoardSpaces[22].name = "Chance 2";
        BoardSpaces[22].isChance = 1;

        BoardSpaces[23].name = "Indiana Avenue";
        BoardSpaces[23].price = 220;
        BoardSpaces[23].color = "Red";
        BoardSpaces[23].mortgageValue = 110;
        BoardSpaces[23].rent = 18;
        BoardSpaces[23].rent1House = 90;
        BoardSpaces[23].rent2House = 250;
        BoardSpaces[23].rent3House = 700;
        BoardSpaces[23].rent4House = 875;
        BoardSpaces[23].rentHotel = 1050;
        BoardSpaces[23].buyHouse = 150;

        BoardSpaces[24].name = "Illinois Avenue";
        BoardSpaces[24].price = 240;
        BoardSpaces[24].color = "Red";
        BoardSpaces[24].mortgageValue = 120;
        BoardSpaces[24].rent = 20;
        BoardSpaces[24].rent1House = 100;
        BoardSpaces[24].rent2House = 300;
        BoardSpaces[24].rent3House = 750;
        BoardSpaces[24].rent4House = 925;
        BoardSpaces[24].rentHotel = 1100;
        BoardSpaces[24].buyHouse = 150;

        BoardSpaces[25].name = "B. & O Railroad";
        BoardSpaces[25].price = 200;
        BoardSpaces[25].mortgageValue = 100;
        BoardSpaces[25].rent = 25;
        BoardSpaces[25].isRailroad = 1;

        BoardSpaces[26].name = "Atlantic Avenue";
        BoardSpaces[26].price = 260;
        BoardSpaces[26].color = "Yellow";
        BoardSpaces[26].mortgageValue = 130;
        BoardSpaces[26].rent = 22;
        BoardSpaces[26].rent1House = 110;
        BoardSpaces[26].rent2House = 330;
        BoardSpaces[26].rent3House = 800;
        BoardSpaces[26].rent4House = 975;
        BoardSpaces[26].rentHotel = 1150;
        BoardSpaces[26].buyHouse = 150;

        BoardSpaces[27].name = "Ventnor Avenue";
        BoardSpaces[27].price = 260;
        BoardSpaces[27].color = "Yellow";
        BoardSpaces[27].mortgageValue = 130;
        BoardSpaces[27].rent = 22;
        BoardSpaces[27].rent1House = 110;
        BoardSpaces[27].rent2House = 330;
        BoardSpaces[27].rent3House = 800;
        BoardSpaces[27].rent4House = 975;
        BoardSpaces[27].rentHotel = 1150;
        BoardSpaces[27].buyHouse = 150;

        BoardSpaces[28].name = "Water Works";
        BoardSpaces[28].price = 150;
        BoardSpaces[28].mortgageValue = 75;
        BoardSpaces[28].rent = 0;// rent based on dice roll
        BoardSpaces[28].isUtility = 1;

        BoardSpaces[29].name = "Marvin Gardens";
        BoardSpaces[29].price = 280;
        BoardSpaces[29].color = "Yellow";
        BoardSpaces[29].mortgageValue = 140;
        BoardSpaces[29].rent = 24;
        BoardSpaces[29].rent1House = 120;
        BoardSpaces[29].rent2House = 360;
        BoardSpaces[29].rent3House = 850;
        BoardSpaces[29].rent4House = 1025;
        BoardSpaces[29].rentHotel = 1200;
        BoardSpaces[29].buyHouse = 150;

        BoardSpaces[30].name = "Go to Jail!";
        BoardSpaces[30].isJail = 1;

        BoardSpaces[31].name = "Pacific Avenue";
        BoardSpaces[31].price = 300;
        BoardSpaces[31].color = "Green";
        BoardSpaces[31].mortgageValue = 150;
        BoardSpaces[31].rent = 26;
        BoardSpaces[31].rent1House = 130;
        BoardSpaces[31].rent2House = 390;
        BoardSpaces[31].rent3House = 900;
        BoardSpaces[31].rent4House = 1100;
        BoardSpaces[31].rentHotel = 1275;
        BoardSpaces[31].buyHouse = 200;

        BoardSpaces[32].name = "North Carolina Avenue";
        BoardSpaces[32].price = 300;
        BoardSpaces[32].color = "Green";
        BoardSpaces[32].mortgageValue = 150;
        BoardSpaces[32].rent = 26;
        BoardSpaces[32].rent1House = 130;
        BoardSpaces[32].rent2House = 390;
        BoardSpaces[32].rent3House = 900;
        BoardSpaces[32].rent4House = 1100;
        BoardSpaces[32].rentHotel = 1275;
        BoardSpaces[32].buyHouse = 200;

        BoardSpaces[33].name = "Community Chest 3";
        BoardSpaces[33].isChest = 1;

        BoardSpaces[34].name = "Pennsylvania Avenue";
        BoardSpaces[34].price = 320;
        BoardSpaces[34].color = "Green";
        BoardSpaces[34].mortgageValue = 160;
        BoardSpaces[34].rent = 28;
        BoardSpaces[34].rent1House = 150;
        BoardSpaces[34].rent2House = 450;
        BoardSpaces[34].rent3House = 1000;
        BoardSpaces[34].rent4House = 1200;
        BoardSpaces[34].rentHotel = 1400;
        BoardSpaces[34].buyHouse = 200;

        BoardSpaces[35].name = "Short Line Railroad";
        BoardSpaces[35].price = 200;
        BoardSpaces[35].mortgageValue = 100;
        BoardSpaces[35].rent = 25;
        BoardSpaces[35].isRailroad = 1;

        BoardSpaces[36].name = "Chance 3";
        BoardSpaces[36].isChance = 1;

        BoardSpaces[37].name = "Park Place";
        BoardSpaces[37].price = 350;
        BoardSpaces[37].color = "Dark Blue";
        BoardSpaces[37].mortgageValue = 175;
        BoardSpaces[37].rent = 35;
        BoardSpaces[37].rent1House = 175;
        BoardSpaces[37].rent2House = 500;
        BoardSpaces[37].rent3House = 1100;
        BoardSpaces[37].rent4House = 1300;
        BoardSpaces[37].rentHotel = 1500;
        BoardSpaces[37].buyHouse = 200;

        BoardSpaces[38].name = "Luxury Tax";
        BoardSpaces[38].isTax = 1;

        BoardSpaces[39].name = "Boardwalk";
        BoardSpaces[39].price = 400;
        BoardSpaces[39].color = "Dark Blue";
        BoardSpaces[39].mortgageValue = 200;
        BoardSpaces[39].rent = 50;
        BoardSpaces[39].rent1House = 200;
        BoardSpaces[39].rent2House = 600;
        BoardSpaces[39].rent3House = 1400;
        BoardSpaces[39].rent4House = 1700;
        BoardSpaces[39].rentHotel = 2000;
        BoardSpaces[39].buyHouse = 200;
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
    int ownBrown;
    int ownLightBlue;
    int ownPink;
    int ownOrange;
    int ownRed;
    int ownYellow;
    int ownGreen;
    int ownDarkBlue;
    int assignedNumber;
    bool isAuction;

    
    void getBalance(Player &positionPlayer)
    {
        cout << "position balance is: " << positionPlayer.balance << endl;
    }

void getPosition(Board &positionBoard)
{
	cout << positionBoard.BoardSpaces[position].name << endl;
}

void setComputer()
{
  isComputer = 1;
}

void rollDice(Board &positionBoard, int numPlayers, Player allPlayers[])
{

int diceRoll1 = rand() % 6 + 1;
int diceRoll2 = rand() % 6 + 1;
int diceSum = diceRoll1 + diceRoll2;
    
if(turnsJail == 0)
{
    
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
      cout << "You passed Go!" << endl;
      position = position - 40;
      balance = balance + 200;
    }
    }
}
    
    
    bool jailEscape =  jailCheck(positionBoard);
    if(positionBoard.BoardSpaces[position].isChest == 1) chestCard(positionBoard, numPlayers, allPlayers);
    if(positionBoard.BoardSpaces[position].isChance == 1) chanceCard(positionBoard, numPlayers, allPlayers);
    if(positionBoard.BoardSpaces[position].isTax == 1)
    {
        if(position == 4) balance = balance-min(200, getIncomeTax(positionBoard));
        if(position == 38) balance = balance-75;
    }
    landOnProperty(positionBoard, allPlayers, numPlayers, diceSum);

    getPosition(positionBoard);
    
    if(numDoubles || jailEscape) rollDice(positionBoard, numPlayers, allPlayers); //or with jail boolean
    
}

bool jailCheck(Board &positionBoard) {
        if(position == 30) {
            position = 10;
            turnsJail = 3;
            numDoubles = 0;
        }

    int diceRoll1 = rand() % 6 + 1;
    int diceRoll2 = rand() % 6 + 1;

        if(turnsJail > 0 && diceRoll1 == diceRoll2){      // need to get dice roll values
                turnsJail = 0;
            position = position + diceRoll1 + diceRoll2;
                return 0;

        }

            if (jailFree >= 1 & position == 10) {
                cout << "Do you wish to use your Get Out of Jail Free Card?" << endl;
                string temp;
                cin >> temp;
                if(temp == "yes"){              // using get out of jail free card
                    jailFree -= 1;
                    turnsJail = 0;
                    return true;
                }
            }
            if(turnsJail > 0) {
                cout << "Do you wish to pay $50 to get out of jail?" << endl;
                string temp;
                cin >> temp;
                if (temp == "yes") {              // paying to get out of jail
                    turnsJail = 0;
                    balance -= 50;
                    return true;
                }
            }

          if(turnsJail == 1){                // waited out turns in jail
             turnsJail -= 1;
             return true;
          }

          if(turnsJail > 1){                // decrementing turns left in jail
              turnsJail -= 1;
              return false;
          }

    return false;           // if not on jail position
        }


void chanceCard(Board &positionBoard, int numPlayers, Player allPlayers[])
{
  int chanceIndex = rand() % 16 + 1;
  
  switch(chanceIndex)
  {
      case 0:
      cout << "You pulled Advance to Boardwalk from the chance deck!" << endl;
      position = 39;
      break;
      
      case 1:
      cout << "You pulled Advance to Go! from the chance deck!" << endl;
      position = 0;
      balance = balance + 200;
      break;
      
      case 2:
      cout << "You pulled Advance to Illinois Avenue from the chance deck!" << endl;
      if(position >= 25)
      {
        cout << "You passed Go!" << endl;
       balance = balance + 200;
       }
      position = 24;
      break;
      
      case 3:
      cout << "You pulled Advance to St. Charles Place from the chance deck!" << endl;
      if(position >= 12)
      {
        cout << "You passed Go!" << endl;
        balance = balance + 200;
      } 
      position = 11;
      break;
      
      case 4:
      cout << "You pulled Advance to Nearest Railroad from the chance deck!" << endl;
      if(position < 5 || position > 35)
      {
       cout << "You passed Go!" << endl;
       position = 5;
       balance = balance + 200;
      }
      else if(position >= 5 && position < 15) position = 15;
      else if(position >= 15 && position < 25) position = 25;
      else position = 35;
      break;
      
      case 5:
      cout << "You pulled Advance to Nearest Railroad from the chance deck!" << endl;
      if(position < 5 || position > 35)
      {
        cout << "You passed Go!" << endl;
       position = 5;
       balance = balance + 200;
      }
      else if(position >= 5 && position < 15) position = 15;
      else if(position >= 15 && position < 25) position = 25;
      else position = 35;
      break;
      
      case 6:
      cout << "You pulled Advance to Nearest Utiility from the chance deck!" << endl;
      if(position < 12) position = 12;
      else if(position >= 28)
      {
        cout << "You passed Go!" << endl;
        position = 12;
        balance = balance + 200;
      }
      else position = 28;
      break;
      
      case 7:
      cout << "You pulled Bank Pays you Dividend from the chance deck!" << endl;
      balance = balance + 50;
      break;
      
      case 8:
      cout << "You pulled Get out of Jail Free from the chance deck!" << endl;
      jailFree = jailFree + 1;
      break;
      
      case 9:
      cout << "You pulled Go back from 3 spaces  from the chance deck!" << endl;
      position = position - 3;
      break;
      
      case 10:
      cout << "You pulled Go to Jail from the chance deck!" << endl;
      position = 10;
      turnsJail = 3;
      numDoubles = 0;
      break;
      
      case 11:
      cout << "You pulled Make general repairs on all your property. For each house pay $25. For each hotel pay $100 from the chance deck!" << endl;
      balance = balance - numHouses * 25;
      balance = balance - numHotels * 100;
      break;
      
      case 12:
      cout << "You pulled Speeding fine $15 from the chance deck!" << endl;
      balance = balance - 15;
      break;
      
      case 13:
      cout << "You pulled Take a trip to Reading Railroad. If you pass Go, collect $200 from the chance deck!" << endl;
      if(position >= 6) balance = balance + 200;
      position = 5;
      break;
      
      case 14:
      cout << "You pulled You have been elected Chairman of the Board. Pay each player $50 from the chance deck!" << endl;
      for(int i = 0; i<numPlayers; i++)
      {
        allPlayers[i].balance = allPlayers[i].balance + 50;
      }
      balance = balance - 50*(numPlayers);
      break;
      
      case 15:
      cout << "You pulled Your building loan matures. Collect $150 from the chance deck!" << endl;
      balance = balance + 100;
      break;
  }
}

void chestCard(Board &positionBoard, int numPlayers, Player allPlayers[])
{
  int chestIndex = rand() % 16 + 1;
  
  switch(chestIndex)
  {
      case 0:
      cout << "You pulled Advance to Go (Collect $200) from the Community Chest!" << endl;
      position = 0;
      balance = balance + 200;
      break;
      
      case 1:
      cout << "You pulled Bank error in your favor. Collect $200 from the Community Chest!" << endl;
      balance = balance + 200;
      break;
      
      case 2:
      cout << "You pulled Doctor's fee. Pay $50 from the Community Chest!" << endl;
      balance = balance - 50;
      break;
      
      case 3:
      cout << "You pulled From sale of stock you get $50 from the Community Chest!" << endl;
      balance = balance + 50;
      break;
      
      case 4:
      cout << "You pulled Get Out of Jail Free from the Community Chest!" << endl;
      jailFree = jailFree + 1;
      break;
      
      case 5:
      cout << "You pulled Go to Jail. Go directly to jail, do not pass Go, do not collect $200 from the Community Chest!" << endl;
      position = 10;
      turnsJail = 3;
      numDoubles = 0;
      break;
      
      case 6:
      cout << "You pulled Holiday fund matures. Receive $100 from the Community Chest!" << endl;
      balance = balance + 200;
      break;
      
      case 7:
      cout << "You pulled Income tax refund. Collect $20 from the Community Chest!" << endl;
      balance = balance + 20;
      break;
      
      case 8:
      cout << "You pulled It is your birthday. Collect $10 from every player from the Community Chest!" << endl;
      for(int i = 0; i<numPlayers; i++)
      {
        allPlayers[i].balance = allPlayers[i].balance - 10;
      }
      balance = balance + 10*(numPlayers);
      break;
      
      case 9:
      cout << "You pulled Life insurance matures. Collect $100 from the Community Chest!" << endl;
      balance = balance + 100;
      break;
      
      case 10:
      cout << "You pulled Pay hospital fees of $100 from the Community Chest!" << endl;
      balance = balance - 100;
      break;
      
      case 11:
      cout << "You pulled Pay school fees of $50 from the Community Chest!" << endl;
      balance = balance - 50;
      break;
      
      case 12:
      cout << "You pulled Receive $25 consultancy fee from the Community Chest!" << endl;
      balance = balance - 25;
      break;
      
      case 13:
      cout << "You pulled You are assessed for street repair. $40 per house. $115 per hotel from the Community Chest!" << endl;
      balance = balance - numHouses * 40;
      balance = balance - numHotels * 115;
      break;
      
      case 14:
      cout << "You pulled You have won second prize in a beauty contest. Collect $10 from the Community Chest!" << endl;
      balance = balance + 10;
      break;
      
      case 15:
      cout << "You pulled You inherit $100 from the Community Chest!" << endl;
      balance = balance + 100;
      break;
  }
  
}

int getIncomeTax(Board &positionBoard)
{
    int runningSum = balance;
    for(int i = 0; i<40; i++)
    {
        if(positionBoard.BoardSpaces[i].ownerNumber == assignedNumber)
        {
            if(positionBoard.BoardSpaces[i].isMortgaged == 1) runningSum += positionBoard.BoardSpaces[i].mortgageValue;
            else runningSum += positionBoard.BoardSpaces[i].price;
            if(positionBoard.BoardSpaces[i].numHouses > 0)
            {
                if(numHouses == 5) runningSum += positionBoard.BoardSpaces[i].buyHouse;
                else runningSum += positionBoard.BoardSpaces[i].numHouses * positionBoard.BoardSpaces[i].buyHouse;
            }
        }
    }
    return runningSum/10;
}

void landOnProperty(Board &positionBoard, Player allPlayers[], int numPlayers, int diceRoll)
{
    if(!(positionBoard.BoardSpaces[position].isParking || positionBoard.BoardSpaces[position].isGo || positionBoard.BoardSpaces[position].isJail || positionBoard.BoardSpaces[position].isChance || positionBoard.BoardSpaces[position].isChest || positionBoard.BoardSpaces[position].isTax))
    {
    int userResponse;
    if(positionBoard.BoardSpaces[position].ownerNumber == 0)
    {
        if(isComputer)
        {
            if(balance >= positionBoard.BoardSpaces[position].price)
            {
              balance = balance - positionBoard.BoardSpaces[position].price;
              positionBoard.BoardSpaces[position].ownerNumber = assignedNumber;
              cout << "Player " << assignedNumber << " has purchased " << positionBoard.BoardSpaces[position].name << "!" << endl;
            }
            else {} // auction
        }
        else
        {
            cout << "Would you like to buy " << positionBoard.BoardSpaces[position].name << "?" <<endl;
            cout << "Enter 1 for Yes, or 2 for No." << endl;
            cin >> userResponse;
            if(userResponse == 1)
            {
                balance = balance - positionBoard.BoardSpaces[position].price;
                positionBoard.BoardSpaces[position].ownerNumber = assignedNumber;
                cout << "Player " << assignedNumber << " has purchased " << positionBoard.BoardSpaces[position].name << "!" << endl;
            }
            else {
            auction(positionBoard, numPlayers, allPlayers);
            } // auction function later on
        }
    }
    else if(positionBoard.BoardSpaces[position].isUtility)
    {
        if(positionBoard.BoardSpaces[12].ownerNumber == positionBoard.BoardSpaces[28].ownerNumber)
        {
            balance = balance - diceRoll * 10;
            allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].balance += diceRoll*10;
        }
        else
        {
          balance = balance - diceRoll * 4;
            allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].balance += diceRoll*4;  
        }
    }
    else if(positionBoard.BoardSpaces[position].isRailroad)
    {
        int numRailroads = 0;
        if(positionBoard.BoardSpaces[position].ownerNumber == positionBoard.BoardSpaces[5].ownerNumber) numRailroads++;
        if(positionBoard.BoardSpaces[position].ownerNumber == positionBoard.BoardSpaces[15].ownerNumber) numRailroads++;
        if(positionBoard.BoardSpaces[position].ownerNumber == positionBoard.BoardSpaces[25].ownerNumber) numRailroads++;
        if(positionBoard.BoardSpaces[position].ownerNumber == positionBoard.BoardSpaces[35].ownerNumber) numRailroads++;

        switch(numRailroads)
        {
            case 1:
            balance = balance - 25;
            allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].balance += 25;
            break;

            case 2:
            balance = balance - 50;
            allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].balance += 50;
            break;

            case 3:
            balance = balance - 100;
            allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].balance += 100;
            break;

            case 4:
            balance = balance - 200;
            allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].balance += 200;
            break;
        }
    }
    else
    {
        balance = balance - positionBoard.BoardSpaces[position].rent;
        allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].balance += positionBoard.BoardSpaces[position].rent;
    }
    }
}

void buyHouse(Board &positionBoard)
{
    string colors[8];
    int counter[8];
    int possibilityArray[8];

    colors[0] = "Brown";
    colors[1] = "LightBlue";
    colors[2] = "Pink";
    colors[3] = "Orange";
    colors[4] = "Red";
    colors[5] = "Yellow";
    colors[6] = "Green";
    colors[7] = "DarkBlue";

    for(int i = 0; i<8; i++)
    {
        counter[i] = 0;
        possibilityArray[8] = 0;
    }

    for(int i = 0; i<40; i++)
    {
        if(positionBoard.BoardSpaces[i].ownerNumber == assignedNumber)
        {
            for(int j = 0; j<8; j++)
            {
                if(positionBoard.BoardSpaces[i].color == colors[j])
                {
                    counter[j]++;
                }
            }
        }
    } 

    int runningSum = 0;

    for(int j = 0; j<8; j++)
    {
        if(j == 0 || j == 8)
        {
            if(counter[j] == 2)
            {
            possibilityArray[j] = 1;
            runningSum++;
            }
        }
        else if(counter[j] == 3)
        {
            runningSum++;
            possibilityArray[j] = 1;
        } 
    }

    if(runningSum == 0)
    {
        cout << "You can not buy any real estate!" << endl;
        return;
    }
    else
    {
        cout << "You can buy property for the following color sets:" << endl;
        if(possibilityArray[0] == 1) cout << "1. Brown" << endl;
        if(possibilityArray[1] == 1) cout << "2. Light Blue" << endl;
        if(possibilityArray[2] == 1) cout << "3. Pink" << endl;
        if(possibilityArray[3] == 1) cout << "4. Orange" << endl;
        if(possibilityArray[4] == 1) cout << "5. Red" << endl;
        if(possibilityArray[5] == 1) cout << "6. Yellow" << endl;
        if(possibilityArray[6] == 1) cout << "7. Green" << endl;
        if(possibilityArray[7] == 1) cout << "8. Dark Blue" << endl;

        int userInput;
        cout << "Enter the number corresponding to the color you would like to build on." << endl;
        cin >> userInput;

        if(possibilityArray[userInput-1] != 1) cout << "Invalid input! You will be returned to the action menu!" << endl;
        else
        {
            int userChoice;
            switch(userInput)
            {
                case 1:
                cout << "Enter the number of the corresponding property you would like to build real estate on." << endl;
                cout << "1. Mediterranean Avenue" << endl;
                cout << "2. Baltic Avenue" << endl;
                cin >> userChoice;
                if(userChoice < 1 || userChoice > 2) cout << "Invalid input." << endl;
                if(userChoice == 1 && positionBoard.BoardSpaces[1].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 1 && (positionBoard.BoardSpaces[1].numHouses > positionBoard.BoardSpaces[3].numHouses && positionBoard.BoardSpaces[3].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[1].buyHouse){
                    if(positionBoard.BoardSpaces[1].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[1].numHouses = 0;
                        positionBoard.BoardSpaces[1].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[1].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[1].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
                }
                if(userChoice == 2 && positionBoard.BoardSpaces[3].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 2 && (positionBoard.BoardSpaces[3].numHouses > positionBoard.BoardSpaces[1].numHouses && positionBoard.BoardSpaces[1].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[3].buyHouse){
                    if(positionBoard.BoardSpaces[3].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[3].numHouses = 0;
                        positionBoard.BoardSpaces[3].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[3].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[3].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                break;

                case 2:
                cout << "Enter the number of the corresponding property you would like to build real estate on." << endl;
                cout << "1. Oriental Avenue" << endl;
                cout << "2. Vermont Avenue" << endl;
                cout << "3. Connecticut Avenue" << endl;
                cin >> userChoice;
                if(userChoice < 1 || userChoice > 3) cout << "Invalid input." << endl;
                if(userChoice == 1 && positionBoard.BoardSpaces[6].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 1 && (positionBoard.BoardSpaces[6].numHouses > positionBoard.BoardSpaces[8].numHouses && positionBoard.BoardSpaces[8].numHotels == 0) && (positionBoard.BoardSpaces[6].numHouses > positionBoard.BoardSpaces[9].numHouses && positionBoard.BoardSpaces[9].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[6].buyHouse){
                    if(positionBoard.BoardSpaces[6].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[6].numHouses = 0;
                        positionBoard.BoardSpaces[6].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[6].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[6].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                if(userChoice == 2 && positionBoard.BoardSpaces[8].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 2 && (positionBoard.BoardSpaces[8].numHouses > positionBoard.BoardSpaces[6].numHouses && positionBoard.BoardSpaces[6].numHotels == 0) && (positionBoard.BoardSpaces[8].numHouses > positionBoard.BoardSpaces[9].numHouses && positionBoard.BoardSpaces[9].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[8].buyHouse){
                    if(positionBoard.BoardSpaces[8].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[8].numHouses = 0;
                        positionBoard.BoardSpaces[8].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[8].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[8].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                if(userChoice == 2 && positionBoard.BoardSpaces[9].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 3 && (positionBoard.BoardSpaces[9].numHouses > positionBoard.BoardSpaces[6].numHouses && positionBoard.BoardSpaces[6].numHotels == 0) && (positionBoard.BoardSpaces[9].numHouses > positionBoard.BoardSpaces[8].numHouses && positionBoard.BoardSpaces[8].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[9].buyHouse){
                    if(positionBoard.BoardSpaces[9].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[9].numHouses = 0;
                        positionBoard.BoardSpaces[9].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[9].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[9].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                break;

                case 3:
                cout << "Enter the number of the corresponding property you would like to build real estate on." << endl;
                cout << "1. St. Charles Place" << endl;
                cout << "2. States Avenue" << endl;
                cout << "3. Virginia Avenue" << endl;
                cin >> userChoice;
                if(userChoice < 1 || userChoice > 3) cout << "Invalid input." << endl;
                if(userChoice == 1 && positionBoard.BoardSpaces[11].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 1 && (positionBoard.BoardSpaces[11].numHouses > positionBoard.BoardSpaces[13].numHouses && positionBoard.BoardSpaces[13].numHotels == 0) && (positionBoard.BoardSpaces[11].numHouses > positionBoard.BoardSpaces[14].numHouses && positionBoard.BoardSpaces[14].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[11].buyHouse){
                    if(positionBoard.BoardSpaces[11].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[11].numHouses = 0;
                        positionBoard.BoardSpaces[11].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[11].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[11].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                if(userChoice == 2 && positionBoard.BoardSpaces[13].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 2 && (positionBoard.BoardSpaces[13].numHouses > positionBoard.BoardSpaces[11].numHouses && positionBoard.BoardSpaces[11].numHotels == 0) && (positionBoard.BoardSpaces[13].numHouses > positionBoard.BoardSpaces[14].numHouses && positionBoard.BoardSpaces[14].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[13].buyHouse){
                    if(positionBoard.BoardSpaces[13].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[13].numHouses = 0;
                        positionBoard.BoardSpaces[13].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[13].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[13].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                if(userChoice == 2 && positionBoard.BoardSpaces[14].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 3 && (positionBoard.BoardSpaces[14].numHouses > positionBoard.BoardSpaces[11].numHouses && positionBoard.BoardSpaces[11].numHotels == 0) && (positionBoard.BoardSpaces[14].numHouses > positionBoard.BoardSpaces[13].numHouses && positionBoard.BoardSpaces[13].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[13].buyHouse){
                    if(positionBoard.BoardSpaces[14].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[14].numHouses = 0;
                        positionBoard.BoardSpaces[14].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[14].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[14].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                break;

                case 4:
                cout << "Enter the number of the corresponding property you would like to build real estate on." << endl;
                cout << "1. St. James Place" << endl;
                cout << "2. Tennessee Avenue" << endl;
                cout << "3. New York Avenue" << endl;
                cin >> userChoice;
                if(userChoice < 1 || userChoice > 3) cout << "Invalid input." << endl;
                if(userChoice == 1 && positionBoard.BoardSpaces[16].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 1 && (positionBoard.BoardSpaces[16].numHouses > positionBoard.BoardSpaces[18].numHouses && positionBoard.BoardSpaces[18].numHotels == 0) && (positionBoard.BoardSpaces[16].numHouses > positionBoard.BoardSpaces[19].numHouses && positionBoard.BoardSpaces[19].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[16].buyHouse){
                    if(positionBoard.BoardSpaces[16].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[16].numHouses = 0;
                        positionBoard.BoardSpaces[16].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[16].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[16].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                if(userChoice == 2 && positionBoard.BoardSpaces[18].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 2 && (positionBoard.BoardSpaces[18].numHouses > positionBoard.BoardSpaces[16].numHouses && positionBoard.BoardSpaces[16].numHotels == 0) && (positionBoard.BoardSpaces[18].numHouses > positionBoard.BoardSpaces[19].numHouses && positionBoard.BoardSpaces[19].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[18].buyHouse){
                    if(positionBoard.BoardSpaces[18].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[18].numHouses = 0;
                        positionBoard.BoardSpaces[18].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[18].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[18].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                if(userChoice == 2 && positionBoard.BoardSpaces[19].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 3 && (positionBoard.BoardSpaces[19].numHouses > positionBoard.BoardSpaces[16].numHouses && positionBoard.BoardSpaces[16].numHotels == 0) && (positionBoard.BoardSpaces[19].numHouses > positionBoard.BoardSpaces[18].numHouses && positionBoard.BoardSpaces[18].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[19].buyHouse){
                    if(positionBoard.BoardSpaces[19].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[19].numHouses = 0;
                        positionBoard.BoardSpaces[19].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[19].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[19].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                break;

                case 5:
                cout << "Enter the number of the corresponding property you would like to build real estate on." << endl;
                cout << "1. Kentucky Avenue" << endl;
                cout << "2. Indiana Avenue" << endl;
                cout << "3. Illinois Avenue" << endl;
                cin >> userChoice;
                if(userChoice < 1 || userChoice > 3) cout << "Invalid input." << endl;
                if(userChoice == 1 && positionBoard.BoardSpaces[21].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 1 && (positionBoard.BoardSpaces[21].numHouses > positionBoard.BoardSpaces[23].numHouses && positionBoard.BoardSpaces[23].numHotels == 0) && (positionBoard.BoardSpaces[21].numHouses > positionBoard.BoardSpaces[24].numHouses && positionBoard.BoardSpaces[24].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[21].buyHouse){
                    if(positionBoard.BoardSpaces[21].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[21].numHouses = 0;
                        positionBoard.BoardSpaces[21].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[21].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[21].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                if(userChoice == 2 && positionBoard.BoardSpaces[23].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 2 && (positionBoard.BoardSpaces[23].numHouses > positionBoard.BoardSpaces[21].numHouses && positionBoard.BoardSpaces[21].numHotels == 0) && (positionBoard.BoardSpaces[23].numHouses > positionBoard.BoardSpaces[24].numHouses && positionBoard.BoardSpaces[24].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[23].buyHouse){
                    if(positionBoard.BoardSpaces[23].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[23].numHouses = 0;
                        positionBoard.BoardSpaces[23].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[23].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[23].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                if(userChoice == 2 && positionBoard.BoardSpaces[24].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 3 && (positionBoard.BoardSpaces[24].numHouses > positionBoard.BoardSpaces[21].numHouses && positionBoard.BoardSpaces[21].numHotels == 0) && (positionBoard.BoardSpaces[24].numHouses > positionBoard.BoardSpaces[23].numHouses && positionBoard.BoardSpaces[23].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[24].buyHouse){
                    if(positionBoard.BoardSpaces[24].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[24].numHouses = 0;
                        positionBoard.BoardSpaces[24].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[24].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[24].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                break;

                case 6:
                cout << "Enter the number of the corresponding property you would like to build real estate on." << endl;
                cout << "1. Atlantic Avenue" << endl;
                cout << "2. Ventnor Avenue" << endl;
                cout << "3. Marvin Gardens" << endl;
                cin >> userChoice;
                if(userChoice < 1 || userChoice > 3) cout << "Invalid input." << endl;
                if(userChoice == 1 && positionBoard.BoardSpaces[26].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 1 && (positionBoard.BoardSpaces[26].numHouses > positionBoard.BoardSpaces[27].numHouses && positionBoard.BoardSpaces[27].numHotels == 0) && (positionBoard.BoardSpaces[26].numHouses > positionBoard.BoardSpaces[29].numHouses && positionBoard.BoardSpaces[29].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[26].buyHouse){
                    if(positionBoard.BoardSpaces[26].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[26].numHouses = 0;
                        positionBoard.BoardSpaces[26].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[26].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[26].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                if(userChoice == 2 && positionBoard.BoardSpaces[27].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 2 && (positionBoard.BoardSpaces[27].numHouses > positionBoard.BoardSpaces[26].numHouses && positionBoard.BoardSpaces[26].numHotels == 0) && (positionBoard.BoardSpaces[27].numHouses > positionBoard.BoardSpaces[29].numHouses && positionBoard.BoardSpaces[29].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[27].buyHouse){
                    if(positionBoard.BoardSpaces[27].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[27].numHouses = 0;
                        positionBoard.BoardSpaces[27].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[27].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[27].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                if(userChoice == 2 && positionBoard.BoardSpaces[29].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 3 && (positionBoard.BoardSpaces[29].numHouses > positionBoard.BoardSpaces[26].numHouses && positionBoard.BoardSpaces[26].numHotels == 0) && (positionBoard.BoardSpaces[29].numHouses > positionBoard.BoardSpaces[27].numHouses && positionBoard.BoardSpaces[27].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[29].buyHouse){
                    if(positionBoard.BoardSpaces[29].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[29].numHouses = 0;
                        positionBoard.BoardSpaces[29].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[29].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[29].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                break;

                case 7:
                cout << "Enter the number of the corresponding property you would like to build real estate on." << endl;
                cout << "1. Pacific Avenue" << endl;
                cout << "2. North Carolina Avenue" << endl;
                cout << "3. Pennsylvania Avenue" << endl;
                cin >> userChoice;
                if(userChoice < 1 || userChoice > 3) cout << "Invalid input." << endl;
                if(userChoice == 1 && positionBoard.BoardSpaces[31].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 1 && (positionBoard.BoardSpaces[31].numHouses > positionBoard.BoardSpaces[32].numHouses && positionBoard.BoardSpaces[132].numHotels == 0) && (positionBoard.BoardSpaces[34].numHouses > positionBoard.BoardSpaces[34].numHouses && positionBoard.BoardSpaces[14].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[31].buyHouse){
                    if(positionBoard.BoardSpaces[31].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[31].numHouses = 0;
                        positionBoard.BoardSpaces[31].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[31].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[31].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                if(userChoice == 2 && positionBoard.BoardSpaces[32].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 2 && (positionBoard.BoardSpaces[32].numHouses > positionBoard.BoardSpaces[31].numHouses && positionBoard.BoardSpaces[31].numHotels == 0) && (positionBoard.BoardSpaces[32].numHouses > positionBoard.BoardSpaces[34].numHouses && positionBoard.BoardSpaces[34].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[32].buyHouse){
                    if(positionBoard.BoardSpaces[32].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[32].numHouses = 0;
                        positionBoard.BoardSpaces[32].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[32].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[32].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                if(userChoice == 2 && positionBoard.BoardSpaces[34].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 3 && (positionBoard.BoardSpaces[34].numHouses > positionBoard.BoardSpaces[31].numHouses && positionBoard.BoardSpaces[31].numHotels == 0) && (positionBoard.BoardSpaces[34].numHouses > positionBoard.BoardSpaces[32].numHouses && positionBoard.BoardSpaces[32].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[34].buyHouse){
                    if(positionBoard.BoardSpaces[34].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[34].numHouses = 0;
                        positionBoard.BoardSpaces[34].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[34].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[34].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                break;

                case 8:
                cout << "Enter the number of the corresponding property you would like to build real estate on." << endl;
                cout << "1. Park Place" << endl;
                cout << "2. Boardwalk" << endl;
                cin >> userChoice;
                if(userChoice < 1 || userChoice > 2) cout << "Invalid input." << endl;
                if(userChoice == 1 && positionBoard.BoardSpaces[37].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 1 && (positionBoard.BoardSpaces[37].numHouses > positionBoard.BoardSpaces[39].numHouses && positionBoard.BoardSpaces[39].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[37].buyHouse){
                    if(positionBoard.BoardSpaces[37].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[37].numHouses = 0;
                        positionBoard.BoardSpaces[37].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[37].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[37].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                if(userChoice == 2 && positionBoard.BoardSpaces[39].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 2 && (positionBoard.BoardSpaces[39].numHouses > positionBoard.BoardSpaces[37].numHouses && positionBoard.BoardSpaces[37].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[39].buyHouse){
                    if(positionBoard.BoardSpaces[39].numHouses == 4)
                    {
                        positionBoard.BoardSpaces[39].numHouses = 0;
                        positionBoard.BoardSpaces[39].numHotels = 1;
                    }
                    else positionBoard.BoardSpaces[39].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[39].buyHouse;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                break;
            }
        }
    }
}

    void auction(Board &positionBoard, int numPlayers, Player allPlayers[]) { // takes in bidding property
        int bidPrice = 0;
        int computerBidMax = positionBoard.BoardSpaces[position].price * 1.25;
        bool auctionContinue = true;
        int chosenComp = -1;
        int numAuction = 0;
        int auctionWinner= -1;


        cout << "The current auction is for: " << positionBoard.BoardSpaces[position].name << endl;
        for(int i = 0; i < numPlayers; i++) {
            allPlayers[i].isAuction = true;

            if(allPlayers[i].isComputer == 1) {
                if(allPlayers[i].balance < computerBidMax){
                    allPlayers[i].isAuction = false;
                    cout << "Player " << i+1 << "has dropped out of the auction" << endl;
                }
            }
        }

        for(int i = 0; i < numPlayers; i++){
            if(allPlayers[i].isComputer == 1 && allPlayers[i].isAuction == true) {
                chosenComp = i;
                bidPrice = computerBidMax;
                break;
            }
        }

        if(chosenComp != -1){
            for(int i = 0; i < numPlayers; i++){
                if(allPlayers[i].isComputer == 1){
                    allPlayers[i].isAuction = false;
                }
            }
            allPlayers[chosenComp].isAuction = true;
            auctionWinner = chosenComp;
            cout << "Player " << chosenComp+1 << " has bid " << bidPrice << endl;
        }

        for(int i= 0; i < numPlayers; i++){
            if(allPlayers[i].isAuction)
                numAuction += 1;
        }

        while(auctionContinue) {
            string cont;
            int tempBidPrice;



            for (int i = 0; i < numPlayers; i++) {
                if(allPlayers[i].isComputer == false && allPlayers[i].isAuction && numAuction > 1){
                    cout << "Player " << i+1 << " would you like to continue bidding on this property? (Type yes or no)" << endl;
                    cin >> cont;
                    if(cont == "no"){
                        allPlayers[i].isAuction = false;
                        numAuction -=1;
                        cout << "Player " << i+1 << " has dropped out of the auction " << endl;
                    }
                    if(cont == "yes"){
                        cout << "The current bidding price is at " << bidPrice << ", please enter a larger bid" << endl;
                        cin >> tempBidPrice;
                        if(tempBidPrice > bidPrice && allPlayers[i].balance >= tempBidPrice) {
                            bidPrice = tempBidPrice;
                            auctionWinner = i;
                            cout << "The current bid has now been raised to " << bidPrice << endl;
                            if (allPlayers[chosenComp].isAuction) {
                                allPlayers[chosenComp].isAuction = false;        // added code make chosen comp drop out of auction
                                numAuction -= 1;
                                cout << "Player " << chosenComp+1 << " has dropped out of the auction" << endl;
                            }

                        }
                    }
                }
            }
            if(numAuction == 1){
                auctionContinue = false;
                cout << "The winner of the bid is player " << auctionWinner+1 << endl;
                positionBoard.BoardSpaces[position].ownerNumber = assignedNumber;
            }


        }

    }

Player()
{
  isComputer = 0;
        position = 0;
        numDoubles = 0;
        numHotels = 0;
        numHouses = 0;
        balance = 1500;
        isAuction = false;
        turnsJail = 0;
        jailFree = 0;
        jailOut = 0;
        ownBrown = 0;
        ownLightBlue = 0;
        ownPink = 0;
        ownOrange = 0;
        ownRed = 0;
        ownYellow = 0;
        ownGreen = 0;
        ownDarkBlue = 0;
}
};
