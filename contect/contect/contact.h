#include<stdio.h>
#include<string.h>

#define NAME_MAX 20
#define TEL_MAX 15
#define SEX_MAX 20
#define ADDR_MAX 100
#define AGE_MAX 20

#define MAX 500


//个人信息
typedef struct person
{
	char name[NAME_MAX];
	char tel[TEL_MAX];
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	int age;
}person;


//通讯录大小
typedef struct contact
{
	person date[MAX];
	int sz;
}contact;



//添加通讯录
void add_contact(contact* pcon);

//显示通讯录
void show_contact(contact* pcon);

//删除通讯录
void del_contact(contact* pcon);

//查找通讯录
void search_contact(contact* pcon);

//修改通讯录
void mod_contact(contact* pcon);

//通讯录排序
void sort_contact(contact* pcon);