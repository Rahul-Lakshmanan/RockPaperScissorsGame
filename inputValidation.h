//
// Created by Rahul Lakshmanan on 4/22/2021.
//

#ifndef ROCKPAPERSCISSORS__INPUTVALIDATION_H_
#define ROCKPAPERSCISSORS__INPUTVALIDATION_H_

#include <random>

bool player_move_valid(std::string& move);
bool replay_is_valid(std::string& input);
int get_valid_number(std::minstd_rand& generator, const int& minimum, const int& maximum);
void remove_whitespace(std::string& line);

#endif //ROCKPAPERSCISSORS__INPUTVALIDATION_H_
