#include <iostream>
#include <fstream>
#include <string>

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
int main()
{
    std::string artist_name = "Anya Chipovskaya";
    std::string file_name = "../name.basics.tsv";
    std::string films;
    std::ifstream myfile; 
    films = FindFilms(file_name, artist_name);
    std::cout << films << std::endl;
    return 0;
}