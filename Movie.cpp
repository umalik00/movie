//
// Created by ursla on 07/04/2020.
//

#include "Movie.h"
#include <string>

Movie::Movie(std::string theTitle, int theYear, std::string theClassifications, std::string theGenres, int theLength, double theRating){       //constructor with parameters being passed in
title = theTitle;
year=theYear;
classifications = theClassifications;
genres = theGenres;
length = theLength;
rating = theRating;}

Movie::Movie() {}       //constructor
Movie::~Movie(){}       //destructor
int Movie:: getYear(){      //getters
    return year;
}
int Movie::getLength() {
    return length;
}
double Movie::getRating() {
    return rating;
}
std::string Movie::getTitle() {
    return title;
}
std::string Movie::getClassifications() {
    return classifications;
}
std::string Movie::getGenres(){
    return genres;
}

std::string Movie::getAllDetails(){
    return title+','+std::to_string(year)+','+classifications+','+genres+','+std::to_string(length)+','+std::to_string(rating);
}
void Movie::setTitle(std::string newTitle) {        //setters
    title = newTitle;
}
void Movie::setYear(int newYear) {
    year = newYear;
}
void Movie::setClassifications(std::string newClassifications) {
    classifications = newClassifications;
}
void Movie::setGenres(std::string newGenres) {
    genres = newGenres;
}
void Movie::setRating(double newRating) {
    rating = newRating;
}
void Movie::setLength(int newLength) {
    length = newLength;
}
