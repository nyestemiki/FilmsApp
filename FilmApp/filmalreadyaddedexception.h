#ifndef FILMALREADYADDEDEXCEPTION_H
#define FILMALREADYADDEDEXCEPTION_H

#include <exception>
#include "myexception.h"
#include <string>
#include <iostream>

class FilmAlreadyAddedException : public virtual MyException {
    public: std::string render(); // Error message
};

#endif // FILMALREADYADDEDEXCEPTION_H
