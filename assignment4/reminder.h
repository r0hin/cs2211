#ifndef REMINDER_H
#define REMINDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STR_LEN 100

struct Month{
	int month_days;
	int start_day;
    char reminder_str[31][MAX_STR_LEN]; 
	bool reminders[31]; 
};

extern struct Month November ; 

void insert_to_calendar(int day, const char* value) ;
int read_reminder(char *str, int n) ;
void print_calendar() ;

#endif