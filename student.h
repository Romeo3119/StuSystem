#include <string>
#include <vector>

typedef struct StuInfo{
	std::string stuNum; //ѧ��ѧ��
	std::string stuName; //ѧ������
	std::string stuTel; //ѧ���绰����
	int stuAge; //ѧ������
	int mathScore; //��ѧ�ɼ�
	int engScore; //Ӣ��ɼ�
	int cScore; //C���Գɼ�
} StuInfo;

class Stu{
private:
	std::vector<StuInfo> stuInfoVec;
	int select;
public:
	void menu(); //�˵�
	//void select();// ѡ���
	void inputStuInfo(); //¼��ѧ����Ϣ
	void searchStuInfo();  //����ѧ����Ϣ
	void addStuInfo(); //����ĳѧ����Ϣ
	void delStuInfo(); //ɾ��ĳѧ����Ϣ
	void modifyStuInfo(); //�޸�ѧ����Ϣ
	void printStuInfo(); //��ӡѧ����Ϣ
	void saveStuInfo(); //����ѧ����Ϣ
	void quitSystem(); //�˳�ϵͳ

};