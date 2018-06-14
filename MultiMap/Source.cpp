
#include"Book.h"

void print(pair<string, Book> e) {
	cout << e.second;
}
int main(){
	setlocale(LC_ALL, "Russian");
int n;
cout << "Enter num: ";
cin >> n;
switch (n) {
	/*
	multy map-ключи могут повторятся
	не использовать []
	insert- не заменяет первоначальное значение
	for_each
	*/
case 1: {
	/*multimap<string, Book> bs;
	ifstream in_file("books.txt");
	string title, author;
	while (!in_file.eof()) {
		in_file >> author >> title;
		bs.insert(pair<string, Book>(author, Book(author, title)));
	}
	for_each(bs.begin(), bs.end(), print);*/

}break;
	//вывод по авторам
case 2: {
	/*multimap<string, Book> bs;
	ifstream in_file("books.txt");
	set<string> as;
	string title, author;
	while (!in_file.eof()) {
		in_file >> author >> title;
		bs.insert(pair<string, Book>(author, Book(author, title)));
	}
	for (auto it = bs.begin();it != bs.end(); it++)
		as.insert(it->first);

	for (auto it = as.begin();it != as.end(); it++) {
		auto itr = bs.equal_range(*it);

		cout << *it << endl;
		for_each(itr.first, itr.second, print);
		cout << endl;
		cout <<endl;
	}*/
}break;

	/*Вариант 3,7 
Написать программу учета книг в библиотеке. Сведения о книгах: ФИО автора, название, год издания, количество экземпляров. Обеспечить:
	Добавление книг
	Удаление книг
	Вывод сведений о книгах по фамилиям авторов
	Вывод сведений о книгах по указанному году издания
Использовать контейнерный класс multimap
*/
case 3: {
	multimap<string, Book> bs;
		set<string> as;
	string title, author;
	size_t yy, count;

	//считали с файла
	ifstream in_file("books.txt");
	while (!in_file.eof()) {
		in_file >> author >> title>>yy>>count;
		bs.insert(pair<string, Book>(author, Book(author, title,yy,count)));
	}
	//записали авторов в сет
	for (auto it = bs.begin();it != bs.end(); it++)
		as.insert(it->first);

	//вывод по автору
	for (auto it = as.begin();it != as.end(); it++) {
		auto itr = bs.equal_range(*it);

		cout << *it << endl;
		for_each(itr.first, itr.second, print);
		cout << endl;
		cout << endl;
	}
	int k;
	cout << " Действие: " << endl;
	cout << " 1- добавить книгу" << endl;
	cout << " 2- удалить книгу" << endl;
	cout << " 3- Вывод сведений о книгах по фамилиям авторов" << endl;
	cout << " 4- Вывод сведений о книгах по указанному году издания" << endl;
	cin >> k;
	switch (k) {
	case 1: {
		string b;
		cout << "Enter the book: ";
		cin.ignore();
		getline(cin, b);
		as.insert(b);
		for (auto it = as.begin();it != as.end(); it++) {
			auto itr = bs.equal_range(*it);
			cout << *it << endl;
			for_each(itr.first, itr.second, print);
			cout << endl;
		}

	}break;
	case 2: {
		string b;
		cout << "Enter the author: ";
		cin >> b;
		auto it = bs.find(author);
		if (it != bs.end())
		{
			bs.erase(it->first);
		}
		/*for (auto it = bs.begin();it != bs.end(); it++) {
			if (it->first == b) {
				bs.erase(it->first);
			}				
		}*/
		
			for_each(bs.begin(), bs.end(), print);
	
		
	}break;
	case 3: {
		string name;
		cout << "Enter an author: ";
		cin >> name;
		for (auto it = as.begin();it != as.end(); it++) {
			auto itr = bs.equal_range(*it);
			if (itr.first->first == name) {
				for_each(itr.first, itr.second, print);
				cout << endl;
			}
		}
	}break;
	case 4: {
		size_t year;
		cout << "Enter an year: ";
		cin >> year;
		for (auto it = as.begin();it != as.end(); it++) {
			auto itr = bs.equal_range(*it);
			if (itr.first->second == year) {
				cout << itr.first->second << endl;
				cout << endl;
			}
		}

	}break;

	}

}break;
}
system("pause");
return 0;
}
