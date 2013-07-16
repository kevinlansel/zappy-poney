//
// Except.cpp for  in /home/lund/svn/abstractvm-2016-dewulf_f
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Thu Feb 21 22:08:59 2013 florian dewulf
// Last update Tue Jul 16 10:23:26 2013 florian dewulf
//

#include	"Except.hpp"

Except::Except(const std::string &str) : _catch_me(str)
{
}

Except::~Except() throw()
{
}

const char	*Except::what() const throw()
{
  return (this->_catch_me.c_str());
}
