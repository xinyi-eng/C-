#pragma once
#ifndef WORD_RECORD_H
#define WORD_RECORD_H
#include <iostream>
#include <string>
#include "LinkList.h"
using namespace std;
class WordRecord {
public:
	string spelling;
	string phonetic;
	string meaning;

	int proficiency;

	WordRecord():proficiency(0){}
	WordRecord(string s, string p,string m)
		:spelling(s),phonetic(p),meaning(m),proficiency(0){ }
	
	bool operator==(const WordRecord& other)const { return spelling == other.spelling; }
	bool operator<(const WordRecord& other)const { return spelling < other.spelling; }

	friend ostream& operator<<(ostream& out, const WordRecord& w);
	friend istream& operator>>(istream& in, WordRecord& w);
};
#endif