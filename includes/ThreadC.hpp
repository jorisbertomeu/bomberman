//
// Thread.hpp for  in /home/mediav_j/rendu/cpp_plazza/includes
//
// Made by Jérémy Mediavilla
// Login   <mediav_j@epitech.net>
//
// Started on  Tue Apr 21 16:24:49 2015 Jérémy Mediavilla
// Last update Wed Jun 10 08:16:34 2015 Joris Bertomeu
//

#ifndef			_THREADC_HPP_
# define		_THREADC_HPP_

#include		<pthread.h>

class			ThreadC
{
private:
  pthread_t		_thread;

public:
  explicit		ThreadC() {

  };
  virtual		~ThreadC() {
    pthread_exit(&this->_thread);
  };
  int			threadJoin() {
    return (pthread_join(this->_thread, NULL));
  };
  void			exec(void *(ptr_func)(void *)) {
    pthread_create(&this->_thread, NULL, ptr_func, NULL);
  }
  void			exec(void *(ptr_func)(void *), void *arg) {
    pthread_create(&this->_thread, NULL, ptr_func, arg);
  }
};

#endif			// _THREAD_HPP_
