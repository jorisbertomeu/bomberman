//
// Bot.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Mon May 25 14:12:07 2015 Nicolas Adès
// Last update Sun Jun 14 07:55:54 2015 Jérémy Mediavilla
//

#include <Bot.hh>
#include <Bomb.hh>

Bot::Bot(glm::vec3 pos, const std::string &name, ModelManager& modelManager) : Bomberman(pos, name, modelManager)
{
  std::cout << "New Bot created : <" << pos.x <<", "<< pos.y << ", "<< pos.z <<"> " << name << std::endl;
  this->_name = name;
  this->_type = BOT;
  this->_isBusy = false;
}

Bot::~Bot()
{

}

// std::string	Bot::getName() const
// {
//   return (this->_name);
// }


std::string	Bot::getColor() const
{
  return (this->_color);
}

void		Bot::setColor(const std::string &color)
{
  this->_color = color;
}

std::list<glm::vec2>		Bot::directTrajectory(glm::vec2 start, glm::vec2 end)
{
  std::list<glm::vec2> posList;

  float		a = 0;
  int		tmp = 0;
  int		dx;
  int		dy;
  int		x;
  int		y;

  dx = abs(end.x - start.x);
  dy = abs(end.y - start.y);
  if (start.x == end.x)
    {
      if (start.y < end.y + 1)
	while (start.y != end.y + 1)
	  {
	    posList.push_back(glm::vec2(start.x, start.y));
	    start.y++;
	  }
      else
	while (start.y != end.y)
	  {
	    posList.push_back(glm::vec2(start.x, start.y));
	    start.y--;
	  }
    }
  else if (start.y == end.y)
    {
      if (start.x < end.x + 1)
	while (start.x != end.x + 1)
	  {
	    posList.push_back(glm::vec2(start.x, start.y));
	    start.x++;
	  }
      else
	while (start.x != end.x + 1)
	  {
	    posList.push_back(glm::vec2(start.x, start.y));
	    start.x--;
	  }
    }
  else
    {
      if (dx >= dy && dx != 0 && dy != 0)
	{
	  if (start.x > end.x)
	    {
	      tmp = start.x;
	      start.x = end.x;
	      end.x = tmp;

	      tmp = start.y;
	      start.y = end.y;
	      end.y = tmp;
	    }
	  a = ((float)(end.y - start.y) / (end.x - start.x));
	  for (int i = 0; i < (dx + 1); i++)
	    {
	      x = i + start.x;
	      y = start.y + (a * i);
	      posList.push_back(glm::vec2(x, y));
	    }
	}
      if (dx < dy && dy != 0 && dx != 0)
	{
	  if (start.y > end.y)
	    {
	      tmp = start.y;
	      start.y = end.y;
	      end.y = tmp;

	      tmp = start.x;
	      start.x = end.x;
	      end.x = tmp;
	    }
	  a = ((float)(end.x - start.x) / (end.y - start.y));
	  for (int i = 0; i < (dy + 1); i++)
	    {
	      x = start.x + (i * a);
	      y = i + start.y;
	      posList.push_back(glm::vec2(x, y));
	    }
	}
      if (dx == 0)
	{
	  if (start.x > end.x)
	    {
	      tmp = start.x;
	      start.x = end.x;
	      end.x = tmp;
	    }
	  for (int i = start.y; i < (end.y + 1); i++)
	    {
	      x = start.x;
	      posList.push_back(glm::vec2(x, i));
	    }
	}
      if (dy == 0)
	{
	  if (start.y > end.y)
	    {
	      tmp = start.y;
	      start.y = end.y;
	      end.y = tmp;
	    }
	  for (int i = start.x; i < (end.x + 1); i++)
	    {
	      x = i;
	      y = start.y;
	      posList.push_back(glm::vec2(x, y));
	    }
	}
    }
  return (posList);
  (void)a;
}

