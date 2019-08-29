#include <bits/stdc++.h>
using namespace std;
unsigned long long i,j,n,m,x,k,y,a,b;
int main()
{
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n;
    i=1;
    while (i<=n&&i<10)
    {
        cout << i << "\n";
        i++;
    }
    m=9;
    x=10;
    while (i<=n)
    {
        m+=x;
        cout << m << "\n";
        k=m+x;
        y=0;
        while (k>0)
        {
            y+=k%10;
            k/=10;
        }
        a=m+x*10;
        b=0;
        while (a>0)
        {
            b+=a%10;
            a/=10;
        }
        //cout << m+x*10 << " " << y << " " << m+x << " " << b << "\n";
        if ((m+x*10)*y<=(m+x)*b)
        {
            x*=10;
        }
        i++;
    }
    return 0;
}
