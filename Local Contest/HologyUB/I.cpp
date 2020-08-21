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


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;

    int low=n/2,sisa=n%2;
    n-=sisa;
    low+=sisa;
    while (low%m!=0 && n>0){
        low++;
        n-=2;
    }

    if (low%m){
        cout << -1 << el;
        return 0;
    }
    cout << low << el;

    return 0;
}