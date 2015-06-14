//
// Bot.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Mon May 25 14:12:07 2015 Nicolas Adès
// Last update Sun Jun 14 07:10:26 2015 Jérémy Mediavilla
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
  bool		_isBusy;
  glm::vec3	_pointToGo;

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
  std::list<glm::vec2>		directTrajectory(glm::vec2, glm::vec2);
  float		calcAngle(const glm::vec3 &, const glm::vec3 &, const glm::vec3 &);
  void		goAwayFromBomb(Scene *, const int&);
  void		goTo(gdl::Clock &, const glm::vec3&, void *);
  bool		checkCollisionForLine(void *, glm::vec3, glm::vec3);
};

#endif // _BOT_H_
