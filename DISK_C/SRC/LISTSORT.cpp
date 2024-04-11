#include "INCLUDE.h"
#include "LISTBASE.h"
#include "LISTSORT.h"

/*
	函数功能：相邻两个节点交换
	参数：两个节点中，前一个交换节点对应的前一个节点，后一个交换节点对应的前一个节点
	返回值：无
*/

void node_swap(struct My_filenode *frontNode1, struct My_filenode *frontNode2)
{

	if (frontNode1->next == NULL)
	{
		return;
	}
	if (frontNode2->next == NULL)
	{
		return;
	}

	struct My_filenode *temp1 = frontNode1->next;
	struct My_filenode *temp2 = frontNode2->next;

	frontNode1->next = temp2;
	temp1->next = temp2->next;
	temp2->next = temp1;
}

/*
	函数功能：用名字排序链表（ABC顺叙）
	参数：头节点
	返回值：无
*/

void sort_by_name1(struct My_filenode *headNode)
{
	int n = count_nodes(headNode);
	struct My_filenode *temp1;
	struct My_filenode *temp2;
	for (int i = 2; i < n + 1; i++)
	{
		int j = 1;
		temp1 = count_to_node(headNode, i);
		temp2 = count_to_node(headNode, j);
		while (strcmp(temp1->name, temp2->name) > 0 && j < i)
		{

			j++;
			temp2 = count_to_node(headNode, j);
		}

		if (i != j)
		{
			for (int k = i; k > j; k--)
			{
				temp1 = count_to_node(headNode, k - 1);
				temp2 = count_to_node(headNode, k - 2);
				node_swap(temp2, temp1);
			}
		}
	}
}

/*
	函数功能：用名字排序链表（ABC倒叙）
	参数：头节点指针
	返回值：无
*/

void sort_by_name2(struct My_filenode *headNode)
{
	int n = count_nodes(headNode);
	struct My_filenode *temp1;
	struct My_filenode *temp2;
	for (int i = 2; i < n + 1; i++)
	{
		int j = 1;
		temp1 = count_to_node(headNode, i);
		temp2 = count_to_node(headNode, j);
		while (strcmp(temp1->name, temp2->name) < 0 && j < i)
		{

			j++;
			temp2 = count_to_node(headNode, j);
		}

		if (i != j)
		{
			for (int k = i; k > j; k--)
			{
				temp1 = count_to_node(headNode, k - 1);
				temp2 = count_to_node(headNode, k - 2);
				node_swap(temp2, temp1);
			}
		}
	}
}

/*
	函数功能：时间比较函数
	参数：两个文件时间结构指针
	返回值：前者新返回1，后者新返回-1，相同返回0
*/

int timecmp(struct Filetime *t1, struct Filetime *t2)
{
	if (t1->y > t2->y)
	{
		return 1;
	}
	else if (t1->y < t2->y)
	{
		return -1;
	}
	if (t1->month > t2->month)
	{
		return 1;
	}
	else if (t1->month < t2->month)
	{
		return -1;
	}
	if (t1->d > t2->d)
	{
		return 1;
	}
	else if (t1->d < t2->d)
	{
		return -1;
	}
	if (t1->h > t2->h)
	{
		return 1;
	}
	else if (t1->h < t2->h)
	{
		return -1;
	}
	if (t1->min > t2->min)
	{
		return 1;
	}
	else if (t1->min < t2->min)
	{
		return -1;
	}
	if (t1->s > t2->s)
	{
		return 1;
	}
	else if (t1->s < t2->s)
	{
		return -1;
	}
	return 0;
}

/*
	函数功能：时间排序（新到旧）
	参数：头节点指针
	返回值：无
*/

