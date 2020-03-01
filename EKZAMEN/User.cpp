#include "User.h"

int menu()
{
	cout << "Выберите тему теста:" << endl
		<< "1.География" << endl << "2.Астрономия и космос" << endl
		<< "3.Религия и мифология" << endl << "4.Мир животных" << endl;
	int menu = 0;
	cin >> menu;
	return menu;
}
int choose()
{
	cout << "Добро пожаловать!" << endl
		<< "Админ, нажмите \"1\"" << endl
		<< "Пользователь, нажмите \"2\"" << endl;
	int choose;
	cin >> choose;
	return choose;
}
int enter()
{
	cout << "Добро пожаловать!" << endl
		<< "Если вы зарегистрированы, нажмите \"1\"" << endl
		<< "Если вы здесь впервые, нажмите \"2\"" << endl
		<< "Если хотите выйти, нажмите \"3\"" << endl;
	int enter;
	cin >> enter;
	return enter;
}

void User::sign_up()
{
	cout << "Добро пожаловать! Зарегистрируйтесь, пожалуйста!" << endl
		<< "Введите имя: ";
		cin.ignore();
		getline(cin, name);
		cout << "Введите ваш адрес: ";
		getline(cin, address);
		cout << "Введите ваш номер телефона: ";
		getline(cin, phone);
		cout << "Введите логин: ";
		getline(cin, login);
		cout << "Введите пароль: ";
		getline(cin, password);
		ofstream fout;
		fout.open("User.txt", ios::app);
		if (!fout.is_open())
		{
			cout << "Невозможно открыть файл, возможно он не существует!" << endl;
			exit(0);
		}
		else fout << name << endl << address << endl << phone << endl << login << endl << password << endl;
}

