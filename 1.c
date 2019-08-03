#include<stdio.h>
void main()
{
unsigned int m[5],n[5],p[5],i;
printf("Enter 5 values for m array : ");
for(i=0;i<5;i++)
scanf("%d",&m[i]);
printf("Enter 5 values for n array : ");
for(i=0;i<5;i++)
scanf("%d",&n[i]);
for(i=0;i<5;i++)
p[i]=m[i]+n[i];
printf("p array is : ");

for(i=0;i<5;i++)
printf("%d ",p[i]);
}
