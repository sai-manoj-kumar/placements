
#ifndef TREE_H
#define TREE_H

#include<stdio.h>

typedef struct node{
        int val;
        struct node *prev, *next;
}node;


void inorder(node *head);

void preorder(node *head);

void postorder(node *head);

node* findmid(node *head, node *end);

node* dll2tree(node *head, node *end);


#endif /* TREE_H */

