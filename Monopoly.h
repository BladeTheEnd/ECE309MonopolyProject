#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

//For our implementation, we really decided only to use two objects. We didn't find a good use for an inherited function, so I figured we should put this here to show you that we do know how to do it, we just didn't find it useful for our setup.
class Placeholder{
public:
    virtual void getBalance()
    {
        cout << "This is my default functionality" << endl;
    }
};

//This is the Property class. It contains several features of a Property in Monopoly. It is heavily interacted with in our other objects, so we had to leave its member variables public. 
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

    //Intializes some of the booleans/important ints that we will check in other pieces of the code. Assigning of other variables is done later on through different means.
    Property(){
         isMortgaged = 0;
         isChest = 0;
         isChance = 0;
         isTax = 0;
         isParking = 0;
         isGo = 0;
         isRailroad = 0;
         isUtility = 0;
         isJail = 0;
         numHotels = 0;
         numHouses = 0;
         ownerNumber = 0;
    }

    //For this class, even though we have a constructor, we do not need a destructor/assignment operator. We would never need to assign a property to another property, and there is no dynamically allocated memory. The defaults for both are just fine.
};


//Ths is the board in which all the players play on. We had a choice between making functions happen here or on the player object, and we chose the player object. Because of that, this array is heavily indexed in other places so we left it public.
class Board{
public:
    //there is a set number of hotels/houses that can be purchased in a game of Monopoly.
    int availableHotels;
    int availableHouses;

    Property BoardSpaces[40];

    //This constructor assigns the important details of every property to them.
    Board(){
        availableHouses = 32;
        availableHotels = 12;

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

    //This class is the same as the previous. No need for personalized destructor/assignment operator.
};

class Player: public Placeholder{
private:
    int position;
    int turnsJail; // turns potentially spent in jail
    int jailOut; // has a get out of jail free card
    int jailFree;
    int numDoubles;
    int numHousesOwned;
    int numHotelsOwned;
    bool isAuction;
    int jailUtility;
    vector<Property> OwnedProperties;

//these variables are used in main, so they have to be public.
public:
    int balance;
    int assignedNumber;
    bool gameOver;
    bool isComputer;
    
    //This function simply prints the player's balance.
    void getBalance()
    {
        cout << "Player " << assignedNumber << "'s current balance is " << balance << endl;
    }

//This function will print the name of the square that the player is current standing on.
void getPosition(Board &positionBoard)
{
    cout << positionBoard.BoardSpaces[position].name << endl;
}

//This function makes the player a computer player.
void setComputer()
{
  isComputer = 1;
}

//Ths is the general function that moves the player around the board. A lot of things occur as a part of this function.
void rollDice(Board &positionBoard, int numPlayers, Player allPlayers[])
{

//rolls 2d6s to determine how the player is going to move.
int diceRoll1 = rand() % 6 + 1;
int diceRoll2 = rand() % 6 + 1;

//it is important to store this info for the utility properties.
int diceSum = diceRoll1 + diceRoll2;

if(turnsJail == 0) cout << "Player " << assignedNumber << " rolled to move " << diceSum << " spaces!" << endl;
    
if(turnsJail == 0) //check to see if the player is in jail, if so they can not move.
{
    
    if(diceRoll1 == diceRoll2) //If the player rolls doubles, they will get to move again.
    {
      numDoubles++;
      if(numDoubles != 3) cout << "Player " << assignedNumber << " rolled doubles and will get to move again!" << endl;
    }
    else numDoubles = 0; //reset numdoubles
    
    if(numDoubles == 3) //if they rolled doubles 3 times in a row, we need to move them to jail. We do this by placing them on the go to jail square, then calling jailcheck later.
    {
      position = 30;
      cout << "Three doubles rolled, go to jail!" << endl;
      numDoubles = 0; //reset here too because it will cause wonky behavior if they get out and it is not zeroed
    }
    else
    {
    position = position + diceRoll1 + diceRoll2;
    cout << endl;
    if(position >= 40)
    { 
      cout << "Player " << assignedNumber << "has passed Go!" << "Collect 200!" << endl;
      position = position - 40; //gotta adjust their position to wrap around the barrier
      balance = balance + 200; //increase their balance as apart of that
    }
    cout << "Player " << assignedNumber << " has moved to ";
    getPosition(positionBoard);
    }
}
    
    
    bool jailEscape =  jailCheck(positionBoard); //this returns 1 if the person escapes from jail and gets to go. It also puts someone in jail if they are on 30 square.
    if(positionBoard.BoardSpaces[position].isChest == 1) chestCard(positionBoard, numPlayers, allPlayers); //call chest if needed
    if(positionBoard.BoardSpaces[position].isChance == 1) chanceCard(positionBoard, numPlayers, allPlayers); //call chance if needed
    if(positionBoard.BoardSpaces[position].isTax == 1) //If the position is one of the taxes, apply the proper effect.
    {
        if(position == 4)
        {
        int incomeTax = getIncomeTax(positionBoard);
        balance = balance-min(200, incomeTax); //income tax
        cout << "Player " << assignedNumber << " has paid $" << min(200, incomeTax) << " in income tax!" << endl;
        }
        if(position == 38) 
        {
        balance = balance-75; //luxury tax 
        cout << "Player " << assignedNumber << " has paid $75 in luxury tax!" << endl;
        }
    }
    landOnProperty(positionBoard, allPlayers, numPlayers, diceSum); //this function handles all that goes on for paying rent/buying property
    checkBankrupt(positionBoard, allPlayers, numPlayers);
    
    if((numDoubles || jailEscape) && !gameOver) rollDice(positionBoard, numPlayers, allPlayers); //Here we use recursion. All players will go through this function. By this point, if they escaped jail, they will need a turn, so it will rego to give them the turn. Also, if they have doubles, we need to use recursion.

}

void checkBankrupt(Board &positionBoard, Player allPlayers[], int numPlayers)
{
    //this function handles ending the game for a player and all of the things that must be done as that occurs.
    bool givenUp = 0;

    if(balance >= 0) return; //no need to do anything

    while(true) //presents player their options for moving forward.
    {
        if(isComputer == 1) break; //computers will auto lose here.

        int userInput;

        while(userInput != 0)
        {
        //list all actions player can take and secure input.
        cout << "Your balance is currently " << balance << ". You must perform the following actions to get a positive balance. Enter 0. If you have things to sell still, you will come back to this menu. If your balance is positive, the game will continue." << endl;
        cout << "1. Trade" << endl;
        cout << "2. Mortgage Property" << endl;
        cout << "3. Sell Real Estate" << endl;
        cout << "4. Give up" << endl;

        cin >> userInput;

        switch(userInput)
        {
            case 1:
                Trade(positionBoard, allPlayers, numPlayers);
                break;

            case 2:
                Mortgage(positionBoard);
                break;

            case 3:
                sellHouse(positionBoard);
                break;

            case 4:
            givenUp = 1;
            break;

            case 0:
                break;

            default:
                cout << "Not a valid input" << endl;
                break;
        }
        }

        int unmortgagedSpaces = 0;

        for(int i = 0; i<40; i++)
            {
                if(positionBoard.BoardSpaces[i].ownerNumber == assignedNumber && positionBoard.BoardSpaces[i].isMortgaged == 0) unmortgagedSpaces++;
            }

        if(givenUp)
        {
            cout << "Player has given up!" << endl;
        }

        if(balance > 0)
        {
            cout << "You have enough money to pay off your debt!" << endl;
            break; //player can afford it now
        }
        if((numHousesOwned + numHotelsOwned) == 0 && unmortgagedSpaces == 0)
        {
            cout << "You have no other properties to use to gain money. Game over!" << endl;
            break; //break because player has nothing to 
        } 
    }

    if(balance > 0 && !givenUp) return; //check here to see if they left the while due to balance

    gameOver = 1; //game is over for this player

    if(positionBoard.BoardSpaces[position].ownerNumber == 0) //debt is to the bank. Unmortgage all properties then auction
    {
        for (int i = 0; i < 40; ++i)
        {
            if(positionBoard.BoardSpaces[i].ownerNumber == assignedNumber)
            {
                positionBoard.BoardSpaces[i].isMortgaged = 0;
                auction(positionBoard, numPlayers, allPlayers, i);
            }
        }
    }
    else //debt is to player
    {
        int mortgageSum = 0;
        if(balance > 0) //if there is some money, give to other player
        {
        allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].balance += balance;
        cout << "Player " << positionBoard.BoardSpaces[position].ownerNumber << " has recieved " << balance << " dollars" << endl;
        }

        for(int i = 0; i < 40; ++i)
        {
           if(positionBoard.BoardSpaces[i].ownerNumber == assignedNumber)
            {
                if(positionBoard.BoardSpaces[i].isMortgaged) // need to ask player if they want to unmortgage, then collect proper fees.
                {
                    mortgageSum += positionBoard.BoardSpaces[i].price/10;
                    cout << "Player " << positionBoard.BoardSpaces[position].ownerNumber << ", would you like to unmortgage" << positionBoard.BoardSpaces[i].name << "?" << "Enter 1 for yes, 2 for no." << endl;
                    int userInput;
                    cin >> userInput;

                    if(userInput == 1) 
                    {
                        mortgageSum += positionBoard.BoardSpaces[i].price/10;
                        positionBoard.BoardSpaces[i].isMortgaged = 0;
                    }
                    else if(userInput == 2);
                    else cout << "Invalid input. Property will remain mortgaged for now" << endl;
                } 
                //transfer ownership
                allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].OwnedProperties.push_back(positionBoard.BoardSpaces[i]);
                positionBoard.BoardSpaces[i].ownerNumber = positionBoard.BoardSpaces[position].ownerNumber;
            } 
        }
        OwnedProperties.clear();
        allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].balance -= mortgageSum;
        cout << "Recieving player has paid " << mortgageSum << " in taxes and unmortgaging fees!";
    }
}

