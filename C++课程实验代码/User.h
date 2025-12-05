#pragma once
#ifndef USER_H
#define USER_H
#include<string>
#include<iostream>
#include<fstream>
#include"LinkList.h"
#include"WordRecord.h"

using namespace std;
class User {
public:
	string username;
	string password;
	LinkList<WordRecord> todo_list;
	LinkList<WordRecord> done_list;
	User(){} User(string u, string p) :username(u), password(p) {}
	void loadUserData();
	void saveUserData();
	void moveWordToDone(WordRecord w);
	bool operator==(const User& other)const {
		return this->username == other.username;
	}
	friend ostream& operator<<(ostream& out, const User& u) {
		out << u.username << " " << u.password;
		return out;
	}
	friend istream& operator>>(istream& in, User& u) {
		in >> u.username >> u.password;
		return in;
	}

};
#endif