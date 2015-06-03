//
// Floor.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed Jun  3 12:57:30 2015 Nicolas Adès
// Last update Wed Jun  3 23:25:42 2015 Geoffrey Merran
//

#ifndef __FLOOR_HH
# define __FLOOR_HH

# include <AEntity.hh>

class		Floor : public AEntity
{
protected:
  int		_width;
  int		_heigth;

public:
  Floor(const glm::vec3 & pos, const int & width, const int & heigth);
  ~Floor();

  int		getWidth() const;
  int		getHeigth() const;
  virtual void  draw(RenderManager & rm);
};

#endif // _FLOOR_HH_
