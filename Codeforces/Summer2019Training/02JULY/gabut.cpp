#include<bits/stdc++.h>
using namespace std;

int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<int> dp(m+3,(int)1e9);
    dp[0] = 0;
    set<int> s;
    s.insert(0);
    for(int i=1;i<=n;i++){
        int x; cin >> x;
        set<int> st = s;
        for(auto e:st){
            int cur = e + x;
            if(cur > m)break;
            s.insert(cur);
            dp[cur] = min(dp[cur], dp[e] + 1);
        }
    }
    cout << (dp[m] == (int)(1e9) ? -1 : dp[m]) << '\n';

}