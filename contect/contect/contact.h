#include<stdio.h>
#include<string.h>

#define NAME_MAX 20
#define TEL_MAX 15
#define SEX_MAX 20
#define ADDR_MAX 100
#define AGE_MAX 20

#define MAX 500


//������Ϣ
typedef struct person
{
	char name[NAME_MAX];
	char tel[TEL_MAX];
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	int age;
}person;


//ͨѶ¼��С
typedef struct contact
{
	person date[MAX];
	int sz;
}contact;



//���ͨѶ¼
void add_contact(contact* pcon);

//��ʾͨѶ¼
void show_contact(contact* pcon);

//ɾ��ͨѶ¼
void del_contact(contact* pcon);

//����ͨѶ¼
void search_contact(contact* pcon);

//�޸�ͨѶ¼
void mod_contact(contact* pcon);

//ͨѶ¼����
void sort_contact(contact* pcon);