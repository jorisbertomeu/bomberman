//
// TextureManager.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 11:17:49 2015 Joris Bertomeu
// Last update Tue May 19 11:24:52 2015 Joris Bertomeu
//

#ifndef			_TEXTUREMANAGER_HH_
# define		_TEXTUREMANAGER_HH_

# include		<list>

# include		<Texture.hpp>

class			TextureManager
{
private:
  std::list<Texture>	_textures;

public:
  explicit		TextureManager();
  virtual		~TextureManager();
  bool			initialize();
  bool			addTexture(const Texture &);
  bool			addTextureFromFile(const std::string &);
};

#endif		/* _TEXTUREMANAGER_HH_ */
