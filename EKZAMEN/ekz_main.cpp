#include "User.h"
#include "Admin.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	Admin a;
	User u;
	switch (choose())
	{
	case 1:
	{
		system("cls");
		int adm = adm_enter();
		if (adm == 1)
		{
			system("cls");
			a.sign_up();
			system("cls");
		}
		else if (adm == 2)
		{
			system("cls");
			if (a.log_in())
			{
				system("cls");
				int adm2 = adm_enter2();
				system("cls");
				if (adm2 == 1)
				{
					a.log_user();
				}
				else if (adm2 == 2)
				{
					a.statistics();
				}
				else if (adm2 == 3)
				{
					a.change_password();
				}
			}
		}
		break;
	}
	case 2:
	{
		system("cls");
		int e = enter();
		system("cls");
		if (e == 1)
		{
			if (u.log_in())
			{
				system("cls");
				u.test();
				system("pause");
				system("cls");
			}
		}
		else if (e == 2)
		{
			u.sign_up();
			cout << "Подождите..." << endl;
			Sleep(1000);
			system("cls");
			int ee = enter();
			if (ee == 1)
			{
				if (u.log_in())
				{
					system("cls");
					u.test();
					system("pause");
					system("cls");
				}
			}
			else if (ee == 2)
			{
				system("cls");
				u.sign_up();
			}
		}
		else exit(0);
		break;
	}
	}
}