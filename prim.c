//PRIM'S MST ALGORITHM

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void bsort(int* src, int* dst, int* wt, int n)
{
	int i, j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<(n-1-i); j++)
        {
            if(wt[j]<wt[j+1])
            {
                int t = src[j];
                src[j] = src[j+1];
                src[j+1] = t;
                
                t = dst[j];
                dst[j] = dst[j+1];
                dst[j+1] = t;
                
                t = wt[j];
                wt[j] = wt[j+1];
                wt[j+1] = t;
            }
        }
    }
}

//utility function to find minimum spanning tree using Prims' Algorithm
void primsMST(int **cost, int n)
{
    int i, j, d=0, e=1, a, b, min, min_cost=0;
    
    int *visited = (int*)malloc(n*sizeof(int)); //array to store the visited vertices
    for(i=0; i<n; i++)
        visited[i]=0;
        
    int *src = (int*)malloc(n*sizeof(int));
    int *dst = (int*)malloc(n*sizeof(int));
    int *wt = (int*)malloc(n*sizeof(int));
    
    visited[0]=1; //select the first node as start and mark as visited
    
    //calculating the MST
    while(e<n)
    {
        min = INT_MAX;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(cost[i][j]<min) //find the minimum cost
                {
                    if(visited[i]!=0) //choosing the path with minimum cost and initial vertex already visited
                    {
                        min = cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }
        
        if(visited[b]==0)
        {
            src[d] = a;
            dst[d] = b;
            wt[d] = min;
            min_cost+=min;
            e++;
            d++;
        }
        
        visited[b]=1;
        cost[a][b] = cost[b][a] = INT_MAX;
    }
    
    bsort(src, dst, wt, d);
    for(i=0; i<d; i++)
        printf("%d %d %d\n",src[i], dst[i], wt[i]);
    printf("%d\n", min_cost);
}
 
//driver code
int main(void)
{
    int n, i, j;
    scanf("%d", &n); //accepting number of vertices
     
    int **cost = (int**)malloc(n*sizeof(int*)); //create 2D array to store adjacency matrix
     
    for(i=0; i<n; i++)
    cost[i] = (int*)malloc(n*sizeof(int));
        
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &cost[i][j]);
            
            //if the cost is 0, initialize with maximum value
            if(cost[i][j]==0)
                cost[i][j] = INT_MAX;
        }
    }
    
    primsMST(cost, n);
    return 0;
}
