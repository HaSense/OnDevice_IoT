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
    }

    // 데이터 조회 SQL
    sql = "SELECT * FROM STUDENT;";

    // 데이터 조회
    rc = sqlite3_exec(db, sql, callback, 0, &errMsg);
    if(rc != SQLITE_OK) {
        fprintf(stderr, "데이터 조회 중 SQL error: %s\n", errMsg
