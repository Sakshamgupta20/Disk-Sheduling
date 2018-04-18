#include<stdio.h>
#include <stdlib.h>

int cylinder;
int header;
int cheader;
int n;
int track_request[20];
bool inc[20];
int pre_req;
int seq[20];

void sstf();

int main()
{
	printf("Enter the size of cylinder: ");
	scanf("%d",&cylinder);
	printf("Enter the present header: ");
	scanf("%d",&header);
	cheader=header;
	printf("Enter the number of tracks: ");
	scanf("%d",&n);
	for(int i=0; i<n ; i++)
	{
	printf("Enter the %d track request for:",i+1);
	scanf("%d",&track_request[i]);
	
	inc[i]=false;
	}
	sstf();
	
}
void sstf()
{
	int sum=0;
	for(int i=0;i<n;i++)
	{
	int min=999;
	int index;
		for(int j=0;j<n;j++)
		{
			if(abs(cheader-track_request[j])<min && inc[j]==false)
			{
				min=abs(cheader-track_request[j]);
				index=j;
			}			
		}
		if(inc[index]==false)
		{
			seq[i]=index;
			inc[index]=true;
			sum=sum+min;
			cheader=track_request[index];
		}
	}
	printf("sum is %d\n",sum);
	for(int i =0;i<n; i++)
	{
		printf("--%d--",track_request[seq[i]]);
	}
	
}

