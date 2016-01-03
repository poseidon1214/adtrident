#!/bin/bash

HOSTNAME="127.0.0.1"
PORT="3306"
USERNAME="root"
PASSWORD="111111"

DBNAME="adtrident_data"
FILEPATH="/data/my_baidu_rpc/public/rtb/data/addict/"

TABLENAME="user"
rm ${FILEPATH}${TABLENAME}_info
export_db_sql="select * into outfile '${FILEPATH}${TABLENAME}_info' CHARACTER SET gbk from ${TABLENAME}"
mysql -h${HOSTNAME}  -P${PORT}  -u${USERNAME} -p${PASSWORD} ${DBNAME} -e "${export_db_sql}"

TABLENAME="idea"
rm ${FILEPATH}${TABLENAME}_info
export_db_sql="select * into outfile '${FILEPATH}${TABLENAME}_info' CHARACTER SET gbk from ${TABLENAME}"
mysql -h${HOSTNAME}  -P${PORT}  -u${USERNAME} -p${PASSWORD} ${DBNAME} -e "${export_db_sql}"

TABLENAME="plan"
rm ${FILEPATH}${TABLENAME}_info
export_db_sql="select * into outfile '${FILEPATH}${TABLENAME}_info' CHARACTER SET gbk from ${TABLENAME}"
mysql -h${HOSTNAME}  -P${PORT}  -u${USERNAME} -p${PASSWORD} ${DBNAME} -e "${export_db_sql}"

TABLENAME="site"
rm ${FILEPATH}${TABLENAME}_info
export_db_sql="select * into outfile '${FILEPATH}${TABLENAME}_info' CHARACTER SET gbk from ${TABLENAME}"
mysql -h${HOSTNAME}  -P${PORT}  -u${USERNAME} -p${PASSWORD} ${DBNAME} -e "${export_db_sql}"

TABLENAME="unit"
rm ${FILEPATH}${TABLENAME}_info
export_db_sql="select * into outfile '${FILEPATH}${TABLENAME}_info' CHARACTER SET gbk from ${TABLENAME}"
mysql -h${HOSTNAME}  -P${PORT}  -u${USERNAME} -p${PASSWORD} ${DBNAME} -e "${export_db_sql}"
