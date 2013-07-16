//
// Except.hpp for  in /home/lund/svn/abstractvm-2016-dewulf_f
// 
// Made by florian dewulf
// Login   <dewulf_f@epitech.net>
// 
// Started on  Thu Feb 21 22:08:54 2013 florian dewulf
// Last update Tue Jul 16 10:23:07 2013 florian dewulf
//

#ifndef		EXCEPT_H__
#define		EXCEPT_H__

#include	<iostream>
#include	<string>
#include	<stdexcept>
#include	<exception>

class		Except : public std::exception
{
public:
  Except(const std::string &);
  virtual	~Except()  throw();
  virtual const char* what() const throw();

private:
  const std::string	_catch_me;
};

#endif
