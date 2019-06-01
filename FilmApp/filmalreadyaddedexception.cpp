#include "filmalreadyaddedexception.h"

std::string FilmAlreadyAddedException::render() { // Error message
    return "Film is already in the list!\n";
}
