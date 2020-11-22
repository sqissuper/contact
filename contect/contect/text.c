#define  _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//ͨѶ¼�˵�
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
	contact con = { 0 }; //������ͨѶ¼
	do
	{
		menu();//ͨѶ¼�˵�
		printf("������:>");
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
				printf("�����˳�ͨѶ¼��\n");
				break;
			default:
				printf("δ�ҵ���������ѡ��!\n");
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}