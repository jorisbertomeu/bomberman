//
// Balloon.hh for  in /home/mari_f/final/src/Scenes
//
// Made by mari_f
// Login   <mari_f@epitech.net>
//
// Started on  Sun Jun 14 01:19:40 2015 mari_f
// Last update Sun Jun 14 01:29:48 2015 mari_f
//

#ifndef			_BALLOON_HH_
# define		_BALLOON_HH_

# include		<Pavement.hh>

class			Balloon : public Pavement
{
public:
  Balloon(const glm::vec3 &, const std::string &, const float & range = 0.3, const float & gap = 20);
  ~Balloon();

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
