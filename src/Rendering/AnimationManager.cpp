//
// AnimationManager.cpp for  in /home/parallels/Tek2/CPP/bomberman/src/Rendering
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Tue May 26 14:52:09 2015 Nicolas Adès
// Last update Sun Jun 14 08:17:43 2015 Geoffrey Merran
//

#include <AnimationManager.hh>

AnimationManager::AnimationManager(gdl::Model *model)
{
  this->_model = model;
  this->_current = NULL;
  this->_animToDisplay = NULL;
}

AnimationManager::~AnimationManager()
{

}

void		AnimationManager::createAnimation(const std::string &name, const int &startFrame, const int &endFrame, const bool &loop)
{
  Animation	*anim = new Animation(name, loop);
  this->_listAnim.push_back(anim);
  this->_current = anim;
  this->_model->createSubAnim(0, name, startFrame, endFrame);
}

void		AnimationManager::playAnimation()
{
  if (this->_animToDisplay == NULL)
    return;
  if (this->_animToDisplay->getName() == this->_current->getName())
    return;
  for (std::list<Animation *>::iterator it = this->_listAnim.begin(); it != this->_listAnim.end(); ++it) {
    if ((*it)->getName() == this->_animToDisplay->getName())
      {
	this->_model->setCurrentSubAnim((*it)->getName(), (*it)->getLoop());
	this->_current = (*it);
	return;
      }
  }
  return;
}

void		AnimationManager::setAnimToDisplay(const std::string &name)
{
  for (std::list<Animation*>::iterator it = this->_listAnim.begin(); it != this->_listAnim.end(); ++it) {
    if ((*it)->getName() == name)
      {
	this->_animToDisplay = (*it);
	return;
      }
  }
  return;
}
