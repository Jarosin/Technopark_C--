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
bool isRussian(std::string name);
int ClearFilmNames(std::vector<std::string> &film_names, std::vector<bool> &checked_films);
