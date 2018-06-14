#pragma once
#include"Library.h"

class Book {
	string author;
	string title;
	size_t yy;
	size_t count;
public:
	Book() {
		author = "";
		title = "";
		yy = 0;
		count = 0;
	}
	Book(string author, string title, size_t yy, size_t count) {
		this->author = author;
		this->title = title;
		this->yy = yy;
		this->count = count;
	}
	friend ostream& operator<<(ostream& os, Book obj) {
		os << obj.author << "\t" << obj.title <<"\t"<<obj.yy<<"\t"<<obj.count<< endl;
		return os;
	}
	bool operator ==(size_t yy) {
		return (this->yy == yy);
	}
	bool operator ==(string author) {
		return (this->author == author);
	}
};