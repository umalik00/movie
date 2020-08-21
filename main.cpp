#include <iostream>
#include "Movie.h"
#include "MovieDatabase.h"

int main() {
    MovieDatabase movieDatabase;
    movieDatabase.read();

    std::vector<Movie> first = movieDatabase.sortedFilms(movieDatabase.films,"Year");
    std::cout<<"The films in chronological order are as follows \n"<<std::endl;
    movieDatabase.mditerator(first);

    std::vector<Movie> second = movieDatabase.subsetFilms("Genres","Film-Noir");
    second = movieDatabase.sortedFilms(second,"Length");
    Movie secondFilm = second[second.size()-3];
    std::cout<<"\nThe third longest Film-Noir Film is :"+secondFilm.getAllDetails()+"\n"<<std::endl;


    std::vector<Movie> third = movieDatabase.subsetFilms("Classifications", "UNRATED");
    third = movieDatabase.sortedFilms(third,"Year");
    Movie thirdFilm = third[third.size()-8];
    std::cout<<"The eighth most recent UNRATED film is :"+thirdFilm.getAllDetails()+"\n"<<std::endl;

    std::vector<Movie> fourth = movieDatabase.sortedFilms(movieDatabase.films, "Title");
    Movie fourthFilm = fourth[fourth.size()-1];
    std::cout<<"The film with the longest title is: \n"+fourthFilm.getAllDetails();

    return 0;
    //used new lines to separate info
}




//ignore below
//used for testing and didn't know whether or not I should keep it here for you to see

//std::cout<<third[1].getAllDetails();
//v.mditerator(fourth);
//    std::vector<Movie> s  = v.subsetFilms("Classifications","PG");
//    std::vector<Movie> s  = v.subsetFilms("Classifications","PG");
//    v.mditerator(s);
// std::cout << "Hello, World!" << std::endl;