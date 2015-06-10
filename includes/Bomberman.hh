//
// Bomberman.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
// 
// Made by Nicolas Adès
// Login   <parallels@epitech.net>
// 
// Started on  Tue May 26 14:52:09 2015 Nicolas Adès
// Last update Fri Jun 12 18:55:32 2015 Jérémy Mediavilla
//

#ifndef _BOMBERMAN_H_
# define _BOMBERMAN_H_

class		Bomberman;

# include <AEntity.hh>
# include <Scene.hh>

class		Bomberman : public AEntity
{
public:
  enum Dir
    {
      UP = 1,
      RIGHT = 2,
      DOWN = 3,
      LEFT = 4
    };

  Bomberman(glm::vec3 pos, const std::string &name);
  ~Bomberman();

  std::string	getName() const;
  void		dropBomb(Scene*);
  void		moveRight();
  void		moveLeft();
  void		moveBack();
  void		moveFront();
  void		jump();
  void		isReleased(Scene *);
  void		isTurningBack(const int &);

  virtual void 	draw(RenderManager & rm);
  virtual void 	update(gdl::Clock &, Scene *);

protected:
  std::string	_name;
  Dir		_dir;
};

#endif // _BOMBERMAN_H_
