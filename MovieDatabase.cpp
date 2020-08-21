//
// Created by ursla on 07/04/2020.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "MovieDatabase.h"

void MovieDatabase::read(){
    std::ifstream l("films.txt");
    std::vector<std::string> film;
    std::string line;
    if(l.good()){                                       //if file exists
        while(getline(l,line,'\n')){        //while there are films left 'unread' in the file
            film = split(line,',');             //define a film
            Movie temp;
            if (film.size()==7){                           //if there is a comma in the title... This is since I am using the comma charecter as a delimeter
                temp.setTitle(film[0]+','+film[1]);
                temp.setYear(stoi(film[2]));
                temp.setClassifications(film[3]);
                temp.setGenres(film[4]);
                temp.setLength(stoi(film[5]));
                temp.setRating(stod(film[6]));      //set attributes in Movie object based on vector containing film details
                films.push_back(temp);}                           //adds the movie object to the end of the Movie vector
            else{
                temp.setTitle(film[0]);
                temp.setYear(stoi(film[1]));
                temp.setClassifications(film[2]);
                temp.setGenres(film[3]);
                temp.setLength(stoi(film[4]));
                temp.setRating(stod(film[5]));
                films.push_back(temp);}}
        l.close();
    }

}

std::vector<std::string> MovieDatabase::split(std::string splitString, char delimeter){
    std::stringstream ss(splitString);
    std::string temp;
    std::vector<std::string> newStringVector;
    while (std::getline(ss, temp, delimeter))
    {
        newStringVector.push_back(temp);
    }
    return newStringVector;
}


std::vector<Movie> MovieDatabase::subsetFilms(std::string category,std::string filter) {
    std::vector<Movie> copy = films;
    std::vector<Movie> newV;

    if(category=="Title"){
        std::copy_if(copy.begin(), copy.end(), std::back_inserter(newV), [filter](Movie a) {      //if Title is the argument passed in, the return vector will be populated with Movie objects matching titles
            return a.getTitle().rfind(filter)!=-1;          //returns values if the year of the movie object is the same as the filter
        });}
    else if (category == "Year"){
        std::copy_if(copy.begin(), copy.end(), std::back_inserter(newV), [filter](Movie a) {
            return a.getYear() == std::stoi(filter);        //returns values if the year of the movie object is the same as the filter
        });}

    else if(category == "Classifications"){
        std::copy_if(copy.begin(), copy.end(), std::back_inserter(newV), [filter](Movie a) {
            return a.getClassifications().rfind(filter)!=-1;        //returns values if the classification of the movie object is the same as the filter
        });
    }
    else if(category == "Genres"){
        std::copy_if(copy.begin(), copy.end(), std::back_inserter(newV), [filter](Movie a) {
            return a.getGenres().rfind(filter)!=-1;                 //returns values if the filter of the movie object is the same as the filter
        });
    }
    else if(category == "Length"){
        std::copy_if(copy.begin(), copy.end(), std::back_inserter(newV), [filter](Movie a) {
            return a.getLength()==std::stoi(filter);            //returns values if the length of the movie object is the same as the filter
        });}
    else if(category == "Rating"){
        std::copy_if(copy.begin(), copy.end(), std::back_inserter(newV), [filter](Movie a) {
            return a.getRating()==std::stod(filter);            //returns values if the rating of the movie object is the same as the filter
        });}
    else{
        std::cout<<"That category doesn't exist"<<std::endl;
    }
    return newV;
}

std::vector<Movie> MovieDatabase::sortedFilms(std::vector<Movie> movies,std::string category){
    if(category=="Title"){
        std::sort(movies.begin(), movies.end(),[](Movie a,Movie b){
            return a.getTitle().size()<b.getTitle().size();     //returns values sorted based on title length
        });}
    else if(category=="Year"){
        std::sort(movies.begin(), movies.end(),[](Movie a,Movie b){
            return a.getYear()<b.getYear();     //returns values sorted based on year value
        });}
    else if(category=="Classifiactions"){
        std::sort(movies.begin(), movies.end(),[](Movie a,Movie b){
            return a.getClassifications()<b.getClassifications();   //returns values sorted based on classifications
        });}
    else if(category=="Genres"){
        std::sort(movies.begin(), movies.end(),[](Movie a,Movie b){
            return a.getGenres()<b.getGenres();     //returns values sorted based on genre
        });}

    else if(category=="Length"){
        std::sort(movies.begin(), movies.end(),[](Movie a,Movie b){
            return a.getLength()<b.getLength();         //returns values sorted based on length value
        });}
    else if(category=="Rating"){
        std::sort(movies.begin(), movies.end(),[](Movie a,Movie b){
            return a.getRating()<b.getRating();     //returns values sorted based on rating value
        });}



        return movies;
    }

void MovieDatabase::mditerator(std::vector<Movie> temp) {
    for (Movie movie:temp) {
        std::cout << movie.getAllDetails() << std::endl;
    }                                                                           //iterates through movies in vector
}

MovieDatabase::~MovieDatabase() {
}
