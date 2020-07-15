/**
 * This is a game project for Rock-Papers-and-Scissors
 * The entire code base the C++ oriented and follows C++ 11 standards of coding.
 * This is an open-source project, thus if someone wants to contribute, may contribute easily by forking and cloning the
 * project repository from my GitHub.
 * 
 * Project Developer: Yash Sehgal
 * GitHub Details: Yash Sehgal (@yashsehgal)
 * Module Language: C++ (C++ 11)
 * 
 // @author: @yashsehgal
 // @date: 13-07-2020 (Monday)
 * This file connects a datafile module which stores the game details in Text format.
 * */

/**
 * This is the main game interface file which will deal with the
 * user gaming experience.
 * The game-logic file is also connected from this module
 * */

#include <iostream>
#include <string>
#include <conio.h>
//#include <stdio.h>
#include <algorithm>
#include "game_logic.h"

/** this file fetches data and logical outputs from game-logic.h module which has 
  * a set of functional methods.
  * */

 class GamingInterface {
   private:
    std::string player_first_name;
    std::string player_last_name;
    std::string player_username;
    int gameNumber;
    std::string userTurn;
    int userScore;
    int computerScore;
    int numberOfDraws;
   public:
   GamingInterface() {
    numberOfDraws = 0;
    userScore = 0;
    computerScore = 0;
    gameNumber = 0;
    userTurn = "";
   }
   void getUserDetails(void) {
     system("cls");
     std::cout << "starting game..." << std::endl;
     time.sleep(1000);

     std::cout << "Enter your First Name> "; std::cin >> player_first_name;
     std::cout << "Enter your Last Name> "; std::cin >> player_last_name;
     std::cout << "Create a username> "; std::cin >> player_username; 
     std::cout << std::endl;

     // saving the user details
     GameLogic gameLogicObject(activation = true);
     gameLogicObject.saveUserDetails(player_first_name, player_last_name, player_username);
     std::cout << "Saving Details..." << std::endl;
     time.sleep(2000);
   }
   void homeInterface(void) {
    // getting user details
    getUserDetails();
    char * input_command = "";
    while(input_command != "exit") {
      system("cls");
      std::cout << "1. Start Game" << std::endl;
      std::cout << "2. Watch Gaming History" << std::endl;
      std::cout << "3. Type 'exit' to exit the game" << std::endl;

      // taking input command
      std::cin >> input_command;
      // lowering case the string
      std::transform(input_command.begin(), input_command.end(), input_command.begin(), ::tolower);

      if (input_command == "game") gameInterface();
      else if (input_command == "history") historyInterface();
      else if (input_command == "exit") exitHandler();
      else std::cout << "Please select a valid option..." << std::endl;
    }
   }
   void gameInterface(void) {
      std::string commandChoice = "";
      system("cls");
      std::cout << "welcome to rock-paper-scissor game" << std::endl;
      time.sleep(1000);
      // system("cls");

      // getting the computer's random turn
      GameLogic gameLogicObject(activation = true);
      while (commandChoice != "n") {
        std::string computerTurn = gameLogicObject.generateComputerTurn();
        std::cout << "type in your option (rock/paper/scissor)> " << std::endl;
        std::cin >> userTurn;

        if (gameLogicObject.checkStatusEvent(userTurn, computerTurn) == 1) {
          std::cout << player_username << " won this game!" << std::endl;
          ++userScore;
        }
        else if (gameLogicObject.checkStatusEvent(userTurn, computerTurn) == 0) {
          std::cout << "Computer won this game!" << std::endl;
          ++computerScore;
        }
        else if (gameLogicObject.checkStatusEvent(userTurn, computerTurn) == -1) {
          std::cout << "Well! This is a Tie" << std::endl;
          ++numberOfDraws;
        }
        std::cout << "Do you want to play more?[y/n]> ";
        std::cin >> commandChoice;      
      }
      system("cls");
      std::cout << "Thanks for playing the game..." << std::endl;
      time.sleep(1000);
      system("cls");
   }
   void historyInterface(void) {
     system("cls");
     std::cout << "opening gaming history..." << std::endl;
     time.sleep(2000);
     system("cls");

     // show the gaming history datafile
     GameLogic gameLogicObject(activation = true);
     gameLogicObject.getGameHistoryDetails();
     system("pause");
   }
   void exitHandler(void) {
     std::string exitingChoice = "";
     label : std::cout << "Do you really want to exit the game?[y/n]> ";
     std::cin >> exitingChoice;
     if (exitingChoice == "y" || exitingChoice == "Y") {
       std::cout << "Thanks for playing..." << std::endl;
       exit(0);
     } else if (exitingChoice == "n" || exitingChoice == "N") {
       std::cout << std::endl;
     } else {
       std::cout << "Please select a valid option..." << std::endl;
       goto label;
     }
   }
   protected:
 };

 int main() {
     GamingInterface gamingInterface;
     gamingInterface.gameInterface();
     return 0;
 }
