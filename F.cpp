#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=200100;
const ll inf = 1e16;
#define lef(x) (x<<1)
#define rig(x) (lef(x)+1)

ll tree[4*N],lazy[4*N];

void push(int p,int tl,int tr)
{
    if(tl!=tr && lazy[p]!=0)
    {
        tree[lef(p)]+=lazy[p];
        tree[rig(p)]+=lazy[p];
        lazy[lef(p)]+=lazy[p];
        lazy[rig(p)]+=lazy[p];
        lazy[p]=0;
    }
}

void build(int p,int tl,int tr,ll x)
{
    if(tl==tr)
    {
        tree[p]=x;
    }else{
        int tmid=(tl+tr)>>1;
        build(lef(p),tl,tmid,x);
        build(rig(p),tmid+1,tr,x);
        tree[p]=x;
    }
}

ll query(int p,int l,int r,int tl,int tr)
{
    if(l>r)
        return inf;
    if(tl==l && tr==r){
        return tree[p];
    }else{
        push(p,tl,tr);
        int tmid=(tl+tr)>>1;
        return min(query(lef(p),l,min(r,tmid),tl,tmid),
            query(rig(p),max(tmid+1,l),r,tmid+1,tr));
    }
}
void update(int p,int l,int r,int tl,int tr, ll x)
{
    if(l>r)
        return;
    if(tl==l && tr==r){
        tree[p]+=x;
        lazy[p]+=x;
    }else{
        push(p,tl,tr);
        int tmid=(tl+tr)>>1;
        update(lef(p),l,min(r,tmid),tl,tmid,x);
        update(rig(p),max(tmid+1,l),r,tmid+1,tr,x);
        tree[p]=min(tree[rig(p)],tree[lef(p)]);
    }
}



int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    ll L,D,l,d;
    int n,q;
    vector<int> ans;
    cin>>L>>D>>l>>d;
    cin>>n>>q;
    build(1,1,n,(L*D*D)/(l*d*d));
    for (int i = 1; i <= q; ++i)
    {
        int ce,cd;
        ll x;
        cin>>ce>>cd>>x;
        if(query(1,ce,cd,1,n)>=x)
        {
            ans.push_back(i);
            update(1,ce,cd,1,n,-x);
        }
    }
    cout<<ans.size()<<"\n";
    for(auto c:ans)
        cout<<c<<" ";
    cout<<"\n";
    return 0;
}
