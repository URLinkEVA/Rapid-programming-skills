// 数据库中新建一个名为“stu”的表，表的内容包括编号、姓名、年龄

#include<stdlib.h>
#include<stdio.h>
#include<mysql/mysql.h>

MYSQL *conn_ptr;
MYSQL_RES *res_ptr;
MYSQL_ROW sqlrow;
unsigned int timeout = 7;	//超时时间7秒

void dispaly_row(MYSQL *ptr)
{
	unsigned int field_count = 0;
	while(field_count<mysql_field_count(ptr))
	{
		printf("%s",sqlrow[field_count]);
		field_count++;
	}
	printf("\n");
}
void display_header()
{
	MYSQL_FIELD *field_ptr;
	printf("Column details:\n");
	while((field_ptr = mysql_fetch_field(res_ptr))!= NULL)//返回列的定义字段信息
	{
		printf("\t Name:%s\n",field_ptr->name);
		printf("\t Type:");
		if(IS_NUM(field_ptr->type))//若字段类型为数字
		{
			printf("Numeric field\n");
		}
		else
		{
			switch(field_ptr->type)
			{
				case FIELD_TYPE_VAR_STRING:
					printf("VACHAR\n");
					break;
				case FIELD_TYPE_LONG:
					printf("LONG\n");
					break;
				default:
					printf("Type is %d,check in mysql_com.h\n",field_ptr->type);
			}
		}
		printf("\t Max width %ld \n",field_ptr->length);
		if(field_ptr->flags & AUTO_INCREMENT_FLAG)
			printf("\t Auto increments\n");
		printf("\n");
	}
}
int main(){	
int ret = 0;	
int first_row = 1;	
conn_ptr = mysql_init(NULL);
for(!conn_ptr)
{		
    printf("mysql_init failed!\n");		
    return -1;	}
    conn_ptr = mysql_real_connect(conn_ptr,"localhost","root","aabbcc","testdb",0,NULL,0);
    if(conn_ptr)	
    {
        printf("Connection Succeed!\n");		
	    ret = mysql_query(conn_ptr,"SELECT childno,fname,age FROM stu WHERE age > 5"); 	
        if(!ret)	
	    {   	
            res_ptr = mysql_use_result(conn_ptr);			
		    if(res_ptr)	
		    {	
                display_header();						
                printf("Retrieved %lu rows\n",(unsigned long)mysql_num_rows(res_ptr));			
                while((sqlrow = mysql_fetch_row(res_ptr)))	
			    {
                    dispaly_row(conn_ptr);	
                }				
            }			
		    if(mysql_errno(conn_ptr)) 
		    {
                printf("Connect Erro:%d %s\n", mysql_errno(conn_ptr), 					
                mysql_error(conn_ptr)); 
                return -2;
		    }			
		    mysql_free_result(res_ptr);		
	    }
        else		
	    {
	        printf("Connect Erro:%d %s\n",mysql_errno(conn_ptr),mysql_error(conn_ptr));	
            return -3;		
	    }		
	    mysql_close(conn_ptr);		
	    printf("Connection closed!\n");	
    }	
    else		
    {		
        printf("Connection Failed!\n");		
        If(mysql_errno(conn_ptr))		
        {			
             printf(“Connect Erro:%d %s\n”,mysql_errno(conn_ptr),mysql_error(conn_ptr));		
        }		
        return -2;	
    }	
    return 0;
}
