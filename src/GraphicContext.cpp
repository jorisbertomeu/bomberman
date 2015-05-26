//
// GraphicContext.cpp for GraphicContext in /home/merran_g/work/rendu/bomberman
// 
// Made by Geoffrey Merran
// Login   <merran_g@epitech.net>
// 
// Started on  Mon May 25 16:25:37 2015 Geoffrey Merran
// Last update Mon May 25 16:30:13 2015 Geoffrey Merran
//

#include "GraphicContext.hh"

GraphicContext::GraphicContext(void)
{

}

GraphicContext::~GraphicContext(void)
{

}

gdl::SdlContext&       		GraphicContext::getSdlContext()
{
  return (this->_sdlContext);
}
