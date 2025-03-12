#include <stdio.h>
#include <string.h>
#include <mysql.h>

// sudo apt install libmysql++
// dpkg -L libmysqlclient -dev | grep mysql.h
// cc -o booksql bookSql.c -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient
// 오브젝트 명 : libmysqlclient.so || libmysqlclient.a

void fetch_books(MYSQL *conn);
void add_books(MYSQL *conn);

typedef struct
{
    int bookid;
    char bookname[40];
    char publisher[40];
    int price;
} Book;

int main(void)
{
    MYSQL *conn;
    char *host = "localhost";
    char *user = "myuser";
    char *pass = "0000";
    char *db = "mydb";
    int port = 3306;
    int choice;

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
    // 쿼리 요청 및 출력 함수
    while (true)
    {
        printf("1. 출력\n2. 추가\n3. 종료\n골라 : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            fetch_books(conn);
            break;
        case 2:
            add_books(conn);
            break;
        }
        if (choice == 3)
        {
            break;
        }
    }

    mysql_close(conn);
    return 0;
}

// 쿼리 요청 함수
void fetch_books(MYSQL *conn)
{
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[255];
    strcpy(query, "select * from Book");
    if (mysql_query(conn, query)) // C에서는 T=1, F=0를 반환하지만 MySQL은 반대로 T = 0, F = 이외의 값을 반환함. 즉 쿼리문이 성공하면 if문이 0을 반환해 건너뛰고 반대는 반대로함
    {
        printf("쿼리 실패\n");
        return;
    }
    res = mysql_store_result(conn);

    if (!res)
    {
        printf("가져오기 실패\n");
        return;
    }

    Book book[100]; // 동적 할당 쓰는게 좋지만 일단 스택에 만듦.
    int i = 0;
    while (row = mysql_fetch_row(res))
    {
        book[i].bookid = atoi(row[0]);
        strcpy(book[i].bookname, row[1]);
        strcpy(book[i].publisher, row[2]);
        book[i].price = atoi(row[3]);
        ++i;
    };
    for (int j = 0; j < i; ++j)
    {
        printf("%d \t%s \t%s \t%d\n",
               book[j].bookid,
               book[j].bookname,
               book[j].publisher,
               book[j].price);
    }
    return;
}

void add_books(MYSQL *conn)
{
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[255];
    Book newbook;

    printf("---도서 추가---\n");

    // 정보 입력 scanf;
    scanf("%d", &newbook.bookid);
    scanf(" %s", newbook.bookname);
    scanf(" %s", newbook.publisher);
    scanf("%d", &newbook.price);

    // query문 작성 strcpy... "insert ..."
    printf("%d %s %s %d\n", newbook.bookid, newbook.bookname, newbook.publisher, newbook.price);

    sprintf(query, "insert into Book values (%d, '%s', '%s', %d)", newbook.bookid, newbook.bookname, newbook.publisher, newbook.price);

    if (mysql_query(conn, query))
    {
        printf("추가 실패");
    }
    else
    {
        printf("성공");
    }

    return;
}