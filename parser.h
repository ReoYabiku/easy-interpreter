#include <string>
#include <vector>
#include <stdio.h>

typedef struct node {
  std::string value;
  struct node *parent;
  struct node *left;
  struct node *right;
} Node;

class parser {
  public:

  static struct node* analyze(std::vector<std::string> tokens) {
    Node *root;
    root = (Node *)malloc(sizeof(Node));
    Node *left_side;
    left_side = (Node *)malloc(sizeof(Node));
    left_side->value = tokens[0];

    Node *tmp; // 最右端のノードへのポインタを保持する

    for(int i = 1; i < tokens.size(); i += 2) {
      if(tokens[i] == "=") {
        root->value = tokens[i];
        root->left = left_side;
        left_side->parent = root;

        Node *pre;
        pre = (Node *)malloc(sizeof(Node));
        tmp = pre;
        pre->value = tokens[i+1];
        pre->parent = root;
        root->right = pre;
      }

      if(tokens[i] == "*" || tokens[i] == "/") {
        Node *parent = tmp->parent;
        Node *now;
        now = (Node *)malloc(sizeof(Node));
        now->value = tokens[i];
        now->left = tmp;
        tmp->parent = now;

        now->parent = parent;
        parent->right = now;

        Node *right;
        right = (Node *)malloc(sizeof(Node));
        right->value = tokens[i+1];
        now->right = right;
        right->parent = now;

        tmp = right;
      }

      if(tokens[i] == "+" || tokens[i] == "-") {
        Node *now;
        now = (Node *)malloc(sizeof(Node));
        now->value = tokens[i];

        while(tmp->parent->value == "*" || tmp->parent->value == "/") {
          tmp = tmp->parent;
        }

        Node *parent = tmp->parent;

        parent->right = now;
        now->parent = parent;

        now->left = tmp;
        tmp->parent = now;

        Node *right;
        right = (Node *)malloc(sizeof(Node));
        right->value = tokens[i+1];
        right->parent = now;
        now->right = right;

        tmp = right;
      }
    }
    
    return root;
  }
};