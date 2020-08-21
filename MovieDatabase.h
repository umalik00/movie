//
// Created by ursla on 07/04/2020.
//

#ifndef UNTITLED4_MOVIEDATABASE_H
#define UNTITLED4_MOVIEDATABASE_H

#include <vector>
#include <string>
#include "Movie.h"

class MovieDatabase {
    std::vector<std::string> split(std::string splitString, char delimeter);



public:
    void read();

    std::vector<Movie> films;

    std::vector<Movie> subsetFilms(std::string category, std::string filter);

    std::vector<Movie> sortedFilms(std::vector<Movie> movies, std::string category);

    void mditerator(std::vector<Movie> temp);       //iterator for Movie Vector

    ~MovieDatabase();       //destructor for Movie Database Objects when they aren't being used anymore
};
#endif //UNTITLED4_MOVIEDATABASE_H
