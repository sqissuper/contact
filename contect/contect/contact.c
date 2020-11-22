#define  _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"


//查找联系人函数
static int Find_con(contact* pcon)
{
	char name[NAME_MAX] = { 0 };
	scanf("%s\n", name);
	int i = 0;
	for (i = 0; i < pcon->sz; i++)
	{
		if (strcmp(name, pcon->date[i].name) == 0)
		{
			return i;//找到返回下标
		}
	}
	return -1;  //未找到
}

//添加通讯录
void add_contact(contact* pcon)
{
	if (pcon->sz == MAX)
	{
		printf("您已越界！");
	}
	else
	{
		printf("请输入名字>");
		scanf("%s\n", pcon->date[pcon->sz].name);
		printf("请输入电话>");
		scanf("%s\n", pcon->date[pcon->sz].tel);
		printf("请输入性别>");
		scanf("%s\n", pcon->date[pcon->sz].sex);
		printf("请输入地址>");
		scanf("%s\n", pcon->date[pcon->sz].addr);
		printf("请输入年龄>");
		scanf("%d\n", &(pcon->date[pcon->sz].age));
		pcon->sz++;
		printf("添加成功！");
	}
}

//显示通讯录
void show_contact(contact* pcon)
{
	int i = 0;
	for (i = 0; i < pcon->sz; i++)
	{
		printf("%s %s %s %s %d\n", pcon->date[i].name,pcon->date[i].tel,pcon->date[i].sex,pcon->date[i].addr,pcon->date[i].age);
	}
}

//删除通讯录
void del_contact(contact* pcon)
{
	if (pcon->sz == 0)
	{
		printf("通讯录为空！");
	}
	else
	{
		//找到联系人的位置
		printf("请输入要删除人的名字:>");
		int pos = Find_con(pcon);  //pos为联系人位置返回值
		if (pos == -1)
		{
			printf("未找到指定联系人！");
		}
		else  //删除联系人
		{
			int j = 0;
			for (j = pos; j < pcon->sz - 1; j++)
			{
				pcon->date[j] = pcon->date[j+1];
			}
			pcon->sz--;  //人数减少
			printf("删除成功！");
		}
	}
}

//查找通讯录
void search_contact(contact* pcon)
{
	printf("请输入被查找人的姓名：>");
	int pos = Find_con(pcon);
	if (pos == -1)
	{
		printf("未找到指定联系人！");
	}
	else
	{
		printf("%s %s %s %s %d\n", pcon->date[pos].name, pcon->date[pos].tel, pcon->date[pos].sex, pcon->date[pos].addr, pcon->date[pos].age);
	}
}

//修改通讯录
void mod_contact(contact* pcon)
{
	printf("请输入要修改人的姓名:>");
	int pos = Find_con(pcon);
	if (pos == -1)
	{
		printf("未找到此人！\n");
	}
	else
	{
		printf("请输入新的联系人:>\n");
		printf("请输入名字>");
		scanf("%s\n", pcon->date[pos].name);
		printf("请输入电话>");
		scanf("%s\n", pcon->date[pos].tel);
		printf("请输入性别>");
		scanf("%s\n", pcon->date[pos].sex);
		printf("请输入地址>");
		scanf("%s\n", pcon->date[pos].addr);
		printf("请输入年龄>");
		scanf("%d\n", &(pcon->date[pos].age));
		printf("修改成功！\n");
	}
}

//通讯录排序
void sort_contact(contact* pcon)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < pcon->sz - 1; i++)
	{
		int flag = 1;//假设已经有序
		for (j = 0; j < pcon->sz - 1 - i; j++)
		{
			if (strcmp(pcon->date[j].name, pcon->date[j + 1].name)>0)
			{
				person tmp = pcon->date[j];
				pcon->date[j] = pcon->date[j + 1];
				pcon->date[j + 1] = tmp;
				int flag = 0;  //进来证明无序
			}
		}
		if (1 == flag)
		{
			break;
		}
	}
}