void		Bot::ia(Scene *scene)
{
  // Bomberman	*bomberman;
  // std::list<glm::vec2> posList;
  
  // bomberman = static_cast<Bomberman *>(scene->getBomberman());
  // posList = this->directTrajectory(this->getPos().x, this->getPos().z, bomberman->getPos().x, bomberman->getPos().z);
  // if (((posList.front().x == this->getPos().x && posList.front().y == this->getPos().z)) || (posList.back().x == bomberman->getPos().x && posList.back().y == bomberman->getPos().z))
  //   this->setPosList(posList);
  // else
  //   {
  //     posList.reverse();
  //     this->setPosList(posList);
  //   }
}

void		Bot::goTo(gdl::Clock &clock, const glm::vec3 &pos, void *scenep)
{
  int		cadrant;
  Scene		*scene = (Scene *)scenep;
  glm::vec3	oldPos;

  oldPos = this->_pos;
  cadrant = 0;
  if (pos.z < this->_pos.z && pos.x > this->_pos.x)
    {
      if (this->calcAngle(glm::vec3(this->_pos.x, this->_pos.y, this->_pos.z + 50),
      			  this->_pos, 
      			  glm::vec3(glm::vec3(pos.x, 0, pos.z))) >
      	  this->calcAngle(glm::vec3(glm::vec3(pos.x, 0, pos.z)),
      			  this->_pos, 
      			  glm::vec3(this->_pos.x + 50, this->_pos.y, this->_pos.z)))
      	{
	  this->moveRight(clock);
      	}
      else
	this->moveFront(clock);
      cadrant = 1;
    }
  else if (pos.z > this->_pos.z && pos.x > this->_pos.x)
    {
      if (this->calcAngle(glm::vec3(this->_pos.x + 50, this->_pos.y, this->_pos.z),
      			  this->_pos, 
      			  glm::vec3(glm::vec3(pos.x, 0, pos.z))) >
      	  this->calcAngle(glm::vec3(glm::vec3(pos.x, 0, pos.z)),
      			  this->_pos, 
      			  glm::vec3(this->_pos.x, this->_pos.y, this->_pos.z + 50)))
      	{
	  this->moveBack(clock);
      	}
      else
	this->moveRight(clock);
      cadrant = 2;
    }
  else if (pos.z > this->_pos.z && pos.x < this->_pos.x)
    {
      if (this->calcAngle(glm::vec3(this->_pos.x, this->_pos.y, this->_pos.z + 50),
      			  this->_pos, 
      			  glm::vec3(glm::vec3(pos.x, 0, pos.z))) >
      	  this->calcAngle(glm::vec3(glm::vec3(pos.x, 0, pos.z)),
      			  this->_pos, 
      			  glm::vec3(this->_pos.x + 50, this->_pos.y, this->_pos.z)))
      	{
	  this->moveLeft(clock);
      	}
      else
	this->moveBack(clock);
      cadrant = 3;
    }
  else if (pos.z < this->_pos.z && pos.x < this->_pos.x)
    {
      if (this->calcAngle(glm::vec3(this->_pos.x + 50, this->_pos.y, this->_pos.z),
      			  this->_pos, 
      			  glm::vec3(glm::vec3(pos.x, 0, pos.z))) >
      	  this->calcAngle(glm::vec3(glm::vec3(pos.x, 0, pos.z)),
      			  this->_pos, 
      			  glm::vec3(this->_pos.x, this->_pos.y, this->_pos.z + 50)))
	{
	  this->moveFront(clock);
	}
      else
	this->moveLeft(clock);
      cadrant = 4;
    }
  if (this->_isBusy && (int)this->_pointToGo.x == (int)this->_pos.x && (int)this->_pointToGo.z == (int)this->_pos.z)
    this->_isBusy = false;
  if (this->_isBusy && this->getHitbox()->checkCollision(scene))
    this->_isBusy = false;
  else if (this->getHitbox()->checkCollision(scene))
    {
      this->setPos(oldPos);
      this->setAcceleration(0.01f);
      if (this->_isBusy)
	this->_isBusy = false;
      this->goAwayFromBomb(scene, cadrant);
    }
}

