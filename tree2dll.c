#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

node* dll2tree(node *head, node *end)
{
        if( head == end ){
                head->prev = head->next = 0;
                return head;
        }
        node *mid = findmid(head, end);
        node *lroot;
        if( head != mid ){
                lroot = dll2tree(head, mid->prev);
        }else {
                lroot = 0;
        }
        node *rroot = dll2tree(mid->next, end);
        mid->prev = lroot;
        mid->next = rroot;

        return mid;
}

void tree2dll(node *root, node **head, node **end)
{
        node **head1 = malloc(sizeof(node *));
        node **end1 = malloc(sizeof(node *));
        node **head2 = malloc(sizeof(node *));
        node **end2 = malloc(sizeof(node *));
        if( root->prev ){
                tree2dll(root->prev, head1, end1);
                root->prev = *end1;
                if( end1 && *end1 )
                        (*end1)->next = root;
        }
        if( root->next ){
                tree2dll(root->next, head2, end2);
                root->next = *head2;
                if( head2 && *head2 )
                        (*head2)->prev = root;
        }

        if( head1 && *head1 )
                *head = *head1;
        else
                *head = root;
        if( end2 && *end2 )
                *end = *end2;
        else
                *end = root;
}


int main()
{
        node *head=0, *cur, *prev=0, *last;
        int i, n = 64;
        for(i = 0; i < n; i++){
                cur = malloc(sizeof(node));
                cur->val = i + 1;
                if( prev ){
                        prev->next = cur;
                }
                if( !head ){
                        head = cur;
                }
                cur->prev = prev;
                prev = cur;
        }
        last = cur;

        node* root = dll2tree(head, last);

        printf("In order\n");
        inorder(root);

        printf("\nPre order\n");
        preorder(root);

        tree2dll(root, &head, &last);

        printf("\nDLL Head to Last\n");
        for(cur = head; cur; cur = cur->next){
                printf("%d  ", cur->val);
        }
        printf("\nLast to Head\n");
        for(cur = last; cur; cur = cur->prev){
                printf("%d  ", cur->val);
        }
        printf("\n");
        return 0;
}

