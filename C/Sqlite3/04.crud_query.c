#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
    NotUsed = 0;
    for(int i = 0; i < argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

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
    } else {
        fprintf(stdout, "데이터베이스 성공적으로 열림\n");
    }

    //테이블이 있으면 삭제
    sql = "DROP TABLE IF EXISTS STUDENT;";
    sqlite3_exec(db, sql, 0, 0, &errMsg);

    // 테이블 생성 SQL
    sql = "CREATE TABLE IF NOT EXISTS STUDENT("
          "ID INT PRIMARY KEY NOT NULL,"
          "NAME TEXT NOT NULL,"
          "PNUMBER TEXT NOT NULL);";

    // 테이블 생성
    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "테이블 생성 성공\n");
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

    // 데이터 조회 SQL
    sql = "SELECT * FROM STUDENT;";

    // 데이터 조회
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "데이터 조회 중 SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "데이터 조회 성공\n");
    }

    // 데이터베이스 닫기
    sqlite3_close(db);

    return 0;
}
