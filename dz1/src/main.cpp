#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <locale> 
#include "args.hpp"
#include "films.hpp"
#include "file.hpp"

int main(int argc, char *argv[])
{    
    std::string name_file_name = "";
    std::string title_file_name = "";
    std::string artist_name = "";

    int rc = ParseArguments(argc, argv, name_file_name, title_file_name, artist_name);
    if (rc)
        return rc;
    rc = CheckDocument(name_file_name, 6);
    if (!rc)
    {
        rc = CheckDocument(title_file_name, 9);
    }
    if (rc)
        return rc;
    std::string raw_films;
    std::vector<std::string> parsed_films;
    std::ifstream myfile; 
    raw_films = FindFilms(name_file_name, artist_name);
    if (raw_films.length() == 0)
    {
        std::cout << "Couldnt find any films with the actor" << std::endl;
        return 0;
    }
    parsed_films = ParseFilmIdString(raw_films);
    std::vector<bool> checked_films(parsed_films.size(), false);
    FindFilmNames(title_file_name, parsed_films, checked_films); 
    int count = 0, found_films = 0;
    for (auto it = parsed_films.begin(); it < parsed_films.end(); it++)
    {
        if (checked_films[it - parsed_films.begin()])
            found_films++;
        if (checked_films[it - parsed_films.begin()] && *it != "")
        {
            std::cout << (*it) << std::endl;
            count++;
        }
    }
    if (!found_films)
    {
        std::cout << "Could not find required info on films in a file" << std::endl;
        return 1;
    }
    if (!count)
        std::cout << "Didnt find any films meeting the criteria" << std::endl;
    return 0;
}