//
// GameButton.hh for Bomberman in /home/polizz_v/rendu/CPP/bomberman/src
//
// Made by Valérian Polizzi
// Login   <polizz_v@epitech.net>
//
// Started on  Fri Jun  5 14:40:47 2015 Valérian Polizzi
// Last update Wed Jun 10 15:36:59 2015 Joris Bertomeu
//

#ifndef _CLOUD_HH_
# define _CLOUD_HH_

# include		<Pavement.hh>

class			Cloud : public Pavement
{
public:
  Cloud(const glm::vec3 &, const std::string &, const float & range = 0.3, const float & gap = 20);
  ~Cloud();

  virtual void	       	update(gdl::Clock &, Scene *);

  void			setCurrent(const bool &);
  const bool &      	getCurrent() const;
  const int &		getId() const;
  void			setRange(const float &);
  void			setGap(const float &);

private:
  int			_id;
  bool			_current;
  int			_dir;
  glm::vec3		_originalPos;
  float			_gap;
  float			_range;
};

#endif
