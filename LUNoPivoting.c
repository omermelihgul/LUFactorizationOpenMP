#include <omp.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void free_mem(double** martix, int n);
void print_matrix(double** martix, int n);
double** empty_matrix(int n, bool zero_initialized);
void fill_random(double** matrix, int n, int max_val);

int main()
{
    // start timer
    clock_t t = clock();

    int n = 10;

    double** matrix = empty_matrix(n, true);

    //
    fill_random(matrix, n, 10);

    //
    print_matrix(matrix, n);

    // 
    free_mem(matrix, n);

    // 
    printf("LU decomposition took %f seconds to execute.\n", ((double)(clock() - t)) / CLOCKS_PER_SEC);

    return 0;
}



// 
void free_mem(double** matrix, int n)
{
    for(int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
}

//
void print_matrix(double** martix, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%lf ", martix[i][i]);

        printf("\n");
    }
}

// 
double** empty_matrix(int n, bool zero_initialized)
{
    if(zero_initialized)
    {
        double** matrix = (double**)calloc(n, sizeof(double*));
        for(int i = 0; i < n; i++)
            matrix[i] = (double*)calloc(n, sizeof(double));

        return matrix;
    }

    double** matrix = (double**)malloc(n * sizeof(double*));
    for(int i = 0; i < n; i++)
        matrix[i] = (double*)malloc(n * sizeof(double));

    return matrix;
}

// 
void fill_random(double** matrix, int n, int max_val)
{
    srand(time(NULL));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            matrix[i][j] = rand() % max_val + 1.0;
}