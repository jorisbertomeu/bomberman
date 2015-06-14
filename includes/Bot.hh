//
// Bot.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Mon May 25 14:12:07 2015 Nicolas Adès
// Last update Sun Jun 14 03:22:13 2015 Geoffrey Merran
//

#ifndef _BOT_H_
# define _BOT_H_

# include <Bomberman.hh>

class		Bot : public Bomberman
{
protected:
  std::string	_color;
  std::list<glm::vec2>	_posList;
  bool		_first;

public:
  Bot(glm::vec3 pos, const std::string &name, ModelManager&);
  ~Bot();

  std::string	getColor() const;
  void		setColor(const std::string &color);
  void		setPosList(const std::list<glm::vec2>&);
  std::list<glm::vec2>	getPosList() const;
  void		popFront();
  void		popBack();
  void		moveToPos(const glm::vec2 &);
  void		stopMove();
  bool		canPlaceBomb();
  bool		isFrontOfWall();
  void		ia(Scene *);
  virtual void 	update(gdl::Clock &, Scene *);
  std::list<glm::vec2>		directTrajectory(int, int, int, int);
  float		calcAngle(const glm::vec3 &, const glm::vec3 &, const glm::vec3 &);
};

#endif // _BOT_H_
