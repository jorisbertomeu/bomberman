//
// CameraManager.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:02:41 2015 Joris Bertomeu
// Last update Fri Jun 12 19:39:55 2015 Geoffrey Merran
//

#ifndef			_CAMERAMANAGER_HH_
# define		_CAMERAMANAGER_HH_

class			CameraManager;

# include		<Game.hh>
# include		<SdlContext.hh>
# include		<RenderManager.hh>

class			CameraManager
{
private:
  RenderManager*       	_renderManager;
  glm::mat4		_projection;
  glm::mat4		_transformation;
  glm::vec3		_pos;
  glm::vec3		_point;
  glm::vec3		_defaultPos;

public:
  explicit		CameraManager();
  virtual		~CameraManager();

  bool			moveTo(const glm::vec3 &, const glm::vec3 &);
  bool			initialize(RenderManager *rm, const glm::vec2 &windowSize);

  const glm::vec3 &    	getPos() const;
  const glm::vec3 &    	getPoint() const;
  const glm::vec3 &	getDefaultPos() const;

  void			setDefaultPos(const glm::vec3 & pos);
};

#endif		/* _CAMERAMANAGER_HH_ */
