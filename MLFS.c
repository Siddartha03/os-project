#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    int bt[20],at[10],n,n2,n3,i,j,temp,p[10],st[10],ft[10],wt[10],ta[10],te[10];
    int totwt=0,totta=0;
    float awt,ata;
    char pn[10][10],t[10];
    //Level 1 code
    printf("Enter the number of process in Level 1:");
    scanf("%d",&n);n2=n;
    for(i=0; i<n; i++)
    {
		printf("Enter name of process : ");
 		scanf("%s",&pn[i]);
 		
		printf("Enter process %d Arrival time: ",i+1);
		scanf("%d",&at[i]);
		
		printf("Enter process %d burst time: ",i+1);
		scanf("%d",&bt[i]);

		printf("Enter process %d priority: ",i+1);
        scanf("%d",&p[i]);
    }
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
        {
            if(p[i]<p[j])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0; i<n; i++)
 
    {
 
        if(i==0)
        {
            st[i]=at[i];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+bt[i];
            ta[i]=ft[i]-at[i];
        }
        else
        {
            st[i]=ft[i-1];
            wt[i]=st[i]-at[i];
            ft[i]=st[i]+bt[i];
            ta[i]=ft[i]-at[i];
        }
        totwt+=wt[i];
    }
