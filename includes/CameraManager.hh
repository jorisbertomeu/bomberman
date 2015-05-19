//
// CameraManager.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:02:41 2015 Joris Bertomeu
// Last update Tue May 19 14:56:23 2015 Joris Bertomeu
//

#ifndef		_CAMERAMANAGER_HH_
# define	_CAMERAMANAGER_HH_

# include	<RenderManager.hh>

class		CameraManager
{
private:
  RenderManager	*_renderManager;

public:
  explicit	CameraManager();
  virtual	~CameraManager();
  bool		moveTo(const glm::vec3 &) const;
  bool		initialize(RenderManager *);
};

#endif		/* _CAMERAMANAGER_HH_ */
