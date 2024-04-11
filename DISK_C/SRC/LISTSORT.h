
#ifndef _LISTSORT_H
#define _LISTSORT_H

#include "LISTDF.h"

void node_swap(struct My_filenode *frontNode1, struct My_filenode *frontNode2);

void sort_by_name1(struct My_filenode *headNode);
void sort_by_name2(struct My_filenode *headNode);

int timecmp(struct Filetime *t1, struct Filetime *t2);
void sort_by_time1(struct My_filenode *headNode);
void sort_by_time2(struct My_filenode *headNode);
void sort_by_size1(struct My_filenode *headNode);
void sort_by_size2(struct My_filenode *headNode);
void My_sort(struct My_filenode *headNode, char sort_way);

#endif _LISTSORT_H