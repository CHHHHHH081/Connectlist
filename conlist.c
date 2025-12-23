#define _CRT_SECURE_NO_WARNINGS
#include "Seqlist.h"
int op,tm;
SL Seq;
SL* Seqp=&Seq;
void addmsg(SLDatatype* x)
{
	printf("请输入姓名：\n");
	scanf("%s", x->name);
	printf("请输入号码：\n");
	scanf("%s", x->number);
	printf("请输入年龄：\n");
	scanf("%d", &x->age);
	printf("请输入地址：\n");
	scanf("%s", x->addr);
}
void menu()
{
	printf("                                   \n");
	printf("***********************************\n");
	printf("****  1.添加  ********  2.删除  ***\n");
	printf("****  3.修改  ********  4.查找  ***\n");
	printf("****  5.显示全部  ****  6.退出  ***\n");
	printf("***********************************\n");
	printf("                                   \n");
	return 0;
}
int main()
{
	SLinit(Seqp);
	do
	{
		menu();
		scanf("%d", &op);
		switch (op)
		{
		case 1:
		{
			SLDatatype temp;
			addmsg(&temp);
			SLtailadd(Seqp, temp);
			printf("添加成功！\n");
			break;
		}
		case 2:
		{
			char t[100];
			printf("请输入要删除的联系人:\n");
			scanf("%s", t);
			tm=SLfind(Seqp, t);
			if (tm == -1)
			{
				printf("未找到该联系人！\n");
			}
			else
			{
				SLpop(Seqp, tm);
				printf("删除成功！\n");
			}
			break;
		}
		case 3:
		{
			char t[100];
			printf("请输入要修改的联系人：\n");
			scanf("%s", t);
			tm = SLfind(Seqp, t);
			if (tm == -1)
			{
				printf("未找到该联系人！\n");
				break;
			}
			SLDatatype temp;
			addmsg(&temp);
			Seqp->arr[tm] = temp;
			printf("修改成功！");
			break;
		}
		case 4:
		{
			char t[100];
			printf("请输入要查找的联系人：\n");
			scanf("%s", t);
			tm = SLfind(Seqp, t);
			if (tm == -1)
			{
				printf("未找到该联系人！\n");
			}
			else
			{
				printf("该联系人信息为：\n");
				SLprintsingle(Seqp, tm);
			}
			break;
		}
		case 5:
		{
			SLprintall(Seqp);
			break;
		}
		case 6:
		{
			return 0;
		}
		default:
		{
			printf("请输入正确的数字！\n");
		}
		}
	} while(op!=6);
	return 0;
}