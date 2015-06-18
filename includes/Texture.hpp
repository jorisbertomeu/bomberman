//
// Texture.hpp for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 11:19:32 2015 Joris Bertomeu
// Last update Sun Jun 14 19:35:08 2015 Jérémy Mediavilla
//

#ifndef		_TEXTURE_HPP_
# define	_TEXTURE_HPP_

# include	<stdexcept>
# include	<string>
# include	<Model.hh>
# include	<Texture.hh>

class		Texture
{
private:
  std::string	_filename;
  int		_online;
  std::string	_id;
  gdl::Texture	_t;

public:
  explicit	Texture(const std::string &filename, int online = 0, const std::string &id = "") {
    this->_filename = filename;
    this->_online = online;
    this->_id = id;
    if (!this->_t.load(filename))
      throw(std::logic_error("Error texture, can't load "  + filename));
  }

  virtual	~Texture(void) {

  }

  gdl::Texture&	getTexture()  {
    return (this->_t);
  }
  std::string	getFilename() {
    return (this->_filename);
  }

  bool		save(std::fstream &fs) {
    fs << "    <texture>" << std::endl;
    fs << "      <id>" << this->_id << "</id>" << std::endl;
    fs << "      <online>" << this->_online << "</online>" << std::endl;
    fs << "      <file>" << this->_filename << "</file>" << std::endl;
    fs << "    </texture>" << std::endl;
    return (true);
  }
};

#endif		/* _TEXTURE_HPP_ */
