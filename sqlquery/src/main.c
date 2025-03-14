

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