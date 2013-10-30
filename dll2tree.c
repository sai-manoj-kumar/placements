#include<stdio.h>
#include<stdlib.h>


typedef struct node{
        int val;
        struct node *prev, *next;
}node;

node* findmid(node* head, node* end)
{
        for(;head && end; head = head->next, end = end->prev){
                if( head == end || head->next == end ){
                        return head;
                }
        }
        return 0;
}

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

void inorder(node *head)
{
        if( head->prev ){
                inorder(head->prev);
        }
        printf("%d\n", head->val);
        if( head->next ){
                inorder(head->next);
        }

}

void preorder(node *head)
{
        printf("%d\n", head->val);
        if( head->prev ){
                preorder(head->prev);
        }
        if( head->next ){
                preorder(head->next);
        }
}

void postorder(node *head)
{
        if( head->prev ){
                postorder(head->prev);
        }
        if( head->next ){
                postorder(head->next);
        }
        printf("%d\n", head->val);
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
        for(cur = head; cur; cur = cur->next){
                printf("%d\n", cur->val);
        }


        head = dll2tree(head, last);

        printf("In order\n");
        inorder(head);

        printf("Pre order\n");
        preorder(head);

        printf("Post order\n");
        postorder(head);

        return 0;
}

