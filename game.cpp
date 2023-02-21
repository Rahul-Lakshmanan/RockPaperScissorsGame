//
// Created by Rahul Lakshmanan on 4/22/2021.
//

#include <iostream>
#include <string>
#include <algorithm>
#include "game.h"
#include "inputValidation.h"

std::string player_take_turn() {
  std::string playerMove;

  do {
    std::cout << "Enter (R)ock, (P)aper, or (S)cissors for your move: " << std::endl;
    std::getline (std::cin, playerMove);
  } while (!player_move_valid(playerMove));

  return playerMove;
}

std::string ai_take_turn(const int& moveNumber) {     // moveNumber = number generator by random number generator

  if (moveNumber == 0) {
    std::cout << "The ai played rock." << std::endl;
    return "rock";
  } else if (moveNumber == 1) {
    std::cout << "The ai played paper." << std::endl;
    return "paper";
  } else {
    std::cout << "The ai played scissors." << std::endl;
    return "scissors";
  }
}

std::string winning_player(const std::string& playerMove, const std::string& moveToWin) {
  if (playerMove == moveToWin) {
    return "player";
  } else {
    return "ai";
  }
}

std::string decide_winner(const std::string& playerMove, const std::string& aiMove) {
  if ((playerMove == "rock" || aiMove == "rock") && (aiMove == "scissors" || playerMove == "scissors")) {   // potential combination of moves
    return winning_player(playerMove, "rock");
  } else if ((playerMove == "rock" || aiMove == "rock") && (aiMove == "paper" || playerMove == "paper")) {    // potential combination of moves
    return winning_player(playerMove, "paper");
  } else {
    return winning_player(playerMove, "scissors");
  }
}

bool game_over(const std::string& playerMove, const std::string& aiMove, std::string& winner) {
  std::string replay;

  if (playerMove == aiMove) {       // checks for a tie game
    std::cout << "You and the AI both played " << playerMove << "." << std::endl;
    std::cout << "Keep playing until someone wins." << std::endl;
    return false;
  } else {
    winner = decide_winner(playerMove, aiMove);
  }

  replay = display_win_message(winner);     // gets if user wants to continue playing or stop

  if (replay == "yes") {
    return false;
  } else {
    return true;
  }
}

std::string display_win_message(const std::string& winner) {
  std::string replay;

  if (winner == "player") {
    std::cout << "You win!" << std::endl;
  } else {
    std::cout << "The AI wins :(" << std::endl;
  }

  do {
    std::cout << "Would you like to replay the game?" << std::endl;
    std::cout << "Enter (Y)es or (N)o: " << std::endl;
    std::getline(std::cin, replay);

    std::transform(replay.begin(), replay.end(), replay.begin(), ::tolower);  // converts line to lowercase
    remove_whitespace(replay);    // removes preceding and trailing whitespace from line
  } while (!replay_is_valid(replay));   // checks if yes or no is inputted by user

  return replay;
}