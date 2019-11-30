#include "student.h"
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <fstream>

#define COL 8
using namespace std;

void Stu::menu()
{
	/*cout << "ϵͳ���ڳ�ʼ��,���Ժ�";
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
	cout << "      ѧ����Ϣ����ϵͳ" << endl;
	cout << "1.¼��ѧ����Ϣ  2.���ѧ����Ϣ" << endl;
	cout << "3.����ѧ����Ϣ  4.ɾ��ѧ����Ϣ" << endl;
	cout << "5.�޸�ѧ����Ϣ  6.��ӡѧ����Ϣ" << endl;
	cout << "7.����ѧ����Ϣ  8.�˳���Ϣϵͳ" << endl;
}

void Stu::inputStuInfo()
{
	string finishInput;
	StuInfo stuInfo;
	cout << "����¼��ѧ����Ϣ,���Ժ�";
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".\n";
	while (1)
	{
		cout << "\nѧ��: ";
		cin >> stuInfo.stuNum;
		cout << "����: ";
		cin >> stuInfo.stuName;
		cout << "�绰����: ";
		cin >> stuInfo.stuTel;
		cout << "����: ";
		cin >> stuInfo.stuAge;
		cout << "��ѧ�ɼ�: ";
		cin >> stuInfo.mathScore;
		cout << "Ӣ��ɼ�: ";
		cin >> stuInfo.engScore;
		cout << "C���Գɼ�: ";
		cin >> stuInfo.cScore;
		stuInfoVec.push_back(stuInfo);
		cout << "�Ƿ����(Y/N):";
		cin >> finishInput;
		if (finishInput == "N")
		{
			continue;
		}
		else
		{
			cout << "¼�����!\n";
			break;
		}
	}
	menu();
	cout << "��������Ӧ�����: ";
	
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
	cout << "1.��ѧ�Ų��� 2.����������\n";
	cout << "��������Ӧ�Ĳ��ҷ�ʽ:";
	cin >> num;
	if (num == 1)
	{
		cout << "������ѧ��:";
		cin >> sNum;
		cout << "ѧ��       ����       �绰����       ����      ��ѧ      Ӣ��      C����\n\n";
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
			cout << "��ӡ���!\n";
		}
		else
		{
			cout << "��ѯ���Ϊ��!\n";
		}
	}
	if (num == 2)
	{
		bool FIND = false;
		cout << "����������:";
		cin >> sName;
		cout << "ѧ��       ����       �绰����       ����      ��ѧ      Ӣ��      C����\n\n";
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
			cout << "��ӡ���!\n";
		}
		else
		{
			cout << "��ѯ���Ϊ��!\n";
		}
	}
	menu();
	cout << "��������Ӧ�����: ";
}

void Stu::delStuInfo()
{
	string sName, sNum;
	int num = 0;
	//ʹ��vector���erase()��ɾ����ע�������ʧЧ������
	vector<StuInfo>::iterator stuIt;
	cout << "1.������ɾ�� 2.��ѧ��ɾ��\n";
	cout << "������ѡ��:";
	cin >> num;
	if (num == 1)
	{
		cout << "������ѧ������:";
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
		cout << "ɾ�����!\n";
	}

	if (num == 2)
	{
		cout << "������ѧ��ѧ��:";
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
		cout << "ɾ�����!\n";
	}
	menu();
	cout << "��������Ӧ�����: ";
}

void Stu::modifyStuInfo()
{
	//����ʵ�����󣬸ı��һ���ǵ绰����ͳɼ��ȡ�������ѧ��һ�㲻��䡣
	//�ȸ���ѧ�Ų��ҵ�ѧ��
	//�ٰѸ�������Ϣ��ӡ����
	
	string sNum;
	cout << "������ѧ����ѧ��:";
	cin >> sNum;
	cout << "������ǰ��ϢΪ:\n";
	cout << "ѧ��       ����       �绰����       ����      ��ѧ      Ӣ��      C����\n\n";
	for (int i = 0; i < stuInfoVec.size(); ++i)
	{
		if (stuInfoVec[i].stuNum == sNum)
		{
			printf("%5s    %5s      %5s    %5d     %5d     %5d     %5d\n", stuInfoVec[i].stuNum.c_str(), stuInfoVec[i].stuName.c_str(),
				stuInfoVec[i].stuTel.c_str(), stuInfoVec[i].stuAge, stuInfoVec[i].mathScore, stuInfoVec[i].engScore, stuInfoVec[i].cScore);
		}
	}
	cout << "1.�޸ĵ绰���� 2.�޸���ѧ�ɼ� 3.�޸�Ӣ��ɼ� 4.�޸�C���Գɼ�\n";
	cout << "��������Ӧ�����:";
	int num = 0;
	cin >> num;
	for (int i = 0; i < stuInfoVec.size(); ++i)
	{
		if (stuInfoVec[i].stuNum == sNum)
		{
			if (num == 1)
			{
				cout << "�������µĵ绰����:";
				string sTel;
				cin >> sTel;
				stuInfoVec[i].stuTel = sTel;
			}
			else if (num == 2)
			{
				cout << "�������µ���ѧ�ɼ�:";
				int sMath;
				cin >> sMath;
				stuInfoVec[i].mathScore = sMath;
			}
			else if (num == 3)
			{
				cout << "�������µ�Ӣ��ɼ�:";
				int sEng;
				cin >> sEng;
				stuInfoVec[i].engScore = sEng;
			}
			else
			{
				cout << "�������µ�C���Գɼ�:";
				int sClan;
				cin >> sClan;
				stuInfoVec[i].cScore = sClan;
			}
		}		
	}
	cout << "�޸����!\n";
	cout << "�Ƿ�����޸�(Y/N):";
	string modifyFinish;
	cin >> modifyFinish;
	if (modifyFinish == "N")
	{
		cout << "�޸����!\n";
		menu();
		cout << "��������Ӧ�����: ";
		return;
	}
	modifyStuInfo();
}

void Stu::printStuInfo()
{
	if (stuInfoVec.size() == 0)
	{
		cout << "ѧ����ϢΪ�գ���ӡʧ��!\n";
		cout << "��������Ӧ�����: ";
	}
	else
	{
		cout << "ѧ��       ����       �绰����       ����      ��ѧ      Ӣ��      C����\n\n";
		for (int i = 0; i < stuInfoVec.size(); ++i)
		{ 
			printf("%5s    %5s      %5s    %5d     %5d     %5d     %5d\n", stuInfoVec[i].stuNum.c_str(), stuInfoVec[i].stuName.c_str(),
				stuInfoVec[i].stuTel.c_str(), stuInfoVec[i].stuAge, stuInfoVec[i].mathScore, stuInfoVec[i].engScore, stuInfoVec[i].cScore);
			if (i == stuInfoVec.size()-1)
			{
				cout << "\nѧ����Ϣ��ӡ���!\n";
				break;
			}
		}
		menu();
		cout << "��������Ӧ�����: ";
	}

}

void Stu::saveStuInfo()
{

	cout << "���ڱ���Ϊ�ļ�,���Ժ�\n";

	ofstream stuFile;

	//д�ķ�ʽ���ļ�
	stuFile.open("..\\ѧ����Ϣ��\\stuInfo.csv", ios::out);
	//rapidcsv::Document doc("..\\ѧ����Ϣ��\\stuInfo.csv", rapidcsv::LabelParams(-1, -1));
	stuFile << "ѧ��," << "����," << "�绰����," << "����," << "��ѧ," << "Ӣ��," << "C����\n";
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
	cout << "�ѳɹ����Ϊ�ļ�!·��Ϊ D:\\cvte codes\\Student Manager System\\ѧ����Ϣ��\\stuInfo.csv\n";
	menu();
	cout << "��������Ӧ�����: ";
}

void Stu::quitSystem()
{
	cout << "��л��ʹ�ñ�ϵͳ!\n";
	cout << "Author: Romeo\n";
}