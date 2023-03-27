#include <file.hpp>
int CheckDocument(std::string file_name, int columns) {
  if (columns < 1) {
    return 1;
  }

  std::ifstream file;
  file.open(file_name);
  if (!file.is_open()) {
    std::cout << "Cant open file" << std::endl;
    return 1;
  }

  std::string temp = "";
  for (int i = 0; i < columns; i++) {
    std::string temp = "";
    std::getline(file, temp, '\t');
    if (temp.find('\n') != std::string::npos) {
      if (i == columns - 1) {
        return 0;
      }
    }
  }
  std::cout << "File has wrong number of columns" << std::endl;
  file.close();
  return 1;
}
