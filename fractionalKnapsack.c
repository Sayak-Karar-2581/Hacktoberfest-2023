//FRACTIONAL KNAPSACK ALGORITHM

#include <stdio.h>
#include <stdlib.h>

//structure to store the weight and price of the item
typedef struct Item
{
	double w;
	double v;
	double vw;
}it;

//utility function to merge the divided array
void merge(it *arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m+1-l;
	int n2 = r-m;
	it left[n1], right[n2];
	for(i=0; i<n1; i++)
		left[i] = arr[l+i];
	for(j=0; j<n2; j++)
		right[j] = arr[m+1+j];
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(left[i].vw>=right[j].vw)
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}
	while(i<n1)
		arr[k++] = left[i++];

	while(j<n2)
		arr[k++] = right[j++];
}

//function to implement merge sort
void merge_sort(it *arr, int l, int r)
{
	if(l<r)
	{
		int m = (l+(r-1))/2;

		merge_sort(arr, l, m);
		merge_sort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}

//function to implement Knapsack algorithm to find the maximum profit
void knapSack(it *arr, int n, double m)
{
	double *x = (double*)malloc(n*sizeof(double)); //array to store amount of each item selected
	double profit=0.0;
	int i;

	for(i=0; i<n; i++)
		x[i]=0.0;

	for(i=0; i<n; i++)
	{
		


	if(arr[i].w<=m)
		{
			x[i] = 1.0;
			m-=arr[i].w;
		}

		else
		{
			x[i] = m/arr[i].w;
			break;
		}
	}

	for(i=0; i<n; i++)
	{
		printf("%0.2lf ", x[i]);
		profit+=(x[i]*arr[i].v); //calculate maximum profit
	}
	printf("\nMaximum profit = %0.2lf\n", profit);
}

//driver code
int main(void)
{
	int n, i; 
	double m;
	printf("Enter the number of items:-\n");
	scanf("%d", &n); //accepting total number of items

	it *arr = (it*)malloc(n*sizeof(it)); //creating an array of structures

    printf("Enter the weight and value of each item separated by a space:-\n");
	for(i=0; i<n; i++)
		scanf("%lf%lf", &arr[i].w, &arr[i].v);	//accepting the weight and value of each item
		
	printf("Enter the capacity of the knapsack:-\n");
	scanf("%lf", &m); //accepting the maximum capacity of knapsack
	
	for(i=0; i<n; i++)
		arr[i].vw = arr[i].v/arr[i].w; //calculating the price to weight ratio of each item

	merge_sort(arr, 0, n-1); //sorting the items in descending order of price to weight ratio
	knapSack(arr, n, m); //calling knapsack function to display maximum profit

	return 0;
}
