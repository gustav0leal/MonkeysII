#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int N = 5100;
const ll mod = 998244353LL;
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);  
    int n,x;
    cin>>n;
    for (int i = 1; i <= n; ++i)
    {
        cin>>x;
        cout<<n-x+1<<" ";
    }
    cout<<"\n";
    return 0;
}