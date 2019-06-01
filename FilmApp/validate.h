#ifndef VALIDATE_H
#define VALIDATE_H

#include "film.h"
#include <regex>

class Validate {
    Film* film;

public:
    Validate();
    Validate(Film*);
    ~Validate();

    bool valid(); // Determines whether the given film is valid
};

#endif // VALIDATE_H
