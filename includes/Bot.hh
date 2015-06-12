//
// Bot.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Mon May 25 14:12:07 2015 Nicolas Adès
// Last update Fri Jun 12 19:20:51 2015 Jérémy Mediavilla
//

#ifndef _BOT_H_
# define _BOT_H_

# include <Bomberman.hh>

class		Bot : public Bomberman
{
protected:
  std::string	_color;

public:
  Bot(glm::vec3 pos, const std::string &name);
  ~Bot();

  std::string	getColor() const;
  void		setColor(const std::string &color);
  void		moveToPos(const glm::vec3 &);
  void		stopMove();
  bool		canPlaceBomb();
  glm::vec3	targetBomberman(const Bomberman &);
  bool		isFrontOfWall();
  void		ia(Scene *);
  virtual void 	update(gdl::Clock &, Scene *);
};

#endif // _BOT_H_
