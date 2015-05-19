//
// CameraManager.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 13:02:41 2015 Joris Bertomeu
// Last update Tue May 19 13:15:12 2015 Joris Bertomeu
//

#ifndef		_CAMERAMANAGER_HH_
# define	_CAMERAMANAGER_HH_

# include	<RenderManager.hh>

class		CameraManager
{
private:
  RenderManager	*_renderManager;

public:
  explicit	CameraManager(RenderManager *);
  virtual	~CameraManager();
  bool		moveTo(const glm::vec3 &) const;
};

#endif		/* _CAMERAMANAGER_HH_ */
