#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

#define NUMMOVIE 3
#define NUMVOTER 0

struct Person{
	int id;
	char name[15];
};

struct Movie{
	int id;
	char name[15];
	char description[20];
	char genre[10];
	int rating;
	char directors[10];
	char actors[10];
	char language[10];
	char countryOfOrigin[10];
	int score;
};

struct Poll{
	int id;
	char name[15];
	char description[20];
	int startDate;
	int endDate;
	struct Movie MovieList[NUMMOVIE];
	struct Person Voter[NUMVOTER];
	struct Poll *next;
};


struct Poll *head = NULL;
struct Poll *current = NULL;

void menu();
void createNewPoll();
int printPoll();
int viewMoviesForPoll(int);
void castVote(int, int);
void viewResult();

#endif
