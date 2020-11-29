#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    int a[m];
    for(int i=0;i<m;i++)
    {
        cin >> a[i];
    }
    int l=1;
    int r=1000000000;
    int mid;
    int rez=0;
    while(l<r)
    {
        mid=(l+r)/2;
        rez=0;
        for(int i=0;i<m;i++)
        {
            rez+=a[i]/mid;
            if(a[i]%mid)rez++;
        }
        if(rez<=n)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    cout << r;
    return 0;
}
