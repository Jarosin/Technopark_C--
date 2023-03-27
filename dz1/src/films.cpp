#include <films.hpp>
constexpr char sep = '\t';
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
        //2-ой столбик - имя актера
        for (int i = 0; i < 2; i++)
        {
            std::getline(in, temp, sep);
        }
        if (temp == actor_name)
        {
            //6-ой столбик - перечисление id фильмов актера
            for (int i = 0; i < 3; i++)
            {
                std::getline(in, temp, sep);
            }
            //берем до конца строки чтобы не захватить лишнего со следующей
            std::getline(in, name, '\n');
        }
        else
            std::getline(in, temp, '\n');
    }
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
    while (name.empty() && !in.eof())
    {
        std::getline(in, temp, sep);
        int cur = -1;
        //пока так из-за использования арифметики указателей
        for (auto it : films)
        {
            cur++;
            //если не нужный id - идем дальше
            if (it != temp)
            {
                continue;
            }   

            std::getline(in, temp, sep);
            if (temp != "movie")
            {
                it = "";
                break;
            }

            //получаем primaryTitle
            std::getline(in, temp, sep);
            it = temp;
            //пропускаем originalTitle
            std::getline(in, temp, sep);

            //проверка на фильм для взрослых
            std::getline(in, temp, sep);
            if (temp == "1")
            {
                it = "";
            } 
            checked_films[cur] = true;
            break;
        }
        //дочитываем строку
        std::getline(in, temp, '\n');  
    }
}

int ClearFilmNames(std::vector<std::string> &film_names, std::vector<std::string> &russian_titles, std::vector<bool> &checked_films)
{
    std::vector<std::string> res = film_names;
    film_names.clear();
    int rc = 0, found_films = 0;
    int cur = 0;
    for (auto it : res)
    {
        //отмечаем что смогли найти фильм
        if (checked_films[cur])
        {
            found_films++;
        }
        //сливаем вместе если найдено хотя бы одно из названий
        if (checked_films[cur] && it != "")
        {
            if (!russian_titles[cur].empty())
            {
                it = russian_titles[cur];
            }
            film_names.push_back(it);
        }
        cur++;
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

int CheckRus(std::ifstream &in, std::vector<std::string> &films)
{
    std::string name = "";
    std::string temp = "";
    std::vector<std::string> res = films;
    //по дефолту - пустая строка
    for (int i = 0; i < films.size(); i++)
    {
        films[i] = "";
    }
    while (!in.eof())
    {
        int cur = -1;
        std::getline(in, temp, sep);
        for (auto it : res)
        {
            cur++;
            if (temp != it)
                continue;
            std::getline(in, temp, sep);
            std::getline(in, name, sep);
            std::getline(in, temp, sep);
            if (temp == "RU")
            {
                films[cur] = name;
            }
        }
        std::getline(in, temp, '\n');
    }
    return 0;
}
