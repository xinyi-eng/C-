#include<iostream>
#include<cstdlib>
#include<ctime>
#include"LinkList.h"
#include"User.h"
#include"WordRecord.h"
#include"Utils.h"
using namespace std;
LinkList<User> sys_users;
void clearScreen() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

User* systemEntry() {

	sys_users.Load("users.dat");

	string name, pwd;
	cout << "--------- 背单词系统---------" << endl;
	cout << "请输入用户名：";
	cin >> name;


	User tempUser(name, "");
	Node<User>* pUserNode = sys_users.Locate(tempUser);

	if (pUserNode == NULL) {
		cout << "用户不存在，正在为您注册..." << endl;
		cout << "请设置密码：";
		cin >> pwd;
		User newUser(name, pwd);
		sys_users.Append(newUser);
		sys_users.Save("users.dat");
		pUserNode = sys_users.Locate(newUser);
		cout << "注册成功！已经自动登录。" << endl;

	}
	else {
		cout << "请输入密码：";
		cin >> pwd;
		if (sys_users.CurData().password != pwd) {
			cout << "密码错误！" << endl;
			return NULL;
		}
		cout << "登陆成功！" << endl;
		if (pUserNode !=NULL) {
			sys_users.CurData().loadUserData();
			return & (sys_users.CurData());
		}
		return NULL;
	}
}
void showDashboard(User& user) {
	int todo = user.todo_list.NumNodes();
	int done = user.done_list.NumNodes();
	int total = todo + done;
	double rate = (total == 0) ? 0.0 : (double)done / total * 100.0;
	cout << "\n========================================" << endl;
	cout << " 👤 用户: " << user.username << endl;
	cout << " 📊 进度: " << fixed << setprecision(1) << rate << "%  (已背: " << done << " / 剩余: " << todo << ")" << endl;
	cout << "========================================" << endl;
}

void studyMode(User& user);
void quizMode(User& user);
void spellMode(User& user);
int main() {
	User* currentUser = systemEntry();

	if (currentUser == NULL) {
		cout << "程序退出。" << endl;
		return 0;
	}

	// 2. 主菜单循环
	int choice;
	while (true) {
		system("cls");
		showDashboard(*currentUser);
		cout << "\n======== 🏠 主菜单 ========" << endl;
		cout << "1. 🃏 顺序背诵" << endl;
		cout << "2. 🧠 选义测试" << endl;
		cout << "0. 💾 保存并退出" << endl;
		cout << "---------------------------" << endl;
		cout << "请选择: ";
		cin >> choice;

		switch (choice) {
		case 1: studyMode(*currentUser); break;
		case 2: quizMode(*currentUser); break;
		case 0:
			currentUser->saveUserData();
			cout << "数据已保存。再见！" << endl;
			return 0;
		default: break;
		}
	}
	return 0;
}