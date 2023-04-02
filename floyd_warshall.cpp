void floyd_warshall()
{
    for (int i = 1; i <= vertex; i++)         // i vertex를 거치는 경우
        for (int j = 1; j <= vertex; j++)     // from vertex
            for (int k = 1; k <= vertex; k++) // to vertex
                if (arr[j][i] != INF && arr[i][k] != INF)
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
}