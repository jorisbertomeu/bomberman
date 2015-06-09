//
// Pavement.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue Jun  9 10:17:18 2015 Joris Bertomeu
// Last update Tue Jun  9 12:36:12 2015 Joris Bertomeu
//

#ifndef		PAVEMENT_HH_
# define	PAVEMENT_HH_

# include		<string>

# include		<glm/glm.hpp>
# include		<glm/gtc/matrix_transform.hpp>
# include		<Input.hh>
# include		<BasicShader.hh>
# include		<SdlContext.hh>
# include		<Geometry.hh>

# include		<AEntity.hh>

class		Pavement : public	AEntity
{
private:
  gdl::Geometry	_geometry;
  gdl::Texture	_textureO;

public:
  explicit	Pavement(glm::vec3, const std::string &);
  virtual	~Pavement();
  virtual void	draw(RenderManager &);
};

#endif