#include <iostream>
#include "IntegerArray.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "");

	while (true) {

		unsigned short length, length1, vote; short Be, be;

		IntegerArray ia;
		for (int i{ 0 }; i < ia.getLength(); ++i) {
			cout << ia[i] << ' ';
		}
		cout << '\n';

		try {
			
			cout << "Введите длину массива, не больше 100:  " << endl;
			cin >> length;
			length1 = length;

			if (length > 100) {
				system("cls");
				throw "bad_length";
			}

			IntegerArray ia(length);

			for (int i{ 0 }; i < length; ++i) {
				ia[i] = i + 1;
			}
			system("cls");
			menu();
			cin >> vote;

			switch (vote) {
			case 1:
				system("cls");
				for (int i{ 0 }; i < ia.getLength(); ++i) {
					cout << ia[i] << ' ';
				}
				cout << '\n';
				break;
			case 2:
				system("cls");
				cout << "Введите размер не больше 100." << endl;
				cin >> length;
				if (length > 100) {
					system("cls");
					throw "Ошибка";
				}
				system("cls");
				ia.resize(length);
				for (int i{ 0 }; i < length; ++i) {
					ia[i] = i + 1;
				}
				cout << "Посмотреть размер массива\n1. Да\n2. Нет" << endl;
				cin >> vote;
				system("cls");
				if (vote != 2) {
					for (int i{ 0 }; i < ia.getLength(); ++i) {
						cout << ia[i] << ' ';
					}
					cout << '\n';
				}
				break;
			case 3:
				cout << "Введите элемент не превышающий элемент массива" << endl;
				cin >> length;
				system("cls");
				if (length > length1) {
					throw "Такого элемента не существует!!!";
				}

				ia.remove(length -1);
				cout << "Ячейка № " << length << " удалена!!" << endl;

				for (int i{ 0 }; i < ia.getLength(); ++i) {
					cout << ia[i] << ' ';
				}
					cout << '\n';

				break;
			case 4:
				cout << "Какую ячейку числа заменить " << endl;
				cin >> Be;
				system("cls");
				if (Be > length || Be < 0) {
					throw "Oops, error...";
				}
				else {
					cout << "На какое число заменить?" << endl;
					cin >> be;
					system("cls");
					ia.Before(be, Be);

					for (int i{ 0 }; i < ia.getLength(); ++i) {
						cout << ia[i] << ' ';
					}
					cout << '\n';
				}
			case 5:
				cout << "Какое число поставить в начале" << endl;
				cin >> Be;
				system("cls");
				if (Be < 0) {
					throw "Error, Bruh";
				}
				cout << "Какое число поставить в конец" << endl;
				cin >> be;
				system("cls");
				if (be < 0) {
					throw "Error, Bruh";
				}
				ia.start(Be);
				ia.End(be);
				for (int i{ 0 }; i < ia.getLength(); ++i) {
					cout << ia[i] << ' ';
				}
				cout << '\n';
				break;
			default:
				break;
			}
		}
		catch (const char* error) {
			cout << error << endl;
		}
	}

}