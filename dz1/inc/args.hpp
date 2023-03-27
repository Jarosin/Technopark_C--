#pragma once
#include <getopt.h>

#include <iostream>
#include <string>
int ParseArguments(int argc, char *argv[], std::string &name_file_name,
                   std::string &title_file_name,
                   std::string &title_akas_file_name, std::string &artist_name);

