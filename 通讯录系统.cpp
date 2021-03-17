#include<iostream>
using namespace std;
#include<string>

//设计联系人结构体
struct Persen {
	string name;
	int sex;
	int age;
	string number;
	string address;
};
//设计通讯录结构体
struct addressbooks {
	struct Persen persenaArr[1000];
	int size;
};

//显示菜单
void showmenu() {
	cout << "********************" << endl;
	cout << "** 1、添加联系人 ***"<< endl;
	cout << "** 2、显示联系人 ***" << endl;
	cout << "** 3、删除联系人 ***" << endl;
	cout << "** 4、查找联系人 ***" << endl;
	cout << "** 5、修改联系人 ***" << endl;
	cout << "** 6、清空联系人 ***" << endl;
	cout << "** 0、退出通讯录 ***" << endl;
	cout << "********************" << endl;
}

//第一个功能，添加联系人函数
void addpersen(addressbooks* p) {
	if (p->size == 1000) {
		cout << "通讯录已满，无法添加。" << endl;
		return;
	}
	else {
		//姓名
		string name;
		cout << "请输入所添加联系人的姓名：" << endl;
		cin >> name;
		p->persenaArr[p->size].name = name;
		//性别
		int sex=0;
		cout << "请输入所添加联系人的性别，输入1则为男，输入2则为女。" << endl;
		while (1) {
			cin >> sex;
			if (sex ==1 || sex == 2) {
				p->persenaArr[p->size].sex = sex;
				break;
			}
			else {
				cout << "输入有误，请重新输入。" << endl;
			}
		}
		//年龄
		int age = 0;
		cout << "请输入所添加联系人的年龄：" << endl;
		cin >> age;
		p->persenaArr[p->size].age = age;
		//电话号码
		string number;
		cout << "请输入所添加联系人的电话号码：" << endl;
		cin >> number;
		p->persenaArr[p->size].number = number;
		//住址
		string address;
		cout << "请输入所添加联系人的住址：" << endl;
		cin >> address;
		p->persenaArr[p->size].address = address;

		cout << "添加成功" << endl;
		p->size++;

		system("pause");
		system("cls");//清屏

	}
}
//第二个功能，显示联系人函数
void showpersen(addressbooks *p) {
	if (p->size == 0) {
		cout << "通讯录为空" << endl;
	}
	else {
		for (int i = 0; i < p->size; i++) {
			cout << "姓名：" << p->persenaArr[i].name << " ";
			if (p->persenaArr[i].sex == 1) {
				cout << "性别：男" << " ";
			}
			else{
				cout << "性别：女" << " ";
			}
			cout << "年龄：" << p->persenaArr[i].age << " ";
			cout << "号码：" << p->persenaArr[i].number << " ";
			cout << "住址：" << p->persenaArr[i].address <<endl;
			
		}
	}
	system("pause");
	system("cls");
}

//设计检测函数，检测有没有想查找的联系人

int exist(addressbooks *p,string name) {
	for (int i = 0; i < p->size; i++) {
		if (p->persenaArr[i].name == name) {
			return i;
		}
	}
	return -1;
}

//第三个功能，删除联系人
void delectpersen(addressbooks *p) {
	cout << "请输入您想要删除的联系人的姓名：" << endl;
	string name;
	cin >> name;
	int ret=exist(p, name);
	if (ret == -1) {
		cout << "查无此人" << endl;
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

//第四个功能，查找联系人
void findpersen(addressbooks* p) {
	string name;
	cout << "请输入您想要查找的联系人姓名：" << endl;
	cin >> name;
	int ret = exist(p, name);
	if (ret == -1) {
		cout << "查无此人。" << endl;
	}
	else {
		for (int i = 0; i < p->size; i++) {
			if (name == p->persenaArr[i].name) {
				cout << "姓名：" << p->persenaArr[i].name << " ";
				if (p->persenaArr[i].sex == 1) {
					cout << "性别：男" << " ";
				}
				else {
					cout << "性别：女" << " ";
				}
				cout << "年龄：" << p->persenaArr[i].age << " ";
				cout << "号码：" << p->persenaArr[i].number << " ";
				cout << "住址：" << p->persenaArr[i].address << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

//第五个功能，修改联系人
void changepersen(addressbooks* p) {
	string name;
	cout << "请输入您想要修改的联系人姓名：" << endl;
	cin >> name;
	int ret = exist(p, name);
	if (ret == -1) {
		cout << "查无此人。" << endl;
	}
	else {
		int sex = 0;
		cout << "请输入所修改联系人的性别，输入1则为男，输入2则为女。" << endl;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				p->persenaArr[ret].sex = sex;
				break;
			}
			else {
				cout << "输入有误，请重新输入。" << endl;
			}
		}
		int age = 0;
		cout << "请输入所修改联系人的年龄：" << endl;
		cin >> age;
		p->persenaArr[ret].age = age;
		string number;
		cout << "请输入所修改联系人的电话号码：" << endl;
		cin >> number;
		p->persenaArr[ret].number = number;
		string address;
		cout << "请输入所修改联系人的住址：" << endl;
		cin >> address;
		p->persenaArr[ret].address = address;

		cout << "修改成功" << endl;
	}
	system("pause");
	system("cls");
}
//第六个功能，清空联系人
void clspersen(addressbooks* p) {
	p->size = 0;
	cout << "通讯录已清空。" << endl;
	system("pause");
	system("cls");
}
int main() {
	//创建通讯录结构体
	addressbooks abs;
	abs.size = 0;

	int select = 0;
	while (true) {
		showmenu();
		cin >> select;
		
		switch (select) {
		case 1://添加联系人
			addpersen(&abs);
			break;
		case 2://显示联系人
			showpersen(&abs);
			break;
		case 3://删除联系人
			delectpersen(&abs);
			break;
		case 4://查找联系人
			findpersen(&abs);
			break;
		case 5://修改联系人
			changepersen(&abs);
			break;
		case 6://清空联系人
			clspersen(&abs);
			break;
		case 0://退出通讯录
			cout << "欢迎您的下次使用。" << endl;
			system("pause");
			return 0;
		default:
			break;
		}
	}
	system("pause");
	return 0;

}