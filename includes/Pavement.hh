//
// Pavement.hh for  in /home/jobertomeu/Work/bomberman/includes
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue Jun  9 10:17:18 2015 Joris Bertomeu
// Last update Fri Jun 12 18:30:16 2015 Jérémy Mediavilla
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

class			Pavement : public AEntity
{
private:
  gdl::Geometry		_geometry;
  Texture*		_textureO;
  Hitbox*		_hitbox;
  void			buildObject();

public:
			Pavement(const glm::vec3 &, const std::string &);
			Pavement(const glm::vec3 &, Texture* t);
  virtual		~Pavement();

  virtual Hitbox	*getHitbox() const;
  float			getHeigth();
  float			getWidth();
  float			getDepth();

  virtual void		draw(RenderManager &);
  virtual void		update(gdl::Clock &, Scene *);
};

#endif
