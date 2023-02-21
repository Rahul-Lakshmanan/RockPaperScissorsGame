//
// Created by Rahul Lakshmanan and Christina Lei on 4/22/2021.
//

#include <iostream>
#include <string>
#include <random>
#include "game.h"
#include "inputValidation.h"

int main(int argc, char* argv[]) {
  int seedGenerator;
  int randomNumber;
  std::string playerMove;
  std::string aiMove;
  std::string winner;

  if (argv[1] != nullptr) {   // if seed is given through command line
    seedGenerator = std::stoi(argv[1]);
  } else {
    seedGenerator = time(nullptr);
  }

  std::minstd_rand generator(seedGenerator);      // passes seed to generator

  do {
    playerMove = player_take_turn();
    randomNumber = get_valid_number(generator, 0, 2);   // gets integer from 0 - 2
    aiMove = ai_take_turn(randomNumber);
  } while (!game_over(playerMove, aiMove, winner));

  return 0;
}
