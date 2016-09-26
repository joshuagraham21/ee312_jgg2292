<<<<<<< HEAD
// assignment-2.c : Defines the entry point for the console application.
=======
// assignment2.c : Defines the entry point for the console application.
>>>>>>> 05da311890f29ae1b935d2d611deccd28880d6b7
//
#include <stdio.h>
#include "stdafx.h"
/*
Student Name: Graham, Joshua
UT EID: jgg2292
Unique Course Number: 16290
Assignment Number: EE312-Assignmnet-2
*/




int rounding(double deci)
{
	double frac;
	int whole = (int)(float)deci;
	frac = deci - whole;
	if (frac >= .5)
	{
		whole++;
	}
	return whole;
}


void time_austin_to_irish(void)
{
	const int TIME = 6;
	const int day = 24;
	int austin_hour, ireland_hour, austin_minutes, ireland_minutes, time;
	printf("\nEnter the Austin time to be converted, express in hours and minutes: ");
	scanf_s("%d %d", &austin_hour, &austin_minutes);
	ireland_hour = austin_hour + TIME;
	ireland_minutes = austin_minutes;
	if (ireland_hour >= day)
	{
		ireland_hour = ireland_hour - day;
		printf("\nThe time in Ireland equivalent to %d %d in Austin is %d %d of the next day ", austin_hour, austin_minutes, ireland_hour, ireland_minutes);
	}
	else if (ireland_hour < day)
	{
		printf("\nThe time in Ireland equivalent to %d %d in Austin is %d %d of the same day ", austin_hour, austin_minutes, ireland_hour, ireland_minutes);
	}
}
void time_irish_to_austin(void)
{
	const int TIME = 6;
	const int day = 24;
	int austin_hour, ireland_hour, austin_minutes, ireland_minutes;
	printf("\nEnter the Irish time to be converted, expressed in hours and minutes: ");
	scanf_s("%d %d", &ireland_hour, &ireland_minutes);
	austin_minutes = ireland_minutes;
	austin_hour = (ireland_hour - TIME);
	if (austin_hour < 0)
	{
		austin_hour = austin_hour + day;
		printf("\nThe time in Austin equivalent to %d %d in Ireland is %d %d of the previous day ", ireland_hour, ireland_minutes, austin_hour, austin_minutes);
	}
	else
	{
		printf("\nThe time in Austin equivalent to %d %d in Ireland is %d %d of the same day ", ireland_hour, ireland_minutes, austin_hour, austin_minutes);
	}
}

void usd_to_eur(void)
{
	const double TOEUROS = .89;
	const double hundred = 100;
	int discrete_dollars, discrete_cents;
	double euros, dollars, cents;
	printf("\nEnter USD value: ");
	scanf_s("%d %d", &discrete_dollars, &discrete_cents);
	dollars = (double)discrete_dollars;
	cents = discrete_cents / hundred;
	dollars += cents;
	euros *= TOEUROS;
	printf("\nEUR value is: %lf Euros ", dollars);
}

void eur_to_usd(void)
{
	const double TODOLLARS = 1.13;
	const double hundred = 100;
	double eur, real_dollars, real_cents, frac;
	int dollars, cents, dummy;
	printf("\nEnter EUR value: ");
	scanf_s("%lf", &eur);
	real_dollars = (double)(eur * TODOLLARS);
	dollars = (int)(float)(real_dollars);
	real_cents = (real_dollars - dollars) * hundred;
	cents = rounding(real_cents);
	printf("\nUSD value is: $%d %d ", dollars, cents);
}

void fahr_to_cels(void)
{
	const double TOCELS = .555555555555555555555555555555555555555555;
	int fahr;
	const int OFFSET = 32;
	double celsius;
	printf("\nEnter temperature in Fahrenheit: ");
	scanf_s("%d", &fahr);
	celsius = (double)((TOCELS)*((double)fahr - OFFSET));
	printf("\nTemperature in celsius is: %lf ", celsius);
}

void cels_to_fahr(void)
{
	const double TOFAHR = 1.8;
	int fahr;
	const int OFFSET = 32;
	double celsius, real_fahr;
	printf("\nEnter temperature in celsius: ");
	scanf_s("%lf", &celsius);
	printf("%lf", celsius);
	real_fahr = (double)((celsius*(TOFAHR)) + OFFSET);
	fahr = rounding(real_fahr);
	printf("\nTemperature in fahrenheit is: %d ", fahr);
}

void kg_to_lbs(void)
{
	const double GRAMS = 453.59237;
	const int OUNCES = 16;
	const double GRAND = 1000;
	double kg, lbs_real, oz_real;
	int lbs, oz;
	printf("\nEnter weight in kg: ");
	scanf_s("%lf", &kg);
	lbs_real = (kg * GRAND) / GRAMS;
	lbs = (int)(float)lbs_real;
	oz_real = (lbs_real - lbs) * OUNCES;
	oz = rounding(oz_real);
	printf("\nWeight in pounds and ounces is: %d lb %d oz ", lbs, oz);
}

void lbs_to_kg(void)
{
	const double WEIGHT = 453.59237;
	const int OUNCES = 16;
	const double GRAND = 1000;
	double kg, lbs_real, oz_real;
	int lbs, oz;
	printf("\nEnter weight in pounds and ounces: ");
	scanf_s("%d %d", &lbs, &oz);
	oz_real = ((double)oz) / OUNCES;
	lbs_real = lbs + oz_real;
	kg = (lbs_real*WEIGHT) / GRAND;
	printf("\nWeight in kilograms is: %lf ", kg);
}

void km_to_mi(void)
{
	const double DISTANCE = .6213712;
	double miles, km;
	printf("\nEnter distance in km: ");
	scanf_s("%lf", &km);
	miles = km * DISTANCE;
	printf("\nDistance in miles: %lf ", miles);
}

void mi_to_km(void)
{
	const double DISTANCE = .6213712;
	double miles, km;
	printf("\nEnter distance in miles: ");
	scanf_s("%lf", &miles);
	km = miles / DISTANCE;
	printf("\nDisstance in kilometers: %lf ", km);
}

int main(void)
{
	int input_num = 0;
	printf("\nEnter a number from the menu (1-11) to perform a specific conversion or to quit:");
	while (input_num != 11)
	{
		scanf_s("%d", &input_num);
		if (input_num == 1)
		{
			time_austin_to_irish();
		}
		else if (input_num == 2)
		{
			time_irish_to_austin();
		}
		else if (input_num == 3)
		{
			usd_to_eur();
		}
		else if (input_num == 4)
		{
			eur_to_usd();
		}
		else if (input_num == 5)
		{
			fahr_to_cels();
		}
		else if (input_num == 6)
		{
			cels_to_fahr();
		}
		else if (input_num == 7)
		{
			kg_to_lbs();
		}
		else if (input_num == 8)
		{
			lbs_to_kg();
		}
		else if (input_num == 9)
		{
			km_to_mi();
		}
		else if (input_num == 10)
		{
			mi_to_km();
		}
	}
	printf("\nGood Bye");
	return 0;
}
