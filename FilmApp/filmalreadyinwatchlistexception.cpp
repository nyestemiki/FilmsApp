#include "filmalreadyinwatchlistexception.h"

std::string FilmAlreadyInWatchlistException::render() { // Error message
    return "Film is already in the watchlist!\n";
}
