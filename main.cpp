#include <iostream>
#include "lexer.h"
#include "parser.h"
using namespace std;

void myprint(node *p) {
  std::cout << p->value << " ";

  if(p->left != NULL) myprint(p->left);
  if(p->right != NULL) myprint(p->right);
}

int main() {
  string input; cin >> input;
  vector<string> tokens = lexer::analyze(input);

  for (string token : tokens) cout << token << " ";
  cout << endl;

  Node *root = parser::analyze(tokens);

  myprint(root);
  std::cout << std::endl;
}