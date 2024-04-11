#ifndef _LISTCOPY_H
#define _LISTCOPY_H

#include "LISTDF.h"

int paste_list_to_dir(struct My_filenode *headNode, struct My_filenode *copyheadNode, int n);
int paste_node_to_dir(struct My_filenode *headNode, struct My_filenode *copyNode);
int My_paste(struct My_vector_ *paste, struct My_filenode *headNode, struct My_filenode *pc_for_paste);
void My_rename(struct My_filenode *theNode, char *newname);
void My_cut(struct My_vector_ *paste, struct My_filenode *headNode, struct My_filenode *pc_for_paste);

#endif _LISTCOPY_H