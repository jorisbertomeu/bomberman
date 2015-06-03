//
// GraphicContext.hpp for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 11:00:56 2015 Joris Bertomeu
// Last update Wed Jun  3 11:16:16 2015 Geoffrey Merran
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
  gdl::BasicShader     	_shaders;

public:
  explicit		GraphicContext(void);
  virtual		~GraphicContext(void);

  gdl::SdlContext&	getSdlContext();
  gdl::BasicShader&    	getShaders();
};

#endif		/* _GRAPHICCONTEXT_HH_ */
