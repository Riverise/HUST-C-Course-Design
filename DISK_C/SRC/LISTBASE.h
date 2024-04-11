
#ifndef _LISTBASE_H

#define _LISTBASE_H

// #include <string.h>
#include "main.h"

void My_init(struct My_filenode **p0, struct My_filenode **ph, struct My_filenode **pc, struct My_filenode **p0_for_dir, struct My_filenode **ph_for_dir, struct My_filenode **pc_for_dir, struct My_filenode **p0_for_paste, struct My_filenode **ph_for_paste, struct My_filenode **pc_for_paste, struct My_vector_ **paste, struct My_vector_ **history, struct My_vector_ **currenthead, struct My_vector_ **search, char *sort_wayp); //初始化全局变量
void free_vector_list(struct My_vector_ *theNode);
struct My_vector_ *add_to_vector_(struct My_vector_ *vhead, struct My_filenode *theNode);
void close_init(struct My_filenode *p0, struct My_filenode *ph, struct My_filenode *pc, struct My_filenode *p0_for_dir, struct My_filenode *ph_for_dir, struct My_filenode *pc_for_dir, struct My_filenode *p0_for_paste, struct My_filenode *ph_for_paste, struct My_filenode *pc_for_paste, struct My_vector_ *paste, struct My_vector_ *history, struct My_vector_ *search);
struct My_filenode *end_of_list(struct My_filenode *theNode);
void get_path(struct My_filenode *theNode, char *buffer);
struct My_filenode *creat_son_list(struct My_filenode *fatherNode);
struct My_filenode *add_at_end(struct My_filenode *theNode, struct ffblk *ff);
void find_all_file(struct My_filenode *fatherNode);
void seach_all_file(struct My_filenode* fatherNode);
int count_all_file(struct My_filenode* fatherNode);
void find_max_sub_file(struct My_filenode *fatherNode, int* count, int max);
void find_all_sub_file(struct My_filenode* fatherNode);
void find_all_dir(struct My_filenode *fatherNode);
void free_son_list_head(struct My_filenode *fatherNode); // free的函数只对链表操作，不对文件操作
void delet_next_node(struct My_filenode *frontNode);	 // delet的函数对文件操作同时删除对应节点
void free_next_node(struct My_filenode *frontNode);
void free_next_node(struct My_vector_ *frontNode);
void delet_list(struct My_filenode *headNode);
void free_list(struct My_filenode *headNode);
int My_strcmp(char *str1, char *str2);
int find_name(struct My_filenode *headNode, char *filename);
struct My_filenode *new_file(struct My_filenode *headNode, char *filename, int filetype, struct My_filenode *srcNode = NULL);
struct My_filenode *find_node_by_path(struct My_filenode *ph, char *apath);
void add_type(char *flagp, char *filename);
int My_count(struct My_filenode *headNode, struct My_filenode *theNode);
int My_count(struct My_vector_ *headNode, struct My_vector_ *theNode);
struct Filetime *get_file_time(struct My_filenode *theNode);
int count_nodes(struct My_filenode *headNode);
int count_nodes(struct My_vector_ *headNode);
struct My_filenode *count_to_node(struct My_filenode *headNode, int n);
struct My_vector_ *count_to_node(struct My_vector_ *headNode, int n);
void to_capital(char *str);
struct My_filenode *vector_to_filenode(struct My_filenode *ph, struct My_vector_ *vnode);
void copy_file_content(struct My_filenode *destNode, struct My_filenode *srcNode);
int get_file_size(struct My_filenode *theNode);
int get_file_size_(struct My_filenode *theNode);
void unselect_all(My_filenode *headNode);
void select_all(My_filenode *headNode);
void inverse_select_all(My_filenode *headNode);
struct Filetime *get_file_base(struct My_filenode *theNode, int *size);
void free_except_end(struct My_filenode* headNode);
void close_all(My_filenode* headNode);
//int count_list_nodes(My_filenode* headNode);
//int count_all_sub_file(struct My_filenode* fatherNode);

#endif /* _LISTBASE_H */