void actionMenu(Board &positionBoard, Player &currentPlayer, Player allPlayers[], int numPlayers) {
    //This function is called in main after hte player has rolled the dice.
    //It serves really as a control path, as it lets the player choose the action they wish to take and then calls the corresponding function.
    int userInput = 0;

    while(userInput != 8 && currentPlayer.isComputer == 0 && currentPlayer.gameOver == 0)
    {
        //list all actions player can take and secure input.
        cout << "Select from the following menu the actions you would like to take:" << endl;
        cout << "1. Current Balance" << endl;
        cout << "2. Trade" << endl;
        cout << "3. Mortgage Property" << endl;
        cout << "4. Unmortgage Property" << endl;
        cout << "5. Buy Real Estate" << endl;
        cout << "6. Sell Real Estate" << endl;
        cout << "7. List Properties Owned" << endl;
        cout << "8. End Turn" << endl;

        cin >> userInput;

        switch(userInput)
        {
            case 1:
                getBalance();
                break;

            case 2:
                Trade(positionBoard, allPlayers, numPlayers);
                break;

            case 3:
                Mortgage(positionBoard);
                break;
            case 4:
                Unmortgage(positionBoard, currentPlayer);
                break;

            case 5:
                buyHouse(positionBoard);
                break;

            case 6:
                sellHouse(positionBoard);
                break;

            case 7:
                propertiesOwned();
                break;

            case 8:
                break;

            default:
                cout << "Not a valid input" << endl;
                break;
        }
    }

}

void propertiesOwned()
{
    //list all the properties that the player owns.
    if(OwnedProperties.size() == 0) cout << "You do not own any propeties to offer" << endl;
        else
        {
        cout << "The current properties you own are:" << endl;
          for(int i=0; i < OwnedProperties.size(); i++)
          {
            cout << i+1 << ". " << OwnedProperties[i].name << endl;
          }
        }
}





