//
// AScene.cpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:38:11 2015 Joris Bertomeu
// Last update Mon Jun  1 17:05:54 2015 Geoffrey Merran
//

#include	<AScene.hh>

AScene::AScene()
{

}

AScene::~AScene()
{

}

void					AScene::draw()
{
  for (std::list<AEntity>::iterator it = this->_objects.begin(); it != this->_objects.end(); it++)
    it->draw();
}
