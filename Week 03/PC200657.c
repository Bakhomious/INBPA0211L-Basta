#include <stdio.h>
#include <stdlib.h>

int which_day(int year, int month, int day) {

    switch (month)
    {
    case 12:
        day += 30;
    case 11:
        day += 31;
    case 10:
        day += 30;
    case 9:
        day += 31;
    case 8:
        day += 31;
    case 7:
        day += 30;
    case 6:
        day += 31;
    case 5:
        day += 30;
    case 4:
        day += 31;
    case 3:
        day += (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 29 : 28;
    case 2:
        day += 31;
    /*case 1:
        day += 0;*/
    }

    return day;
}

int next_arrival(int year, int month, int day) {

    int day_of_today = which_day(year, month, day);

    if(month == 12 && day > 6)
    {
        int day_of_santa = which_day(year + 1, 12, 6);
        return 31 - day + day_of_santa;
    }
    else
    {
        int day_of_santa = which_day(year, 12, 6);
        return day_of_santa - day_of_today;
    }
}


int main() {
    int year, month, day;
    int next_arrival(int, int, int);
    while (scanf("%d %d %d", &year, &month, &day) != EOF)
    {
        int res = next_arrival(year, month, day);
        printf("%d\n", res);
    }
    return EXIT_SUCCESS;
}

