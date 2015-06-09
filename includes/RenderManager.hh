//
// RenderManager.hh for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 10:49:21 2015 Joris Bertomeu
// Last update Tue Jun  9 22:20:22 2015 Jérémy Mediavilla
//

#ifndef			_RENDERMANAGER_HH_
# define		_RENDERMANAGER_HH_

# include		<SoundManager.hh>
# include		<TextureManager.hh>
# include		<GraphicManager.hh>
# include		<ModelManager.hh>
# include		<TimeManager.hh>

class			RenderManager;

# include		<Scene.hh>

class			RenderManager
{
protected:
  SoundManager		_soundManager;
  TextureManager	_textureManager;
  GraphicManager	_graphicManager;
  ModelManager		_modelManager;
  TimeManager		_timeManager;

public:
  explicit		RenderManager();
  virtual		~RenderManager();

  bool			initialize(const glm::vec2 &, const std::string &);
  void			delay();
  bool			update(gdl::Input &);
  void			stop();
  void			draw(Scene *);


  GraphicManager&	getGraphicManager();
  ModelManager&		getModelManager();
  TimeManager&		getTimeManager();
  SoundManager&		getSoundManager();
};

#endif			/* _RENDERMANAGER_HH */
