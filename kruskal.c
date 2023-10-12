//KRUSKAL'S MINIMUM SPANNING TREE ALGORITHM

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//find function
int find(int *parent, int i)
{
    while(parent[i])
        i=parent[i];
    return i;
}

//union function
int unite(int *parent, int i, int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }

    return 0;
}

//utility function to find minimum spanning tree using Kruskal's Algorithm
void kruskalsMST(int **cost, int n)
{
    int i, j, e=1, a, b, u, v, min, min_cost=0;
    int *parent = (int*)malloc(n*sizeof(int));
    
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
                        min = cost[i][j];
                        a=u=i;
                        b=v=j;
                }
            }
        }
        
        u = find(parent, u);
        v = find(parent, v);
        
        if(unite(parent, u, v))
        {
            printf("%d %d %d\n", a+1, b+1, min);
            min_cost+=min;
            e++;
        }
        
        cost[a][b] = cost[b][a] = INT_MAX;
    }
    
    printf("Cost of the MST = %d\n", min_cost);
}
 
//driver code
int main(void)
{
    int n, i, j;
    printf("Enter the number of vertices:-\n");
    scanf("%d", &n);
     
    int **cost = (int**)malloc(n*sizeof(int*));
     
    for(i=0; i<n; i++)
    cost[i] = (int*)malloc(n*sizeof(int));
    
    printf("Enter the cost matrix:-\n");
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
    
    printf("\nMinimum Spanning Tree\n");
    printf("---------------------\n");
    kruskalsMST(cost, n);
    return 0;
}
