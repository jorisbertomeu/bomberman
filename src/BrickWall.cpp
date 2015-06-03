//
// BrickWall.cpp for  in /home/parallels/Tek2/CPP/bomberman
// 
// Made by Nicolas Adès
// Login   <parallels@epitech.net>
// 
// Started on  Wed May 27 13:17:23 2015 Nicolas Adès
// Last update Wed Jun  3 15:08:52 2015 Jérémy Mediavilla
//

#include <BrickWall.hh>

BrickWall::BrickWall(glm::vec3 pos) : AEntity(pos, AEntity::BRICKWALL)
{
  std::cout << "New brickwall created : <" << pos.x <<", "<< pos.y << ", "<< pos.z <<"> " << std::endl;
}

BrickWall::~BrickWall()
{

}

void		BrickWall::draw()
{

}
