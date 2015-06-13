//
// MapPreviewer.hh for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Sat Jun 13 19:41:54 2015 Geoffrey Merran
// Last update Sat Jun 13 21:23:24 2015 Geoffrey Merran
//

#ifndef __MAP_PREVIEWER_HH
# define __MAP_PREVIEWER_HH

# include "Pavement.hh"

class			MapPreviewer : public Pavement
{
public:
  MapPreviewer(const glm::vec3 &, const std::string &);
  ~MapPreviewer();

  virtual void		draw(RenderManager &);
  virtual void		update(gdl::Clock &, Scene *);

  void			setHidden(const bool &);
  void			setCurrent(const bool &);
  void			changeMap(const std::string & tpath);

private:
  bool			_hidden;
  bool			_current;
};

#endif /* __MAP_PREVIEWER_HH */
