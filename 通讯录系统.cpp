#include<iostream>
using namespace std;
#include<string>

//�����ϵ�˽ṹ��
struct Persen {
	string name;
	int sex;
	int age;
	string number;
	string address;
};
//���ͨѶ¼�ṹ��
struct addressbooks {
	struct Persen persenaArr[1000];
	int size;
};

//��ʾ�˵�
void showmenu() {
	cout << "********************" << endl;
	cout << "** 1�������ϵ�� ***"<< endl;
	cout << "** 2����ʾ��ϵ�� ***" << endl;
	cout << "** 3��ɾ����ϵ�� ***" << endl;
	cout << "** 4��������ϵ�� ***" << endl;
	cout << "** 5���޸���ϵ�� ***" << endl;
	cout << "** 6�������ϵ�� ***" << endl;
	cout << "** 0���˳�ͨѶ¼ ***" << endl;
	cout << "********************" << endl;
}

//��һ�����ܣ������ϵ�˺���
void addpersen(addressbooks* p) {
	if (p->size == 1000) {
		cout << "ͨѶ¼�������޷���ӡ�" << endl;
		return;
	}
	else {
		//����
		string name;
		cout << "�������������ϵ�˵�������" << endl;
		cin >> name;
		p->persenaArr[p->size].name = name;
		//�Ա�
		int sex=0;
		cout << "�������������ϵ�˵��Ա�����1��Ϊ�У�����2��ΪŮ��" << endl;
		while (1) {
			cin >> sex;
			if (sex ==1 || sex == 2) {
				p->persenaArr[p->size].sex = sex;
				break;
			}
			else {
				cout << "�����������������롣" << endl;
			}
		}
		//����
		int age = 0;
		cout << "�������������ϵ�˵����䣺" << endl;
		cin >> age;
		p->persenaArr[p->size].age = age;
		//�绰����
		string number;
		cout << "�������������ϵ�˵ĵ绰���룺" << endl;
		cin >> number;
		p->persenaArr[p->size].number = number;
		//סַ
		string address;
		cout << "�������������ϵ�˵�סַ��" << endl;
		cin >> address;
		p->persenaArr[p->size].address = address;

		cout << "��ӳɹ�" << endl;
		p->size++;

		system("pause");
		system("cls");//����

	}
}
//�ڶ������ܣ���ʾ��ϵ�˺���
void showpersen(addressbooks *p) {
	if (p->size == 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < p->size; i++) {
			cout << "������" << p->persenaArr[i].name << " ";
			if (p->persenaArr[i].sex == 1) {
				cout << "�Ա���" << " ";
			}
			else{
				cout << "�Ա�Ů" << " ";
			}
			cout << "���䣺" << p->persenaArr[i].age << " ";
			cout << "���룺" << p->persenaArr[i].number << " ";
			cout << "סַ��" << p->persenaArr[i].address <<endl;
			
		}
	}
	system("pause");
	system("cls");
}

//��Ƽ�⺯���������û������ҵ���ϵ��

int exist(addressbooks *p,string name) {
	for (int i = 0; i < p->size; i++) {
		if (p->persenaArr[i].name == name) {
			return i;
		}
	}
	return -1;
}

//���������ܣ�ɾ����ϵ��
void delectpersen(addressbooks *p) {
	cout << "����������Ҫɾ������ϵ�˵�������" << endl;
	string name;
	cin >> name;
	int ret=exist(p, name);
	if (ret == -1) {
		cout << "���޴���" << endl;
	}
	else {
		for (int i = ret; i < p->size; i++) {
			p->persenaArr[i] = p->persenaArr[i + 1];
			p->size--;
		}
	}
	system("pause");
	system("cls");
}

//���ĸ����ܣ�������ϵ��
void findpersen(addressbooks* p) {
	string name;
	cout << "����������Ҫ���ҵ���ϵ��������" << endl;
	cin >> name;
	int ret = exist(p, name);
	if (ret == -1) {
		cout << "���޴��ˡ�" << endl;
	}
	else {
		for (int i = 0; i < p->size; i++) {
			if (name == p->persenaArr[i].name) {
				cout << "������" << p->persenaArr[i].name << " ";
				if (p->persenaArr[i].sex == 1) {
					cout << "�Ա���" << " ";
				}
				else {
					cout << "�Ա�Ů" << " ";
				}
				cout << "���䣺" << p->persenaArr[i].age << " ";
				cout << "���룺" << p->persenaArr[i].number << " ";
				cout << "סַ��" << p->persenaArr[i].address << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

//��������ܣ��޸���ϵ��
void changepersen(addressbooks* p) {
	string name;
	cout << "����������Ҫ�޸ĵ���ϵ��������" << endl;
	cin >> name;
	int ret = exist(p, name);
	if (ret == -1) {
		cout << "���޴��ˡ�" << endl;
	}
	else {
		int sex = 0;
		cout << "���������޸���ϵ�˵��Ա�����1��Ϊ�У�����2��ΪŮ��" << endl;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				p->persenaArr[ret].sex = sex;
				break;
			}
			else {
				cout << "�����������������롣" << endl;
			}
		}
		int age = 0;
		cout << "���������޸���ϵ�˵����䣺" << endl;
		cin >> age;
		p->persenaArr[ret].age = age;
		string number;
		cout << "���������޸���ϵ�˵ĵ绰���룺" << endl;
		cin >> number;
		p->persenaArr[ret].number = number;
		string address;
		cout << "���������޸���ϵ�˵�סַ��" << endl;
		cin >> address;
		p->persenaArr[ret].address = address;

		cout << "�޸ĳɹ�" << endl;
	}
	system("pause");
	system("cls");
}
//���������ܣ������ϵ��
void clspersen(addressbooks* p) {
	p->size = 0;
	cout << "ͨѶ¼����ա�" << endl;
	system("pause");
	system("cls");
}
int main() {
	//����ͨѶ¼�ṹ��
	addressbooks abs;
	abs.size = 0;

	int select = 0;
	while (true) {
		showmenu();
		cin >> select;
		
		switch (select) {
		case 1://�����ϵ��
			addpersen(&abs);
			break;
		case 2://��ʾ��ϵ��
			showpersen(&abs);
			break;
		case 3://ɾ����ϵ��
			delectpersen(&abs);
			break;
		case 4://������ϵ��
			findpersen(&abs);
			break;
		case 5://�޸���ϵ��
			changepersen(&abs);
			break;
		case 6://�����ϵ��
			clspersen(&abs);
			break;
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�����´�ʹ�á�" << endl;
			system("pause");
			return 0;
		default:
			break;
		}
	}
	system("pause");
	return 0;

}