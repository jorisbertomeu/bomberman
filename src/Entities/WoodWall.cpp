//
// WoodWall.cpp for  in /home/parallels/Tek2/CPP/bomberman
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Wed May 27 13:13:09 2015 Nicolas Adès
// Last update Wed Jun  3 21:31:55 2015 Geoffrey Merran
//

#include <WoodWall.hh>

WoodWall::WoodWall(glm::vec3 pos) : AEntity(pos, AEntity::WOODWALL)
{

}

WoodWall::~WoodWall()
{

}

void	WoodWall::draw(RenderManager & rm)
{
  (void) rm;
}
