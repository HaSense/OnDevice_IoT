#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

int main() {
    sqlite3 *db;
    char *errMsg = 0;
    int rc;
    const char *sql;

    // 데이터베이스 열기
    rc = sqlite3_open("st1.db", &db);
    if(rc) {
        fprintf(stderr, "데이터베이스 열기 실패: %s\n", sqlite3_errmsg(db));
        return(0);
    }

    // 데이터 삽입 SQL
    sql = "INSERT INTO STUDENT (ID, NAME, PNUMBER) "
          "VALUES (1, '홍길동', '010-1111-1111');";

    // 데이터 삽입
    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "데이터 삽입 중 SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "데이터 삽입 성공\n");
    }

    // 데이터베이스 닫기
    sqlite3_close(db);

    return 0;
}
