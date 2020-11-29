#include <bits/stdc++.h>
/*
   Solution by Jovan Kašćelan
*/
using namespace std;
int n;
double xx[1001];
double yy[1001];
int prt[1001];
int sz[1001];
int findd(int x)
{
    while(x!=prt[x])
    {
        prt[x]=prt[prt[x]];
        x=prt[x];
    }
    return x;
}
void unionn(int x,int y)
{
    x=findd(x);
    y=findd(y);
    if(x==y)return;
    if(sz[x]<sz[y])swap(x,y);
    prt[y]=x;
    sz[x]+=sz[y];
}
void sett()
{
    for(int i=0;i<n;i++)
    {
        prt[i]=i;
        sz[i]=1;
    }
}
double euclid(int i,int j)
{
    double rez=(xx[i]-xx[j])*(xx[i]-xx[j])+(yy[i]-yy[j])*(yy[i]-yy[j]);
    return sqrt(rez);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(6);
    cout << fixed;
    cin >> n;
    for(int i=0;i<n;i++)
    {
       cin >> xx[i] >> yy[i];
    }
    double l=0;
    double r=1000000000;
    double m;
    for(int i=0;i<100;i++)
    {
        sett();
        m=(l+r)/2;
        for(int j=0;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(euclid(j,k)<=2*m)
                {
                    unionn(j,k);
                }
            }
        }
        if(sz[findd(0)]<n)
        {
            l=m;
        }
        else
        {
            r=m;
        }
    }
    cout << r;
    return 0;
}
