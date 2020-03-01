#include "User.h"

int menu()
{
	cout << "�������� ���� �����:" << endl
		<< "1.���������" << endl << "2.���������� � ������" << endl
		<< "3.������� � ���������" << endl << "4.��� ��������" << endl;
	int menu = 0;
	cin >> menu;
	return menu;
}
int choose()
{
	cout << "����� ����������!" << endl
		<< "�����, ������� \"1\"" << endl
		<< "������������, ������� \"2\"" << endl;
	int choose;
	cin >> choose;
	return choose;
}
int enter()
{
	cout << "����� ����������!" << endl
		<< "���� �� ����������������, ������� \"1\"" << endl
		<< "���� �� ����� �������, ������� \"2\"" << endl
		<< "���� ������ �����, ������� \"3\"" << endl;
	int enter;
	cin >> enter;
	return enter;
}

void User::sign_up()
{
	cout << "����� ����������! �����������������, ����������!" << endl
		<< "������� ���: ";
		cin.ignore();
		getline(cin, name);
		cout << "������� ��� �����: ";
		getline(cin, address);
		cout << "������� ��� ����� ��������: ";
		getline(cin, phone);
		cout << "������� �����: ";
		getline(cin, login);
		cout << "������� ������: ";
		getline(cin, password);
		ofstream fout;
		fout.open("User.txt", ios::app);
		if (!fout.is_open())
		{
			cout << "���������� ������� ����, �������� �� �� ����������!" << endl;
			exit(0);
		}
		else fout << name << endl << address << endl << phone << endl << login << endl << password << endl;
}

