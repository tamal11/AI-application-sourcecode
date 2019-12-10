#include <bits/stdc++.h>

using namespace std;

int fitness[100], N, P;
double C, M;
//string chrom[];
vector <string> population;
map <int, string> m;
map <string, int> m2;

int calc_fit(string s)
{
    int mat[N][N];
    memset(mat, 0, sizeof(mat));
    int i, j, temp, fit=0, k, l;
    for(i=0; i<P; i++)
    {
        temp = s[i]-'0';
        //cout << s[i] << " "<<  temp << endl;
        mat[temp][i] = 1;
    }

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    for(j=0; j<N; j++)
    {
        for(i=0; i<N; i++)
        {
            //cout << mat[i][j] << " ";
            if(mat[i][j]==1)
            {
                for(k=i-1; k>=0; k--)
                    if(mat[k][j]) fit++;

                for(k=i+1; k<N; k++)
                    if(mat[k][j]) fit++;

                for(k=j-1; k>=0; k--)
                    if(mat[i][k]) fit++;

                for(k=j+1; k<N; k++)
                    if(mat[i][k]) fit++;

                for(k=i-1, l=j+1; k>=0 && l<N; k--, l++)
                    if(mat[k][l]) fit++;

                for(k=i+1, l=j+1; k<N && l<N; k++, l++)
                    if(mat[k][l]) fit++;

                for(k=i-1, l=j-1; k>=0 && l>=0; k--, l--)
                    if(mat[k][l]) fit++;

                for(k=i+1, l=j-1; k<N && l>=0; k++, l--)
                    if(mat[k][l]) fit++;
            }
        }
    }
    m[fit] = s;
    m2[s] = fit;
    cout << fit << endl;
    return fit;
}

int main()
{
    cout << "input N, P, C, M respectively";
    cin >> N >> P >> C >> M;
    int i, j, temp, fit;
    char string_temp[30];
    string str;
    m[0] = "notac";
    for(i=0; i<P; i++)
    {
        temp = 0;
        for(j=0; j<N; j++)
        {
            temp = temp*10 + rand() % N;
        }
        //string_temp = itoa(temp);
        sprintf(string_temp, "%d", temp);
        cout << string_temp << endl;
        fit = calc_fit(string_temp);
        if(fit==0) break;
        population.push_back(string_temp);
    }

    //if(m[0]=="notac") cout <<  "nqueen";
    int r, cnt;
    while(m[0]=="notac")
    {
        cnt = 0;
        r = rand() % 9;
        if(r > 0)
        {
            for(i=0; i<50; i++)
            {

            }
        }
    }
//    while(!population.empty())
//    {
//        str = population.back();
//        cout << str << " " << m[str] << endl;
//        population.pop_back();
//    }

    return 0;
}
