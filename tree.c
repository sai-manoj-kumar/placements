#include"tree.h"

void inorder(node *head)
{
        if( head->prev ){
                inorder(head->prev);
        }
        printf("%d  ", head->val);
        if( head->next ){
                inorder(head->next);
        }

}

void preorder(node *head)
{
        printf("%d  ", head->val);
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
        printf("%d  ", head->val);
}


