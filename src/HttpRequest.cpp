//
// HttpRequest.cpp for  in /home/jobertomeu/Work/bomberman
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Jun 10 17:34:08 2015 Joris Bertomeu
// Last update Wed Jun 10 17:41:20 2015 Joris Bertomeu
//

#include	<HttpRequest.hh>

extern	"C" {
  size_t	write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
  {
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
  }
}

HttpRequest::HttpRequest(const std::string &url, const std::string &file)
{
  this->_url = url;
  this->_file = file;
}

HttpRequest::~HttpRequest()
{

}

bool	HttpRequest::exec()
{
  CURL	*curl;
  FILE	*fp;
  CURLcode res;

  curl = curl_easy_init();
  if (curl) {
    fp = fopen(this->_file.c_str(), "wb");
    curl_easy_setopt(curl, CURLOPT_URL, this->_url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    fclose(fp);
    return (true);
  }
  return (false);
}
