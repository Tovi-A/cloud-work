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
    mysql_query(&mysql, "create database mysql_test;");
    mysql_query(&mysql, "use mysql_test;");
    mysql_query(&mysql, "create table table_test (name CHAR(30), age INT);");
    //插入1000条数据
    for (int i = 0; i<1000; i++) {
        char name[30];
        char sql[100];
        sprintf(name, "zhangsan%d", i);
        sprintf(sql, "insert into table_test (name,age) values ('%s',%d);", name, i%10 + 10);
        mysql_query(&mysql, sql);
    }
    //string sqll = "drop table table_test;";
    //mysql_query(&mysql, sqll.c_str());
    mysql_close(&mysql);
    return 0;
}
