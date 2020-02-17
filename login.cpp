#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Content-Type:text/html\n\n");
    printf("<html>\n");
    printf("<head>\n<title>xxx</title>\n</head>\n");
    printf("<body>\n");

    char *postStr;
    int len;
    char formStr[30];
    memset(formStr,0,sizeof(formStr));

    char *username;
    char *password;

    postStr=getenv("CONTENT-LENGTH");
    if(postStr==NULL){
        printf("Location: http://localhost:3000/one.html\n\n");
    }
    else{
        len = atoi(postStr);
        fgets(formStr,len+1,stdin);
        sscanf(formStr,"username=%[*&]&password=%[*&]",username,password);
        if(atoi(username)==111&&atoi(password)==222) 
        {
             printf("Location: http://localhost:3000/two.html\n\n");
        }


    }




    printf("</body>\n");
    printf("</html>\n");


    return 0;
}