#include <iostream>
#include <fstream>
#include <string>
int main()
{
    std::string artist_name = "Robert De Niro";
    std::string file_name = "../name.basics.tsv";
    std::ifstream myfile; 
    std::string name;
    std::string temp;
    myfile.open(file_name);
    while (name.size() == 0 && !myfile.eof())
    {
        for (int i = 0; i < 2; i++)
        {
            std::getline(myfile, temp, '\t');
        }
        if (temp == artist_name)
            name = temp;
        std::getline(myfile, temp);
    }
    std::cout << name << std::endl;
    //std::cout << temp;
    return 0;
}