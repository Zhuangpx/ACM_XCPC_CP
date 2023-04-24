#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define ll long long
#define uint unsigned int
const int maxn=3e5+25;
inline int read()
{
    int ans=0;
    char last=' ',ch=getchar();
    while(ch<'0'|ch>'9')last=ch,ch=getchar();
    while(ch>='0' && ch<='9')ans=ans*10+ch-'0',ch=getchar();
    if(last=='-')ans=-ans;
    return ans;
}
int block_size; // Äª¶Ó¿é´óÐ¡
int ans[maxn],color[maxn],cnt[maxn],num[maxn];
int l=1,r=0,sum=0,n,m,mx;
struct Query
{
    int l,r,id;
    bool operator<(const Query& sec)const
    {
        if(l/block_size!=sec.l/block_size)return l<sec.l;
        return r<sec.r;
    }
}q[maxn];
int getans(int x,int m)
{
    if(m<=(x+1)/2)return 1;
    return 2*m-x;
}
void add(int cur)
{
    num[cnt[cur]]--;
    cnt[cur]++;
    num[cnt[cur]]++;
    mx=max(mx,cnt[cur]);
}
void del(int cur)
{
    num[cnt[cur]]--;
    cnt[cur]--;
    num[cnt[cur]]++;
    if(!num[mx])mx--;
}
int main()
{
    n=read(),m=read();
    block_size=sqrt(n)+1;
    for(int i=1;i<=n;i++)
        color[i]=read();
    for(int i=0;i<m;i++)
    {
        q[i].l=read(),q[i].r=read();
        q[i].id=i;
    }
    sort(q,q+m);
    for(int i=0;i<m;i++)
    {
        while(l>q[i].l)add(color[--l]);
        while(r<q[i].r)add(color[++r]);
        while(l<q[i].l)del(color[l++]);
        while(r>q[i].r)del(color[r--]);
        ans[q[i].id]=getans(q[i].r-q[i].l+1,mx);
    }
    for(int i=0;i<m;i++)
    {
        cout<<ans[i]<<"\n";
    }
    return 0;
}
/*
6 6
1 2 3 3 2 1
2 6
3 4
1 3
2 5
1 6
2 6

6 6
3 3 3 3 3 3
1 1
2 2
3 3
4 4
5 5
6 6

6 6
3 3 3 3 3 3
1 1
1 2
1 3
1 4
1 5
1 6

*/
