//
// Fire.hh for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Sun Jun 14 17:27:35 2015 Geoffrey Merran
// Last update Sun Jun 14 17:46:22 2015 Geoffrey Merran
//

#ifndef __FIRE_HH
# define __FIRE_HH

# include <AEntity.hh>

class			Fire : public AEntity
{
public:
  Fire(glm::vec3 pos);
  ~Fire();

  virtual void			draw(RenderManager & rm);
  virtual void			update(gdl::Clock &, Scene *);

private:
  float				_fireTime;
};

#endif /* __FIRE_HH */