void Trade(Board &positionBoard, Player allPlayers[], int numPlayers){
        //This function allows the player to create a trade package to send and one to recieve. Then another player can accept.
        int userInput;
        int balanceOffered;
        int balanceRequested;
        vector<Property> tradeOffer;
        vector<Property> tradeRequest;

        for(int i = 0; i<OwnedProperties.size(); i++) //vector contains property, really only used for size + name need to make sure houses/hotels are equal since they are checked here.
        {
            for(int j = 0; j<40; j++)
            {
                if(OwnedProperties[i].name == positionBoard.BoardSpaces[j].name)
                {
                    OwnedProperties[i].numHouses = positionBoard.BoardSpaces[j].numHouses;
                    OwnedProperties[i].numHotels = positionBoard.BoardSpaces[j].numHotels;
                }
            }
        }
        
        cout << "Player " << assignedNumber << " is beginning a trade." << endl;

        //Let the player know their balance before hand so they will know how much they can offer.
        cout << "Your current balance is ";
        getBalance();
        
        //List all the properties that the player owns so that they will know what can be offered.
        if(OwnedProperties.size() == 0) cout << "You do not have any propeties to offer" << endl;
        else
        {
        cout << "The current properties you own are:" << endl;
          for(int i=0; i < OwnedProperties.size(); i++)
          {
            cout << i+1 << ". " << OwnedProperties[i].name << endl;
          }
        }
        
        cout << "You can trade with the following players:" << endl;
        //list players than can be traded with.
        for(int i = 0; i<numPlayers; i++)
        {
          if(allPlayers[i].assignedNumber != assignedNumber && allPlayers[i].gameOver == 0) cout << i+1 << ". Player " << i+1 << endl;
        }
        
        //Need to enter corresponding player number
        cout << "Enter the number of the player you would like to trade with." << endl;
        
        cin >> userInput;
        
        if(userInput > numPlayers || userInput <= 0 || userInput == assignedNumber || allPlayers[userInput-1].gameOver != 0) cout << "Invalid Player" << endl; //need to vet the number here just to be sure
        //here repeat the above process for the player they are attempting to trade with so everyone knows what can be acquired.
        else
        {
          cout << "Player " << userInput << " has a balance of ";
          allPlayers[userInput - 1].getBalance();
          if(allPlayers[userInput - 1].OwnedProperties.size() == 0) cout << "This player does not have any propeties to offer" << endl;
          else
          {
            cout << "The current properties they own are:" << endl;
            for(int i=0; i < OwnedProperties.size(); i++)
            {
            cout << i+1 << ". " << OwnedProperties[i].name << endl;
            }
          }
          
          //reuse the userInput variable, preserve this for later
          int playerNum = userInput;

          for(int i = 0; i<allPlayers[playerNum - 1].OwnedProperties.size(); i++) //need to do same for other player
        {
            for(int j = 0; j<40; j++)
            {
                if(allPlayers[playerNum - 1].OwnedProperties[i].name == positionBoard.BoardSpaces[j].name)
                {
                    allPlayers[playerNum - 1].OwnedProperties[i].numHouses = positionBoard.BoardSpaces[j].numHouses;
                    allPlayers[playerNum - 1].OwnedProperties[i].numHotels = positionBoard.BoardSpaces[j].numHotels;
                }
            }
        }
          
          //after seeing what all can acquired, see if the player still wants to go through.
          cout << "Would you like to extend a deal to this player. Enter 1 for yes, 2 for no." << endl;
          cin >> userInput;
          
          if(userInput != 1) cout << "Trade cancelled" << endl; //cancel, even on invalid input
          else
          {
            cout << "Enter the amount of money you are offering" << endl; //prompt for money they want. Can enter 0.
            cin >> balanceOffered;
            while(balanceOffered > balance || balanceOffered < 0) //see if they can offer, then prompt them accordingly. Loop until a proper number is through
            {
              cout << "Input is invalid or you can not afford this trade" << endl;
              cin >> balanceOffered;
            }
            
            cout << "Enter the amount of money you are requesting" << endl;
            cin >> balanceRequested;
            while(balanceRequested > allPlayers[playerNum - 1].balance || balanceRequested < 0) //same process as above, but they are asking for other player.
            {
              cout << "Input is Invalid or other player can not afford this trade" << endl;
              cin >> balanceRequested;
            }
            
              //player here needs to refer to the list posted above. They will then enter the property they want to trade as it as indentified above. When they enter 0, it will go on.
              cout << "According to the list of properties you own above, enter the corresponding number of a property you would like to offer. Enter 0 when you are ready to move on or if you own no properties" << endl;
              while(userInput != 0) //loop
              {
                cin >> userInput;
                if(userInput != 0)
                {
                if(userInput > OwnedProperties.size() || userInput < 0) cout << "Invalid input" << endl; //vet bad imputs
                else
                {
                if(OwnedProperties[userInput-1].numHotels == 0 && OwnedProperties[userInput-1].numHouses == 0)
                {
                cout << OwnedProperties[userInput-1].name << " has been added to your trade package." << endl;
                tradeOffer.push_back(OwnedProperties[userInput-1]);
                }
                else cout << "Property has real estate and can not be traded" << endl; //cant trade properties with houses on them
                }
                }
              }
              
              //repeat above process, this time in regards to properties the other player owns
              cout << "According to the list of properties the other player owns above, enter the corresponding number of a property you would like to recieve. Enter 0 when you are ready to move on or if they own no properties" << endl;
              userInput = 1;
              while(userInput != 0)
              {
                cin >> userInput;
                if(userInput != 0)
                {
                if(userInput = 0) break;
                if(userInput > allPlayers[userInput - 1].OwnedProperties.size() || userInput < 0) cout << "Invalid input" << endl;
                else
                {
                if(allPlayers[userInput - 1].OwnedProperties[userInput-1].numHotels == 0 && allPlayers[userInput - 1].OwnedProperties[userInput-1].numHouses == 0)
                {
                cout << allPlayers[userInput - 1].OwnedProperties[userInput-1].name << " has been added to your trade package." << endl;
                tradeOffer.push_back(allPlayers[userInput - 1].OwnedProperties[userInput-1]);
                }
                else cout << "Property has real estate and can not be traded" << endl;
                }
                }
              }
              
              //print out the full trade package the player is offering.
              cout << "You are offering " << balanceOffered << " dollars and ";
              if(tradeOffer.size() == 0) cout << "no properties" << endl;
              else
              {
              cout << "the properties of ";
              for(int i = 0; i < tradeOffer.size(); i++)
              {
                cout << tradeOffer[i].name << " ";
              }
              }
              
              //print out the full trade package the player is requesting.
              cout << "For " << balanceRequested << " dollars and ";
              if(tradeRequest.size() == 0) cout << "no properties" << endl;
              else
              {
              cout << "the properties of ";
              for(int i = 0; i < tradeRequest.size(); i++)
              {
                cout << tradeRequest[i].name << " ";
              }
              }
              
              cout << endl;
              
              cout << "Do you wish to extend this trade? Enter 1 for yes, or 2 for no." << endl; //congfirm the player still wants to go through with the trade
              
              cin >> userInput;
              if(userInput != 1) cout << "Trade cancelled" << endl;
              else
              {
                if(allPlayers[playerNum-1].isComputer) cout << "Trade declined!" << endl; //computer players decline all trades.
                else
                {
                  cout << "Player " << playerNum << " do you accept this offer? Enter 1 for yes, or 2 for no." << endl; //ask other player if they wish to accept the trade.
                  cin >> userInput;
                  if(userInput != 1) cout << "Trade cancelled" << endl;
                  else
                  {
                    cout << "Trade accepted!" << endl;

                    //adjust balance of player. Should be vetted by this point, no checks needed.
                    balance = balance - balanceOffered;
                    balance = balance + balanceRequested;
                    
                    //adjust balance of other player. Should be vetted by this point, no checks needed.
                    allPlayers[playerNum-1].balance = allPlayers[playerNum-1].balance + balanceOffered;
                    allPlayers[playerNum-1].balance = allPlayers[playerNum-1].balance + balanceRequested;
                    
                    //This loop changes the owner number of the property on the board, and adjusts the vectors of both players.
                    for(int i = 0; i < tradeRequest.size(); i++)
                    {
                      for(int j = 0; j<40; j++) //not a super efficient way to do this, but iterate thru whole board to find the property and change it there. It needs to be changed in both places to ensure game state works + make vector useful.
                      {
                        if(positionBoard.BoardSpaces[j].name == tradeRequest[i].name)
                        {
                          positionBoard.BoardSpaces[j].ownerNumber = assignedNumber;
                          OwnedProperties.push_back(positionBoard.BoardSpaces[j]);
                          for(int k = 0; k < OwnedProperties.size(); k++)
                          {
                            if(allPlayers[playerNum-1].OwnedProperties[k].name == tradeOffer[i].name) allPlayers[playerNum-1].OwnedProperties.erase(allPlayers[playerNum-1].OwnedProperties.begin() + k);
                          }
                        }
                      }
                    }
                    
                    //same loop as above, but the perspective is changed
                    for(int i = 0; i < tradeOffer.size(); i++)
                    {
                      for(int j = 0; j<40; j++)
                      {
                        if(positionBoard.BoardSpaces[j].name == tradeOffer[i].name)
                        {
                          positionBoard.BoardSpaces[j].ownerNumber = playerNum;
                          allPlayers[playerNum-1].OwnedProperties.push_back(positionBoard.BoardSpaces[j]);
                          for(int k = 0; k < OwnedProperties.size(); k++)
                          {
                            if(OwnedProperties[k].name == tradeOffer[i].name) OwnedProperties.erase(OwnedProperties.begin() + k);
                          }
                        }
                      }
                    }
                    
                  }
                }
              }
          }
          
        }
    }


void Mortgage(Board &positionBoard){
    //This function allows a user to mortgage a property they own.
        string propName;
        int mortgageSpace = 0;
    cin.ignore();
      while(mortgageSpace == 0){
          cout << " What property would you like to mortgage? Type quit to exit" << endl; //prompt the user for input
          getline(cin, propName);
          if(propName == "quit"){
              return;
          }

    for(int i = 0; i < 40; i++) {
        if (positionBoard.BoardSpaces[i].name == propName) { //iterate thru board and mortgage through property. 
            mortgageSpace = i;
        }
    }
    if(mortgageSpace == 0){
        cout << "The property name entered could not be found please try again" << endl;  // incorrect name
    }
    if(mortgageSpace != 0){
        if(positionBoard.BoardSpaces[mortgageSpace].mortgageValue ==0){
            cout << "The property name entered cannot be mortgaged, try entering a different property" << endl; //prevent people from mortgaging go
            mortgageSpace = 0;
        }
        else if(positionBoard.BoardSpaces[mortgageSpace].ownerNumber != assignedNumber){
            cout << "The property entered is not owned by you, try entering a different property" << endl; //not owned by user
            mortgageSpace = 0;
        }
          else if(positionBoard.BoardSpaces[mortgageSpace].numHouses != 0 && positionBoard.BoardSpaces[mortgageSpace].numHotels != 0){
              cout << "The property name entered has houses/hotel built and cannot be mortgaged, try entering a different property" << endl; //cant mortgage with property
              mortgageSpace = 0;
          }
          else if(positionBoard.BoardSpaces[mortgageSpace].isMortgaged){
              cout << "The property name entered has already been mortgaged, try entering a different property" << endl; //already mortgaged
              mortgageSpace = 0;
          }
          //then mortage the property
          else{
              positionBoard.BoardSpaces[mortgageSpace].isMortgaged = true;
              balance += positionBoard.BoardSpaces[mortgageSpace].mortgageValue;
              cout << "The property " << positionBoard.BoardSpaces[mortgageSpace].name << " is now mortgaged, you have gained " << positionBoard.BoardSpaces[mortgageSpace].mortgageValue << endl;
          }
    }
      }

}

