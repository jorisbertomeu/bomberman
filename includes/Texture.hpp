//
// Texture.hpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 11:19:32 2015 Joris Bertomeu
// Last update Tue May 26 17:37:18 2015 Geoffrey Merran
//

#ifndef		_TEXTURE_HPP_
# define	_TEXTURE_HPP_

# include	<string>
# include	<Model.hh>
# include	<Texture.hh>

class		Texture
{
private:
  std::string	_filename;

public:
  explicit	Texture(const std::string &filename) {
    (void) filename;
  }

  virtual	~Texture(void) {

  }
};

#endif		/* _TEXTURE_HPP_ */
