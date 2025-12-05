#include"User.h"
const string MASTER_DICT = "dictionary.txt";
void User::loadUserData() {
	string my_todo_file = username + "_todo.txt";
	string my_done_file = username + "_done.txt";
	ifstream fin(my_todo_file.c_str());
	if (!fin) {
		cout << "\n[系统] 检测到新用户，正在为您初始化词库..." << endl;
		int count = todo_list.Load(MASTER_DICT.c_str());
		if (count > 0) {
			cout << "[系统]初始化成功！已导入" << count << "个单词。" << endl;
		}
		else {
			cout << "[错误] 母本词库缺失，请联系管理员！" << endl;
		}
	}
	else {
		fin.close();
		todo_list.Load(my_todo_file.c_str());
		done_list.Load(my_todo_file.c_str());
	}
}
void User::saveUserData() { 
	string my_todo_file = username + "_todo.text";
	string my_done_file = username + "_done.text";
	todo_list.Save(my_todo_file.c_str()); 
	done_list.Save(my_done_file.c_str());
}
void User::moveWordToDone(WordRecord w) {
	done_list.Append(w);
}