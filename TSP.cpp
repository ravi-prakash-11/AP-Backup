#include <bits/stdc++.h>
using namespace std;

int cost=0,n;
int arr[10][10], completed[10];

int least(int c)
{
    int i,nc=999;
    int min=999,kmin;
    
    for(i=0;i < n;i++)
    {
        if((arr[c][i]!=0)&&(completed[i]==0))
            if(arr[c][i]+arr[i][c] < min)
            {
                min=arr[i][0]+arr[c][i];
                kmin=arr[c][i];
                nc=i;
            }
    }
 
    if(min!=999)
        cost+=kmin;
    
    return nc;
}

void mincost(int city)
{
    int i,ncity;
    completed[city]=1;
    
    cout<<char(65+city)<<"--->";
    ncity=least(city);
    
    if(ncity==999)
    {
        ncity=0;
        cout<<char(65+ncity);
        cost+=arr[city][ncity];
        return;
    }
    
    mincost(ncity);
}
 
void takeInput()
{    
    cout<<"\n\nEnter Number of Cities: ";
    cin >> n;
    
    cout<<"\n\nEnter adjacency matrix...\n\n\n";
    for(int i=0; i<n; i++)
    {
        cout<<"\t"<<char(65+i);
    }
    cout<<"\n";
    for(int i=0; i<n; i++)
    {
        cout<<"\n"<<char(65+i)<<":\t";
        for(int j=0; j<n; j++)
            cin>>arr[i][j];
        completed[i]=0; 
    }
    
    cout<<"\n\n\t...ADJACENCY MATRIX...\n\n\t";
    for(int i=0; i<n; i++)
    {
        cout<<"\t"<<char(65+i);
    }
    cout<<"\n";

    for(int i=0; i<n; i++)
    {
        cout<<"\n\t"<<char(65+i);
        for(int j=0; j<n; j++)
        {
            cout<<"\t"<<arr[i][j];
        }
    }
}


main()
{
    takeInput();

    cout<<"\n\nThe Path is:\n";
    mincost(arr[0][0]);
    
    cout<<"\n\nMinimum cost is "<<cost<<"\n\n\n"<<endl;
}