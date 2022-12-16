#include <iostream>
#include "lexer.h"
#include "parser.h"
using namespace std;

int main() {
  string input = "x2=x1+3*2";
  vector<string> tokens = lexer::analyze(input);

  for (string token : tokens) cout << token << " ";
  cout << endl;

  Node *root = parser::analyze(tokens);
  Node *child1 = root->child;
  std::cout << child1->value << " ";
  std::cout << child1->brother->value << " ";
  std::cout << child1->brother->brother->value << std::endl;
}