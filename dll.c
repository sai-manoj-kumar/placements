#include"tree.h"
#include"dll.h"


node* findmid(node* head, node* end)
{
        for(;head && end; head = head->next, end = end->prev){
                if( head == end || head->next == end ){
                        return head;
                }
        }
        return 0;
}


