//
// GraphicContext.hpp for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 11:00:56 2015 Joris Bertomeu
// Last update Tue May 19 15:15:27 2015 Joris Bertomeu
//

#ifndef		_GRAPHICCONTEXT_HH_
# define	_GRAPHICCONTEXT_HH_

# include	<BasicShader.hh>
# include	<SdlContext.hh>
# include	<Geometry.hh>

class		GraphicContext
{
private:
  gdl::SdlContext	_sdlContext;
  gdl::BasicShader	_shaders;

public:
  explicit	GraphicContext(void) {

  }

  virtual	~GraphicContext(void) {

  }
};

#endif		/* _GRAPHICCONTEXT_HH_ */
