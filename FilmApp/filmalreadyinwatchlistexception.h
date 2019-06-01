#ifndef FILMALREADYINWATCHLISTEXCEPTION_H
#define FILMALREADYINWATCHLISTEXCEPTION_H

#include <exception>
#include "myexception.h"
#include <string>
#include <iostream>

class FilmAlreadyInWatchlistException  : public virtual MyException {
    public: std::string render(); // Error message
};

#endif // FILMALREADYINWATCHLISTEXCEPTION_H
