#include "bowling.h"
#include <dotenv.h>

MYSQL *conn;
MYSQL_RES *res;
MYSQL_ROW row;

// MySQL 연결 설정
void connect_to_db()
{
    conn = mysql_init(NULL);
    if (conn == NULL)
    {
        fprintf(stderr, "초기화 실패.\n");
        exit(1);
    }

    if (mysql_real_connect(conn, "localhost", "myuser", "0000", "mydb", 3306, NULL, 0) == NULL)
    {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(conn);
        exit(1);
    }
    printf("MySQL 연결 성공\n");
}

// 테이블 생성 없을시
void create_table(MYSQL *conn)
{
    const char *create_table_query = "CREATE TABLE bowling_scores (username VARCHAR(40) NOT NULL, score INT NOT NULL, date TIMESTAMP);";

    if (mysql_query(conn, create_table_query))
    {
        fprintf(stderr, "테이블 생성 실패 : Error: %s\n", mysql_error(conn));
        exit(1);
    }
    else
    {
        printf("'bowling_scores'이미 존재합니다.\n");
    }
}

// 점수 입력 함수
void insert_score(const char *username, int score)
{
    char query[256];
    snprintf(query, sizeof(query), "INSERT INTO bowling_scores (username, score, date) VALUES ('%s', %d, CURDATE())", username, score);

    if (mysql_query(conn, query))
    {
        fprintf(stderr, "INSERT 실패: %s\n", mysql_error(conn));
    }
    else
    {
        printf("점수 입력 성공: %s - %d\n", username, score);
    }
}

// 점수 조회 함수
void display_scores()
{
    if (mysql_query(conn, "SELECT username, score, date FROM bowling_scores"))
    {
        fprintf(stderr, "SELECT 실패: %s\n", mysql_error(conn));
        return;
    }

    res = mysql_store_result(conn);
    if (res == NULL)
    {
        fprintf(stderr, "mysql_store_result() 실패: %s\n", mysql_error(conn));
        return;
    }

    int num_fields = mysql_num_fields(res);
    while ((row = mysql_fetch_row(res)))
    {
        for (int i = 0; i < num_fields; i++)
        {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }
}

void close_db()
{
    mysql_free_result(res);
    mysql_close(conn);
}
