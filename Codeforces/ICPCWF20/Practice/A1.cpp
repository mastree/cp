#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

const int N = 2e5 + 10;

int n, m;
vector<int> adl[N];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cout << n << " " << m << el;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        cout << a << " " << b << el;
        adl[a].pb(b);
        adl[b].pb(a);
    }

    return 0;
}