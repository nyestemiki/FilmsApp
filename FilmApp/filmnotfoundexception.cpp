#include "filmnotfoundexception.h"

std::string FilmNotFoundException::render() { // Error message
    return "Film was not found!\n";
}
