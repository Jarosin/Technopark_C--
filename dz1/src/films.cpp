#include <films.hpp>

bool isRussian(std::string name)
{
    std::string rus = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ ,;':.!?<>[]{}";
    for (auto i = name.begin(); i < name.end(); i++)
    {
        if (rus.find(*i) == std::string::npos && !std::isdigit(*i))
        {
            return false;
        }
    }
    return true;
}

int FindFilmIds(std::ifstream &in, std::string actor_name, std::vector<std::string>& film_names)
{
    if (!in)
    {
        return 1;
    }
    std::string name = "";
    std::string temp;
    while (name.empty() && !in.eof())
    {
        //второй столбик - имя актера
        for (int i = 0; i < 2; i++)
        {
            std::getline(in, temp, '\t');
        }
        if (temp == actor_name)
        {
            //6ой столбик - перечисление id фильмов актера
            for (int i = 0; i < 3; i++)
            {
                std::getline(in, temp, '\t');
            }
            //берем до конца строки чтобы не захватить лишнего
            std::getline(in, temp, '\n');
            name = temp;
        }
        else
            std::getline(in, temp, '\n');
    }
    in.close();
    if (name.length() == 0)
    {
        std::cout << "Couldnt find any films with the actor" << std::endl;
        return 1;
    }
    film_names = ParseFilmIdString(name);
    return 0;
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

void FindFilmNames(std::ifstream &in, std::vector<std::string> &films, std::vector<bool> &checked_films)
{
    if (!in.is_open())
    {
        return;
    }
    std::string name;
    std::string temp;
    while (name.length() == 0 && !in.eof())
    {
        std::getline(in, temp, '\t');
        //пока так из-за checked_films строчки ниже
        for (auto it = films.begin(); it < films.end(); it++)
        {
            //если не нужный id - идем дальше
            if ((*it) != temp)
            {
                continue;
            }   

            //нашли фильм
            checked_films[it - films.begin()] = true;
            std::getline(in, temp, '\t');
            if (temp != "movie")
            {
                *it = "";
                break;
            }

            //получаем primaryTitle
            std::getline(in, temp, '\t');
            *it = temp;

            //проверка на русское название для originalTitle(из ревью следует что это необходимо поменять на проверку региона)
            std::getline(in, temp, '\t');
            if (isRussian(temp))
            {
                *it = temp;
            }
    
            //проверка на фильм для взрослых
            std::getline(in, temp, '\t');
            if (temp == "1")
            {
                *it = "";
            }
            break;
        }
        std::getline(in, temp, '\n');  
    }
    in.close();
}

int ClearFilmNames(std::vector<std::string> &film_names, std::vector<bool> &checked_films)
{
    std::vector<std::string> res = film_names;
    film_names.clear();
    int rc = 0, found_films = 0;
    for (auto it = res.begin(); it < res.end(); it++)
    {
        if (checked_films[it - res.begin()])
        {
            found_films++;
        }
        if (checked_films[it - res.begin()] && *it != "")
        {
            film_names.push_back(*it);
        }
    }
    //нет найденных фильмов
    if (!found_films)
    {
        std::cout << "Could not find required info on films in a file" << std::endl;
        return 1;
    }
    //все фильмы не подошли/не были проверены
    if (!film_names.size())
    {
        std::cout << "Didnt find any films meeting the criteria" << std::endl;
    }
    return 0;
}