void		Bot::update(gdl::Clock &clock, Scene *scene)
{
  int		cadrant;

  if (this->_isBusy)
    {
      this->goTo(clock, this->_pointToGo, scene);
      return;
    }
  cadrant = 0;
  this->goTo(clock, static_cast<Bomberman *>(scene->getBomberman())->getPos(), scene);
}

void	        Bot::moveToPos(const glm::vec2 &pos)
{
  this->setPos(glm::vec3(pos.x, this->getPos().y, pos.y));
} 

void		Bot::setPosList(const std::list<glm::vec2> &pos)
{
  this->_posList = pos;
}

std::list<glm::vec2>	Bot::getPosList() const
{
  return (this->_posList);
}

void		Bot::popBack()
{
  this->_posList.pop_back();
}

void		Bot::popFront()
{
  this->_posList.pop_front();
}

float		Bot::calcAngle(const glm::vec3 &a, const glm::vec3 &b, const glm::vec3 &c)
{
  glm::vec2	vecAB;
  glm::vec2	vecBC;
  float		AB;
  float		BC;

  vecAB.x = b.x - a.x;
  vecAB.y = b.z - a.z;
  vecBC.x = c.x - b.x;
  vecBC.y = c.z - b.z;

  AB = sqrt(pow(b.x - a.x ,2) + pow(b.z - a.z ,2));
  BC = sqrt(pow(c.x - b.x ,2) + pow(c.z - b.z ,2));
  return (cos((-1 * (vecAB.x * vecBC.x + vecAB.y * vecBC.y)) / (AB * BC)) * 180 / 3.14159265f);
}

void		Bot::goAwayFromBomb(Scene *scene, const int &cadrant)
{
  if (!this->checkCollisionForLine(scene, this->_pos, glm::vec3(this->_pos.x + 25, this->_pos.y, this->_pos.z - 25)))
    {
      this->_pointToGo = glm::vec3(this->_pos.x + 25, this->_pos.y, this->_pos.z - 25);
      this->_isBusy = true;
      printf("on peut se placer en haut à droite\n");
    }
  else if (!this->checkCollisionForLine(scene, this->_pos, glm::vec3(this->_pos.x + 21, this->_pos.y, this->_pos.z + 21)))
    {
      this->_pointToGo = glm::vec3(this->_pos.x + 21, this->_pos.y, this->_pos.z + 21);
      this->_isBusy = true;
      printf("on peut se placer en bas à droite\n");
    }
  else if (!this->checkCollisionForLine(scene, this->_pos,  glm::vec3(this->_pos.x - 21, this->_pos.y, this->_pos.z + 21)))
    {
      this->_pointToGo = glm::vec3(this->_pos.x - 21, this->_pos.y, this->_pos.z + 21);
      this->_isBusy = true;
      printf("on peut se placer en bas à gauche\n");
    }
  else if (!this->checkCollisionForLine(scene, this->_pos,  glm::vec3(this->_pos.x - 21, this->_pos.y, this->_pos.z - 21)))
    {
      this->_pointToGo = glm::vec3(this->_pos.x - 21, this->_pos.y, this->_pos.z - 21);
      this->_isBusy = true;
      printf("on peut se placer en haut à gauche\n");      
    }
  else
    printf("peut pas\n");
}

bool		Bot::checkCollisionForLine(void *scenep, glm::vec3 start, glm::vec3 end)
{
  std::list<glm::vec2>	posList;
  Scene		*scene = (Scene *)scenep;

  posList = this->directTrajectory(glm::vec2(start.x, start.z), glm::vec2(end.x, end.z));
  for (std::list<glm::vec2>::iterator it = posList.begin(); it != posList.end(); ++it)
    if (this->getHitbox()->checkCollisionForPointForEntities(scene, glm::vec3((*it).x, this->getPos().y, (*it).y)))
      return (true);
  return (false);
}
