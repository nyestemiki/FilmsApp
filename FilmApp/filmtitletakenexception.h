#ifndef FILMTITLETAKENEXCEPTION_H
#define FILMTITLETAKENEXCEPTION_H

#include <iostream>
#include "myexception.h"

class FilmTitleTakenException : public virtual MyException {
    public: std::string render(); // Error message
};

#endif // FILMTITLETAKENEXCEPTION_H
