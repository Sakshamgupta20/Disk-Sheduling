#include<stdio.h>
int main()
{
	int track_request[100];
	int sequence[100];
	int sum=0;
	int head,locations;
	int i;
	printf("Enter the Number of Locations\n");
	scanf("%d",&locations);
	
	printf("\nEnter the Head Value\n");
	scanf("%d",&head);
	int a=head;
	printf("\nEnter Disc Queue\n");
	
	for(i=0;i<locations;i++)
	{
		scanf("%d",&track_request[i]);
		sequence[i]=head-track_request[i];
		if(sequence[i]<0)
		{
			sequence[i]=track_request[i]-head;
		}
		head=track_request[i];
 sum=sum+sequence[i];
 }
 printf("\n********The Seek Order is********\n");
for(i=0;i<locations;i++)
	{
		if(i==locations-1)
		{
			printf("%d",track_request[i]);
		}
		else
		{
			printf("%d->",track_request[i]);
		}
	}
printf("\n********Movement of total cylinders********\n");	
 printf("%d",sum);
}

