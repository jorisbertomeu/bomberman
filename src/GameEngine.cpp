//
// GameEngine.cpp for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue May 19 09:32:34 2015 Joris Bertomeu
// Last update Thu Jun  4 00:16:29 2015 Geoffrey Merran
//

#include <GameEngine.hh>

GameEngine::GameEngine(int ac, char **argv) : _running(1)
{
  try {
    this->_parameters.setParameters(ac, argv);
  } catch (const std::exception &e) {
    throw std::logic_error(e.what());
  }
}

GameEngine::~GameEngine()
{

}

bool	GameEngine::initialize()
{
  if (!this->_renderManager.initialize(this->_parameters.getSize(), std::string("Bomberman")))
    return (false);
  if (!this->_gameContext.initialize(&(this->_renderManager), this->_parameters.getSize()))
    return (false);
  return (true);
}

bool	GameEngine::update()
{
  this->_renderManager.update();
  return (true);
}

void	GameEngine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.50f, 0.50f, 0.50f, 1.0f);
  glClearDepth(1.0f);
  this->_renderManager.draw(this->_gameContext.getCurrentScene());
}

bool	GameEngine::run()
{
  this->_gameContext.addScene("XMLfiles/ArchitectureXML.xml");

  SDL_Event	event;
  while (this->_running)
    {
      SDL_PollEvent(&event);
      switch (event.type)
      	{
      	case SDL_QUIT:
      	  this->_running = 0;
      	case SDL_KEYDOWN:
      	  switch (event.key.keysym.sym)
      	    {
      	    case SDLK_ESCAPE:
      	      this->_running = 0;
      	    }
      	}
      this->update();
      this->draw();
    }
  this->_renderManager.stop();
  return (true);
}
