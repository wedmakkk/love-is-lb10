#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <queue>
#include <iostream>
using namespace std;

void generate_matrix(int n, float p, int** adjacency_matrix, int** m) {

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
                int a;
                
                    a = rand() % 100;
            
                
                
                    adjacency_matrix[i][j] = a;
                    adjacency_matrix[j][i] = a;
                    m[i][j] = a;
                    
               
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

void** BFS(int** G, int** F, int size, int* vis, int s)
{
    queue <int> q;
    q.push(s);

    vis[s] = 0;

    while (!q.empty()) {
        s = q.front();
        q.pop();
        for (int i = 0; i < size; i++)
        {
            if (G[s][i] > 0 && vis[i] == -1)
            {
                q.push(i);
                vis[i] = vis[s] + G[s][i];
            }
        }
    }
    return 0;
}


int main()
{
    int n;
    float p;
    int s = 0,z = 0;

    srand(time(NULL));


    printf("Input count of peaks  : ");
    scanf("%d", &n);


    int** matrix = (int**)malloc(n * sizeof(int*));
    int** m = (int**)malloc(n * sizeof(int*));
    int** F1 = (int**)malloc(n * sizeof(int*));
    int** F2 = (int**)malloc(n * sizeof(int*));
    for (int i = 0;i < n;i++)
    {
        matrix[i] = (int*)malloc(n * sizeof(int));
        m[i] = (int*)malloc(n * sizeof(int));
        F1[i] = (int*)malloc(n * sizeof(int));
        F2[i] = (int*)malloc(n * sizeof(int));
    }
    printf("Enter the probability of having an edge (0.0 to 1.0):");
    scanf("%f", &p);
    if (p < 0.0 || p > 1.0) {
        printf("The probability should be in the range from 0.0 to 1.0.\n");

        return 1;
    }
    int* vis = (int*)malloc(n * sizeof(int*));
    int* ex = (int*)malloc(n * sizeof(int*));
    for (int i = 0;i < n;i++)
    {
        vis[i] = -1;
        ex[i] = -1;
    }
    generate_matrix(n, p, matrix,m);
    print_matrix(n, matrix);
    int max = 0, min = 103;
    
    for (int i = 0;i < n;i++)
    {
        max = 0, min = 103;
        BFS(matrix, F1, n, vis, i);
        for (int j = 0;j < n;j++)
        {
            F1[i][j] = vis[j];
            if (vis[j] >= max)
            {
                ex[i] = vis[j];
                max = vis[j];
            }
            if (vis[j] < min && vis[j] > 0)
            {
                min = vis[j];
            }
        }
        for (int h = 0;h < n;h++)
        {
            vis[h] = -1;
        }
    }
    printf("\nMatrix1:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d ", F1[i][j]);
        } 
        printf("\n");
    }
    printf("ex1:\n");
    max = ex[0],min = ex[0];
    for (int i = 0;i < n;i++)
    {
        if (ex[i] > max)
        {
            max = ex[i];
        }
        if (ex[i] < min)
        {
            min = ex[i];
        }
        printf("%d - %d\n", i, ex[i]);
    }
    printf("\ndiam: %d", max);
    printf("\nrad: %d", min);
    printf("\nperf:");

    for (int i = 0;i < n;i++)
    {
        if (ex[i] = max)
        {
            printf("%d", i);
        }
    }
    printf("\ncenter:");
    for (int i = 0;i < n;i++)
    {
        if (ex[i] = min)
        {
            printf("%d", i);
        }
    }
    max = 0, min = 103;
    for (int i = 0;i < n;i++)
    {
        max = 0, min = 103;
            BFS(m, F2, n, vis, i);
            for (int j = 0;j < n;j++)
            {
                F2[i][j] = vis[j];
                if (vis[j] >= max)
                {
                    ex[i] = vis[j];
                    max = vis[j];
                }
                if (vis[j] < min && vis[j] > 0)
                {
                    min = vis[j];
                }
            }
            for (int h = 0;h < n;h++)
            {
                vis[h] = -1;
            }
    }
    printf("\nMatrix2:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%5d ", F2[i][j]);
        }
        printf("\n");
    }
    printf("ex2:\n");
    max = ex[0], min = ex[0];
    for (int i = 0;i < n;i++)
    {

        if (ex[i] > max)
        {
            max = ex[i];
        }
        if (ex[i] < min & ex[i] > 0)
        {
            min = ex[i];
        }
        printf("%d - %d\n", i, ex[i]);
    }

    printf("\ndiam2: %d", max);
    printf("\nrad2: %d", min);
    printf("\nperf:");

    for (int i = 0;i < n;i++)
    {
        if (ex[i] = max)
        {
            printf("%d", i);
        }
    }
    printf("\ncenter:");
    for (int i = 0;i < n;i++)
    {
        if (ex[i] = min)
        {
            printf("%d", i);
        }
    }
    getchar();
    getchar();
    getchar();
    return 0;
}
