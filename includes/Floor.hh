//
// Floor.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed Jun  3 12:57:30 2015 Nicolas Adès
// Last update Wed Jun  3 21:29:45 2015 Geoffrey Merran
//

#ifndef _FLOOR_H_
# define _FLOOR_H_

# include <AEntity.hh>

class		Floor : public AEntity
{
protected:
  int		_width;
  int		_heigth;

public:
  Floor(glm::vec3 pos, int width, int heigth);
  ~Floor();

  int		getWidth() const;
  int		getHeigth() const;
  virtual void  draw(RenderManager & rm);
};

#endif // _FLOOR_H_
