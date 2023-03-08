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
bool isRussian(std::string name)
{
    //я пытался сделать по человечески
    /*std::locale loc("ru-RU");
    for (auto it = name.begin(); it < name.end(); it++)
        if (!(std::isalpha(*it, loc) || std::isdigit(*it)))
            return 0;*/
    bool flag = false;
    std::string rus = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    for (auto i = name.begin(); i < name.end(); i++)
    {
        if (std::isdigit(*i))
            continue;
        for (auto it = rus.begin(); it < rus.end(); it++)
            if (*it == *i)
            {
                flag = true;
                break;
            }
        if (!flag)
            return false;
        flag = false;
    }
    return true;
}
void FindFilmNames(std::string file_name, std::vector<std::string> films)
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
                for (int i = 0; i < 2; i++)
                {
                    std::getline(myfile, temp, '\t');
                }
                *it = temp;
                std::cout << "First name: " << temp << std::endl;
                std::getline(myfile, temp, '\t');
                std::cout << "Second name: " << temp << std::endl;
                if (!isRussian(*it))
                {
                    if (isRussian(temp))
                        *it = temp;
                }
                std::getline(myfile, temp, '\t');
                if (temp == "1")
                    *it = "";
                break;
            }
        }
        std::getline(myfile, temp, '\n');  
    }
}

int main()
{
    std::string artist_name = "Anya Chipovskaya";
    std::string nfile_name = "../name.basics.tsv";
    std::string ffile_name = "../title.basics.tsv";
    std::string raw_films;
    std::vector<std::string> parsed_films;
    std::ifstream myfile; 
    raw_films = FindFilms(nfile_name, artist_name);
    std::cout << raw_films << std::endl;
    parsed_films = ParseFilmIdString(raw_films);
    for (auto it = parsed_films.begin(); it < parsed_films.end(); it++)
    {
        std::cout << (*it) << std::endl;
    }
    FindFilmNames(ffile_name, parsed_films);
    for (auto it = parsed_films.begin(); it < parsed_films.end(); it++)
    {
        std::cout << (*it) << std::endl;
    }
    return 0;
}