#include "WordRecord.h"

ostream& operator<<(ostream& out, const WordRecord& w) {
    out << w.spelling << " " << w.phonetic << " " << w.proficiency << endl;
    out << w.meaning << endl;
    return out;
}

istream& operator>>(istream& in, WordRecord& w) {
    in >> w.spelling >> w.phonetic >> w.proficiency;
    char temp[1000];
    in.getline(temp, 1000);
    if (in.peek() == '\n') in.ignore();
    in.getline(temp, 1000);
    w.meaning = temp;
    return in;
}