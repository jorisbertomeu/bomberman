//
// RenderManager.hh for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 10:49:21 2015 Joris Bertomeu
// Last update Sun Jun 14 07:08:01 2015 Geoffrey Merran
//

#ifndef			_RENDERMANAGER_HH_
# define		_RENDERMANAGER_HH_

# include		<fstream>

class			RenderManager;

# include		<SoundManager.hh>
# include		<TextureManager.hh>
# include		<GraphicManager.hh>
# include		<ModelManager.hh>
# include		<TimeManager.hh>
# include		<CameraManager.hh>
# include		<Scene.hh>

class			RenderManager
{
protected:
  SoundManager		_soundManager;
  TextureManager	_textureManager;
  GraphicManager	_graphicManager;
  ModelManager		_modelManager;
  TimeManager		_timeManager;
  CameraManager		*_cameraManager;

public:
  explicit		RenderManager();
  virtual		~RenderManager();

  bool			initialize(const glm::vec2 &, const std::string &);
  void			delay();
  bool			update(gdl::Input &);
  void			stop();
  void			draw(Scene *);

  CameraManager*	getCameraManager() const;
  void			setCameraManager(CameraManager*);
  GraphicManager&	getGraphicManager();
  ModelManager&		getModelManager();
  TimeManager&		getTimeManager();
  SoundManager&		getSoundManager();
  TextureManager&	getTextureManager();
};

#endif			/* _RENDERMANAGER_HH */
