#include <stdio.h>
#define MAX_DESCRIPTION_LENGTH 100
#define MAX_DAY_NAME_LENGTH 20
struct Day {
 char dayName[MAX_DAY_NAME_LENGTH];
 int date;
 char activityDescription[MAX_DESCRIPTION_LENGTH];
};
struct Day weekCalendar[7];
void read() {
 for (int i = 0; i < 7; ++i) {
 printf("Enter day name for day %d: ", i + 1);
 scanf("%s", weekCalendar[i].dayName);
 printf("Enter date for day %d: ", i + 1);
 scanf("%d", &weekCalendar[i].date);
 printf("Enter activity description for day %d: ", i + 1);
 scanf(" %s", weekCalendar[i].activityDescription);
 }
}
void display() {
 printf("\n--- Calendar ---\n");
 for (int i = 0; i < 7; ++i) {
 printf("Day %d: %s, Date: %d, Activity: %s\n", i + 1, weekCalendar[i].dayName, 
weekCalendar[i].date, weekCalendar[i].activityDescription);
 }
}
int main() {
 printf("Enter details for each day of the week:\n");
 read();
 display();
 return 0;
}
