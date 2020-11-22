#define  _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"


//������ϵ�˺���
static int Find_con(contact* pcon)
{
	char name[NAME_MAX] = { 0 };
	scanf("%s\n", name);
	int i = 0;
	for (i = 0; i < pcon->sz; i++)
	{
		if (strcmp(name, pcon->date[i].name) == 0)
		{
			return i;//�ҵ������±�
		}
	}
	return -1;  //δ�ҵ�
}

//���ͨѶ¼
void add_contact(contact* pcon)
{
	if (pcon->sz == MAX)
	{
		printf("����Խ�磡");
	}
	else
	{
		printf("����������>");
		scanf("%s\n", pcon->date[pcon->sz].name);
		printf("������绰>");
		scanf("%s\n", pcon->date[pcon->sz].tel);
		printf("�������Ա�>");
		scanf("%s\n", pcon->date[pcon->sz].sex);
		printf("�������ַ>");
		scanf("%s\n", pcon->date[pcon->sz].addr);
		printf("����������>");
		scanf("%d\n", &(pcon->date[pcon->sz].age));
		pcon->sz++;
		printf("��ӳɹ���");
	}
}

//��ʾͨѶ¼
void show_contact(contact* pcon)
{
	int i = 0;
	for (i = 0; i < pcon->sz; i++)
	{
		printf("%s %s %s %s %d\n", pcon->date[i].name,pcon->date[i].tel,pcon->date[i].sex,pcon->date[i].addr,pcon->date[i].age);
	}
}

//ɾ��ͨѶ¼
void del_contact(contact* pcon)
{
	if (pcon->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�");
	}
	else
	{
		//�ҵ���ϵ�˵�λ��
		printf("������Ҫɾ���˵�����:>");
		int pos = Find_con(pcon);  //posΪ��ϵ��λ�÷���ֵ
		if (pos == -1)
		{
			printf("δ�ҵ�ָ����ϵ�ˣ�");
		}
		else  //ɾ����ϵ��
		{
			int j = 0;
			for (j = pos; j < pcon->sz - 1; j++)
			{
				pcon->date[j] = pcon->date[j+1];
			}
			pcon->sz--;  //��������
			printf("ɾ���ɹ���");
		}
	}
}

//����ͨѶ¼
void search_contact(contact* pcon)
{
	printf("�����뱻�����˵�������>");
	int pos = Find_con(pcon);
	if (pos == -1)
	{
		printf("δ�ҵ�ָ����ϵ�ˣ�");
	}
	else
	{
		printf("%s %s %s %s %d\n", pcon->date[pos].name, pcon->date[pos].tel, pcon->date[pos].sex, pcon->date[pos].addr, pcon->date[pos].age);
	}
}

//�޸�ͨѶ¼
void mod_contact(contact* pcon)
{
	printf("������Ҫ�޸��˵�����:>");
	int pos = Find_con(pcon);
	if (pos == -1)
	{
		printf("δ�ҵ����ˣ�\n");
	}
	else
	{
		printf("�������µ���ϵ��:>\n");
		printf("����������>");
		scanf("%s\n", pcon->date[pos].name);
		printf("������绰>");
		scanf("%s\n", pcon->date[pos].tel);
		printf("�������Ա�>");
		scanf("%s\n", pcon->date[pos].sex);
		printf("�������ַ>");
		scanf("%s\n", pcon->date[pos].addr);
		printf("����������>");
		scanf("%d\n", &(pcon->date[pos].age));
		printf("�޸ĳɹ���\n");
	}
}

//ͨѶ¼����
void sort_contact(contact* pcon)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < pcon->sz - 1; i++)
	{
		int flag = 1;//�����Ѿ�����
		for (j = 0; j < pcon->sz - 1 - i; j++)
		{
			if (strcmp(pcon->date[j].name, pcon->date[j + 1].name)>0)
			{
				person tmp = pcon->date[j];
				pcon->date[j] = pcon->date[j + 1];
				pcon->date[j + 1] = tmp;
				int flag = 0;  //����֤������
			}
		}
		if (1 == flag)
		{
			break;
		}
	}
}