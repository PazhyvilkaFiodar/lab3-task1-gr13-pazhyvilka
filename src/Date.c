#include "Date.h"
#include <stdlib.h>
#include <stdio.h>

struct Date* initDate(int year, int month, int day){
  struct Date* date = (struct Date*)malloc(sizeof(struct Date));
  date->year = year;
  date->month = month;
  date->day = day;
  return date;
}

void checkLeapYear(int year, long long* count) {
  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    (*count) += 1;
}

void countYears(struct Date* date1, struct Date* date2, long long* count) {
  for (int year = date1->year + 1; year < date2->year; ++year) {
    (*count) += 365;
    checkLeapYear(year, count);
  }
}

void countMonths(struct Date* date1, struct Date* date2, long long* count) {
  const long long numberPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  int lastMonth = date1->year == date2->year ? date2->month : 13;
  for (int month = date1->month + 1; month < lastMonth; ++month){
    (*count) += numberPerMonth[month - 1];
    checkLeapYear(date1->year, count);
  }
  if (date1->year != date2->year)
    for (int month = 1; month < date2->month; ++month) {
      (*count) += numberPerMonth[month - 1];
      checkLeapYear(date2->year, count);
    }
}

long long countDays(struct Date* date1, struct Date* date2) {
  long long count = 0;
  const int numberPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  
  countYears(date1, date2, &count);
  countMonths(date1, date2, &count);
  if (date1->year == date2->year && date1->month == date2->month)
    count = date2->day - date1->day;
  else
    count += numberPerMonth[date1->month - 1] - date1->day + date2->day;

  return count;
}