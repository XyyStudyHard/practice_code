#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct str
{
	struct str *prev;
       	struct str *next;
	int num;
};	



int main(void)
{
	struct str *str1, *str2, *str_rst, *str_tmp;
	int  tmp, flag = 0;
	str1 = (struct str *)malloc(sizeof(struct str));
	str1->prev = NULL;
	str1->next = NULL;
	str1->num = -1;
	struct str *head1 = str1;
	str2 = (struct str *)malloc(sizeof(struct str));
	str2->prev = NULL;
	str2->next = NULL;
	str2->num = -1;
	struct str *head2 = str2;
	scanf("%d", &tmp);
	if (tmp == -1)
		flag = 1;
	while(tmp != -1)
	{
		str_tmp = (struct str *)malloc(sizeof(struct str));
		str1->next = str_tmp;
		str1->num = tmp;
		str_tmp->prev = str1;
		str1 = str_tmp;
		scanf("%d", &tmp);
	}
	if(flag == 0)
	{
		str_tmp->num = tmp;
		str_tmp->next = NULL;
	}
	flag = 0;
	scanf("%d", &tmp);
	if (tmp == -1)
		flag = 1;
	while(tmp != -1)
	{
		str_tmp = (struct str *)malloc(sizeof(struct str));
		str2->next = str_tmp;
	   	str2->num = tmp;
		str_tmp->prev = str2;
		str2 = str_tmp;
		scanf("%d", &tmp);
	}
	if (flag == 0)
	{
		str_tmp->num = tmp;
		str_tmp->next = NULL;
	}
	str1 = head1;
	str2 = head2;	
	if((str1->num == -1) && (str2->num == -1))
	{
		printf("NULL");
		return 0;
	}
	str_rst = (struct str *)malloc(sizeof(struct str));
	str_rst->next = NULL;
	str_rst->prev = NULL;
	str_rst->num = -1;
	struct str *head_rst = str_rst;
	while((str1->num != -1) && (str2->num != -1))
	{
			if (str1->num < str2->num)
			{
				str_tmp = (struct str *)malloc(sizeof(struct str));
				str_rst->num = str1->num;
				str_rst->next = str_tmp;
				str_tmp->prev = str_rst;
				str_rst = str_tmp;
				str1 = str1->next;
			}
			else
			{
				str_tmp = (struct str *)malloc(sizeof(struct str));
				str_rst->num = str2->num;
				str_rst->next = str_tmp;
				str_tmp->prev = str_rst;
				str_rst = str_tmp;
				str2 = str2->next;
			}
		
	}
	if (str1->num == -1)
	{
		while(str2->num != -1)
		{
			str_tmp = (struct str *)malloc(sizeof(struct str));
			str_rst->num = str2->num;
			str_rst->next = str_tmp;
			str_tmp->prev = str_rst;
			str_rst = str_tmp;
			str2 = str2->next;
		}
	}
	else 
		while(str1->num != -1)
		{

			str_tmp = (struct str *)malloc(sizeof(struct str));
			str_rst->num = str1->num;
			str_rst->next = str_tmp;
			str_tmp->prev = str_rst;
			str_rst = str_tmp;
			str1 = str1->next;
		}

	str_tmp->num = -1;
	str_tmp->next = NULL;
	str_rst = head_rst;
	while(str_rst->num != -1)
	{
		printf("%d", str_rst->num);
		str_rst = str_rst->next;
		if (str_rst->num != -1)
			printf(" ");
	}
	return 0;
}
