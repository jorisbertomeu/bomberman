//
// MainMenu.hpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue Jun  9 11:12:51 2015 Joris Bertomeu
// Last update Tue Jun  9 12:36:58 2015 Joris Bertomeu
//

#ifndef		_MAINMENU_HPP_
# define	_MAINMENU_HPP_

# include	<Scene.hh>
# include	<Pavement.hh>

class		MainMenu : public	Scene
{
private:
  Pavement	*_p1;
public:
  explicit	MainMenu() {
    this->_p1 = new Pavement(glm::vec3(0, 100, 0), std::string("wall_texture.tga"));
    this->addEntity(this->_p1);
  }
  virtual	~MainMenu() {

  }
};

#endif
