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

const int N = 510;

int n;
int ar[N];

int dp[N];

bool merge(int a, int b){
    if (a == b) return 1;
    
    stack <int> st;
    st.push(ar[a]);
    for (int i=a + 1;i<=b;i++){
        int cur = ar[i];
        while(!st.empty() && cur == st.top()){
            st.pop();
            cur++;
        }
        st.push(cur);
    }
    return (st.size() == 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i];
    }
    fill(dp, dp + N, MOD);
    dp[0] = 0;
    dp[1] = 1;
    for (int i=2;i<=n;i++){
        for (int j=0;j<i;j++){
            if (merge(j + 1, i)) dp[i] = min(dp[i], dp[j] + 1);
        }
    }

    cout << dp[n] << el;

    return 0;
}