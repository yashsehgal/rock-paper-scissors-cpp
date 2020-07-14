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
#include <stdio.h>
#include <algorithm>
#include <game_logic.h>

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
   void homeInterface(void) {
    char * input_command = "";
    while(input_command != "exit") {
      std::cout << "1. Start Game" << std::endl;
      std::cout << "2. Watch Gaming History" << std::endl;
      std::cout << "3. Type 'exit' to exit the game" << std::endl;

      // taking inputcommand 
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
      system("cls");
      std::cout << "welcome to rock-paper-scissor game" << std::endl;
      time.sleep(1000);
      system("cls");

      // getting the computer's random turn
      GameLogic gameLogicObject(activation = true);
      std::string computerTurn = gameLogicObject.generateComputerTurn();
      std::cout << "type in your option (rock/paper/scissor)> " << std::endl;
      std::cin >> userTurn;

      if (gameLogicObject.checkStatusEvent(userTurn, computerTurn) == 1) {
        ++userScore;
      }
      else if (gameLogicObject.checkStatusEvent(userTurn, computerTurn) == 0) {
        ++computerScore;
      }
      else if (gameLogicObject.checkStatusEvent(userTurn, computerTurn) == -1) {
        ++numberOfDraws;
      }
   }
   void historyInterface(void);
   void exitHandler(void);
   protected:
 };
