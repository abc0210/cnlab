#include <stdio.h>
#include <stdlib.h>
#define RTT 4
#define TIMEOUT 4
#define TOT_FRAMES 7
enum {NO,YES} ACK;
int main()
{
int wait_time,i=1;
ACK=YES;
for(;i<=TOT_FRAMES;)
{
if (ACK==YES && i!=1)
{
printf("\nSENDER: ACK for Frame %d Received.\n",i-1);
}
printf("\nSENDER: Frame %d sent, Waiting for ACK...\n",i);
ACK=NO;
wait_time= rand() % 4+1;
if (wait_time==TIMEOUT)
{
    printf("SENDER: ACK not received for Frame %d=>TIMEOUT Resending Frame...",i);

}
else
{
    sleep(RTT);
printf("\nRECEIVER: Frame %d received, ACK sent\n",i);
printf(" ");
ACK=YES;
i++;
}
}
return 0;
}