bool User::log_in()
{
	cout << "Введите логин: ";
	cin.ignore();
	getline(cin, login);
	cout << "Введите пароль: ";
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
		cout << "Невозможно открыть файл, возможно он не существует!" << endl;
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
		cout << "\tГеография" << endl;
		cout << "1.Каким из этих слов называют группу островов?" << endl
			<< "a) Фьорд" << endl << "b) Архипелаг" << endl
			<< "c) Каньон" << endl << "d) Глетчер" << endl;
		cin >> ch;
		right = 'b';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "2.Какая горная система служит границей между Европой и Азией?" << endl
			<< "a) Алтай" << endl << "b) Карпаты" << endl
			<< "c) Урал" << endl << "d) Пик Коммунизма" << endl;
		cin >> ch;
		right = 'c';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "3.Какая пустыня на Земле - самая безводная?" << endl
			<< "a) Сахара" << endl << "b) Атакама" << endl
			<< "c) Каракумы" << endl << "d) Гоби" << endl;
		cin >> ch;
		right = 'b';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "4.Какое государство самое маленькое в мире?" << endl
			<< "a) Лихтенштейн" << endl << "b) Андорра" << endl
			<< "c) Ватикан" << endl << "d) Монако" << endl;
		cin >> ch;
		right = 'c';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "5.Назовите наибольшее по площади озеро Америки." << endl
			<< "a) Гурон" << endl << "b) Онтарио" << endl
			<< "c) Верхнее" << endl << "d) Мичиган" << endl;
		cin >> ch;
		right = 'c';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "6.Чья экспедиция совершила первое кругосветное путешествие?" << endl
			<< "a) Магелана" << endl << "b) Лисянского" << endl
			<< "c) Кука" << endl << "d) Врангеля" << endl;
		cin >> ch;
		right = 'a';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "Конец!" << endl
			<< "Количество верных ответов: " << answers << endl << "Ваша оценка: " << mark << endl;
		fout << " " << "География" << " " << mark << endl;
		break;
	case 2:
		cout << "\tАстрономия и космос" << endl
			<< "1.Какая страна запустила первый искусственный спутник Земли?" << endl
			<< "a) США" << endl << "b) Китай" << endl
			<< "c) Япония" << endl << "d) СССР" << endl;
		cin >> ch;
		right = 'd';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "2.В каком созвездии находится Полярная звезда?" << endl
			<< "a) Большая медведица" << endl << "b) Малая медведица" << endl
			<< "c) Южная рыба" << endl << "d) Касиопея" << endl;
		cin >> ch;
		right = 'a';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "3.Как называется граница света и тени на поверхности планет?" << endl
			<< "a) Альмукантрат" << endl << "b) Терминатор" << endl
			<< "c) Параллакс" << endl << "d) Факул" << endl;
		cin >> ch;
		right = 'b';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "4.Какая из этих планет не является спутником планеты Юпитер?" << endl
			<< "a) Ио" << endl << "b) Титан" << endl
			<< "c) Фива" << endl << "d) Европа" << endl;
		cin >> ch;
		right = 'b';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "5.Как называется газовая оболочка ядра кометы, образующая с ним голову кометы?" << endl
			<< "a) Корона" << endl << "b) Апекс" << endl
			<< "c) Квазар" << endl << "d) Кома" << endl;
		cin >> ch;
		right = 'd';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "6.Какой химический элемент преобладает в составе Солнца?" << endl
			<< "a) Азот" << endl << "b) Водород" << endl
			<< "c) Гелий" << endl << "d) Кислород" << endl;
		cin >> ch;
		right = 'b';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "Конец!" << endl
			<< "Количество верных ответов: " << answers << endl << "Ваша оценка: " << mark << endl;
		fout << " " << "Астрономия и космос" << " " << mark << endl;
		break;
	case 3:
		cout << "\tРелигия и мифология" << endl;
		cout << "1.Вера в предметы, обладающие различными сверхъестественными силами?" << endl
			<< "a) Тотемизм" << endl << "b) Анимизм" << endl
			<< "c) Фетишизм" << endl << "d) Шаманизм" << endl;
		cin >> ch;
		right = 'c';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "2.На какой горе жили, по преданию, греческие боги?" << endl
			<< "a) Парнас" << endl << "b) Олимп" << endl
			<< "c) Везувий" << endl << "d) Арарат" << endl;
		cin >> ch;
		right = 'b';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "3.Как в греческой мифологии называли крылатых женщин, похищающих детей и человеческие души?" << endl
			<< "a) Силены" << endl << "b) Грифоны" << endl
			<< "c) Василиски" << endl << "d) Гарпии" << endl;
		cin >> ch;
		right = 'd';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "4.Кто из перечисленных князей окрестил Русь?" << endl
			<< "a) Ярослав" << endl << "b) Святослав" << endl
			<< "c) Владимир" << endl << "d) Игорь" << endl;
		cin >> ch;
		right = 'c';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "5.Какой духовный титул является в православной церкви высшим?" << endl
			<< "a) Митрополит" << endl << "b) Архиепископ" << endl
			<< "c) Епископ" << endl << "d) Патриарх" << endl;
		cin >> ch;
		right = 'd';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "6.Как называются люди, которые стараются обратить других в свою религию?" << endl
			<< "a) Набобы" << endl << "b) Еретики" << endl
			<< "c) Миссионеры" << endl << "d) Религисты" << endl;
		cin >> ch;
		right = 'c';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "Конец!" << endl
			<< "Количество верных ответов: " << answers << endl << "Ваша оценка: " << mark << endl;
		fout << " " << "Религия и мифология" << " " << mark << endl;
		break;
	case 4:
		cout << "\tМир животных" << endl;
		cout << "1.Как называется место на берегу, где обитают тюлени?" << endl
			<< "a) Пастбище" << endl << "b) Лежбище" << endl
			<< "c) Стойбище" << endl << "d) Стоянка" << endl;
		cin >> ch;
		right = 'b';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "2.Разновидность какой из этих ящериц является крупнейшей в мире?" << endl
			<< "a) Геккон" << endl << "b) Игуана" << endl
			<< "c) Агама" << endl << "d) Варан" << endl;
		cin >> ch;
		right = 'd';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "3.Какое из этих животных вымерло по вине человека?" << endl
			<< "a) Мамонт" << endl << "b) Птеродактиль" << endl
			<< "c) Дронт" << endl << "d) Рыжий таракан" << endl;
		cin >> ch;
		right = 'c';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "4.Какое из этих животных родом не из Австралии?" << endl
			<< "a) Утконос" << endl << "b) Динго" << endl
			<< "c) Панда" << endl << "d) Коала" << endl;
		cin >> ch;
		right = 'c';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "5.Какой из этих морских обитателей является рыбой?" << endl
			<< "a) Морской лев" << endl << "b) Морской черт" << endl
			<< "c) Морской заяц" << endl << "d) Морской слон" << endl;
		cin >> ch;
		right = 'b';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "6.Каких летучих животных не существует?" << endl
			<< "a) Рыб" << endl << "b) Кошек" << endl
			<< "c) Собак" << endl << "d) Белок" << endl;
		cin >> ch;
		right = 'b';
		if (ch == right)
		{
			cout << "Верно!" << endl;
			answers++;
			mark += 2;
		}
		else cout << "Неверно!" << endl;
		cout << "Конец!" << endl
			<< "Количество верных ответов: " << answers << endl << "Ваша оценка: " << mark << endl;
		fout << " " << "Мир животных" << " " << mark << endl;
		break;
	}
	fout.close();
}