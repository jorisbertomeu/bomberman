//
// AnimationManager.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
// 
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
// 
// Started on  Tue May 26 14:52:09 2015 Nicolas Adès
// Last update Sun Jun 14 03:02:42 2015 Nicolas Adès
//

#ifndef ANIMATIONMANAGER_HH_
# define ANIMATIONMANAGER_HH_

# include <ModelManager.hh>
# include <Animation.hh>
# include <iostream>
# include <list>

class					AnimationManager
{
private:
  gdl::Model*				_model;
  std::list<Animation*>			_listAnim;
  Animation*				_current;
  Animation*				_animToDisplay;
  
public:
  AnimationManager(gdl::Model *model);
  ~AnimationManager();

  void					createAnimation(const std::string &name, const int &startFrame, const int &endFrame, const bool &loop);
  void					playAnimation();
  void					setAnimToDisplay(const std::string &name);
};

#endif // ANIMATIONMANAGER_HH_
