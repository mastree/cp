#include <bits/stdc++.h>

#define pb push_back

using ll = long long;
using namespace std;

const int N = 1e4 + 10;

int n, m;
vector<int> adl[N];

int main(){
    ios_base::sync_sith_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        adl[a].pb(b);
        adl[b].pb(a);
    }
    

}