void Unmortgage(Board &positionBoard, Player &currentPlayer){
    //This is for unmortgaging mortgaged properly
    //Works the same as above function essentially, with the exception of interest.
    string propName;
    int unmortgageSpace = 0;
    int interest = 0;
    cin.ignore();
    while(unmortgageSpace == 0){
        cout << " What property would you like to unmortgage? Type quit to exit" << endl;
        getline(cin, propName);
        if(propName == "quit"){
            return;
        }

        for(int i = 0; i < 40; i++) {
            if (positionBoard.BoardSpaces[i].name == propName) {
                unmortgageSpace = i;
            }
        }
        if(unmortgageSpace == 0){
            cout << "The property name entered could not be found please try again" << endl;
        }
        if(unmortgageSpace != 0){
            if(positionBoard.BoardSpaces[unmortgageSpace].mortgageValue ==0){
                cout << "The property name entered cannot be unmortgaged, try entering a different property" << endl;
                unmortgageSpace = 0;
            }
            else if(positionBoard.BoardSpaces[unmortgageSpace].ownerNumber != assignedNumber){
                cout << "The property entered is not owned by you, try entering a different property" << endl;
                unmortgageSpace = 0;
            }

            else if(positionBoard.BoardSpaces[unmortgageSpace].isMortgaged == false){
                cout << "The property name entered is not mortgaged, try entering a different property" << endl;
                unmortgageSpace = 0;
            }
            else if(currentPlayer.balance < positionBoard.BoardSpaces[unmortgageSpace].mortgageValue){

            }

            else{
                positionBoard.BoardSpaces[unmortgageSpace].isMortgaged = false;
                interest = positionBoard.BoardSpaces[unmortgageSpace].price / 10; //get interest
                currentPlayer.balance = currentPlayer.balance - positionBoard.BoardSpaces[unmortgageSpace].mortgageValue - interest;
                cout << "The property " << positionBoard.BoardSpaces[unmortgageSpace].name << " is now unmortgaged which cost " << positionBoard.BoardSpaces[unmortgageSpace].mortgageValue + interest << endl;
            }
        }
    }
    }

