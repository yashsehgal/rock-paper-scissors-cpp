/**
 * This is a game logic project for Rock-Papers-and-Scissors
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
  // TODO: To design an algorithm which follows the gaming discipline.
  // ? After developing the logic we need to design an interactive interface for our game.
  // ! This is the game's logic file which will be directly used in the gaming interface environment.
 * */


// creating a macro by following object-oriented programming approach.
#ifndef _GAME_LOGIC__
#define _GAME_LOGIC__

// importing some useful modules for the code.
#include <iostream>
#include <string>
#include <fstream>
// #include <datetimeapi.h>
#include <ctime>
#include <random>

class GameLogic {
  private:
  char computer_turn_options[10][3];
  public:
  GameLogic(bool activation = false) {
    computer_turn_options[10][3] = {"rock", "paper", "scissors"};
  }
  // this function will return the user and computer score at every iteration of the gameplay.
  std::string getWinnerName(int user_score, int computer_score) {
    if (user_score > computer_score) {
      std::string statement = "user"; 
      return statement;
    } else if (user_score < computer_score) {
        std::string statement = "computer"; 
        return statement;
    } else if (user_score == computer_score) {
      std::string statement = "draw";
      return statement;
    } else {
      return ;
    }
  }
  /***
   * Check Status Event function has a logical game metrics which will compare the
   * user turns and option-selections and returns the respective values according to the
   * game logical events. The function will just return the score increment and decrement
   * values after comparing the user's moves.
  */
  int checkStatusEvent(char * user_turn, char * computer_turn) {
    // checking if the input options are non-empty
    if (user_turn != '\0' && computer_turn != '\0') {
      // comparing the user-selection events
      // converting all possible inputs to a specific keyword - for user-turn
      if (user_turn == "rock" || user_turn == "Rock" || 
          user_turn == "r" || user_turn == "R") user_turn = "rock";
      else if (user_turn == "paper" || user_turn == "p" || 
               user_turn == "P" || user_turn == "Paper") user_turn = "paper";
      else if (user_turn == "scissor" || user_turn == "s" || 
               user_turn == "S" || user_turn == "Scissor") user_turn = "scissor";
      
      // converting all possible inputs to a specific keyword - for computer-turn
      if (computer_turn == "rock" || computer_turn == "Rock" || 
          computer_turn == "r" || computer_turn == "R") computer_turn = "rock";
      else if (computer_turn == "paper" || computer_turn == "p" || 
               computer_turn == "P" || computer_turn == "Paper") computer_turn = "paper";
      else if (computer_turn == "scissor" || computer_turn == "s" || 
               computer_turn == "S" || computer_turn == "Scissor") computer_turn = "scissor";

      // comparing game logical events
      if (user_turn == "rock" && computer_turn == "rock") return -1;
      else if (user_turn == "rock" && computer_turn == "paper") return 0; 
      else if (user_turn == "rock" && computer_turn == "scissor") return 1;
      else if (user_turn == "paper" && computer_turn == "rock") return 1;
      else if (user_turn == "paper" && computer_turn == "paper") return -1;
      else if (user_turn == "paper" && computer_turn == "scissor") return 0;
      else if (user_turn == "scissor" && computer_turn == "rock") return 0;
      else if (user_turn == "scissor" && computer_turn == "paper") return 1;
      else if (user_turn == "scissor" && computer_turn == "scissor") return -1;
      else return ;
    }
  }
  // this function will  save the gaming history in a text file,
  // in the format of:
  /**
   *  Date(DD|MM|YYYY) - Time(IST+19 format)
   * User wins, Computer Wins, Number of Draws 
   */
  void saveGameData(void) {
    std::fstream fileObject;
    fileObject.open("game-history.txt", ios::in | ios::app);
    // fetching the current date and time
    std::time_t current_time =  std::time(0);
    // converting the time values into string
    char* bufferStringDateTime = std::ctime(&current_time);
    // checking if the file is open or not
    if (!fileObject) std::cout << "datafile is unable to open..." << std::endl;
    // else writing data in the datafile
    else fileObject.write((char *)&bufferStringDateTime, sizeof(bufferStringDateTime));
    // closing the datafile
    fileObject.close();
  }
  void saveGameplayDetails(char * username, int user_score, int computer_score) {
    char * computer_name = "computer";
    std::to_string(user_score);
    std::to_string(computer_score);
    std::transform(user_score.begin(), user_score.end(), user_score.begin(), ::tolower);
    std::transform(computer_score.begin(), computer_score.end(), computer_score.begin(), ::tolower);
    // opening file in a fstream object
    std::fstream gameplayDetailsFile;
    gameplayDetailsFile.open("game_history_details.txt", ios::in | ios::app);
    // checking if the file is open or not
    if (!gameplayDetailsFile) std::cout << "datafile is unable to open..." << std::endl;
    else {
      getGameHistoryDetails();
      // char * writingText = computer_name;
      gameplayDetailsFile.write((char *)&computer_name, sizeof(computer_name));
      gameplayDetailsFile.write((std::string)&computer_score, sizeof(computer_score));
      gameplayDetailsFile.write((std::string)&username, sizeof(username));
      gameplayDetailsFile.write((std::string)&user_score, sizeof(user_score));
    }
  }
  // this function will show the data
  void getGameHistoryDetails(void) {
    std::fstream fileObject;
    fileObject.open("game-history.txt", ios::out);
    // checking if the file is open or not
    if (!fileObject) std::cout << "datafile is unable to open..." << std::endl;
    else {
      // showing the complete data from the text datafile
      char * fetchString = std::getline(fileObject);
      std::cout << fetchString << std::endl;
      // closing the datafile after being used
      fileObject.close();
    }
  }
  std::string generateComputerTurn(void) {
    std::random_device randomDeviceNumber;
    std::mt19937 gen(randomDeviceNumber());
    std::uniform_int_distribution<> distr(0, 2);
    int randomValueIndex = distr(gen);
    std::string randomComputerTurn = * computer_turn_options[randomValueIndex];
    return (std::string)randomComputerTurn;
  }
  /**
   * This function is to save the user details throughout the gaming experience
   * */

  void saveUserDetails(std::string userFirstName, std::string userLastName, std::string username) {
    std::fstream userDetailsFileObject; 
    userDetailsFileObject.open("user_details.txt", ios::in | ios::app);
    // checking if the datafile is open or not
    if (!userDetailsFileObject) std::cout << "datafile is unable to open..." << std::endl;
    else {
      userDetailsFileObject.write((std::string)&userFirstName, sizeof(userFirstName));
      userDetailsFileObject.write((std::string)&userLastName, sizeof(userLastName));
      userDetailsFileObject.write((std::string)*username, sizeof(username));
    }
  }
  protected:
};

#endif