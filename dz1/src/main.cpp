#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "args.hpp"
#include "file.hpp"
#include "films.hpp"

int main(int argc, char *argv[]) {
  std::string name_file_name = "";
  std::string title_file_name = "";
  std::string actor_name = "";
  std::string title_akas_file_name = "";

  // проверка валидности входных данных
  int rc;
  if (rc = ParseArguments(argc, argv, name_file_name, title_file_name,
                          title_akas_file_name, actor_name)) {
    return rc;
  }
  if (rc = CheckDocument(name_file_name, 6)) {
    return rc;
  }
  if (rc = CheckDocument(title_file_name, 9)) {
    return rc;
  }
  if (rc = CheckDocument(title_akas_file_name, 8)) {
    return rc;
  }

  std::ifstream name_file(name_file_name, std::ifstream::in);
  std::ifstream title_file(title_file_name, std::ifstream::in);
  std::ifstream title_akas_file(title_akas_file_name, std::ifstream::in);
  std::vector<std::string> film_names;

  // находим id фильмов
  if (rc = FindFilmIds(name_file, actor_name, film_names)) {
    return rc;
  }
  std::vector<bool> checked_films(film_names.size(), false);
  std::vector<std::string> russian_titles = film_names;
  CheckRus(title_akas_file, russian_titles);
  // находим имена фильмов по id и чистим неподходящие по критериям
  FindFilmNames(title_file, film_names, checked_films);
  if (rc = ClearFilmNames(film_names, russian_titles, checked_films)) {
    return rc;
  }
  for (auto elm : film_names) {
    std::cout << elm << std::endl;
  }
  name_file.close();
  title_file.close();
  title_akas_file.close();
  return rc;
}

