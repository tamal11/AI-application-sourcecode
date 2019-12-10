#include <bits/stdc++.h>

using namespace std;
vector <int> edge[1000];
int edges, nodes, color, node_color[100];

bool is_safe(int n, int c)
{
    int i, s;
    s = edge[n].size();
    for(i=0; i<s; i++)
        if(node_color[edge[n][i]]==c) return false;

    return true;
}

bool color_graph(int x)
{
    int i, j;

    for(i=1; i<=color; i++)
    {
        if(is_safe(x, i))
        {
            node_color[x] = i;
            int s = edge[x].size();
            for(j=0; j<s; j++)
            {
                if(node_color[edge[x][j]]==0)
                {
                    if(color_graph(edge[x][j])==false)
                        break;
                }
            }
            if(j==s) return true;
        }
    }

    return false;
}

int main()
{
    int i, j, x, y;
    char x1, y1;
    cout << "input nodes, edges, color respectively";
    cin >> nodes >> edges >> color;
    for(i=0; i<edges; i++)
    {
        cin >> x1 >> y1;
        x = x1 - 'A';
        y = y1 - 'A';
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    cout << "printing\n";

    for(i=0; i<nodes; i++)
    {
        if(node_color[i]==0)
        {
            if(color_graph(i)==false)
            {
                cout << "can't solve" << endl;
                return 0;
            }
        }
    }

    for(i=0; i<nodes; i++)
        cout << i << " " << node_color[i] << endl;

    return 0;
}
