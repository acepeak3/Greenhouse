//Kasian N. K-12

#pragma once
using std::string;

class Greenhouse
{
public:

	Greenhouse();

	bool openTheWindow();
	bool closeTheWindow();
	bool onTheHeater();
	bool offTheHeater();
	bool greenhouseSelfChange();

	bool getGreenhouseCondition();

	string consoleOut();

	void endOfStep();

private:

	void changetemperature();
	void changehumidity();

	bool windowIsOpen;
	bool heaterIsOn;
	bool greenhouseIsAlive;
	double temperature;
	double humidity;
	int lifeTime;
	
	double currentTemperatureChange;
	double currentHumidityChange;

	const double minTemperature;
	const double maxTemperature;
	const double minHumidity;
	const double maxHumidity;

	string windowCondition();
	string heaterCondition();
	string greenhouseCondition();
};