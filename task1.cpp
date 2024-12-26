#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <queue>
using namespace std;

void generate_matrix(int n, float p, int** adjacency_matrix,int** m) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjacency_matrix[i][j] = 0;
			m[i][j] = 0;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((float)rand() / RAND_MAX < p) 
			{
				int a = 0;
				a = rand()%100;
                adjacency_matrix[i][j] = a;
                adjacency_matrix[j][i] = a;
            }
        }
    }

}

void print_matrix(int n, int** adjacency_matrix)
{
    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

void** BFS(int** G,int** F, int size, int* vis,int s)
{
    queue <int> q;
    q.push(s);

    vis[s] = 0;

    while (!q.empty()) {
        s = q.front();
        q.pop();
        for (int i = 0; i < size; i++)
		{
            if (G[s][i] >0 && vis[i] == -1) 
			{
                q.push(i);
                vis[i] = vis[s]+G[s][i];
				F[s][i] = vis[i];
				F[i][s] = G[s][i];
            }
        }
    }
    return 0;
}

int main()
{
    int n;
    float p;
	int s = 0;

    srand(time(NULL));


    printf("Input count of peaks  : ");
    scanf("%d", &n);


    int** matrix = (int**)malloc(n * sizeof(int*));
	int** m = (int**)malloc(n * sizeof(int*));
    for (int i = 0;i < n;i++)
    {
        matrix[i] = (int*)malloc(n * sizeof(int));
		m[i] = (int*)malloc(n * sizeof(int));
    }
    printf("Enter the probability of having an edge (0.0 to 1.0):");
    scanf("%f", &p);
    if (p < 0.0 || p > 1.0) {
        printf("The probability should be in the range from 0.0 to 1.0.\n");

        return 1;
    }
    int* vis = (int*)malloc(n * sizeof(int*));
    for (int i = 0;i < n;i++)
    {
        vis[i] = -1;
    }
    generate_matrix(n, p, matrix,m);
    print_matrix(n, matrix);
	BFS(matrix,m,n, vis,s);
	printf("\nMatrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d ", m[i][j]);
        }
        printf("\n");
    }
    getchar();
    getchar();
    getchar();
    return 0;
}
