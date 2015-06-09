//
// GameButton.cpp for Bomberman in /home/polizz_v/rendu/CPP/bomberman/src
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Fri Jun  5 14:43:04 2015 Valérian Polizzi
// Last update Mon Jun  8 01:08:42 2015 Valérian Polizzi
//

#include "GameButton.hh"

GameButton::GameButton(glm::vec3 pos, glm::vec3 scale) : AEntity(pos, AEntity::BUTTON)
{
  (void)scale;
}

GameButton::~GameButton()
{
}

void		GameButton::setTexture(const std::string &path)
{
  (void)path;
}

void		GameButton::draw(RenderManager &rm)
{
  rm = rm;
}
