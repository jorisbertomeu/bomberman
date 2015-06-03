//
// RenderManager.hh for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 10:49:21 2015 Joris Bertomeu
// Last update Wed Jun  3 15:21:06 2015 Geoffrey Merran
//

#ifndef			_RENDERMANAGER_HH_
# define		_RENDERMANAGER_HH_

# include		<SoundManager.hh>
# include		<TextureManager.hh>
# include		<GraphicManager.hh>
# include		<ModelManager.hh>

class			RenderManager;

# include		<AScene.hh>

class			RenderManager
{
protected:
  SoundManager		_soundManager;
  TextureManager	_textureManager;
  GraphicManager	_graphicManager;
  ModelManager		_modelManager;

public:
  explicit		RenderManager();
  virtual		~RenderManager();

  bool			initialize(const glm::vec2 &, const std::string &);
  bool			start();
  bool			update();
  void			stop();
  void			draw(AScene *);

  GraphicManager	getGraphicManager() const;
};

#endif			/* _RENDERMANAGER_HH */
