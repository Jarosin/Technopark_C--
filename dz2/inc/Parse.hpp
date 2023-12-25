#ifndef PARSE_H
#define PARSE_H

#include <string>
constexpr auto kSqrtSign = "@";
constexpr auto kSqrtWord = "sqrt";
constexpr auto kCeilSign = "&";
constexpr auto kCeilWord = "ceil";
constexpr auto kAddSign = '+';
constexpr auto kSubSign = '-';
constexpr auto kMulSign = '*';
constexpr auto kOpenBracket = '(';
constexpr auto kCloseBracket = ')';

void ParseInput(std::string &inp);
int FindOpeningBracket(const std::string &inp);

#endif
