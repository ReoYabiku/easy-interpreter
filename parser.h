#include <string>
#include <vector>
#include <stdio.h>

typedef struct node {
  std::string value;
  struct node *child;
  struct node *brother;
} Node;

class parser {
  public:

  static struct node* analyze(std::vector<std::string> tokens) {
    Node *child3;
    child3 = (Node *)malloc(sizeof(Node));
    child3->value = "5";
    child3->child = NULL;
    child3->brother = NULL;

    Node *child2;
    child2 = (Node *)malloc(sizeof(Node));
    child2->value = "=";
    child2->child = NULL;
    child2->brother = NULL;

    Node *child1;
    child1 = (Node *)malloc(sizeof(Node));
    child1->value = "x";
    child1->child = NULL;
    child1->brother = NULL;

    Node *root;
    root = (Node *)malloc(sizeof(Node));
    root->child = child1;
    child1->brother = child2;
    child2->brother = child3;
    root->brother = NULL;

    return root;
  }
};