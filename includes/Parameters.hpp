//
// Parameters.hpp for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 10:19:02 2015 Joris Bertomeu
// Last update Fri Jun 12 04:35:24 2015 Geoffrey Merran
//

#ifndef		_PARAMETERS_HH_
# define	_PARAMETERS_HH_

# include	<stdexcept>
# include	<glm/glm.hpp>
# include	<glm/gtc/matrix_transform.hpp>

class		Parameters
{
private:
  int		_ac;
  char		**_argv;
  int		_width;
  int		_height;

public:
  explicit	Parameters() {

  }

  virtual	~Parameters() {

  }

  void		setParameters(int ac, char **argv)  {
    this->_ac = ac;
    this->_argv = argv;
    this->_width = 1280;
    this->_height = 720;
  }

  glm::vec2		getSize() const {
    return (glm::vec2((float) this->_width, (float) this->_height));
  }
};

#endif
