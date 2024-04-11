#ifndef _DRAWFILE_H_
#define _DRAWFILE_H_

#include <graphics.h>
#include "LISTDF.h"
#include "LISTBASE.h"
#include "LISTSORT.h"
#include "icdr.h"
#include "flic.h"

void filetypecpy(char flag, char *dest);
void main_file_bar1(int x1, int y1, int color);
void draw_main_file1(int x1, int y1, struct My_filenode *headNode, int n, int state, int page);
void main_file_bar2(int x1, int y1, int color);
void draw_main_file2(int x1, int y1, struct My_filenode *headNode, int n, int state, int page);
int count_dirs(struct My_filenode *headNode);
struct My_filenode *count_to_dir(struct My_filenode *headNode, int *n);
void tree_file_bar(int x1, int y1, int color);
void draw_tree_file(int x1, int y1, struct My_filenode *headNode, int n, int state, int page);
void search_file_bar(int x1, int y1, int color);
void draw_search_file(int x1, int y1, struct My_vector_ *headNode, int n, int state);
void My_draw_main_file1(int n, struct My_filenode *headNode, int state, int page);
void My_draw_main_file2(int n, struct My_filenode *headNode, int state, int page);
void My_draw_tree_file(int n, struct My_filenode *headNode, int state, int page);
void My_draw_search_file(int n, struct My_vector_ *headNode, int state);
int pop_error(int pop_type, char* func_name, char* cause, char* object_name = NULL);
void pop_properties(struct My_filenode* theNode);

#endif