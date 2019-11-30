#include "student.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <fstream>

#define COL 8
using namespace std;

void Stu::menu()
{
	/*cout << "系统正在初始化,请稍后";
	cout << ".";
	Sleep(400);
	cout << ".";
	Sleep(400);
	cout << ".";
	Sleep(400);
	cout << ".";
	Sleep(400);
	cout << ".";
	Sleep(400);
	cout << ".\n";
	Sleep(400);
	system("cls");
	*/
	cout << "      学生信息管理系统" << endl;
	cout << "1.录入学生信息  2.添加学生信息" << endl;
	cout << "3.查找学生信息  4.删除学生信息" << endl;
	cout << "5.修改学生信息  6.打印学生信息" << endl;
	cout << "7.保存学生信息  8.退出信息系统" << endl;
}

void Stu::inputStuInfo()
{
	string finishInput;
	StuInfo stuInfo;
	cout << "即将录入学生信息,请稍后";
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".\n";
	while (1)
	{
		cout << "\n学号: ";
		cin >> stuInfo.stuNum;
		cout << "姓名: ";
		cin >> stuInfo.stuName;
		cout << "电话号码: ";
		cin >> stuInfo.stuTel;
		cout << "年龄: ";
		cin >> stuInfo.stuAge;
		cout << "数学成绩: ";
		cin >> stuInfo.mathScore;
		cout << "英语成绩: ";
		cin >> stuInfo.engScore;
		cout << "C语言成绩: ";
		cin >> stuInfo.cScore;
		stuInfoVec.push_back(stuInfo);
		cout << "是否结束(Y/N):";
		cin >> finishInput;
		if (finishInput == "N")
		{
			continue;
		}
		else
		{
			cout << "录入完毕!\n";
			break;
		}
	}
	menu();
	cout << "请输入相应的序号: ";
	
	//cin >> select;
}

void Stu::addStuInfo()
{
	inputStuInfo();
}

void Stu::searchStuInfo()
{
	bool FIND = false;
	string sName;
	string sNum;
	int num;
	cout << "1.按学号查找 2.按姓名查找\n";
	cout << "请输入相应的查找方式:";
	cin >> num;
	if (num == 1)
	{
		cout << "请输入学号:";
		cin >> sNum;
		cout << "学号       姓名       电话号码       年龄      数学      英语      C语言\n\n";
		for (int i = 0; i < stuInfoVec.size(); ++i)
		{
			if (stuInfoVec[i].stuNum == sNum)
			{
				printf("%5s    %5s      %5s    %5d     %5d     %5d     %5d\n", stuInfoVec[i].stuNum.c_str(), stuInfoVec[i].stuName.c_str(),
					stuInfoVec[i].stuTel.c_str(), stuInfoVec[i].stuAge, stuInfoVec[i].mathScore, stuInfoVec[i].engScore, stuInfoVec[i].cScore);
				FIND = true;
			}
		}
		if (FIND == true)
		{
			cout << "打印完毕!\n";
		}
		else
		{
			cout << "查询结果为空!\n";
		}
	}
	if (num == 2)
	{
		bool FIND = false;
		cout << "请输入姓名:";
		cin >> sName;
		cout << "学号       姓名       电话号码       年龄      数学      英语      C语言\n\n";
		for (int i = 0; i < stuInfoVec.size(); ++i)
		{
			if (stuInfoVec[i].stuName == sName)
			{	
				printf("%5s    %5s      %5s    %5d     %5d     %5d     %5d\n", stuInfoVec[i].stuNum.c_str(), stuInfoVec[i].stuName.c_str(),
					stuInfoVec[i].stuTel.c_str(), stuInfoVec[i].stuAge, stuInfoVec[i].mathScore, stuInfoVec[i].engScore, stuInfoVec[i].cScore);
				FIND = true;
			}
		}
		if (FIND == true)
		{
			cout << "打印完毕!\n";
		}
		else
		{
			cout << "查询结果为空!\n";
		}
	}
	menu();
	cout << "请输入相应的序号: ";
}

void Stu::delStuInfo()
{
	string sName, sNum;
	int num = 0;
	//使用vector里的erase()来删除，注意迭代器失效的问题
	vector<StuInfo>::iterator stuIt;
	cout << "1.按名字删除 2.按学号删除\n";
	cout << "请输入选项:";
	cin >> num;
	if (num == 1)
	{
		cout << "请输入学生姓名:";
		cin >> sName;
		for (stuIt = stuInfoVec.begin(); stuIt != stuInfoVec.end(); )
		{
			if ((*stuIt).stuName == sName)
			{
				stuIt = stuInfoVec.erase(stuIt);
			}
			else
			{
				++stuIt;
			}
		}
		cout << "删除完毕!\n";
	}

	if (num == 2)
	{
		cout << "请输入学生学号:";
		cin >> sNum;
		for (stuIt = stuInfoVec.begin(); stuIt != stuInfoVec.end();)
		{
			if ((*stuIt).stuNum == sNum)
			{
				stuIt = stuInfoVec.erase(stuIt);
			}
			else
			{
				++stuIt;
			}
		}
		cout << "删除完毕!\n";
	}
	menu();
	cout << "请输入相应的序号: ";
}

