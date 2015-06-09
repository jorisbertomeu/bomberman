//
// Bot.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Mon May 25 14:12:07 2015 Nicolas Adès
// Last update Tue Jun  9 11:46:32 2015 Jérémy Mediavilla
//

#ifndef _BOT_H_
# define _BOT_H_

# include <Bomberman.hh>

class		Bot : public Bomberman
{
protected:
  std::string	_color;

private:
  Bot(glm::vec3 pos, const std::string &name);
  ~Bot();

  std::string	getColor() const;
  void		setColor(const std::string &color);
  virtual void	draw(RenderManager & rm);
  void		moveToPos(int x, int y);
  void		stopMove();
  bool		canPlaceBomb();
  glm::vec3	targetBomberman(const Bomberman &);
  bool		isFrontOfWall();
};

#endif // _BOT_H_