void sort_by_time1(struct My_filenode *headNode)
{
	int n = count_nodes(headNode);
	struct My_filenode *temp1;
	struct My_filenode *temp2;
	struct Filetime *tempt1;
	struct Filetime *tempt2;
	for (int i = 2; i < n + 1; i++)
	{
		int j = 1;
		temp1 = count_to_node(headNode, i);
		tempt1 = get_file_time(temp1);
		temp2 = count_to_node(headNode, j);
		tempt2 = get_file_time(temp2);
		while (timecmp(tempt1, tempt2) == 1 && j < i)
		{
			free(tempt2);
			j++;
			temp2 = count_to_node(headNode, j);
			tempt2 = get_file_time(temp2);
		}

		if (i != j)
		{
			for (int k = i; k > j; k--)
			{
				temp1 = count_to_node(headNode, k - 1);
				temp2 = count_to_node(headNode, k - 2);
				node_swap(temp2, temp1);
			}
		}
		free(tempt1);
		free(tempt2);
	}
}

/*
	函数功能：时间排序（旧到新）
	参数：头节点指针
	返回值：无
*/

void sort_by_time2(struct My_filenode *headNode)
{
	int n = count_nodes(headNode);
	struct My_filenode *temp1;
	struct My_filenode *temp2;
	struct Filetime *tempt1;
	struct Filetime *tempt2;
	for (int i = 2; i < n + 1; i++)
	{
		int j = 1;
		temp1 = count_to_node(headNode, i);
		tempt1 = get_file_time(temp1);
		temp2 = count_to_node(headNode, j);
		tempt2 = get_file_time(temp2);
		while (timecmp(tempt1, tempt2) == -1 && j < i)
		{
			free(tempt2);
			j++;
			temp2 = count_to_node(headNode, j);
			tempt2 = get_file_time(temp2);
		}

		if (i != j)
		{
			for (int k = i; k > j; k--)
			{
				temp1 = count_to_node(headNode, k - 1);
				temp2 = count_to_node(headNode, k - 2);
				node_swap(temp2, temp1);
			}
		}
		free(tempt1);
		free(tempt2);
	}
}

/*
	函数功能：通过文件大小排序（小到大）
	参数：头节点指针
	返回值：无
*/

void sort_by_size1(struct My_filenode *headNode)
{
	int n = count_nodes(headNode);
	struct My_filenode *temp1;
	struct My_filenode *temp2;
	for (int i = 2; i < n + 1; i++)
	{
		int j = 1;
		temp1 = count_to_node(headNode, i);
		temp2 = count_to_node(headNode, j);
		while (get_file_size(temp1) > get_file_size(temp2) && j < i)
		{
			j++;
			temp2 = count_to_node(headNode, j);
		}

		if (i != j)
		{
			for (int k = i; k > j; k--)
			{
				temp1 = count_to_node(headNode, k - 1);
				temp2 = count_to_node(headNode, k - 2);
				node_swap(temp2, temp1);
			}
		}
	}
}

/*
	函数功能：通过文件大小排序（大到小）
	参数：头节点指针
	返回值：无
*/

void sort_by_size2(struct My_filenode *headNode)
{
	int n = count_nodes(headNode);
	struct My_filenode *temp1;
	struct My_filenode *temp2;
	for (int i = 2; i < n + 1; i++)
	{
		int j = 1;
		temp1 = count_to_node(headNode, i);
		temp2 = count_to_node(headNode, j);
		while (get_file_size(temp1) < get_file_size(temp2) && j < i)
		{
			j++;
			temp2 = count_to_node(headNode, j);
		}

		if (i != j)
		{
			for (int k = i; k > j; k--)
			{
				temp1 = count_to_node(headNode, k - 1);
				temp2 = count_to_node(headNode, k - 2);
				node_swap(temp2, temp1);
			}
		}
	}
}

/*
	函数功能：文件排序
	参数：头节点指针，char（1：ABC顺序2：ABC倒序3：时间新到旧4：时间旧到新5：文件大小小到大6：文件大小大到小0：默认排序）
	返回值：无
*/

void My_sort(struct My_filenode *headNode, char sort_way)
{
	switch (sort_way)
	{
	case 1:
		sort_by_name1(headNode);
		break;
	case 2:
		sort_by_name2(headNode);
		break;
	case 3:
		sort_by_time1(headNode);
		break;
	case 4:
		sort_by_time2(headNode);
		break;
	case 5:
		sort_by_size1(headNode);
		break;
	case 6:
		sort_by_size2(headNode);
		break;
	default:
		break;
	}
}