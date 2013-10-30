#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
#include"dll.h"


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


int main()
{
        node *head=0, *cur, *prev=0, *last;
        int i, n = 10;
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
        printf("List\n");
        for(cur = head; cur; cur = cur->next){
                printf("%d  ", cur->val);
        }
        printf("\n");


        head = dll2tree(head, last);

        printf("In order\n");
        inorder(head);

        printf("\nPre order\n");
        preorder(head);

        printf("\nPost order\n");
        postorder(head);
        printf("\n");

        return 0;
}

