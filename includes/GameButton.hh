//
// GameButton.hh for Bomberman in /home/polizz_v/rendu/CPP/bomberman/src
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Fri Jun  5 14:40:47 2015 Valérian Polizzi
// Last update Tue Jun  9 14:11:38 2015 Joris Bertomeu
//

#ifndef _GAMEBUTTON_HH_
# define _GAMEBUTTON_HH_
# include	"AEntity.hh"
# include	<SDL/SDL.h>
# include	<SDL/SDL_ttf.h>

class GameButton : public AEntity
{
public:
  GameButton(glm::vec3 pos, const glm::vec3 scale);
  ~GameButton();
private:
  SDL_Rect	_btn;
  SDL_Rect	*_texture;
  virtual void		draw(RenderManager &rm);
  void			setTexture(const std::string &path);
};

#endif // _GAMEBUTTON_HH_
