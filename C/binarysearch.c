#include<stdio.h>
#include<conio.h>
int main()
{
	int i,a[20],n,high,low,mid,num,in,found=0;
	printf("Enter number >20 :");
	scanf("%d",&n);
	printf("Enter %d number in ascending order:\n",n);
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	printf("Enter number to search:",num);
	scanf("%d",&num);
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==num)
		{
			found=1;
			in=mid;
			break;
		}
		else if(num>a[mid])
		{
			low=mid+1;
		}
		else
		    high=mid-1;
	}
	if(found==1)
	printf("number found at index %d",in);
	else
	printf("number not found");
	
	getch();
}
