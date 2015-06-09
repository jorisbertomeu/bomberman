//
// Rectangle.hh for  in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Sat Jun  6 19:28:18 2015 Geoffrey Merran
// Last update Sat Jun  6 19:32:26 2015 Geoffrey Merran
//

#ifndef __RECTANGLE_H
# define __RECTANGLE_H

# include <AEntity.hh>

class			Rectangle
{
public:
  Rectangle();
  ~Rectangle();

  virtual void	       	draw(RenderManager & rm);
}

#endif /* __RECTANGLE_H */
