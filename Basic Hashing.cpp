#include<bits/stdc++.h>
#define LL long long
#define MX 105
using namespace std;
const LL M=1e9+7, B=257;
LL power[MX];
map<LL, int> check;

LL BigMod(LL n, LL p, LL m)
{
    if(p==0)
        return 1%m;
    LL x=BigMod(n, p/2, m);
    x%=m;
    x=(x*x)%m;
    if(p%2==1)
        x=(n*x)%m;
    return x%m;
}

void cal_power()
{
    for(int i=0; i<MX; i++)
        power[i]=BigMod(B, i, M);

}

LL Hash(string s)
{
    LL has=0;
    for(int i=0; s[i]!=NULL; i++)
    {
        has= (has+((s[i]*power[i])%M))%M;
    }
    return has;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin >> n;
    cal_power();
    for(int i=0; i<n; i++)
    {
        cin >> s;
        LL has=Hash(s);
        if(check[has]==0)
        {
            cout << "NO" << endl;
            check[has]=1;
        }
        else
            cout << "YES" << endl;
    }
    return 0;
}
/*
5
salman
chy
Hello
chy
salman
*/
