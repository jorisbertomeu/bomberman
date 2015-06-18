//
// Model.hh for  in /home/mediav_j/mabm/bomberman
// 
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
// 
// Started on  Sun Jun 14 20:45:41 2015 Jérémy Mediavilla
// Last update Sun Jun 14 20:49:53 2015 Jérémy Mediavilla
//

#ifndef			_MODEL_HPP_
# define		_MODEL_HPP_

#include		<string>

class			Model
{
private:
  int			_online;
  std::string		_filename;

public:
  explicit		Model(const std::string &filename, const int &online) {
    this->_filename = filename;
    this->_online = online;
  };
  virtual		~Model() {

  };
  int			getOnline() const {
    return (this->_online);
  }
  std::string		getFilename() const {
    return (this->_filename);
  }
};

#endif			// _MODEL_HPP_
