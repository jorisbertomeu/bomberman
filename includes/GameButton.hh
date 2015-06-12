//
// GameButton.hh for Bomberman in /home/polizz_v/rendu/CPP/bomberman/src
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Fri Jun  5 14:40:47 2015 Valérian Polizzi
// Last update Fri Jun 12 23:32:59 2015 Geoffrey Merran
//

#ifndef _GAMEBUTTON_HH_
# define _GAMEBUTTON_HH_

# include		<Pavement.hh>

class			GameButton : public Pavement
{
public:
  GameButton(const glm::vec3 &, const std::string &, const int & id = -1);
  ~GameButton();

  virtual void	       	update(gdl::Clock &, Scene *);

  void			setCurrent(const bool &);
  const bool &      	getCurrent() const;
  const int &		getId() const;

private:
  int			_id;
  bool			_current;
};

#endif // _GAMEBUTTON_HH_
