#define  _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//通讯录菜单
void menu()
{
	printf("*********************************\n");
	printf("*******1.add         2.del*******\n");
	printf("*******3.search      4.mod*******\n");
	printf("*******5.show        6.sort******\n");
	printf("*******        0.exit     *******\n");
	printf("*********************************\n");
}

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MOD,
	SHOW,
	SORT,
};


void test()
{
	int input = 0;
	contact con = { 0 }; //创建的通讯录
	do
	{
		menu();//通讯录菜单
		printf("请输入:>");
		scanf("%d\n", &input);
		int getchar();
		switch (input)
		{
			case ADD:
				add_contact(&con);
				break;
			case DEL:
				del_contact(&con);
				break;
			case SEARCH:
				search_contact(&con);
				break;
			case MOD:
				mod_contact(&con);
				break;
			case SHOW:
				show_contact(&con);
				break;
			case SORT:
				sort_contact(&con);
				break;
			case EXIT:
				printf("您已退出通讯录！\n");
				break;
			default:
				printf("未找到，请重新选择!\n");
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}