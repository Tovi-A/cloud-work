#include <iostream>                                                                                                             
#include <mysql/mysql.h>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    MYSQL mysql;
    mysql_init(&mysql);
    mysql_real_connect(&mysql, "mysql-0.glusterfs.default.svc.cluster.local", "root", "password", "mysql", 3306, NULL, 0);
    mysql_query(&mysql, "use mysql_test;");
    mysql_query(&mysql, "select * from table_test;");
    MYSQL_RES *result;
    MYSQL_FIELD *field;
    MYSQL_ROW row;
    result = mysql_store_result(&mysql);
    if (!result) {
        cout << "result error, line:" << __LINE__ <<endl;
        return 0;
    }
    int num;
    num = mysql_num_fields(result);     // 返回字段个数
    for (int i = 0; i<num; i++) {
        field = mysql_fetch_field_direct(result, i);    // 返回字段类型
        cout << field->name << "\t\t";      //输出字段名
    }
    cout <<endl;
    while (row = mysql_fetch_row(result), row) {
        for (int i = 0; i<num; i++) {
            cout << row[i] << "\t\t";
        }
        cout <<endl;
    }
    mysql_close(&mysql);
    return 0;
}
