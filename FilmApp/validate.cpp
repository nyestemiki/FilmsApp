#include "validate.h"

Validate::Validate() {}

Validate::Validate(Film* film){
    this->film = film;
}

Validate::~Validate() {}

// Determines whether the given film is valid
bool Validate::valid() {
    // Empty string
    if (film->get_title() == "" || film->get_genre() == "" || film->get_trailer() == "")
        return false;

    // Checking if trailer is valid link
    if (std::regex_match(film->get_trailer(), std::regex("^(https?:\/\/)?([\da-z\.-]+)\.([a-z\.]{2,6})([\/\w \.-]*)*\/?$") ))
        return false;

    // Year out of scope
    if (film->get_year() < 1700 || film->get_year() > 2022)
        return false;

    return true;
}
