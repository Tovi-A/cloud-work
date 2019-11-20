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
    // 删除数据表
    mysql_query(&mysql, "drop table table_test;");
    // 删除数据库
    mysql_query(&mysql, "drop database mysql_test;");
    mysql_close(&mysql);
    return 0;
}
