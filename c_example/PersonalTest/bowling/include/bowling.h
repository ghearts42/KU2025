#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql.h>

typedef struct
{
    char username[40];
    int bowlingScore;
    int date;
} user;

#define FRAME 11
#define TRY 2
#define PLAYER 2

void print_menu(void);
void waitEnter(void);
void frame();
void scoring();

void connect_to_db();
void create_table(MYSQL *conn);
void insert_score(const char *username, int score);
void display_scores();
void close_db();