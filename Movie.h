//
// Created by ursla on 07/04/2020.
//

#ifndef UNTITLED4_MOVIE_H
#define UNTITLED4_MOVIE_H

#include <string>

class Movie{
private:
    std::string title; int year; std::string classifications; std::string genres; int length{}; double rating{};

public:
    Movie();
    Movie(std::string title, int year, std::string classifications, std::string genres, int length,double rating);
    ~Movie();   //destructor

    std::string getTitle();
    int getYear();
    int getLength();
    std::string getGenres();
    std::string getClassifications();
    double getRating();
    std::string getAllDetails();

    void setTitle(std::string newTitle);
    void setYear(int newYear);
    void setClassifications(std::string newClassifications);
    void setGenres(std::string newGenres);
    void setLength(int newLength);
    void setRating(double newRating);

};

#endif //UNTITLED4_MOVIE_H
