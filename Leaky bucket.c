#include<stdio.h>
#define bucketsize 1000
#define n 5 
void bucketoutput(int *bucket,int op)
{
if(*bucket > 0 && *bucket > op) 
{
*bucket= *bucket-op; 
printf("\n%d-outputed remaining is %d",op,*bucket);
}
else if(*bucket > 0) 
{
printf("\n remaining data output = %d",*bucket);
*bucket=0;
}
}
int main()
{
int op,newpack,oldpack=0,wt,i,j,bucket=0; 

printf("enter output rate"); 
scanf("%d",&op);
for(i=1;i<=n;i++)
{
newpack=rand()%500; 

printf("\n\n new packet size = %d",newpack);
newpack=oldpack+newpack;
wt=rand()%5; 
if(newpack<bucketsize)
bucket=newpack;
else
{
printf("\n%d = the newpacket and old pack is greater than bucketsizereject",newpack);
bucket=oldpack;
}
printf("\nthe data in bucket = %d",bucket);
printf("\n the next packet will arrive after = %d sec",wt);

for(j=0;j<wt;j++)
{
bucketoutput(&bucket,op);
sleep(1);
}
oldpack=bucket;
}
while(bucket>0)
bucketoutput(&bucket,op);
return 0;
}