void sellHouse(Board &positionBoard){
    //purpose is this function is to sell real estate

    int runningSum = 0;

    //loop to see if there are any properties that the player owns /w houses on them.
    for(int i = 0; i<40; i++)
    {
        if(positionBoard.BoardSpaces[i].ownerNumber == assignedNumber && (positionBoard.BoardSpaces[i].numHotels > 0 || positionBoard.BoardSpaces[i].numHouses < 0)) cout << i << ". " << positionBoard.BoardSpaces[i].name << endl;
        runningSum++;
    }

    //stop here if there are none.
    if(runningSum == 0) cout << "You have no houses you can sell.";
    else
    {
        int userInput;
        //large case statement here, same for all cases really.
        cout << "Enter the number corresponding to the house you would like to sell a house on." << endl;
        cin >> userInput;
        if(userInput < 0 || userInput > 39 || positionBoard.BoardSpaces[userInput].ownerNumber != assignedNumber || (positionBoard.BoardSpaces[userInput].numHotels == 0 && positionBoard.BoardSpaces[userInput].numHouses == 0)) cout << "Invalid input." << endl; // do a couple more checks here to validate if input is good
        else
        {
            if(positionBoard.BoardSpaces[userInput].color == "Brown") //filter first by color
            {
                switch(userInput)
                {
                    case 1:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1) //hotel is on space, need to switch for houses.
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4; //change houses + hotels
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse; // adjust balance
                        positionBoard.availableHotels++; //change houses player has + available
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && positionBoard.BoardSpaces[3].numHotels == 1) cout << "You can not sell real estate on this property" << endl; //cant sell while hotel is on other colored property.
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[3].numHouses) cout << "You can not sell real estate on this property" << endl; //more houses on other colored property
                    else
                    {
                        // make changes similar to above.
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    //all remaining cases have same dataflow as above.

                    case 3:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1)
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4;
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHotels++;
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && positionBoard.BoardSpaces[1].numHotels == 1) cout << "You can not sell real estate on this property" << endl;
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[1].numHouses) cout << "You can not sell real estate on this property" << endl;
                    else
                    {
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    default:
                    break;
                }
            }

            if(positionBoard.BoardSpaces[userInput].color == "Light Blue")
            {
                switch(userInput)
                {
                    case 6:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1)
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4;
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHotels++;
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && (positionBoard.BoardSpaces[8].numHotels == 1 || positionBoard.BoardSpaces[9].numHotels == 1)) cout << "You can not sell real estate on this property" << endl;
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[8].numHouses || positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[9].numHouses) cout << "You can not sell real estate on this property" << endl;
                    else
                    {
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    case 8:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1)
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4;
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHotels++;
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && (positionBoard.BoardSpaces[6].numHotels == 1 || positionBoard.BoardSpaces[9].numHotels == 1)) cout << "You can not sell real estate on this property" << endl;
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[9].numHouses || positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[6].numHouses) cout << "You can not sell real estate on this property" << endl;
                    else
                    {
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    case 9:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1)
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4;
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHotels++;
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && (positionBoard.BoardSpaces[8].numHotels == 1 || positionBoard.BoardSpaces[6].numHotels == 1)) cout << "You can not sell real estate on this property" << endl;
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[6].numHouses || positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[8].numHouses) cout << "You can not sell real estate on this property" << endl;
                    else
                    {
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    default:
                    break;
                }
            }

            if(positionBoard.BoardSpaces[userInput].color == "Pink")
                {
                switch(userInput)
                {
                    case 11:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1)
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4;
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHotels++;
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && (positionBoard.BoardSpaces[13].numHotels == 1 || positionBoard.BoardSpaces[14].numHotels == 1)) cout << "You can not sell real estate on this property" << endl;
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[13].numHouses || positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[14].numHouses) cout << "You can not sell real estate on this property" << endl;
                    else
                    {
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    case 13:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1)
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4;
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHotels++;
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && (positionBoard.BoardSpaces[11].numHotels == 1 || positionBoard.BoardSpaces[14].numHotels == 1)) cout << "You can not sell real estate on this property" << endl;
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[11].numHouses || positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[14].numHouses) cout << "You can not sell real estate on this property" << endl;
                    else
                    {
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    case 14:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1)
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4;
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHotels++;
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && (positionBoard.BoardSpaces[11].numHotels == 1 || positionBoard.BoardSpaces[13].numHotels == 1)) cout << "You can not sell real estate on this property" << endl;
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[11].numHouses || positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[13].numHouses) cout << "You can not sell real estate on this property" << endl;
                    else
                    {
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    default:
                    break;
                }
            }

            if(positionBoard.BoardSpaces[userInput].color == "Orange")
                {
                switch(userInput)
                {
                    case 16:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1)
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4;
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHotels++;
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && (positionBoard.BoardSpaces[18].numHotels == 1 || positionBoard.BoardSpaces[19].numHotels == 1)) cout << "You can not sell real estate on this property" << endl;
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[18].numHouses || positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[19].numHouses) cout << "You can not sell real estate on this property" << endl;
                    else
                    {
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    case 18:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1)
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4;
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHotels++;
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && (positionBoard.BoardSpaces[16].numHotels == 1 || positionBoard.BoardSpaces[19].numHotels == 1)) cout << "You can not sell real estate on this property" << endl;
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[16].numHouses || positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[19].numHouses) cout << "You can not sell real estate on this property" << endl;
                    else
                    {
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    case 19:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1)
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4;
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHotels++;
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && (positionBoard.BoardSpaces[18].numHotels == 1 || positionBoard.BoardSpaces[16].numHotels == 1)) cout << "You can not sell real estate on this property" << endl;
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[18].numHouses || positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[16].numHouses) cout << "You can not sell real estate on this property" << endl;
                    else
                    {
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    default:
                    break;
                }
            }

            if(positionBoard.BoardSpaces[userInput].color == "Red")
                {
                switch(userInput)
                {
                    case 21:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1)
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4;
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHotels++;
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && (positionBoard.BoardSpaces[23].numHotels == 1 || positionBoard.BoardSpaces[24].numHotels == 1)) cout << "You can not sell real estate on this property" << endl;
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[23].numHouses || positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[24].numHouses) cout << "You can not sell real estate on this property" << endl;
                    else
                    {
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    case 23:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1)
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4;
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHotels++;
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && (positionBoard.BoardSpaces[21].numHotels == 1 || positionBoard.BoardSpaces[24].numHotels == 1)) cout << "You can not sell real estate on this property" << endl;
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[21].numHouses || positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[24].numHouses) cout << "You can not sell real estate on this property" << endl;
                    else
                    {
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    case 24:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1)
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4;
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHotels++;
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && (positionBoard.BoardSpaces[23].numHotels == 1 || positionBoard.BoardSpaces[21].numHotels == 1)) cout << "You can not sell real estate on this property" << endl;
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[23].numHouses || positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[21].numHouses) cout << "You can not sell real estate on this property" << endl;
                    else
                    {
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    default:
                    break;
                }
            }

            if(positionBoard.BoardSpaces[userInput].color == "Yellow")
            {
                switch(userInput)
                {
                    case 26:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1)
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4;
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHotels++;
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && (positionBoard.BoardSpaces[27].numHotels == 1 || positionBoard.BoardSpaces[29].numHotels == 1)) cout << "You can not sell real estate on this property" << endl;
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[27].numHouses || positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[29].numHouses) cout << "You can not sell real estate on this property" << endl;
                    else
                    {
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    case 27:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1)
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4;
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHotels++;
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && (positionBoard.BoardSpaces[26].numHotels == 1 || positionBoard.BoardSpaces[29].numHotels == 1)) cout << "You can not sell real estate on this property" << endl;
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[26].numHouses || positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[29].numHouses) cout << "You can not sell real estate on this property" << endl;
                    else
                    {
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    case 29:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1)
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4;
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHotels++;
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && (positionBoard.BoardSpaces[26].numHotels == 1 || positionBoard.BoardSpaces[27].numHotels == 1)) cout << "You can not sell real estate on this property" << endl;
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[26].numHouses || positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[27].numHouses) cout << "You can not sell real estate on this property" << endl;
                    else
                    {
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    default:
                    break;
                }
            }

            if(positionBoard.BoardSpaces[userInput].color == "Green")
                {
                switch(userInput)
                {
                    case 31:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1)
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4;
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHotels++;
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && (positionBoard.BoardSpaces[32].numHotels == 1 || positionBoard.BoardSpaces[34].numHotels == 1)) cout << "You can not sell real estate on this property" << endl;
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[32].numHouses || positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[34].numHouses) cout << "You can not sell real estate on this property" << endl;
                    else
                    {
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    case 32:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1)
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4;
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHotels++;
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && (positionBoard.BoardSpaces[31].numHotels == 1 || positionBoard.BoardSpaces[34].numHotels == 1)) cout << "You can not sell real estate on this property" << endl;
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[31].numHouses || positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[34].numHouses) cout << "You can not sell real estate on this property" << endl;
                    else
                    {
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    case 34:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1)
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4;
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHotels++;
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && (positionBoard.BoardSpaces[31].numHotels == 1 || positionBoard.BoardSpaces[32].numHotels == 1)) cout << "You can not sell real estate on this property" << endl;
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[31].numHouses || positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[32].numHouses) cout << "You can not sell real estate on this property" << endl;
                    else
                    {
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    default:
                    break;
                }
            }
            
            if(positionBoard.BoardSpaces[userInput].color == "Dark Blue")
            {
                switch(userInput)
                {
                    case 37:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1)
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4;
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHotels++;
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && positionBoard.BoardSpaces[39].numHotels == 1) cout << "You can not sell real estate on this property" << endl;
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[39].numHouses) cout << "You can not sell real estate on this property" << endl;
                    else
                    {
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    case 39:
                    if(positionBoard.BoardSpaces[userInput].numHotels == 1)
                    {
                        positionBoard.BoardSpaces[userInput].numHotels = 0;
                        positionBoard.BoardSpaces[userInput].numHouses = 4;
                        balance = balance + 0.5 * positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHotels++;
                        numHotelsOwned--;
                    }
                    else if(positionBoard.BoardSpaces[userInput].numHotels == 0 && positionBoard.BoardSpaces[37].numHotels == 1) cout << "You can not sell real estate on this property" << endl;
                    else if(positionBoard.BoardSpaces[userInput].numHouses < positionBoard.BoardSpaces[37].numHouses) cout << "You can not sell real estate on this property" << endl;
                    else
                    {
                        positionBoard.BoardSpaces[userInput].numHouses = positionBoard.BoardSpaces[userInput].numHouses--;
                        balance = balance + 0.5*positionBoard.BoardSpaces[userInput].buyHouse;
                        positionBoard.availableHouses++;
                        numHousesOwned--;
                    }
                    break;

                    default:
                    break;
                }
            }
        }
    }
}


