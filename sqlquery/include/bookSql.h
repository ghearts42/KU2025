#pragma once

#include <stdio.h>
#include <string.h>
#include <mysql.h>

// sudo apt install libmysql++
// dpkg -L libmysqlclient -dev | grep mysql.h
// cc -o booksql bookSql.c -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient
// 오브젝트 명 : libmysqlclient.so || libmysqlclient.a

void fetch_books(MYSQL *conn);
void add_books(MYSQL *conn);
void delete_books(MYSQL *conn);
void update_books(MYSQL *conn);
void query_books(MYSQL *conn);
void print_menu(void);
void waitEnter(void);