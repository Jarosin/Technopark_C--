#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <locale> 
void FindFilmNames(std::string file_name, std::vector<std::string> &films, std::vector<bool> &checked_films);
std::vector<std::string> ParseFilmIdString(std::string film_ids);
std::string FindFilms(std::string file_name, std::string artist_name);
bool isRussian(std::string name);

