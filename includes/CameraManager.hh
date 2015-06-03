//
// CameraManager.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:02:41 2015 Joris Bertomeu
// Last update Wed Jun  3 11:42:39 2015 Geoffrey Merran
//

#ifndef			_CAMERAMANAGER_HH_
# define		_CAMERAMANAGER_HH_

# include		<Game.hh>
# include		<SdlContext.hh>
# include		<RenderManager.hh>

class			CameraManager
{
private:
  RenderManager*       	_renderManager;
  glm::mat4		_projection;
  glm::mat4		_transformation;

public:
  explicit		CameraManager();
  virtual		~CameraManager();
  bool			moveTo(const glm::vec3 &);
  bool			initialize(RenderManager *rm, const glm::vec2 &windowSize);
};

#endif		/* _CAMERAMANAGER_HH_ */