bool jailCheck(Board &positionBoard) {
    //this function handles jailing players, players getting out of jail, and players staying trapped in jail.
    //it returns true when a player needs to be given a normal turn after their decision, and false if they are still trapped or moved already.
        if(position == 30) { //if player is on go to jail square, throw them in jail. We also use this for jail by trips need to terminate turn here immediately
            position = 10;
            turnsJail = 3;
            numDoubles = 0;
        }
        else
        {

            if (jailFree >= 1 & position == 10) { 

            if(isComputer){                // computer automatically uses get out of jail free card
                cout << "Player " << assignedNumber << " has used their get out of jail free card" << endl;
                jailFree -= 1;
                turnsJail = 0;
                return true;
            }
            else{

            //prompt the player to spend their card if they have one.
                cout << "Do you wish to use your Get Out of Jail Free Card?" << endl;
                string temp;
                cin >> temp;
                if(temp == "yes"){              // using get out of jail free card
                    jailFree -= 1;
                    turnsJail = 0;
                    cout << "Player " << assignedNumber << "has used their get out of jail free card!" << endl;
                    return true;
                }
            }
            }
            if(turnsJail > 0) {

                if(isComputer){
                if(balance >= 50)
                {                // computer automatically uses get out of jail free card
                cout << "Player " << assignedNumber << " has paid their way out of jail!" << endl;
                jailFree -= 1;
                turnsJail = 0;
                balance = balance - 50;
                return true;
            }
            }
            else{
                cout << "Do you wish to pay $50 to get out of jail?" << endl; // allow player to pay their way out of jail.
                string temp;
                cin >> temp;
                if (temp == "yes") {              // paying to get out of jail
                    turnsJail = 0;
                    balance -= 50;
                    cout << "Player " << assignedNumber << "has paid their way out of jail!" << endl;
                    return true;
                }
            }
            }

            //check if player escapes by rolling doubles.
            int diceRoll1 = rand() % 6 + 1;
            int diceRoll2 = rand() % 6 + 1;

        //free them if they do, then move them according spaces.
        if(turnsJail > 0 && diceRoll1 == diceRoll2){      // need to get dice roll values
                turnsJail = 0;
            cout << "Player " << assignedNumber << " has rolled " << diceRoll1 + diceRoll2 << " by means of doubles and will escape jail!";
            position = position + diceRoll1 + diceRoll2;
            if(position == 12) jailUtility = diceRoll1 + diceRoll2; //this is needed so that the player will properly pay the rent on this square since they won't get an proper turn thru dice roll
                return false;

        }

          if(turnsJail == 1){                // waited out turns in jail
             turnsJail -= 1;
             balance = balance - 50; //must pay fee at this point.
             cout << "Player " << assignedNumber << " has been served their time and will be fined $50. They rolled a " << diceRoll1 + diceRoll2 << "this turn to escape, and will now move that many spaces." << endl;
             //move player in accordance with their attempted doubles roll.
             position = position + diceRoll1 + diceRoll2;
             if(position == 12) jailUtility = diceRoll1 + diceRoll2;
             return false;
          }

          if(turnsJail > 1){                // decrementing turns left in jail
              turnsJail -= 1;
              cout << "Player " << assignedNumber << " has " << turnsJail << " turns left in jail." << endl;
              return false;
          }

        }
        return false;           // if not on jail position
    }


void chanceCard(Board &positionBoard, int numPlayers, Player allPlayers[])
{
    //this function handles chance cards. since we assume the deck is shuffled all the time, we can boil this down to raw probability.
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
      balance = balance - numHousesOwned * 25;
      balance = balance - numHotelsOwned * 100;
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
        //this function handles chest cards. since we assume the deck is shuffled all the time, we can boil this down to raw probability.

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
      balance = balance - numHousesOwned * 40;
      balance = balance - numHotelsOwned * 115;
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
    //this function simplifies income tax for the player
    // it calculates their property value and returns it

    if(balance < 0) return 200; //debit the player 200 if they have no worth
    int runningSum = balance;
    for(int i = 0; i<40; i++)
    {
        if(positionBoard.BoardSpaces[i].ownerNumber == assignedNumber)
        {
            if(positionBoard.BoardSpaces[i].isMortgaged == 1) runningSum += positionBoard.BoardSpaces[i].mortgageValue; //add mortgaged to sum
            else runningSum += positionBoard.BoardSpaces[i].price; //add vlaue to sum
            if(positionBoard.BoardSpaces[i].numHouses > 0)
            {
                //add real estate prices t sum
                if(positionBoard.BoardSpaces[i].numHotels == 1) runningSum += positionBoard.BoardSpaces[i].buyHouse;
                else runningSum += positionBoard.BoardSpaces[i].numHouses * positionBoard.BoardSpaces[i].buyHouse;
            }
        }
    }
    return runningSum/10; //take 10%
}

void landOnProperty(Board &positionBoard, Player allPlayers[], int numPlayers, int diceRoll)
{
    //this function handles what happens when a player lands on a square. It is decently segmented as to possible outcomes.
    //first filter out all non rent properties
    if(!(positionBoard.BoardSpaces[position].isParking || positionBoard.BoardSpaces[position].isGo || positionBoard.BoardSpaces[position].isJail || positionBoard.BoardSpaces[position].isChance || positionBoard.BoardSpaces[position].isChest || positionBoard.BoardSpaces[position].isTax))
    {
    int userResponse;
    if(positionBoard.BoardSpaces[position].ownerNumber == 0) //case where property can be bought and is unowned
    {
        if(isComputer) //pc will always buy if it can
        {
            if(balance >= positionBoard.BoardSpaces[position].price)
            {
              balance = balance - positionBoard.BoardSpaces[position].price;
              positionBoard.BoardSpaces[position].ownerNumber = assignedNumber;
              cout << "Player " << assignedNumber << " has purchased " << positionBoard.BoardSpaces[position].name << "!" << endl;
              OwnedProperties.push_back(positionBoard.BoardSpaces[position]);
            }
            else {
            auction(positionBoard, numPlayers, allPlayers); //goes to auction if pc can not buy
            } // auction
        }
        else
        {
            if(balance >= positionBoard.BoardSpaces[position].price)
            {
            cout << "Would you like to buy " << positionBoard.BoardSpaces[position].name << "?" <<endl;
            cout << "Enter 1 for Yes, or 2 for No." << endl;
            cin >> userResponse;
            if(userResponse == 1)
            {
                balance = balance - positionBoard.BoardSpaces[position].price;
                positionBoard.BoardSpaces[position].ownerNumber = assignedNumber;
                cout << "Player " << assignedNumber << " has purchased " << positionBoard.BoardSpaces[position].name << "!" << endl;
                OwnedProperties.push_back(positionBoard.BoardSpaces[position]);
            }
            else auction(positionBoard, numPlayers, allPlayers); //goes to auction if player cant buy or refuses to
        }
        else 
            {
                cout << "You can not afford this property, and it will be auctioned." << endl;
                auction(positionBoard, numPlayers, allPlayers);
            }
        }
    }
    else if(positionBoard.BoardSpaces[position].isUtility && (!positionBoard.BoardSpaces[position].isMortgaged)) //utilities have unique dice rules, so they need their own case.
    {
        cout << "Player " << assignedNumber << " must pay player " << positionBoard.BoardSpaces[position].ownerNumber << " rent!" << endl;
        if(positionBoard.BoardSpaces[12].ownerNumber == positionBoard.BoardSpaces[28].ownerNumber)
        {
            if(jailUtility != 0)
            {
                balance = balance - jailUtility * 10;
                jailUtility = 0;
                allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].balance += jailUtility*10;
            }
            else
            {
            balance = balance - diceRoll * 10;
            allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].balance += diceRoll*10;
            }
        }
        else
        {
          if(jailUtility != 0)
            {
                balance = balance - jailUtility * 4;
                jailUtility = 0;
                allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].balance += jailUtility*4;
            }
            else
            {
            balance = balance - diceRoll * 4;
            allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].balance += diceRoll*4;
            } 
        }
    }
    else if(positionBoard.BoardSpaces[position].isRailroad && (!positionBoard.BoardSpaces[position].isMortgaged)) //railroads also have unique rent rules
    {
        cout << "Player " << assignedNumber << "must pay player " << positionBoard.BoardSpaces[position].ownerNumber << "rent!" << endl;
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
        if(!positionBoard.BoardSpaces[position].isMortgaged)
        {
            cout << "Player " << assignedNumber << "must pay player " << positionBoard.BoardSpaces[position].ownerNumber << "rent!" << endl;
            switch(positionBoard.BoardSpaces[position].numHouses) //need to determine how much rent is based on number of houses.
            {
                case 0: //either 0 houses or a hotel
                if(positionBoard.BoardSpaces[position].numHotels == 1) //check if hotel rent
                {
                    balance = balance - positionBoard.BoardSpaces[position].rentHotel;
                    allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].balance += positionBoard.BoardSpaces[position].rentHotel;
                }
                else //need to determine if a player owns all of this color, cause if they do, rent is doubled.
                {
                    string currentColor = positionBoard.BoardSpaces[position].color;
                    int currentOwner = positionBoard.BoardSpaces[position].ownerNumber;
                    int colorCounter = 0;

                    for(int i = 0; i<allPlayers[currentOwner-1].OwnedProperties.size(); i++)
                    {
                        if(allPlayers[currentOwner-1].OwnedProperties[i].color == currentColor) colorCounter++;
                    }

                    if((currentColor == "Brown" || currentColor == "Dark Blue") && colorCounter == 2)
                    {
                        balance = balance - positionBoard.BoardSpaces[position].rent*2;
                        allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].balance += positionBoard.BoardSpaces[position].rent;
                    }
                    else if(colorCounter == 3)
                    {
                        balance = balance - positionBoard.BoardSpaces[position].rent*2;
                        allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].balance += positionBoard.BoardSpaces[position].rent;
                    }
                    else
                    {
                        balance = balance - positionBoard.BoardSpaces[position].rent;
                        allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].balance += positionBoard.BoardSpaces[position].rent;
                    }
                    
                }
                break;

                case 1: //rent for 1 house
                balance = balance - positionBoard.BoardSpaces[position].rent1House;
                allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].balance += positionBoard.BoardSpaces[position].rent1House;
                break;

                case 2:
                balance = balance - positionBoard.BoardSpaces[position].rent2House;
                allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].balance += positionBoard.BoardSpaces[position].rent2House;
                break;

                case 3:
                balance = balance - positionBoard.BoardSpaces[position].rent3House;
                allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].balance += positionBoard.BoardSpaces[position].rent3House;
                break;

                case 4:
                balance = balance - positionBoard.BoardSpaces[position].rent4House;
                allPlayers[positionBoard.BoardSpaces[position].ownerNumber-1].balance += positionBoard.BoardSpaces[position].rent4House;
                break;
            }
        }
    }
    }
}

