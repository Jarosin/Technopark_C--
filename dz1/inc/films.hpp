#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <locale> 
void FindFilmNames(std::ifstream &in, std::vector<std::string> &films, std::vector<bool> &checked_films);
std::vector<std::string> ParseFilmIdString(std::string film_ids);
int FindFilmIds(std::ifstream &in, std::string actor_name, std::vector<std::string> &filmed_names);
int ClearFilmNames(std::vector<std::string> &film_names, std::vector<std::string> &russian_titles, std::vector<bool> &checked_films);
int CheckRus(std::ifstream &in, std::vector<std::string> &films);