//
// Created by Rahul Lakshmanan on 4/22/2021.
//

#ifndef ROCKPAPERSCISSORS__GAME_H_
#define ROCKPAPERSCISSORS__GAME_H_

std::string player_take_turn();
std::string ai_take_turn(const int& moveNumber);
bool game_over(const std::string& playerMove, const std::string& aiMove, std::string& winner);
std::string display_win_message(const std::string& winner);

#endif //ROCKPAPERSCISSORS__GAME_H_
