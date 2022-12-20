#include <string>
#include <vector>
#include <stdio.h>

class lexer {
  public:

  static std::vector<std::string> analyze(std::string input) {
    std::vector<std::string> output;
    std::string str_cur = "";
    for(int i = 0; i <= input.size(); i++) {
      if(i == input.size()) {
        printf("roop finished with i is %d\n", i);
        output.push_back(str_cur);
        break;
      }

      std::string str = input.substr(i, 1);
      printf("%dth: %s\n", i+1, str.c_str());

      if(str == "=" || str == "+" || str == "-" || str == "*" || str == "/") {
        output.push_back(str_cur);
        output.push_back(str);
        str_cur = "";
      } else if(str == " ") {
        printf("this is empty.");
      } else {
        str_cur += str;
      }
    }
    return output;
  }
};