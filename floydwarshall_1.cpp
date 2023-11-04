#include <iostream>
using namespace std;
#define inf 99999999

void printGraph(int arr[5][5], int v)
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("%8d", arr[i][j]);
        }
    }
    printf("\n");
}
void FloydWarshall(int arr[5][5], int v)
{
    printf("Graph\n");
    printGraph(arr, v);
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (arr[i][k] != inf && arr[k][j] != inf && arr[i][k] + arr[k][j] < arr[i][j])
                {
                    arr[i][j] = arr[i][k] + arr[k][j];
                    printf("Change: [%d,%d] = [%d,%d] + [%d,%d] = [%d]\n", i, j, i, k, k, j, arr[i][j]);
                }
            }
        }
        printGraph(arr, v);
    }
}
int main()
{
    int ds[5][5] = {
        {0, 4, 2, 5, inf},
        {inf, 0, 1, inf, 4},
        {1, 3, 0, 1, 2},
        {-2, inf, inf, 0, 2},
        {inf, -3, 3, 1, 0}};
    FloydWarshall(ds, 5);
}