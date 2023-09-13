#include "list.h"
#include <stdlib.h>

t_list *sort_list(t_list* lst, int (*cmp)(int, int))
{
    int aux;
    t_list *tmp;

    tmp = lst;
    while(lst->next != NULL)
    {
        if((*cmp)(lst->data, lst->next->data) == 0)
        {
            aux = lst->data;
            lst->data = lst->next->data;
            lst->next->data = aux;
            lst = tmp;
        }
        else
            lst = lst->next;
    }
    lst = tmp;
    return lst;
}