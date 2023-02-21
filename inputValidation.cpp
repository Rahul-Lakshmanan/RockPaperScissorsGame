//
// Created by Rahul Lakshmanan on 4/22/2021.
//

#include <string>
#include <algorithm>
#include <vector>
#include <random>
#include "inputValidation.h"

bool player_move_valid(std::string& move) {
  std::transform(move.begin(), move.end(), move.begin(), ::tolower);  // converts line to lowercase
  remove_whitespace(move);    // removes preceding and trailing whitespace

  std::vector<std::string> rockValidMoves = {"r", "(r)ock", "rock"};  // valid inputs for rock
  std::vector<std::string> paperValidMoves = {"p", "(p)aper", "paper"};   // valid inputs for paper
  std::vector<std::string> scisscorValidMoves = {"s", "(s)cissors", "scissors"};    // valid inputs for scissors

  if (std::find(rockValidMoves.begin(), rockValidMoves.end(), move) != rockValidMoves.end()) {
    // iterates through vector containing valid inputs for "rock"
    move = "rock";
    return true;
  } else if (std::find(paperValidMoves.begin(), paperValidMoves.end(), move) != paperValidMoves.end()) {
    // iterates through vector containing valid inputs for "paper"
    move = "paper";
    return true;
  } else if (std::find(scisscorValidMoves.begin(), scisscorValidMoves.end(), move) != scisscorValidMoves.end()) {
    // iterates through vector containing valid inputs for "scissors"
    move = "scissors";
    return true;
  } else {
    return false;
  }
}

bool replay_is_valid(std::string& input) {
  std::transform(input.begin(), input.end(), input.begin(), ::tolower); // converts line to lowercase
  remove_whitespace(input);   // removes preceding and trailing whitespace

  std::vector<std::string> validYesInputs = {"y", "(y)es", "yes"};   // valid inputs to continue game
  std::vector<std::string> validNoInputs = {"no", "(n)o", "n"};   // valid inputs to end game

  if (std::find(validYesInputs.begin(), validYesInputs.end(), input) != validYesInputs.end()) {
    // iterates through vector containing valid inputs to continue game
    input = "yes";
    return true;
  } else if (std::find(validNoInputs.begin(), validNoInputs.end(), input) != validNoInputs.end()) {
    // iterates through vector containing valid inputs to end game
    input = "no";
    return true;
  } else {
    return false;
  }
}

int get_valid_number(std::minstd_rand& generator, const int& minimum, const int& maximum) {
  std::uniform_int_distribution<int> dist(minimum, maximum);
  int randomNumber = dist(generator);   // generates random number between min and max

  return randomNumber;
}

void remove_whitespace(std::string& line) {
  while(isspace(line.front())) {    // removes all whitespace before first character
    line.erase(line.begin());
  }
  while(isspace(line.back())) {   // removes all whitespace trailing last character in line
    line.pop_back();
  }
}