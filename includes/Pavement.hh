//
// Pavement.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue Jun  9 10:17:18 2015 Joris Bertomeu
// Last update Thu Jun 11 20:01:09 2015 Geoffrey Merran
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

class		Pavement : public AEntity
{
private:
  gdl::Geometry	_geometry;
  Texture*	_textureO;
  Hitbox*	_hitbox;
  void		buildObject();

public:
			Pavement(const glm::vec3 &, const std::string &);
			Pavement(const glm::vec3 &, Texture* t);
  virtual		~Pavement();
  virtual void		draw(RenderManager &);
  virtual Hitbox	*getHitbox() const;
  float			getHeigth();
  float			getWidth();
  float			getDepth();
};

#endif