void buyHouse(Board &positionBoard)
{
    //this function is similar to sell house, but it handles for the inverse.
    //All of these loops at the start are to determine what color pairs the player has and can buy for. This is an older function in our development so it is a lot less efficient, but mostly works.
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

    if(runningSum == 0) //no color pairs possible
    {
        cout << "You can not buy any real estate!" << endl;
        return;
    }
    else
    { //print out the player menu
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
                case 1: //all cases are the same. Start by listing out color properties and getting user input.
                cout << "Enter the number of the corresponding property you would like to build real estate on." << endl;
                cout << "1. Mediterranean Avenue" << endl;
                cout << "2. Baltic Avenue" << endl;
                cin >> userChoice;
                if(userChoice < 1 || userChoice > 2) cout << "Invalid input." << endl;
                if(userChoice == 1 && positionBoard.BoardSpaces[1].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 1 && (positionBoard.BoardSpaces[1].numHouses > positionBoard.BoardSpaces[3].numHouses && positionBoard.BoardSpaces[3].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl; //this check works for the 2 property color combos, but not the 3 yet.
                else
                {
                    if(balance > positionBoard.BoardSpaces[1].buyHouse){ //you need to check first if players will follow even rule when they buy, then see if they are buying a house or a hotel.
                    if(positionBoard.BoardSpaces[1].numHouses == 4)
                    {   
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[1].numHouses = 0;
                        positionBoard.BoardSpaces[1].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                        }
                        else cout << "There are no hotels available for purchase!" << endl; //there may not be hotels left
                    }
                    else if(positionBoard.availableHouses > 0)
                    {
                    positionBoard.BoardSpaces[1].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[1].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl; //may not be housers left
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
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[3].numHouses = 0;
                        positionBoard.BoardSpaces[3].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                    }
                    else cout << "There are no hotels available for purchase!" << endl;
                    }
                    else if(positionBoard.availableHouses > 0)
                    { positionBoard.BoardSpaces[3].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[3].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                break;

                //all following cases use the same general code

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
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[6].numHouses = 0;
                        positionBoard.BoardSpaces[6].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                    }
                    else cout << "There are no hotels available for purchase!" << endl;
                    }
                    else if(positionBoard.availableHouses > 0)
                    { positionBoard.BoardSpaces[6].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[6].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl;
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
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[8].numHouses = 0;
                        positionBoard.BoardSpaces[8].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                    }
                    else cout << "There are no hotels available for purchase!" << endl;
                    }
                    else  if(positionBoard.availableHouses > 0)
                    {positionBoard.BoardSpaces[8].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[8].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl;
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
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[9].numHouses = 0;
                        positionBoard.BoardSpaces[9].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                    }
                    else cout << "There are no hotels available for purchase!" << endl;
                    }
                    else  if(positionBoard.availableHouses > 0)
                    {positionBoard.BoardSpaces[9].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[9].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl;
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
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[11].numHouses = 0;
                        positionBoard.BoardSpaces[11].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                    }
                    else cout << "There are no hotels available for purchase!" << endl;
                    }
                    else  if(positionBoard.availableHouses > 0)
                    {positionBoard.BoardSpaces[11].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[11].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl;
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
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[13].numHouses = 0;
                        positionBoard.BoardSpaces[13].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                    }
                    else cout << "There are no hotels available for purchase!" << endl;
                    }
                    else  if(positionBoard.availableHouses > 0)
                    {positionBoard.BoardSpaces[13].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[13].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                if(userChoice == 3 && positionBoard.BoardSpaces[14].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 3 && (positionBoard.BoardSpaces[14].numHouses > positionBoard.BoardSpaces[11].numHouses && positionBoard.BoardSpaces[11].numHotels == 0) && (positionBoard.BoardSpaces[14].numHouses > positionBoard.BoardSpaces[13].numHouses && positionBoard.BoardSpaces[13].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[13].buyHouse){
                    if(positionBoard.BoardSpaces[14].numHouses == 4)
                    {
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[14].numHouses = 0;
                        positionBoard.BoardSpaces[14].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                    }
                    else cout << "There are no hotels available for purchase!" << endl;
                    }
                    else  if(positionBoard.availableHouses > 0)
                    {positionBoard.BoardSpaces[14].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[14].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl;
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
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[16].numHouses = 0;
                        positionBoard.BoardSpaces[16].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                    }
                    else cout << "There are no hotels available for purchase!" << endl;
                    }
                    else  if(positionBoard.availableHouses > 0)
                    {positionBoard.BoardSpaces[16].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[16].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl;
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
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[18].numHouses = 0;
                        positionBoard.BoardSpaces[18].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                    }
                    else cout << "There are no hotels available for purchase!" << endl;
                    }
                    else  if(positionBoard.availableHouses > 0)
                    {positionBoard.BoardSpaces[18].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[18].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                if(userChoice == 3 && positionBoard.BoardSpaces[19].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 3 && (positionBoard.BoardSpaces[19].numHouses > positionBoard.BoardSpaces[16].numHouses && positionBoard.BoardSpaces[16].numHotels == 0) && (positionBoard.BoardSpaces[19].numHouses > positionBoard.BoardSpaces[18].numHouses && positionBoard.BoardSpaces[18].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[19].buyHouse){
                    if(positionBoard.BoardSpaces[19].numHouses == 4)
                    {
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[19].numHouses = 0;
                        positionBoard.BoardSpaces[19].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                    }
                    else cout << "There are no hotels available for purchase!" << endl;
                    }
                    else  if(positionBoard.availableHouses > 0)
                    {positionBoard.BoardSpaces[19].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[19].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl;
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
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[21].numHouses = 0;
                        positionBoard.BoardSpaces[21].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                    }
                    else cout << "There are no hotels available for purchase!" << endl;
                    }
                    else  if(positionBoard.availableHouses > 0)
                    {positionBoard.BoardSpaces[21].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[21].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl;
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
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[23].numHouses = 0;
                        positionBoard.BoardSpaces[23].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                    }
                    else cout << "There are no hotels available for purchase!" << endl;
                    }
                    else  if(positionBoard.availableHouses > 0)
                    {positionBoard.BoardSpaces[23].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[23].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                if(userChoice == 3 && positionBoard.BoardSpaces[24].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 3 && (positionBoard.BoardSpaces[24].numHouses > positionBoard.BoardSpaces[21].numHouses && positionBoard.BoardSpaces[21].numHotels == 0) && (positionBoard.BoardSpaces[24].numHouses > positionBoard.BoardSpaces[23].numHouses && positionBoard.BoardSpaces[23].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[24].buyHouse){
                    if(positionBoard.BoardSpaces[24].numHouses == 4)
                    {
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[24].numHouses = 0;
                        positionBoard.BoardSpaces[24].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                    }
                    else cout << "There are no hotels available for purchase!" << endl;
                    }
                    else  if(positionBoard.availableHouses > 0)
                    {positionBoard.BoardSpaces[24].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[24].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl;
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
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[26].numHouses = 0;
                        positionBoard.BoardSpaces[26].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                    }
                    else cout << "There are no hotels available for purchase!" << endl;
                    }
                    else  if(positionBoard.availableHouses > 0)
                    {positionBoard.BoardSpaces[26].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[26].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl;
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
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[27].numHouses = 0;
                        positionBoard.BoardSpaces[27].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                    }
                    else cout << "There are no hotels available for purchase!" << endl;
                    }
                    else  if(positionBoard.availableHouses > 0)
                    {positionBoard.BoardSpaces[27].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[27].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                if(userChoice == 3 && positionBoard.BoardSpaces[29].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 3 && (positionBoard.BoardSpaces[29].numHouses > positionBoard.BoardSpaces[26].numHouses && positionBoard.BoardSpaces[26].numHotels == 0) && (positionBoard.BoardSpaces[29].numHouses > positionBoard.BoardSpaces[27].numHouses && positionBoard.BoardSpaces[27].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[29].buyHouse){
                    if(positionBoard.BoardSpaces[29].numHouses == 4)
                    {
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[29].numHouses = 0;
                        positionBoard.BoardSpaces[29].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                    }
                    else cout << "There are no hotels available for purchase!" << endl;
                    }
                    else  if(positionBoard.availableHouses > 0)
                    {positionBoard.BoardSpaces[29].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[29].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl;
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
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[31].numHouses = 0;
                        positionBoard.BoardSpaces[31].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                    }
                    else cout << "There are no hotels available for purchase!" << endl;
                    }
                    else  if(positionBoard.availableHouses > 0)
                    {positionBoard.BoardSpaces[31].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[31].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl;
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
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[32].numHouses = 0;
                        positionBoard.BoardSpaces[32].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                    }
                    else cout << "There are no hotels available for purchase!" << endl;
                    }
                    else  if(positionBoard.availableHouses > 0)
                    {positionBoard.BoardSpaces[32].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[32].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                if(userChoice == 3 && positionBoard.BoardSpaces[34].numHotels == 1) cout << "You can not add more real estate to this property." << endl;
                else if(userChoice == 3 && (positionBoard.BoardSpaces[34].numHouses > positionBoard.BoardSpaces[31].numHouses && positionBoard.BoardSpaces[31].numHotels == 0) && (positionBoard.BoardSpaces[34].numHouses > positionBoard.BoardSpaces[32].numHouses && positionBoard.BoardSpaces[32].numHotels == 0)) cout << "You must build on your other properties of this color first." << endl;
                else
                {
                    if(balance > positionBoard.BoardSpaces[34].buyHouse){
                    if(positionBoard.BoardSpaces[34].numHouses == 4)
                    {
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[34].numHouses = 0;
                        positionBoard.BoardSpaces[34].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                    }
                    else cout << "There are no hotels available for purchase!" << endl;
                    }
                    else  if(positionBoard.availableHouses > 0)
                    {positionBoard.BoardSpaces[34].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[34].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl;
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
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[37].numHouses = 0;
                        positionBoard.BoardSpaces[37].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                    }
                    else cout << "There are no hotels available for purchase!" << endl;
                    }
                    else  if(positionBoard.availableHouses > 0)
                    {positionBoard.BoardSpaces[37].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[37].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl;
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
                        if(positionBoard.availableHotels > 0)
                        {
                        positionBoard.BoardSpaces[39].numHouses = 0;
                        positionBoard.BoardSpaces[39].numHotels = 1;
                        positionBoard.availableHotels--;
                        numHotelsOwned++;
                    }
                    else cout << "There are no hotels available for purchase!" << endl;
                    }
                    else  if(positionBoard.availableHouses > 0)
                    {positionBoard.BoardSpaces[39].numHouses++;
                    balance = balance - positionBoard.BoardSpaces[39].buyHouse;
                    positionBoard.availableHouses--;
                    numHousesOwned++;
                }
                else cout << "There are no houses available for purchase!" << endl;
                }
                else cout << "You can not afford to buy real estate on this property." << endl;
            }
                break;
            }
        }
    }
}

    void auction(Board &positionBoard, int numPlayers, Player allPlayers[], int forcedProperty = 0) { // takes in bidding property
        //this function handles bid when players do not buy things.
        int propertyforAuction = position;
        if(forcedProperty != 0) propertyforAuction = forcedProperty;
        int bidPrice = 0;
        int computerBidMax = positionBoard.BoardSpaces[propertyforAuction].price * 1.25; //computers wont bid over this
        bool auctionContinue = true;
        int chosenComp = -1;
        int numAuction = 0;
        int auctionWinner= -1;

        //list what is being auction
        cout << "The current auction is for: " << positionBoard.BoardSpaces[propertyforAuction].name << endl;
        for(int i = 0; i < numPlayers; i++) {
            if(allPlayers[i].gameOver == 0) allPlayers[i].isAuction = true;

            if(allPlayers[i].isComputer == 1) {
                if(allPlayers[i].balance < computerBidMax){ //go ahead and drop computers if they can't afford it.
                    allPlayers[i].isAuction = false;
                    cout << "Player " << i+1 << " has dropped out of the auction" << endl;
                }
            }
        }

        //computers automatically bid to their max. This is technically out of order, but it will save time since the players will have to deal with it anyway
        for(int i = 0; i < numPlayers; i++){
            if(allPlayers[i].isComputer == 1 && allPlayers[i].isAuction == true && allPlayers[i].gameOver == 0) {
                chosenComp = i;
                bidPrice = computerBidMax;
                break;
            }
        }

        //first computer to bid will always win
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


            //manage auctioning
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
                else
                {
                    for(int i = 0; i< numPlayers; i++)
                    {
                        if(allPlayers[i].isAuction == true) auctionWinner = i;
                    }
                }
            }
            if(numAuction == 1){
                auctionContinue = false;
                cout << "The winner of the bid is player " << auctionWinner+1 << endl;
                allPlayers[auctionWinner].balance = allPlayers[auctionWinner].balance - bidPrice;
                positionBoard.BoardSpaces[propertyforAuction].ownerNumber = assignedNumber;
                allPlayers[auctionWinner].OwnedProperties.push_back(positionBoard.BoardSpaces[propertyforAuction]);
            }


        }

    }

Player()
{
    isComputer = 0;
        position = 0;
        numDoubles = 0;
        numHotelsOwned = 0;
        numHousesOwned = 0;
        balance = 1500;
        isAuction = false;
        turnsJail = 0;
        jailFree = 0;
        jailOut = 0;
        jailUtility = 0;
        gameOver = 0;
}

//Like the other objects, player has no dynamic memory or a reason for assignment.
};