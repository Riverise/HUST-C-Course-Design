
#include "INCLUDE.h"
#include "LISTBASE.h"
#include "LISTSRCH.h"

/*
	函数功能：搜索当前目录下含有搜索词的文件并存在搜索链表中，存储第max-10到max个文件
	参数：search头节点，目录头节点，搜索内容，计数int指针，显示的第几-1页
	返回值：无
*/

void My_search(struct My_vector_ *search, struct My_filenode *headNode, char *str, int * n, int page)
{
	if (headNode == NULL || headNode->next == NULL)
	{
		return;
	}
	struct My_filenode *temp;
	int limit;
	to_capital(str);
	for (limit = 0,temp = headNode->next; limit < 100 && temp != NULL; temp = temp->next)
	{
		if (strstr(temp->name, str) != NULL)
		{
			if ((*n) > (((page * 10) + 10) - 1))
			{
				break;
			}
			if (My_strcmp(temp->name, "C:"))
			{
				if ((*n) > (((page * 10) + 10) - 11))
				{
					add_to_vector_(search, temp);
				}
				(*n)++;
			}
		}		
		if (temp->flag & IS_DIR)
		{
			seach_all_file(temp);
			My_search(search, temp->son_list_head, str, n, page);
			free_son_list_head(temp);
		}

	}
	if (My_strcmp(headNode->next->name,"C:"))
	{
		free_list(headNode);
	}
	else
	{
		free_list(headNode->next->son_list_head);
		
	}
}
