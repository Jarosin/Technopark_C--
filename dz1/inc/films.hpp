#pragma once
#include <fstream>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include <vector>
#define NAME_COLUMN 2
#define FILM_ID_COLUMN 5
void FindFilmNames(std::ifstream &in, std::vector<std::string> &films,
                   std::vector<bool> &checked_films);
std::vector<std::string> ParseFilmIdString(std::string film_ids);
int FindFilmIds(std::ifstream &in, std::string actor_name,
                std::vector<std::string> &filmed_names);
int ClearFilmNames(std::vector<std::string> &film_names,
                   std::vector<std::string> &russian_titles,
                   std::vector<bool> &checked_films);
int CheckRus(std::ifstream &in, std::vector<std::string> &films);
