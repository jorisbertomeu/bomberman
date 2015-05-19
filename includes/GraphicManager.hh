//
// SoundManager.hh for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 10:55:51 2015 Joris Bertomeu
// Last update Tue May 19 11:27:09 2015 Joris Bertomeu
//

#ifndef			_GRAPHICMANAGER_HH_
# define		_GRAPHICMANAGER_HH_

# include		<string>

# include		<glm/glm.hpp>
# include		<glm/gtc/matrix_transform.hpp>

# include		<GraphicContext.hpp>

class			GraphicManager
{
private:
  GraphicContext	_context;

public:
  explicit		GraphicManager();
  virtual		~GraphicManager();
  bool			initialize(const glm::vec2 &, const std::string &);
};

#endif			/* _GRAPHICMANAGER_HH_ */
