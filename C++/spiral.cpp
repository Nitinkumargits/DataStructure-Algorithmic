#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<int> result;

    int row = 0, col = 0, dir = 0;
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};

    for (int i = 0; i < n * m; i++)
    {
        result.push_back(matrix[row][col]);
        visited[row][col] = true;
        int newRow = row + dr[dir], newCol = col + dc[dir];

        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !visited[newRow][newCol])
        {
            row = newRow;
            col = newCol;
        }
        else
        {
            dir = (dir + 1) % 4;
            row += dr[dir];
            col += dc[dir];
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = spiralOrder(matrix);

    for (int num : result)
        cout << num << " ";
}
