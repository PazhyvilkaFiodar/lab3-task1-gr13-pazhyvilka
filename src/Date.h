#ifndef DATE_H
#define DATE_H

struct Date {
  int year;
  int month;
  int day;
};

#endif

struct Date* initDate(int year, int month, int day);
long long countDays(struct Date* date1, struct Date* date2);