#include <bits/stdc++.h>

using namespace std;
int n,m;
long long t;
long long a[101];
long long b[101];
long long c[101];
long long d[101];
long long calc(long long med)
{
    long long rez=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>med)continue;
        rez+=(med-a[i])/b[i]+1;
    }
    for(int i=0;i<m;i++)
    {
        if(med+c[i]>t)continue;
        rez-=(t-med-c[i])/d[i]+1;
    }
    return rez;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i]>>b[i];
    }
    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin >> c[i]>>d[i];
    }
    long long l=1;
    long long r=t;
    long long med;
    while(l<=r)
    {
        med=(l+r)/2;
        long long rez=calc(med);
        if(rez<=0)
        {
           l=med+1;
        }
        else
        {
            r=med-1;
        }
    }
    cout << l-1;
    return 0;
}
