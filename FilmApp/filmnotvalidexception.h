#ifndef FILMNOTVALIDEXCEPTION_H
#define FILMNOTVALIDEXCEPTION_H

#include <exception>
#include "myexception.h"
#include <string>
#include <iostream>

class FilmNotValidException : public virtual MyException {
    public: std::string render(); // Error message
};

#endif // FILMNOTVALIDEXCEPTION_H
