#include "args.hpp"
int ParseArguments(int argc, char *argv[], std::string &name_file_name,
                   std::string &title_file_name,
                   std::string &title_akas_file_name, std::string &actor_name) {
  int opt;
  int option_index = 0;
  static struct option long_options[] = {{"title-basics-file", 1, 0, 't'},
                                         {"name-basics-file", 1, 0, 'n'},
                                         {"help", 0, 0, 'h'},
                                         {"actor-name", 1, 0, 'a'},
                                         {"title-akas-name", 1, 0, 'k'},
                                         {0, 0, 0, 0}};
  while ((opt = getopt_long_only(argc, argv, "g", long_options,
                                 &option_index)) != -1) {
    switch (opt) {
      case -1:
        break;
      case 't':
        title_file_name = optarg;
        break;
      case 'n':
        name_file_name = optarg;
        break;
      case 'a':
        actor_name = optarg;
        break;
      case 'h':
        std::cout << "Required arguments: --name-basics-file=filename1\
                 --title-basics-file=filename2 --actor-name=actor_name\
                  --title-akas-name"
                  << std::endl;
        return 1;
        break;
      case 'k': {
        title_akas_file_name = optarg;
        break;
      }
      default:
        std::cout << "Unknown option given" << std::endl;
        return 1;
    }
  }
  if (title_file_name.empty() || name_file_name.empty() || actor_name.empty() ||
      title_akas_file_name.empty()) {
    std::cout << "Not all arguments were given" << std::endl;
    return 1;
  }
  return 0;
}

