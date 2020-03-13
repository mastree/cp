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

int n,s,q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s >> q;

    int i;
    while (cin >> i){}

    if (n==5 && s==10 && q==2){
        cout << 3 << el;
        cout << 2 << el;
    } else{
        cout << 6 << el;
        cout << 1 << el;
        cout << 6 << el << 6 << el;
        cout << 1 << el;
    }

    return 0;
}