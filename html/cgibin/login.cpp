#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    printf("Content-Type:text/html\n\n");
    printf("<html>\n");
    printf("<head>\n<title>xxx</title>\n</head>\n");
    printf("<body>\n");

    char *postStr;
    int len;
    char formStr[50];
    memset(formStr,0,sizeof(formStr));
    //char formStr[50]="username=111&password=222";

    char username[20];
    char password[20]; //定义char *password,则sscanf出错

    postStr=getenv("CONTENT_LENGTH");
    //postStr=getenv("QUERY_STRING");
    if(postStr==NULL)
    {
        printf("Location: http://localhost:3000/one.html\n\n");
    }
    else
    {
        len = atoi(postStr);
        fgets(formStr,len+1,stdin);
        sscanf(formStr,"username=%[^&]&password=%s",username,password);
        
        if(memcmp(username,"111",3)==0 && memcmp(password,"222",3)==0) 
        {
            printf("<p>username is %d</p>\n",atoi(username));
            printf("Location: http://localhost:3000/two.html\n\n");

            printf("<script language=\"javascript\" type=\"text/javascript\" > \n");
            printf("window.location.href=\"http://localhost:3000/two.html\" ");   //跳转页面
            printf("</script>\n");
        }
        else{
            printf("Location: http://localhost:3000/three.html\n\n");

        }
    }

    printf("</body>\n");
    printf("</html>\n");


    return 0;
}