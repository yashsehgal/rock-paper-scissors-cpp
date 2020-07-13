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

class GameLogic {
  private:
  char computer_turn_options[10][3];
  public:
  GameLogic() {
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
   * game logical events. The function will just return the score increament and decreament
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
  protected:
};

#endif