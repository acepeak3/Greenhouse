//Kasian N. K-12

#include <iostream>
#include "Greenhouse.h"

using namespace std;

Greenhouse::Greenhouse() :
	windowIsOpen(false),
	heaterIsOn(false),
	greenhouseIsAlive(true),
	temperature(25),
	humidity(80),
	currentTemperatureChange(0.1),
	currentHumidityChange(0.1),
	minTemperature(20),
	maxTemperature(30),
	minHumidity(70),
	maxHumidity(90),
	lifeTime(0)
{
}

bool Greenhouse::openTheWindow()
{
	if (!windowIsOpen)
	{
		windowIsOpen = true;
		currentTemperatureChange -= 0.3;
		currentHumidityChange -= 0.4;
	}
	else return false;
}

bool Greenhouse::closeTheWindow()
{
	if (windowIsOpen)
	{
		windowIsOpen = false;
		currentTemperatureChange += 0.3;
		currentHumidityChange += 0.4;
	}
	else return false;
}

bool Greenhouse::onTheHeater()
{
	if (!heaterIsOn)
	{
		heaterIsOn = true;
		currentTemperatureChange += 0.5;
		currentHumidityChange += 0.3;
	}
	else return false;
}

bool Greenhouse::offTheHeater()
{
	if (heaterIsOn)
	{
		heaterIsOn = false;
		currentTemperatureChange -= 0.5;
		currentHumidityChange -= 0.3;
	}
	else
		return false;
}

bool Greenhouse::greenhouseSelfChange()
{
	if (getGreenhouseCondition())
	{
		currentTemperatureChange -= 0.2;
		currentHumidityChange -= 0.3;
	}
	else return false;
}

bool Greenhouse::getGreenhouseCondition()
{
	if ((temperature < minTemperature) || (temperature > maxTemperature) || (humidity < minHumidity) || (humidity > maxHumidity))
		greenhouseIsAlive = false;

	return greenhouseIsAlive;
}

string Greenhouse::consoleOut()
{
	string Console;

	Console += windowCondition();
	Console += heaterCondition();
	Console += greenhouseCondition();

	Console += "Температура " + to_string(temperature) + "\n";
	Console += "Вологiсть повiтря " + to_string(humidity) + "\n";
	Console += "Теплиця пропрацювала " + to_string(lifeTime) + " годин.\n";

	return Console;
}

void Greenhouse::endOfStep()
{
	changetemperature();
	changehumidity();

	lifeTime++;
}

void Greenhouse::changetemperature()
{
	temperature += currentTemperatureChange;
}

void Greenhouse::changehumidity()
{
	humidity += currentHumidityChange;
}

string Greenhouse::windowCondition()
{
	string Console;

	switch (windowIsOpen)
	{
	case true:
		Console = "Вiкно вiдчинене.\n";
		break;
	case false:
		Console = "Вiкно зачинене.\n";
		break;
	}
	return Console;
}

string Greenhouse::heaterCondition()
{
	string Console;

	switch (heaterIsOn)
	{
	case true:
		Console = "Обiгрiвач увiмкнений.\n";
		break;
	case false:
		Console = "Обiгрiвач вимкнений.\n";
		break;
	}
	return Console;
}

string Greenhouse::greenhouseCondition()
{
	string Console;

	switch (greenhouseIsAlive)
	{
	case true:
		Console = "Теплиця жива.\n";
		break;
	case false:
		Console = "Теплиця не жива.\n";
		break;
	}
	return Console;
}