#include <films.hpp>
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

