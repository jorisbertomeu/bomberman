//
// GameButton.cpp for Bomberman in /home/polizz_v/rendu/CPP/bomberman/src
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Fri Jun  5 14:43:04 2015 Valérian Polizzi
// Last update Fri Jun  5 14:51:32 2015 Valérian Polizzi
//

#include "GameButton.hh"

GameButton::GameButton(glm::vec3 pos, const std::string &content) : AEntity(pos, AEntity::BUTTON)
{
  (void)content;
}

GameButton::~GameButton()
{
}

void		GameButton::draw(RenderManager &rm)
{
  rm = rm;
}
