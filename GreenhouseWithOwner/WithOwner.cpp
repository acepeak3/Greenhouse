//Kasian N. K-12

#include <iostream>
#include <string>
#include "../WrittingLibrary/WritingLibrary.h"
#include "Greenhouse.h"

using namespace std;

void trygreenhouseSelfChange(Greenhouse &oneWithOwner)
{
	if (!oneWithOwner.greenhouseSelfChange())
		cout << "Теплиця вже померла." << endl;
}

void tryOpenWindow(Greenhouse &oneWithOwner)
{
	if (oneWithOwner.getGreenhouseCondition())
	{
		if (!oneWithOwner.openTheWindow())
			cout << "Вiкно вже вiдкрите." << endl;
	}
	else
		cout << "Теплиця вже померла." << endl;
}

void tryCloseWindow(Greenhouse &oneWithOwner)
{
	if (oneWithOwner.getGreenhouseCondition())
	{
		if (!oneWithOwner.closeTheWindow())
			cout << "Вiкно вже закрите." << endl;
	}
	else
		cout << "Теплиця вже померла." << endl;
}

void tryOnHeater(Greenhouse &oneWithOwner)
{
	if (oneWithOwner.getGreenhouseCondition())
	{
		if (!oneWithOwner.onTheHeater())
			cout << "Обiгрiвач вже ввiмкнено." << endl;
	}
	else
		cout << "Теплиця вже померла." << endl;
}

void tryOffHeater(Greenhouse &oneWithOwner)
{
	if (oneWithOwner.getGreenhouseCondition())
	{
		if (!oneWithOwner.offTheHeater())
			cout << "Обiгрiвач вже вимкнено." << endl;
	}
	else
		cout << "Теплиця вже померла." << endl;
}

void chooseAction(int action, Greenhouse &oneWithOwner)
{
	switch (action)
	{
	case 0:
		trygreenhouseSelfChange(oneWithOwner);
		break;
	case 1:
		tryOpenWindow(oneWithOwner);
		break;
	case 2:
		tryCloseWindow(oneWithOwner);
		break;
	case 3:
		tryOnHeater(oneWithOwner);
		break;
	case 4:
		tryOffHeater(oneWithOwner);
		break;
	default:
		break;
	}
}

void help()
{
	cout << "Iнструкцiя:" << endl;
	cout << "Greenhouse [ -0 | -1 | -2 | -3 | -4 | -9 ]" << endl << endl;
	cout << "\t-0 : Теплиця на самообслуговуваннi." << endl;
	cout << "\t-1 : Вiдкрити вiкно." << endl;
	cout << "\t-2 : Зачинити вiкно." << endl;
	cout << "\t-3 : Ввiмкнути обiгрiвач." << endl;
	cout << "\t-4 : Вимкнути обiгрiвач." << endl;
	cout << "\t-5 : Завершити сесiю." << endl;
	cout << "\t-6 : Завершити керування." << endl;
}

int getAction()
{
	int action;
	bool isSuccess = false;

	do
	{
		cin >> action;
		if (cin.fail())
		{
			isSuccess = false;
			cin.clear();
			cin.get();
			cout << "Ви ввели невiрне значення. Повторiть спробу." << endl;
		}
		else isSuccess = true;
	} while (!isSuccess);
	return action;
}

void main()
{
	Greenhouse oneWithOwner;
	int action,
		endOfStep = 5,
		endOfControl = 6;

	setlocale(LC_CTYPE, "Rus");
	Copyright();
	help();

	do
	{
		action = getAction();
		if (!(endOfStep == action) && !(endOfControl == action))
		{
			chooseAction(action, oneWithOwner);
		}
		else if (endOfStep == action)
		{
			oneWithOwner.endOfStep();
			cout << oneWithOwner.consoleOut() << endl;
		}
	} while (!(endOfControl == action));

	cout << endl << "Керування теплицею завершено." << endl;

	system("pause");
}