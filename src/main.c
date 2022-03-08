#include <stdio.h>
#include "Date.h"

int main (void)
{
  printf("Enter the date in format yyyy-mm-dd\n");
  int year, month, day;
  scanf("%d-%d-%d", &year, &month, &day);
  printf("Number of days between dates: %lld\n", countDays(initDate(1970, 1, 1), initDate(year, month, day)));
  return 0;
}
