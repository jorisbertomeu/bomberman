//
// Floor.hh for  in /home/parallels/Tek2/CPP/bomberman/includes
//
// Made by Nicolas Adès
// Login   <ades_n@epitech.net>
//
// Started on  Wed Jun  3 12:57:30 2015 Nicolas Adès
// Last update Thu Jun 11 19:50:05 2015 Geoffrey Merran
//

#ifndef __FLOOR_HH
# define __FLOOR_HH

# include <Pavement.hh>

class		Floor : public Pavement
{
private:
  int		_width;
  int		_heigth;

public:
  Floor(const glm::vec3 & pos, const int & width, const int & heigth, Texture*);
  virtual ~Floor();

  int		getWidth() const;
  int		getHeigth() const;
};

#endif // _FLOOR_HH_
