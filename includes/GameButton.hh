//
// GameButton.hh for Bomberman in /home/polizz_v/rendu/CPP/bomberman/src
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Fri Jun  5 14:40:47 2015 Valérian Polizzi
// Last update Fri Jun  5 14:51:19 2015 Valérian Polizzi
//

#ifndef _GAMEBUTTON_HH_
# define _GAMEBUTTON_HH_
# include "AEntity.hh"

class GameButton : public AEntity
{
public:
  GameButton(glm::vec3 pos, const std::string &content);
  ~GameButton();

  virtual void		draw(RenderManager &rm);
};

#endif
