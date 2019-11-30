#include <string>
#include <vector>

typedef struct StuInfo{
	std::string stuNum; //学生学号
	std::string stuName; //学生姓名
	std::string stuTel; //学生电话号码
	int stuAge; //学生年龄
	int mathScore; //数学成绩
	int engScore; //英语成绩
	int cScore; //C语言成绩
} StuInfo;

class Stu{
private:
	std::vector<StuInfo> stuInfoVec;
	int select;
public:
	void menu(); //菜单
	//void select();// 选项函数
	void inputStuInfo(); //录入学生信息
	void searchStuInfo();  //查找学生信息
	void addStuInfo(); //增加某学生信息
	void delStuInfo(); //删除某学生信息
	void modifyStuInfo(); //修改学生信息
	void printStuInfo(); //打印学生信息
	void saveStuInfo(); //保存学生信息
	void quitSystem(); //退出系统

};