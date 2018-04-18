#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void scan();
void look();
void c_scan();
void clook();
int cylinder,header,he,pre_request,*track_request,*current_header,request;
int main()
{

	printf("\nEnter the number of track requests: ");
	scanf("%d",&request);
	
	printf("\nEnter the number of total number of cylinders: ");
	scanf("%d",&cylinder);
	
	track_request=(int*)malloc(sizeof(int)*request);
	current_header=(int*)malloc(sizeof(int)*request);
	
	printf("\nplease enter the Track Request: ");
		for(int i=0;i<request;i++)
	{
		printf("\nTrack Request[%d]:- ",i);
	    scanf("%d",&track_request[i]);
	}
	
	for(int i=0;i<request;i++)
	{
		for(int j=0;j<request;j++)
		{
			if(track_request[i]<track_request[j])
			{
				int t=track_request[i];
				track_request[i]=track_request[j];
				track_request[j]=t;
			}
		}
	}

  printf("\nEnter the header: ");
  scanf("%d",&header);
  
  printf("\nEnter the Pre Request: ");
  scanf("%d",&pre_request);
  
  
  for(int i=0;i<request;i++)
  {
  	if(header >= track_request[i] && header < track_request[i+1])
  	{
  		 he=i;
  	}
  }
  
  
   printf("After Sorting");
   
   for(int i=0;i<request;i++)
   {
   	printf("\n %d",track_request[i]);
   }
   
   scan();
   look();
   c_scan();
   clook();
   return 0;
}

void scan()
{
printf("\n\n   SCAN   :-");
	int k=1;
	current_header[0]=header;
	if(header >= pre_request)
	{


		for(int i=he+1;i<request;i++)
		{
			current_header[k]=track_request[i];
			k++;
			if(i==request-1)
			{
				current_header[k]=cylinder-1;
				
				k++;
				break;
			}
		}
		for(int i=he;i>=0;i--)
		{
			current_header[k]=track_request[i];
			k++;
		}
	}
    
    else
    {
    	
    		for(int i=he;i>=0;i--)
		{
			current_header[k]=track_request[i];
			k++;
			if(i==0)
			{
				current_header[k]=0;
				k++;
				break;
			}
		}
        for(int i=he+1;i<request;i++)
		{
			current_header[k]=track_request[i];
			k++;
		}
		
    }
    
    printf("\n the sequence is:- ");
    for(int i=0;i<= request+1;i++)
    {
    	printf("%d ->",current_header[i]);
    }
    int seek_time=0;
    
    for(int i=0;i<request+1;i++)
    {
    	seek_time+=abs(current_header[i]-current_header[i+1]);
    	
    }
    printf("\nseek time - %d",seek_time);
}
void look()
{

printf("\n\n   look  :-");
int k=1;
current_header[0]=header;
	if(header >= pre_request)
	{
	
		for(int i=he+1;i<request;i++)
		{
			current_header[k]=track_request[i];
			k++;
		
		}
		for(int i=he;i>=0;i--)
		{
			current_header[k]=track_request[i];
			k++;
		}
	}
    
    else
    {
    	int k=0;
    		for(int i=he;i>=0;i--)
		{
			current_header[k]=track_request[i];
			k++;
			
		}
        for(int i=he+1;i<request;i++)
		{
			current_header[k]=track_request[i];
			k++;
		}
		
    }
    
    printf("\n the sequence is:- ");
  
    for(int i=0;i<request;i++)
    {
    	
    	printf("%d ->",current_header[i]);
    }
    int seek_time=0;
    
    for(int i=0;i<request;i++)
    {
    	seek_time+=abs(current_header[i]-current_header[i+1]);
    	
    }
    printf("\nseek time - %d",seek_time);

}
void c_scan()
{
	
printf("\n\n   C-SCAN   :-");
int k=1;
current_header[0]=header;
	if(header >= pre_request)
	{

	
		for(int i=he+1;i<request;i++)
		{
			current_header[k]=track_request[i];
			k++;
			if(i==request-1)
			{
				current_header[k]=cylinder-1;
				k++;
				break;
			}
		}
		
		for(int i=0;i<=he;i++)
		{
			current_header[k]=track_request[i];
			k++;
		}
	}
    
    else
    {
    	
    		for(int i=he;i>=0;i--)
		{
			current_header[k]=track_request[i];
			k++;
			if(i==0)
			{
				current_header[k]=0;
				k++;
				break;
			}
		}
        for(int i=request-1;i>=he;i++)
		{
			current_header[k]=track_request[i];
			k++;
		}
		
    }
    
    printf("\n the sequence is:- ");

    for(int i=0;i<request;i++)
    {
    	
    	printf("%d ->",current_header[i]);
    }
    int seek_time=0;
    
    for(int i=0;i<request+1;i++)
    {
    	seek_time+=abs(current_header[i]-current_header[i+1]);
    	
    }
    printf("\nseek time - %d",seek_time);

}
void clook()
{

printf("\n\n  c-look  :-");
int k=1;
current_header[0]=header;
	if(header >= pre_request)
	{
	
		for(int i=he+1;i<request;i++)
		{
			current_header[k]=track_request[i];
			k++;
		
		}
		for(int i=0;i<=he;i++)
		{
			current_header[k]=track_request[i];
			k++;
		}
	}
    
    else
    {
    	int k=0;
    		for(int i=he;i>=0;i--)
		{
			current_header[k]=track_request[i];
			k++;
			
		}
        for(int i=request-1;i>he;i--)
		{
			current_header[k]=track_request[i];
			k++;
		}
		
    }
    
    printf("\n the sequence is:- ");
  
    for(int i=0;i<request;i++)
    {
    	
    	printf("%d ->",current_header[i]);
    }
    int seek_time=0;
    
    for(int i=0;i<request;i++)
    {
    	seek_time+=abs(current_header[i]-current_header[i+1]);
    	
    }
    printf("\nseek time - %d",seek_time);

}
