//
// GameButton.hh for Bomberman in /home/polizz_v/rendu/CPP/bomberman/src
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Fri Jun  5 14:40:47 2015 Valérian Polizzi
// Last update Fri Jun 12 04:00:38 2015 Geoffrey Merran
//

#ifndef _GAMEBUTTON_HH_
# define _GAMEBUTTON_HH_

# include		<Pavement.hh>

class			GameButton : public Pavement
{
public:
  GameButton(const glm::vec3 &, const std::string &);
  ~GameButton();

  virtual void	       	update(gdl::Clock &);

  void			setCurrent(const bool &);
  const bool &      	getCurrent();

private:
  bool			_current;
};

#endif // _GAMEBUTTON_HH_
