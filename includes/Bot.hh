//
// Bot.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Mon May 25 14:12:07 2015 Nicolas Adès
// Last update Wed Jun  3 21:27:49 2015 Geoffrey Merran
//

#ifndef _BOT_H_
# define _BOT_H_

# include <AEntity.hh>

class		Bot : public AEntity
{
protected:
  std::string	_name;
  std::string	_color;

private:
  Bot(glm::vec3 pos, const std::string &name);
  ~Bot();

  std::string	getName() const;
  std::string	getColor() const;
  void		setColor(const std::string &color);
  virtual void	draw(RenderManager & rm);
};

#endif // _BOT_H_
