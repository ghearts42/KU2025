#include <stdio.h>
#include <stdlib.h>
#include "/usr/include/mysql/mysql.h"

int main()
{
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    conn = mysql_init(NULL);

    if (conn == NULL)
    {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (mysql_real_connect(conn, "localhost", "root", "0000", "mydb", 0, NULL, 0) == NULL)
    {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(conn);
        exit(1);
    }

    printf("sql connected\n");

    const char *create_table_query =
        "CREATE TABLE IF NOT EXISTS test_data ("
        "id INT AUTO_INCREMENT PRIMARY KEY, "
        "temperture DECIMAL(5,2), "
        "fan_status BOOLEAN)";

    if (mysql_query(conn, create_table_query))
    {
        fprintf(stderr, "CREATE TABLE failed. ERROR: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    printf("Table Created Success.\n");

    mysql_close(conn);

    return 0;
}