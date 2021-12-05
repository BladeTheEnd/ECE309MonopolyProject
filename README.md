Monopoly is a board game in which a a group of at least 2 players sit down and compete for property. By acquiring property and buying real estate on it, players are able to increase that propert's value. Whenever a player lands on a a property owned by another player, they must play that player money. The chance and chest decks allow the players to occasionally draw cards that affect gameplay, and also sometimes players may find themselves trapped in jail! The game ends for a player when they can not afford to pay off a debt they have to another player, and the game is over when there is only one player left standing.

Our version is faithful to the original ruleset of Monopoly. The only quirk about our version is that player's must complete all of the movement they are given in a turn before they are allowed to engage in any player actions. They are allowed to buy property as apart of this movement. Auctions will also occur during this time.

To compile our code, you must have a c++ compiler. The main.cpp and Monopoly.h must be in the same file. All of the includes into Monopoly.h should be standard in any given c++ compiler. Our debugging was done using g++ through Grendel and Clion, so there are no known dependencies for our code other than having the two files within the same folder. 

To run  our code using g++, simply paste this into the command line: 
g++ -g -o monopoly main.cpp
Then run
./monopoly

Some interesting features about our version include:
Due to our implementation of Chance/Chest, it is possible to have multiple get out of jail free cards!
Flow of a turn is very simple for players to replicate.
Income tax will automatically be calculated for the player and it will make the easiest choice for them instantly.
The computer AI is very simple, and will always deny trades, always get themselves out of jail when they can, and will only invest up to a certain number on auctions. They are pushovers.

Status Report:
At the moment, the code works as intended for everything that we planned to do.
The only bug that we know at the moment is that the even rule does not apply properly when buying property. It is possible to have 1 2 0 houses instead of a proper 1 1 1. It works for selling houses, as that is less restrictive. 