void Stu::modifyStuInfo()
{
	//根据实际需求，改变的一般是电话号码和成绩等。姓名和学号一般不会变。
	//先根据学号查找到学生
	//再把该生的信息打印出来
	
	string sNum;
	cout << "请输入学生的学号:";
	cin >> sNum;
	cout << "该生当前信息为:\n";
	cout << "学号       姓名       电话号码       年龄      数学      英语      C语言\n\n";
	for (int i = 0; i < stuInfoVec.size(); ++i)
	{
		if (stuInfoVec[i].stuNum == sNum)
		{
			printf("%5s    %5s      %5s    %5d     %5d     %5d     %5d\n", stuInfoVec[i].stuNum.c_str(), stuInfoVec[i].stuName.c_str(),
				stuInfoVec[i].stuTel.c_str(), stuInfoVec[i].stuAge, stuInfoVec[i].mathScore, stuInfoVec[i].engScore, stuInfoVec[i].cScore);
		}
	}
	cout << "1.修改电话号码 2.修改数学成绩 3.修改英语成绩 4.修改C语言成绩\n";
	cout << "请输入相应的序号:";
	int num = 0;
	cin >> num;
	for (int i = 0; i < stuInfoVec.size(); ++i)
	{
		if (stuInfoVec[i].stuNum == sNum)
		{
			if (num == 1)
			{
				cout << "请输入新的电话号码:";
				string sTel;
				cin >> sTel;
				stuInfoVec[i].stuTel = sTel;
			}
			else if (num == 2)
			{
				cout << "请输入新的数学成绩:";
				int sMath;
				cin >> sMath;
				stuInfoVec[i].mathScore = sMath;
			}
			else if (num == 3)
			{
				cout << "请输入新的英语成绩:";
				int sEng;
				cin >> sEng;
				stuInfoVec[i].engScore = sEng;
			}
			else
			{
				cout << "请输入新的C语言成绩:";
				int sClan;
				cin >> sClan;
				stuInfoVec[i].cScore = sClan;
			}
		}		
	}
	cout << "修改完毕!\n";
	cout << "是否继续修改(Y/N):";
	string modifyFinish;
	cin >> modifyFinish;
	if (modifyFinish == "N")
	{
		cout << "修改完毕!\n";
		menu();
		cout << "请输入相应的序号: ";
		return;
	}
	modifyStuInfo();
}

void Stu::printStuInfo()
{
	if (stuInfoVec.size() == 0)
	{
		cout << "学生信息为空，打印失败!\n";
		cout << "请输入相应的序号: ";
	}
	else
	{
		cout << "学号       姓名       电话号码       年龄      数学      英语      C语言\n\n";
		for (int i = 0; i < stuInfoVec.size(); ++i)
		{ 
			printf("%5s    %5s      %5s    %5d     %5d     %5d     %5d\n", stuInfoVec[i].stuNum.c_str(), stuInfoVec[i].stuName.c_str(),
				stuInfoVec[i].stuTel.c_str(), stuInfoVec[i].stuAge, stuInfoVec[i].mathScore, stuInfoVec[i].engScore, stuInfoVec[i].cScore);
			if (i == stuInfoVec.size()-1)
			{
				cout << "\n学生信息打印完毕!\n";
				break;
			}
		}
		menu();
		cout << "请输入相应的序号: ";
	}

}

void Stu::saveStuInfo()
{

	cout << "正在保存为文件,请稍后…\n";

	ofstream stuFile;

	//写的方式打开文件
	stuFile.open("..\\学生信息表\\stuInfo.csv", ios::out);
	//rapidcsv::Document doc("..\\学生信息表\\stuInfo.csv", rapidcsv::LabelParams(-1, -1));
	stuFile << "学号," << "姓名," << "电话号码," << "年龄," << "数学," << "英语," << "C语言\n";
	if (stuFile.is_open() == true)
	{
		for (int i = 0; i < stuInfoVec.size(); ++i)
		{
			stuFile << stuInfoVec[i].stuNum << "," << stuInfoVec[i].stuName << ","
				<< stuInfoVec[i].stuTel << "," << stuInfoVec[i].stuAge << ","
				<< stuInfoVec[i].mathScore << "," << stuInfoVec[i].engScore << ","
				<< stuInfoVec[i].cScore << "\n";
		}
	}

	stuFile.close();
	cout << "已成功另存为文件!路径为 D:\\cvte codes\\Student Manager System\\学生信息表\\stuInfo.csv\n";
	menu();
	cout << "请输入相应的序号: ";
}

void Stu::quitSystem()
{
	cout << "感谢您使用本系统!\n";
	cout << "Author: Romeo\n";
}