#include<bits/stdc++.h>

using namespace std;
queue <string> q;
string input,goal;
map <string,int> m,n;
map <string,string> parent;
stack <string> s;

void bfs()
{
    while(!q.empty())
    {
        string test=q.front();
        if(q.front()==goal)
        {
            printf("moves:");
            cout<<n[goal]<<endl;
            return;
        }
        string test2=test;
        q.pop();
        for(int i=0;i<test.size();i++)
        {
                if(i==0)
                {
                    swap(test[0],test[1]);
                    if(m[test]==1)
                    {
                        test=test2;
                    }
                    else
                    {
                        q.push(test);
                        m[test]=1;
                        n[test]=n[test2]+1;
                        parent[test]=test2;
                        test=test2;
                    }

                    swap(test[0],test[3]);
                    if(m[test]==1)
                    {
                        test=test2;
                    }
                    else
                    {
                        q.push(test);
                        m[test]=1;
                        n[test]=n[test2]+1;
                        parent[test]=test2;
                        test=test2;
                    }
                }
                else if(i==1)
                {
                    swap(test[1],test[2]);
                    if(m[test]==1)
                    {
                        test=test2;
                    }
                    else
                    {
                        q.push(test);
                        m[test]=1;
                        n[test]=n[test2]+1;
                        parent[test]=test2;
                        test=test2;
                    }

                    swap(test[1],test[4]);
                    if(m[test]==1)
                    {
                        test=test2;
                    }
                    else
                    {
                        q.push(test);
                        m[test]=1;
                        n[test]=n[test2]+1;
                        parent[test]=test2;
                        test=test2;
                    }
                }

                else if(i==2)
                {

                    swap(test[2],test[5]);
                    if(m[test]==1)
                    {
                        test=test2;
                    }
                    else
                    {
                        q.push(test);
                        m[test]=1;
                        n[test]=n[test2]+1;
                        parent[test]=test2;
                        test=test2;
                    }
                }

                else if(i==3)
                {

                    swap(test[3],test[6]);
                   if(m[test]==1)
                    {
                        test=test2;
                    }
                    else
                    {
                        q.push(test);
                        m[test]=1;
                        n[test]=n[test2]+1;
                        parent[test]=test2;
                        test=test2;
                    }

                    swap(test[3],test[4]);
                    if(m[test]==1)
                    {
                        test=test2;
                    }
                    else
                    {
                        q.push(test);
                        m[test]=1;
                        n[test]=n[test2]+1;
                        parent[test]=test2;
                        test=test2;
                    }
                }

                else if(i==4)
                {

                    swap(test[4],test[5]);
                   if(m[test]==1)
                    {
                        test=test2;
                    }
                    else
                    {
                        q.push(test);
                        m[test]=1;
                        n[test]=n[test2]+1;
                        parent[test]=test2;
                        test=test2;
                    }


                    swap(test[4],test[7]);
                    if(m[test]==1)
                    {
                        test=test2;
                    }
                    else
                    {
                        q.push(test);
                        m[test]=1;
                        n[test]=n[test2]+1;
                        parent[test]=test2;
                        test=test2;
                    }
                }

                else if(i==5)
                {

                    swap(test[5],test[8]);
                    if(m[test]==1)
                    {
                        test=test2;
                    }
                    else
                    {
                        q.push(test);
                        m[test]=1;
                        n[test]=n[test2]+1;
                        parent[test]=test2;
                        test=test2;
                    }
                }

                else if(i==6)
                {
                    swap(test[6],test[7]);
                    if(m[test]==1)
                    {
                        test=test2;
                    }
                    else
                    {
                        q.push(test);
                        m[test]=1;
                        n[test]=n[test2]+1;
                        parent[test]=test2;
                        test=test2;
                    }

                }
                else if(i==7)
                {

                    swap(test[7],test[8]);
                    if(m[test]==1)
                    {
                        test=test2;
                    }
                   else
                    {
                        q.push(test);
                        m[test]=1;
                        n[test]=n[test2]+1;
                        parent[test]=test2;
                        test=test2;
                    }


                }
        }
    }
}

void path()
{
    int i;
    string str=goal;
    for( ; ; )
    {
        s.push(str);
        if(str==input) break;
        str=parent[str];
    }

    while(!s.empty())
    {
        string sTest = s.top();
        int cnt_char;
        for(cnt_char=0; cnt_char<sTest.length(); cnt_char++)
        {
            if(cnt_char%3==0) cout << endl;
            cout << sTest[cnt_char];
        }
        cout << endl;
        s.pop();
    }
}

int main()
{
    int i;
    char j;
    freopen("input.txt","r",stdin);
    for(i=0;i<9;i++)
    {
        scanf("%c",&j);
        getchar();
        input=input+j;
    }

    cout<<input << endl;

    for(i=0;i<9;i++)
    {
        scanf("%c",&j);
        getchar();
        goal=goal+j;
    }
    cout<<goal<<endl;
    q.push(input);
    m[input]=1;
    n[input]=0;
    bfs();
    path();
    return 0;
}
