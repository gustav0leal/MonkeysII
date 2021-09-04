#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int a[N];

int main(){
    
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    int rs=-1,at;
    for (int i = 1; i < n-1 ; ++i)
    {
        if(a[i]<min(a[i-1],a[i+1]))
        {
            if(rs==-1)
                rs=i;
            else if(a[i]<a[rs])
                rs=i;
        }
    }
    cout<<rs+1<<"\n";
    return 0;
}