#include "Admin.h"
#include "User.h"

void Admin::sign_up()
{
	cout << "����� ����������! �����������������, ����������!" << endl;
	cout << "������� �����: ";
	cin.ignore();
	getline(cin, login); 
	cout << "������� ������: ";
	getline(cin, password);
	vector<string> is_empty;
	string str;
	ofstream fout;
	fout.open("Admin.txt", ios::app);
	ifstream fin;
	fin.open("Admin.txt");
	if (!fout.is_open())
	{
		cout << "���������� ������� ����, �������� �� �� ����������!" << endl;
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
			cout << "����� ��� ���������������!" << endl; 
			Sleep(1500);
			return; 
		}
	}
	fout.close();
	fin.close();
}

bool Admin::log_in()
{
	cout << "������� �����: ";
	cin.ignore();
	getline(cin, login);
	cout << "������� ������: ";
	getline(cin, password);
	vector<string> logins;
	vector<string> passwords;
	ifstream fin;
	string str;
	fin.open("Admin.txt");
	if (!fin.is_open())
	{
		cout << "���������� ������� ����, �������� �� �� ����������!" << endl;
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
			cout << "���� �������!" << endl;
			Sleep(1500);
			return true;
		}
		else
		{
			cout << "�������� ������!" << endl;
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
		cout << "���������� ����������!" << endl;
		exit(0);
	}
	else
	{
		cout << "����������: " << endl;
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
		cout << "���������� ������� ����, �������� �� �� ����������!" << endl;
		exit(0);
	}
	else 
	{
		cout << "������� �����: ";
		cin.ignore();
		getline(cin, login);
		cout << "������� ����� ������: ";
		getline(cin, password);
		fout << login << endl << password << endl;
		cout << "������ ������� �������!" << endl;
	}
	fout.close();
}

int adm_enter()
{
	cout << "��������: " << endl 
		<< "1.�����������" << endl
		<< "2.����" << endl;
	int a = 0;
	cin >> a;
	return a;
}

int adm_enter2()
{
	cout << "��������: " << endl
		<< "1.�������� ������������" << endl
		<< "2.����������" << endl
		<< "3.����� ������" << endl;
	int a = 0;
	cin >> a;
	return a;
}