bool User::log_in()
{
	cout << "������� �����: ";
	cin.ignore();
	getline(cin, login);
	cout << "������� ������: ";
	getline(cin, password);
	vector<string> logins;
	vector<string> passwords;
	string str;
	ifstream fin;
	fin.open("User.txt");
	ofstream fout;
	fout.open("Test.txt", ios::app);
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
			if (number % 4 == 0) {
				logins.push_back(str);

			}
			if (number % 5 == 0) {
				passwords.push_back(str);
				number = 0;
			}
			number++;
		}
		bool enter = false;
		for (int i = 0; i < logins.size(); i++)
		{
			if (logins[i] == login && passwords[i] == password) 
			{
				enter = true;
				fout << logins[i];
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
	fout.close();
}

void User::test()
{
	char ch;
	char right;
	int answers = 0;
	int mark = 0;
	ofstream fout;
	fout.open("Test.txt", ios::app);
	switch (menu())
	{
	case 1:
		cout << "\t���������" << endl;
		cout << "1.����� �� ���� ���� �������� ������ ��������?" << endl
			<< "a) �����" << endl << "b) ���������" << endl
			<< "c) ������" << endl << "d) �������" << endl;
		cin >> ch;
		right = 'b';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "2.����� ������ ������� ������ �������� ����� ������� � �����?" << endl
			<< "a) �����" << endl << "b) �������" << endl
			<< "c) ����" << endl << "d) ��� ����������" << endl;
		cin >> ch;
		right = 'c';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "3.����� ������� �� ����� - ����� ���������?" << endl
			<< "a) ������" << endl << "b) �������" << endl
			<< "c) ��������" << endl << "d) ����" << endl;
		cin >> ch;
		right = 'b';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "4.����� ����������� ����� ��������� � ����?" << endl
			<< "a) �����������" << endl << "b) �������" << endl
			<< "c) �������" << endl << "d) ������" << endl;
		cin >> ch;
		right = 'c';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "5.�������� ���������� �� ������� ����� �������." << endl
			<< "a) �����" << endl << "b) �������" << endl
			<< "c) �������" << endl << "d) �������" << endl;
		cin >> ch;
		right = 'c';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "6.��� ���������� ��������� ������ ������������ �����������?" << endl
			<< "a) ��������" << endl << "b) ����������" << endl
			<< "c) ����" << endl << "d) ��������" << endl;
		cin >> ch;
		right = 'a';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "�����!" << endl
			<< "���������� ������ �������: " << answers << endl << "���� ������: " << mark << endl;
		fout << " " << "���������" << " " << mark << endl;
		break;
	case 2:
		cout << "\t���������� � ������" << endl
			<< "1.����� ������ ��������� ������ ������������� ������� �����?" << endl
			<< "a) ���" << endl << "b) �����" << endl
			<< "c) ������" << endl << "d) ����" << endl;
		cin >> ch;
		right = 'd';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "2.� ����� ��������� ��������� �������� ������?" << endl
			<< "a) ������� ���������" << endl << "b) ����� ���������" << endl
			<< "c) ����� ����" << endl << "d) ��������" << endl;
		cin >> ch;
		right = 'a';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "3.��� ���������� ������� ����� � ���� �� ����������� ������?" << endl
			<< "a) ������������" << endl << "b) ����������" << endl
			<< "c) ���������" << endl << "d) �����" << endl;
		cin >> ch;
		right = 'b';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "4.����� �� ���� ������ �� �������� ��������� ������� ������?" << endl
			<< "a) ��" << endl << "b) �����" << endl
			<< "c) ����" << endl << "d) ������" << endl;
		cin >> ch;
		right = 'b';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "5.��� ���������� ������� �������� ���� ������, ���������� � ��� ������ ������?" << endl
			<< "a) ������" << endl << "b) �����" << endl
			<< "c) ������" << endl << "d) ����" << endl;
		cin >> ch;
		right = 'd';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "6.����� ���������� ������� ����������� � ������� ������?" << endl
			<< "a) ����" << endl << "b) �������" << endl
			<< "c) �����" << endl << "d) ��������" << endl;
		cin >> ch;
		right = 'b';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "�����!" << endl
			<< "���������� ������ �������: " << answers << endl << "���� ������: " << mark << endl;
		fout << " " << "���������� � ������" << " " << mark << endl;
		break;
	case 3:
		cout << "\t������� � ���������" << endl;
		cout << "1.���� � ��������, ���������� ���������� ������������������� ������?" << endl
			<< "a) ��������" << endl << "b) �������" << endl
			<< "c) ��������" << endl << "d) ��������" << endl;
		cin >> ch;
		right = 'c';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "2.�� ����� ���� ����, �� ��������, ��������� ����?" << endl
			<< "a) ������" << endl << "b) �����" << endl
			<< "c) �������" << endl << "d) ������" << endl;
		cin >> ch;
		right = 'b';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "3.��� � ��������� ��������� �������� �������� ������, ���������� ����� � ������������ ����?" << endl
			<< "a) ������" << endl << "b) �������" << endl
			<< "c) ���������" << endl << "d) ������" << endl;
		cin >> ch;
		right = 'd';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "4.��� �� ������������� ������ �������� ����?" << endl
			<< "a) �������" << endl << "b) ���������" << endl
			<< "c) ��������" << endl << "d) �����" << endl;
		cin >> ch;
		right = 'c';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "5.����� �������� ����� �������� � ������������ ������ ������?" << endl
			<< "a) ����������" << endl << "b) �����������" << endl
			<< "c) �������" << endl << "d) ��������" << endl;
		cin >> ch;
		right = 'd';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "6.��� ���������� ����, ������� ��������� �������� ������ � ���� �������?" << endl
			<< "a) ������" << endl << "b) �������" << endl
			<< "c) ����������" << endl << "d) ���������" << endl;
		cin >> ch;
		right = 'c';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "�����!" << endl
			<< "���������� ������ �������: " << answers << endl << "���� ������: " << mark << endl;
		fout << " " << "������� � ���������" << " " << mark << endl;
		break;
	case 4:
		cout << "\t��� ��������" << endl;
		cout << "1.��� ���������� ����� �� ������, ��� ������� ������?" << endl
			<< "a) ��������" << endl << "b) �������" << endl
			<< "c) ��������" << endl << "d) �������" << endl;
		cin >> ch;
		right = 'b';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "2.������������� ����� �� ���� ������ �������� ���������� � ����?" << endl
			<< "a) ������" << endl << "b) ������" << endl
			<< "c) �����" << endl << "d) �����" << endl;
		cin >> ch;
		right = 'd';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "3.����� �� ���� �������� ������� �� ���� ��������?" << endl
			<< "a) ������" << endl << "b) ������������" << endl
			<< "c) �����" << endl << "d) ����� �������" << endl;
		cin >> ch;
		right = 'c';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "4.����� �� ���� �������� ����� �� �� ���������?" << endl
			<< "a) �������" << endl << "b) �����" << endl
			<< "c) �����" << endl << "d) �����" << endl;
		cin >> ch;
		right = 'c';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "5.����� �� ���� ������� ���������� �������� �����?" << endl
			<< "a) ������� ���" << endl << "b) ������� ����" << endl
			<< "c) ������� ����" << endl << "d) ������� ����" << endl;
		cin >> ch;
		right = 'b';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "6.����� ������� �������� �� ����������?" << endl
			<< "a) ���" << endl << "b) �����" << endl
			<< "c) �����" << endl << "d) �����" << endl;
		cin >> ch;
		right = 'b';
		if (ch == right)
		{
			cout << "�����!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "�������!" << endl;
		cout << "�����!" << endl
			<< "���������� ������ �������: " << answers << endl << "���� ������: " << mark << endl;
		fout << " " << "��� ��������" << " " << mark << endl;
		break;
	}
	fout.close();
}