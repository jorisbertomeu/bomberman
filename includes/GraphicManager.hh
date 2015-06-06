//
// SoundManager.hh for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 10:55:51 2015 Joris Bertomeu
// Last update Sat Jun  6 14:14:42 2015 Geoffrey Merran
//

#ifndef			_GRAPHICMANAGER_HH_
# define		_GRAPHICMANAGER_HH_

# include		<string>
# include		<stdexcept>
# include		<unistd.h>

# include		<glm/glm.hpp>
# include		<glm/gtc/matrix_transform.hpp>

# include		<GraphicContext.hh>

class			GraphicManager
{
private:
  GraphicContext	_context;

public:
  explicit		GraphicManager();
  virtual		~GraphicManager();
  bool			initialize(const glm::vec2 &, const std::string &);
  void			stop();
  void			flush();

  GraphicContext	getContext() const;
};

#endif			/* _GRAPHICMANAGER_HH_ */
