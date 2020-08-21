#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

ll pc[41];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for (int i=0;i<41;i++) pc[i]=(1 << i);

    ll a,b;
    cin >> a >> b;

    ll xa=a%4;
    if (xa==0) xa=a;
    else if (xa==2) xa=a+1;
    else if (xa==1) xa=1;
    else xa=0;
    ll xb=b%4;
    if (xb==0) xb=b;
    else if (xb==2) xb=b+1;
    else if (xb==1) xb=1;
    else xb=0;

    xa=(xa^a);

    cout << (xb^xa) << el;

    return 0;
}