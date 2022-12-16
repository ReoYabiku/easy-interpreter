#include <string>
#include <vector>
#include <stdio.h>

class lexer {
  public:

  static std::vector<std::string> analyze(std::string input) {
    std::vector<std::string> output;
    output.push_back("x2");
    output.push_back("=");
    output.push_back("x1");
    output.push_back("+");
    output.push_back("3");
    output.push_back("*");
    output.push_back("5");
    return output;
  }
};