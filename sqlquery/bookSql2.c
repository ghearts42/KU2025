#include <stdio.h>
#include <string.h>
#include <mysql.h>

// sudo apt install libmysql++
// dpkg -L libmysqlclient -dev | grep mysql.h
// cc -o booksql bookSql.c -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient
// 오브젝트 명 : libmysqlclient.so || libmysqlclient.a

// typedef struct
// {
//     int bookid;
//     char bookname[40];
//     char publisher[40];
//     int price;
// } Book;

int main(void)
{
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *host = "localhost";
    char *user = "myuser";
    char *pass = "0000";
    char *db = "mydb";
    char query[255];
    int port = 3306;

    strcpy(query, "select * from Book");
    mysql_init(NULL);

    // 연결
    conn = mysql_init(NULL); // DB 연결 요청 준비
    if (mysql_real_connect(conn, host, user, pass, db, port, NULL, 0))
    {
        printf("MySQL 연결 성공\n");
    }
    else
    {
        printf("MySQL 연결 실패\n");
        return 1;
    }

    // 쿼리 요청
    if (mysql_query(conn, query))
    {
        printf("쿼리 실패");
        return 1;
    }
    res = mysql_store_result(conn);
    // Book book[100]; // 동적 할당 쓰는게 좋지만 일단 스택에 만듦.
    int i = 0;
    while (row = mysql_fetch_row(res))
    {
        printf("%s\t", row[0]);
        printf("%s\t", row[1]);
        printf("%s\t", row[2]);
        printf("%d\t\n", atoi(row[3]));
    };
    mysql_close(conn);

    return 0;
}