#ifndef FILMNOTFOUNDEXCEPTION_H
#define FILMNOTFOUNDEXCEPTION_H

#include <exception>
#include "myexception.h"
#include <string>
#include <iostream>

class FilmNotFoundException : public virtual MyException {
    public: std::string render(); // Error message
};

#endif // FILMNOTFOUNDEXCEPTION_H
