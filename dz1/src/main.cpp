#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <locale> 
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
void FindFilmNames(std::string file_name, std::vector<std::string> &films)
{
    std::ifstream myfile;
    myfile.open(file_name);
    std::string name;
    std::string temp;
    while (name.length() == 0 && !myfile.eof())
    {
        std::getline(myfile, temp, '\t');
        for (auto it = films.begin(); it < films.end(); it++)
        {
            if ((*it) == temp)
            {
                for (int i = 0; i < 3; i++)
                {
                    std::getline(myfile, temp, '\t');
                }
                *it = temp;
                std::getline(myfile, temp, '\t');
                if (temp == "1")
                    *it = "";
                break;
            }
        }
        std::getline(myfile, temp, '\n');  
    }
}
//1 - файл с актерами, 2 - файл с фильмами, 3 - имя актера
int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        return 0;
    } 
    std::string nfile_name = argv[1];
    std::string ffile_name = argv[2];
    std::string artist_name = argv[3];
    std::string raw_films;
    std::vector<std::string> parsed_films;
    std::ifstream myfile; 
    raw_films = FindFilms(nfile_name, artist_name);
    parsed_films = ParseFilmIdString(raw_films);
    FindFilmNames(ffile_name, parsed_films);
    for (auto it = parsed_films.begin(); it < parsed_films.end(); it++)
    {
        std::cout << (*it) << std::endl;
    }
    return 0;
}