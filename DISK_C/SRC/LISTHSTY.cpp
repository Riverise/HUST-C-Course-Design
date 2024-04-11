#include "INCLUDE.h"
#include "LISTBASE.h"
#include "LISTHSTY.h"

/*
	函数功能：记录历史目录
	参数：history头节点，被记录头节点
	返回值：新建的vector节点
*/

struct My_vector_ *add_to_history(struct My_vector_ *vhead, struct My_filenode *theNode)
{
	if (theNode == NULL)
	{
		return NULL;
	}
	while (count_nodes(vhead) >= 10)
	{
		free_next_node(vhead);
	}
	struct My_vector_ *tempNode;
	struct My_vector_ *newNode = (struct My_vector_ *)malloc(sizeof(struct My_vector_));
	for (tempNode = vhead; tempNode->next != NULL; tempNode = tempNode->next)
		;
	char buffer[80];
	buffer[0] = '\0';
	get_path(theNode, buffer);
	strcpy(newNode->path, buffer);
	strcpy(newNode->name, theNode->name);
	newNode->next = NULL;
	tempNode->next = newNode;
	return newNode;
}

/*
	函数功能：当前目录改变
	参数：('n',头节点)：到这个目录 ('n')：到历史记录的下一个目录 ('f')：到历史的上一个目录
	返回值：无
*/

void move_dir(struct My_vector_ *history, struct My_vector_ **currenthead, char d, struct My_filenode *fatherNode)
{
	if (d == 'n' && fatherNode != NULL)
	{
		free_vector_list(*currenthead);
		*currenthead = add_to_history(history, fatherNode);
	}
	else if (d == 'n')
	{
		if ((*currenthead)->next != NULL)
		{
			*currenthead = (*currenthead)->next;
		}
	}
	else if (d == 'f')
	{
		int n = My_count(history, *currenthead);
		if (n > 1)
		{
			n--;
			*currenthead = count_to_node(history, n);
		}
	}
}
