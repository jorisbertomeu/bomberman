//
// HttpRequest.hh for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Jun 10 17:32:57 2015 Joris Bertomeu
// Last update Wed Jun 10 17:48:23 2015 Joris Bertomeu
//

#ifndef		_HTTPREQUEST_HH_
# define	_HTTPREQUEST_HH_

# include	<string>

# include	<curl/curl.h>

class		HttpRequest
{
private:
  std::string	_url;
  std::string	_file;

public:
  explicit	HttpRequest(const std::string &url, const std::string &file);
  virtual	~HttpRequest();
  bool		exec();
};

#endif
