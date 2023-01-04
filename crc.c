#include<stdio.h>
#include<string.h>
#define N strlen(g)
char t[28],cs[28],g[]="10001000000100001";
int a,i,j;
void xor()
{
    for(j=1;j<N;j++)
    cs[j]=((cs[j]==g[j])?'0':'1');
}
void crc()
{
    for(i=0;i<N;i++)
        cs[i]=t[i];
    do
    {
        if(cs[0]=='1')
            xor();
        for(j=0;j<N-1;j++)
        cs[j]=cs[j+1];
        cs[j]=t[i++];
    }while(i<=a+N-1);
}
int main()
{
    printf("enter the message\n");
    scanf("%s",t);
    printf(" generator polynomial %s",g);
    a=strlen(t);
    for(i=a;i<a+N-1;i++)
    t[i]='0';
    crc();
    printf("checksum is %s",cs);
    printf("after adding checksum with the message\n");
    
    for(i=a;i<a+N-1;i++)
    t[i]=cs[i-a];
    printf("final trasmitted %s",t);
    printf("enter the received message\n");
    scanf("%s",t);
    crc();
    for(i=0;i<N-1&&cs[i]!='1';i++);
    if(i<N-1)
    printf("error detected");
    else
    printf("no error");
    return 0;
}