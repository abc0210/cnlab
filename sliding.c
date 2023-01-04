#include <stdio.h>
#include <stdlib.h>
#define RTT 5
int main()
{
int window_size,i,f,frames[50];
printf("Enter window size: ");
scanf("%d",&window_size);
printf("\nEnter number of frames to transmit: ");
scanf("%d",&f);
printf("\nEnter %d frames: ",f);
for(i=1;i<=f;i++)
scanf("%d",&frames[i]);
printf("\nAfter sending %d frames at each stage sender waitsfor ACK",window_size);
printf("\nSending frames in the following manner....\n\n");
for(i=1;i<=f;i++)
{
if(i%window_size!=0)
{
    printf(" %d",frames[i]);

}
else
{
    printf(" %d\n",frames[i]);
printf("SENDER: waiting for ACK...\n\n");
sleep(RTT/2);
printf("RECEIVER: Frames Received, ACK Sent\n");
printf(" \n");
sleep(RTT/2);
printf("SENDER:ACK received, sending next frames\n");
}
}

if(f%window_size!=0)
{
printf("\nSENDER: waiting for ACK...\n");
sleep(RTT/2);
printf("\nRECEIVER:Frames Received, ACK Sent\n");
printf(" \n");
sleep(RTT/2);
printf("SENDER:ACK received.");
}
return 0;
}