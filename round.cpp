#include<stdio.h>
main()
{
int n;
printf("Enter the number of process\n");
scanf("%d",&n);
int ID[n],BT[n],WT[n],TAT[n],P[n],i,j,temp,t;
for(i=0;i<n;i++)
{
printf("Enter process %d id: ",i+1);
scanf("%d",&ID[i]);
printf("Enter process %d burst time: ",i+1);
scanf("%d",&BT[i]);
printf("Enter process %d priority: ",i+1);
scanf("%d",&P[i]);
}
printf("Enter the time quantum for round robin scheduling");
scanf("%d",&t);
for(int i=0;i<n;i++)
{
	if (BT[i]>t)
	{
		BT[i] = BT[i] - t;
	}
	else
	{ 
		BT[i] = 0;
	}
}
for(int i=0;i<n;i++)
{
	printf("new batch time of the processes is %d\n",BT[i]);
}
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(P[i]>P[j])
{
temp=P[i];
P[i]=P[j];
P[j]=temp;
temp=BT[i];
BT[i]=BT[j];
BT[j]=temp;
temp=ID[i];
ID[i]=ID[j];
ID[j]=temp;
}
}
WT[i]=0;
}
for(i=0;i<n;i++)
{
for(j=0;j<i;j++)
{
WT[i]=WT[i]+BT[j];
}
TAT[i]=WT[i]+BT[i];
}
float avwt=0,avtat=0;
printf("Process\t\tPriority\tBatch Time \tWaiting Time\tTurn Around Time\n");
for(i=0;i<n;i++)
{
printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\n",ID[i],P[i],BT[i],WT[i],TAT[i]);
avwt=avwt+WT[i];
avtat=avtat+TAT[i];
}
avwt=avwt/n;
avtat=avtat/n;
printf("Average Waiting Time: %f\n",avwt);
printf("\nAverage Turn-around Time: %f",avtat);
}
