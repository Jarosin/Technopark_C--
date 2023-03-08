#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
std::string FindFilms(std::string file_name, std::string artist_name)
{
    std::ifstream myfile;
    myfile.open(file_name);
    std::string name;
    std::string temp;
    while (name.length() == 0 && !myfile.eof())
    {
        for (int i = 0; i < 2; i++)
        {
            std::getline(myfile, temp, '\t');
        }
        if (temp == artist_name)
        {
            name = temp;
            for (int i = 0; i < 3; i++)
            {
                std::getline(myfile, temp, '\t');
            }
            std::getline(myfile, temp, '\n');

        }
        else
            std::getline(myfile, temp);
    }
    return temp;
}
std::vector<std::string> ParseFilmIdString(std::string film_ids)
{
    std::string temp;
    std::stringstream buff(film_ids);
    std::vector<std::string> res;
    while (std::getline(buff, temp, ','))
    {
        res.push_back(temp);
    }
    return res;
}
int main()
{
    std::string artist_name = "Anya Chipovskaya";
    std::string file_name = "../name.basics.tsv";
    std::string raw_films;
    std::vector<std::string> parsed_films;
    std::ifstream myfile; 
    raw_films = FindFilms(file_name, artist_name);
    std::cout << raw_films << std::endl;
    parsed_films = ParseFilmIdString(raw_films);
    for (auto it = parsed_films.begin(); it < parsed_films.end(); it++)
    {
        std::cout << (*it) << std::endl;
    }
    return 0;
}