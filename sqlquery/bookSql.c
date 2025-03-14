#include <stdio.h>
#include <string.h>
#include <mysql.h>

// sudo apt install libmysql++
// dpkg -L libmysqlclient -dev | grep mysql.h
// cc -o booksql bookSql.c -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient
// 오브젝트 명 : libmysqlclient.so || libmysqlclient.a

typedef struct
{
    int bookid;
    char bookname[40];
    char publisher[40];
    int price;
} Book; // 구조체

enum menu
{
    SELECT,
    INSERT,
    DROP,
    ALTER,
    QUERY,
    QUIT
};

void fetch_books(MYSQL *conn);
void add_books(MYSQL *conn);
void delete_books(MYSQL *conn);
void update_books(MYSQL *conn);
void query_books(MYSQL *conn);
void print_menu(void);
void waitEnter(void);

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
        print_menu();
        scanf("%d", &choice);
        switch (choice)
        {
        case SELECT:
            fetch_books(conn); // 조회
            break;
        case INSERT:
            add_books(conn); // 추가
            break;
        case DROP:
            delete_books(conn); // 삭제
            break;
        case ALTER:
            update_books(conn); // 변경
            break;
        case QUERY:
            query_books(conn);
            break;
        case QUIT:
            printf("프로그램 종료...");
            exit(0);
        }
    }
    mysql_close(conn);
    return 0;
}
// 메뉴 출력 함수
void print_menu(void)
{
    system("clear");
    printf("=== 도서 관리 시스템 ===\n");
    printf("0. 도서 조회\n");
    printf("1. 도서 추가\n");
    printf("2. 도서 삭제\n");
    printf("3. 도서 변경\n");
    printf("4. 쿼리문 입력\n");
    printf("5. 종료\n");
}

// 0. 도서 조회 함수
void fetch_books(MYSQL *conn)
{
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[255];
    int i = 0;

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

    Book *pBook; // 동적 할당 쓰는게 좋지만 일단 스택에 만듦.
    pBook = (Book *)malloc(sizeof(Book));

    while (row = mysql_fetch_row(res))
    {
        (pBook + i)->bookid = atoi(row[0]);
        strcpy((pBook + i)->bookname, row[1]);
        strcpy((pBook + i)->publisher, row[2]);
        (pBook + i)->price = atoi(row[3]);
        ++i;
        pBook = realloc(pBook, i + 1);
    };

    for (int j = 0; j < i; ++j)
    {
        printf("%d \t%s \t%s \t%d\n",
               (pBook + j)->bookid,
               (pBook + j)->bookname,
               (pBook + j)->publisher,
               (pBook + j)->price);
    }

    free(pBook);

    waitEnter();

    // TODO: 엔터만 쳐도 넘어가도록
    // int temp;
    // getchar();
    // scanf("%d%*s", &temp);
    return;
}

// 1. 도서 추가 함수
void add_books(MYSQL *conn)
{
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[255];
    Book newbook;

    printf("---도서 추가---\n");

    // 정보 입력 scanf;
    printf("도서 ID : ");
    scanf("%d", &newbook.bookid);
    printf("도서명 : ");
    scanf(" %s", newbook.bookname);
    printf("출판사 : ");
    scanf(" %s", newbook.publisher);
    printf("가격 : ");
    scanf("%d", &newbook.price);

    // printf("%d %s %s %d\n", newbook.bookid, newbook.bookname, newbook.publisher, newbook.price);

    // query문 작성 strcpy... "insert ..."

    sprintf(query, "insert into Book values (%d, '%s', '%s', %d)", newbook.bookid, newbook.bookname, newbook.publisher, newbook.price);

    if (mysql_query(conn, query))
    {
        printf("추가 실패 : %s\n", mysql_error(conn));
    }
    else
    {
        printf("성공\n");
    }

    void waitEnter();

    // int temp;
    // getchar();
    // scanf("%d%*s", &temp);
    return;
}

// 2. 도서 삭제 함수
void delete_books(MYSQL *conn)
{
    // index 번호 받기scanf
    // 지우는 쿼리
    char query[255];
    int bookid;

    printf("---도서 삭제---\n");

    // 정보 입력 scanf;
    printf("삭제할 도서 ID : ");
    scanf("%d", &bookid);

    sprintf(query, "delete from Book where bookid = %d", bookid);

    if (mysql_query(conn, query))
    {
        printf("삭제 실패 : %s\n", mysql_error(conn));
    }
    else
    {
        // TODO: 뭔지 알아보기
        my_ulonglong affected_row = mysql_affected_rows(conn);
        printf("삭제 성공 : %lu 개 항목을 삭제함\n", affected_row);
    }

    printf("엔터입력으로 종료...\n");
    char temp;
    scanf("%c%*c", &temp);

    // void waitEnter();

    // int temp;
    // getchar();
    // scanf("%d%*s", &temp);
    return;
}

// 3. 도서 변경 함수
void update_books(MYSQL *conn)
{
    // 모든 번호 받기scanf
    // 변경하는 쿼리
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[255];
    Book newbook;

    printf("---도서 변경---\n");

    // 정보 입력 scanf;
    printf("변경할 도서 ID : ");
    scanf("%d", &newbook.bookid);
    printf("도서명 변경 : ");
    scanf(" %s", newbook.bookname);
    printf("출판사 변경: ");
    scanf(" %s", newbook.publisher);
    printf("가격 변경: ");
    scanf("%d", &newbook.price);

    // printf("%d %s %s %d\n", newbook.bookid, newbook.bookname, newbook.publisher, newbook.price);

    // query문 작성 strcpy... "insert ..."

    sprintf(query, "UPDATE Book SET bookname='%s', publisher='%s', price='%d' WHERE bookid=%d;", newbook.bookname, newbook.publisher, newbook.price, newbook.bookid);

    if (mysql_query(conn, query))
    {
        printf("변경 실패 : %s\n", mysql_error(conn));
    }
    else
    {
        printf("변경 성공\n");
    }

    void waitEnter();

    // int temp;
    // getchar();
    // scanf("%d%*s", &temp); //%*s개행문자를 버림
    return;
}

// 4. 쿼리문 입력 함수
void query_books(MYSQL *conn)
{
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[255];
    printf("실행 쿼리 입력 : ");
    // fgetc(stdin);
    getchar();
    fgets(query, sizeof(query), stdin);

    if (mysql_query(conn, query))
    {
        printf("쿼리 실패, %s\n", mysql_error(conn));
        return;
    }
    res = mysql_store_result(conn);
    if (res)
    {
        while (row = mysql_fetch_row(res))
        {
            for (int i = 0; i < mysql_num_fields(res); ++i)
            {
                printf("%s\t", row[i]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("데이터 없음.");
    }

    printf("엔터입력으로 종료...\n");
    char temp;
    scanf("%c%*c", &temp);

    // void waitEnter();

    // int temp;
    // fgetc(stdin);
    // getchar();
    // scanf("%d%*s", &temp);
    return;
    // 쿼리 스트링을 받아서
    // 쿼리 요청
    // 결과 프린트
}

void waitEnter(void)
{
    printf("엔터입력으로 종료...\n");
    char temp;
    while (temp != '\n')
    {
        scanf("%c%*c", &temp);
    }
}