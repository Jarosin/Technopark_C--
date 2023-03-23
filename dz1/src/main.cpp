#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "args.hpp"
#include "films.hpp"
#include "file.hpp"

int main(int argc, char *argv[])
{    
    std::string name_file_name = "";
    std::string title_file_name = "";
    std::string actor_name = "";

    //проверка валидности входных данных
    int rc = ParseArguments(argc, argv, name_file_name, title_file_name, actor_name);
    if (!rc)
    {
        rc = CheckDocument(name_file_name, 6);
        if (!rc)
        {
            rc = CheckDocument(title_file_name, 9);
        }
    }
    if (rc)
    {
        return rc;
    }
    
    std::ifstream name_file(name_file_name, std::ifstream::in);
    std::ifstream title_file(title_file_name, std::ifstream::in);
    std::vector<std::string> film_names;
    //находим id фильмов
    rc = FindFilmIds(name_file, actor_name, film_names);
    if (!rc)
    {
        std::vector<bool> checked_films(film_names.size(), false);
        //находим имена фильмов по id и чистим неподходящие по критериям
        FindFilmNames(title_file, film_names, checked_films); 
        rc = ClearFilmNames(film_names, checked_films);
        if (!rc)
        {
            for (auto elm : film_names)
            {
                std::cout << elm << std::endl;
            }
        }
    }
    name_file.close();
    title_file.close();
    return rc;
}