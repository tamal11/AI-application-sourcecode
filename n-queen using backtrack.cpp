#include <bits/stdc++.h>

using namespace std;

int ara[100][100], total_size;
bool is_safe(int row, int column)
{
    int i, j;
    for(i=column-1; i>=0; i--)
        if(ara[row][i]) return false;

    for(i=row-1, j=column-1; i>=0 && j>=0; i--, j--)
        if(ara[i][j]) return false;

    for(i=row+1, j=column-1; i<=total_size && j>=0; i++, j--)
        if(ara[i][j]) return false;

    return true;
}

bool solve_n_queen(int column)
{
    int i;
    if(column>=total_size) return true;

    for(i=0; i<total_size; i++)
    {
        if(is_safe(i, column))
        {
            ara[i][column] = 1;
            if(solve_n_queen(column+1)) return true;

            ara[i][column] = 0;
        }
    }
    return false;
}

int main()
{
    int i, j;
    cin >> total_size;
    if(solve_n_queen(0))
    {
        for(i=0; i<total_size; i++){
            for(j=0; j<total_size; j++)
                cout << ara[i][j] << " ";

            cout << endl;
        }
    }
    else
        cout << "can't solve!" << endl;

    return 0;
}
