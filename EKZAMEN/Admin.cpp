#include "Admin.h"
#include "User.h"

void Admin::sign_up()
{
	cout << "Добро пожаловать! Зарегистрируйтесь, пожалуйста!" << endl;
	cout << "Введите логин: ";
	cin.ignore();
	getline(cin, login); 
	cout << "Введите пароль: ";
	getline(cin, password);
	vector<string> is_empty;
	string str;
	ofstream fout;
	fout.open("Admin.txt", ios::app);
	ifstream fin;
	fin.open("Admin.txt");
	if (!fout.is_open())
	{
		cout << "Невозможно открыть файл, возможно он не существует!" << endl;
		exit(0);
	}
	else
	{
		while (fin >> str)
		{
			is_empty.push_back(str);
		}
		if (is_empty.empty())
		{
			fout << login << endl << password << endl;
		}
		else 
		{
			cout << "Админ уже зарегистрирован!" << endl; 
			Sleep(1500);
			return; 
		}
	}
	fout.close();
	fin.close();
}

bool Admin::log_in()
{
	cout << "Введите логин: ";
	cin.ignore();
	getline(cin, login);
	cout << "Введите пароль: ";
	getline(cin, password);
	vector<string> logins;
	vector<string> passwords;
	ifstream fin;
	string str;
	fin.open("Admin.txt");
	if (!fin.is_open())
	{
		cout << "Невозможно открыть файл, возможно он не существует!" << endl;
		exit(0);
	}
	else
	{
		int number = 1;
		while (getline(fin, str))
		{
			if (number % 1 == 0) {
				logins.push_back(str);

			}
			if (number % 2 == 0) {
				passwords.push_back(str);
				number = 0;
			}
			number++;
		}
		bool enter = false;
		for (int i = 0; i < logins.size(); i++)
		{
			if (logins[i] == login && passwords[i] == password) {
				enter = true;
				break;
			}
		}
		if (enter)
		{
			cout << "Вход удачный!" << endl;
			Sleep(1500);
			return true;
		}
		else
		{
			cout << "Неверный пароль!" << endl;
			system("pause");
			return false;
		}
	}
	fin.close();
}

void Admin::statistics()
{
	string str;
	ifstream fin;
	fin.open("Test.txt");
	vector<string> results;
	if (!fin.is_open())
	{
		cout << "Статистика недоступна!" << endl;
		exit(0);
	}
	else
	{
		cout << "Статистика: " << endl;
		while (getline(fin, str))
		{
			results.push_back(str);
		}
		for (vector<string>::iterator it = results.begin(); it != results.end(); it++)
		{
			cout << *it << endl;
		}
	}
}

void Admin::log_user()
{
	User user;
	user.log_in();
}

void Admin::change_password()
{
	ofstream fout;
	fout.open("Admin.txt", ios::trunc);
	if (!fout.is_open())
	{
		cout << "Невозможно открыть файл, возможно он не существует!" << endl;
		exit(0);
	}
	else 
	{
		cout << "Введите логин: ";
		cin.ignore();
		getline(cin, login);
		cout << "Введите новый пароль: ";
		getline(cin, password);
		fout << login << endl << password << endl;
		cout << "Пароль успешно изменен!" << endl;
	}
	fout.close();
}

int adm_enter()
{
	cout << "Выберите: " << endl 
		<< "1.Регистрация" << endl
		<< "2.Вход" << endl;
	int a = 0;
	cin >> a;
	return a;
}

int adm_enter2()
{
	cout << "Выберите: " << endl
		<< "1.Добавить пользователя" << endl
		<< "2.Статистика" << endl
		<< "3.Смена пароля" << endl;
	int a = 0;
	cin >> a;
	return a;
}
