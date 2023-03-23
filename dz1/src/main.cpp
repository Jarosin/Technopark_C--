#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <locale> 
#include <getopt.h>
bool isRussian(std::string name)
{
    //я пытался сделать по человечески
    /*std::locale loc("ru-RU");
    for (auto it = name.begin(); it < name.end(); it++)
        if (!(std::isalpha(*it, loc) || std::isdigit(*it)))
            return 0;*/
    std::string rus = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ ,;':.!?<>[]{}";
    for (auto i = name.begin(); i < name.end(); i++)
    {
        if (std::isdigit(*i))
            continue;
        if (rus.find(*i) == std::string::npos)
            return false;
    }
    return true;
}
std::string FindFilms(std::string file_name, std::string artist_name)
{
    std::ifstream myfile;
    myfile.open(file_name);
    if (!myfile)
        return "";

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
    myfile.close();
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
void FindFilmNames(std::string file_name, std::vector<std::string> &films, std::vector<bool> &checked_films)
{
    std::ifstream myfile;
    myfile.open(file_name);
    if (!myfile.is_open())
        return;
    std::string name;
    std::string temp;
    while (name.length() == 0 && !myfile.eof())
    {
        std::getline(myfile, temp, '\t');
        for (auto it = films.begin(); it < films.end(); it++)
        {
            if ((*it) == temp)
            {      
                checked_films[it - films.begin()] = true;
                std::getline(myfile, temp, '\t');
                if (temp != "movie")
                {
                    *it = "";
                    break;
                }

                std::getline(myfile, temp, '\t');
                *it = temp;

                std::getline(myfile, temp, '\t');
                if (isRussian(temp))
                    *it = temp;

                std::getline(myfile, temp, '\t');
                if (temp == "1")
                    *it = "";
                break;
            }
        }
        std::getline(myfile, temp, '\n');  
    }
    myfile.close();
}
int ParseArguments(int argc, char *argv[], std::string &name_file_name, std::string &title_file_name, std::string &artist_name)
{
    int opt;
    int option_index = 0;
    static struct option long_options[] = {
        {"title-basics-file", 1, 0, 't'},
        {"name-basics-file", 1, 0, 'n'},
        {"help", 0, 0, 'h'},
        {"artist-name", 1, 0, 'a'},
        {0, 0, 0, 0}
    };
     while ((opt = getopt_long_only(argc, argv, "abc", long_options, &option_index)) != -1)
    {
        switch(opt)
        {
            case -1:
                break;
            case 't':
                title_file_name = optarg;
                break;
            case 'n':
                name_file_name = optarg;
                break;
            case 'a':
                artist_name = optarg;
                break;
            case 'h':
                std::cout << "Required arguments: --name-basics-file=filename1 --title-basics-file=filename2 --artist-name=artist_name" << std::endl;
                return 1;
                break;
            default:
                std::cout << "Unknown option given" << std::endl;
                return 1;
        }
    }
    if (title_file_name.empty() || name_file_name.empty() || artist_name.empty())
    {
        std::cout << "Not all arguments were given" << std::endl;
        return 1;
    }
    return 0;
}
//1 - файл с актерами, 2 - файл с фильмами, 3 - имя актера
int main(int argc, char *argv[])
{    
    std::string name_file_name = "";
    std::string title_file_name = "";
    std::string artist_name = "";
    int rc = ParseArguments(argc, argv, name_file_name, title_file_name, artist_name);
    if (rc)
        return rc;
    std::string raw_films;
    std::vector<std::string> parsed_films;
    std::ifstream myfile; 
    raw_films = FindFilms(name_file_name, artist_name);
    parsed_films = ParseFilmIdString(raw_films);   
    std::vector<bool> checked_films(parsed_films.size(), false);
    FindFilmNames(title_file_name, parsed_films, checked_films);
    for (auto it = parsed_films.begin(); it < parsed_films.end(); it++)
    {
        if (checked_films[it - parsed_films.begin()] && *it != "")
            std::cout << (*it) << std::endl;    
    }
    return 0;
}
//todo: разнести функции по файлам
//todo: проверить что в документах правильное количество столбцов(насчет названий не уверен)