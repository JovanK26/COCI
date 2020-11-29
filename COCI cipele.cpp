#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(n>m)
    {
        swap(n,m);
        swap(a,b);
    }
    int l=0;
    int r=1000000000;
    int mid;
    bool check;
    while(l<r)
    {
        mid=(l+r)/2;
        int j=0;
        check=0;
        for(int i=0;i<n;i++)
        {
            while(j<m && abs(a[i]-b[j])>mid)j++;
            if(j==m)
            {
                check=1;
                break;
            }
            j++;
        }
        if(!check)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    cout << l;
    return 0;
}
