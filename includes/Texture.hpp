//
// Texture.hpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 11:19:32 2015 Joris Bertomeu
// Last update Tue May 19 11:25:25 2015 Joris Bertomeu
//

#ifndef		_TEXTURE_HPP_
# define	_TEXTURE_HPP_

# include	<string>

class		Texture
{
private:
  std::string	_filename;

public:
  explicit	Texture(const std::string &filename) {

  }

  virtual	~Texture(void) {

  }
};

#endif		/* _TEXTURE_HPP_ */
