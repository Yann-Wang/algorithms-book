#include<stdio.h>

int leapYear(int year) {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				return 0;
			}
		}
		else {
			return 0;
		}
	}

	return 1;
}

void main() {
	int time, t;
	int leapYearSeconds, nonLeapYearSeconds;
	int year = 1970;
	int month = 0;
	int monthArray[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = 0;
	scanf_s("%d", &time);

	leapYearSeconds = 3600 * 24 * 366;
	nonLeapYearSeconds = 3600 * 24 * 365;

	t = time;
	while (1) {
		if (leapYear(year) == 0) {
			if (t >= leapYearSeconds) {
				t = t - leapYearSeconds;
				++year;
			}
			else {
				break;
			}
		}
		else if (t >= nonLeapYearSeconds) {
			t = t - nonLeapYearSeconds;
			++year;
		}
		else {
			break;
		}


	}

	if (leapYear(year) == 0) {
		monthArray[1] = 29;
	}

	while (1) {
		if (t >= monthArray[month] * 86400) {
			t = t - monthArray[month] * 86400;
			++month;
		}
		else
			break;
	}

	while (1) {
		if (t >= 86400) {
			t = t - 86400;
			++day;
		}
		else
			break;
	}



	printf("%d %d %d\n", year, month + 1, day + 1);
}

// input: 1475 051171
// output: 2016 09 28
