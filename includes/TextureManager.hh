//
// TextureManager.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 11:17:49 2015 Joris Bertomeu
// Last update Sun Jun 14 19:25:12 2015 Jérémy Mediavilla
//

#ifndef				_TEXTUREMANAGER_HH_
# define			_TEXTUREMANAGER_HH_

# include			<stdexcept>
# include			<iostream>
# include			<fstream>
# include			<map>

# include			<Texture.hpp>

class				TextureManager
{
private:
  std::map<std::string, Texture* >       	_textures;

public:
  explicit			TextureManager();
  virtual			~TextureManager();
  bool				initialize();
  bool				addTexture(const Texture &);
  bool				addTextureFromFile(const std::string & name, const std::string &filename, int online = 0);
  // void				save(std::fstream &);
  std::map<std::string, Texture *>		getTextures();
  Texture*		       	getTexture(const std::string & name);
};

#endif		/* _TEXTUREMANAGER_HH_ */
