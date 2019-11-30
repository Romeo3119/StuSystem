#include "student.h"
#include <iostream>
using namespace std;

int select = 0; 

int main()
{
	bool QUIT = false;
	Stu stu;
	stu.menu();
	cout << "\n请输入相应的序号:";
	while (1)
	{
		if (QUIT == true)
		{
			break;
		}
		cin >> select;
		switch (select)
		{
		case 1:
			stu.inputStuInfo();
			break;
		case 2:
			stu.addStuInfo();
			break;

		case 3:
			stu.searchStuInfo();
			break;

		case 4:
			stu.delStuInfo();
			break;

		case 5:
			stu.modifyStuInfo();
			break;

		case 6:
			stu.printStuInfo();
			break;

		case 7:
			stu.saveStuInfo();
			break;
		case 8:
			stu.quitSystem();
			QUIT = true;
			break;
		default:
			cout << "输入错误,请重新输入:";
			break;
		}
	}
	cout << "系统即将关闭!\n";
	system("pause");
	return 0;
}