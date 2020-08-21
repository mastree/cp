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

const int N = 1e6 + 7;
int n;
string s;
int cnt[N];

set <int> gg;
int del = N;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.length();
    s = '*' + s;
    // cout << n << el;
    stack <int> st;
    int cur = 0, last = 0;
    for (int r=1;r<=n;r++){
        if (s[r]=='('){
            st.push(r);
        }
        else{
            if (!st.empty()){
                int l = st.top();
                st.pop();
                gg.insert(l);
                cur+=2;
                // cout << r << " " << cur << el;
                int tp;
                if (st.empty()) tp = 0;
                else tp = st.top();
                auto it = gg.lower_bound(tp);
                // cout << l << " " << r << el;
                if (it != gg.end()) cnt[r - *it + 1]++;
            } else{
                last = r;
                cur=0;
                gg.clear();
                continue;
            }
        }
    }

    // for (int i=1;i<=n;i++){
    //     for (int j=i;j<=n;j++){
    //         bool bisa = 1;
    //         int byk =0;
    //         for (int id=i;id<=j;id++){
    //             if (s[id]=='(') byk++;
    //             else byk--;
    //             if (byk<0){
    //                 bisa=0;
    //                 break;
    //             } 
    //         }
    //         if (bisa && byk==0){
    //             cout << i << " " << j << el;
    //         }
    //     }
    // }

    pii ans = {0, 1};
    for (int i=1;i<N;i++){
        if (cnt[i]){
            ans = {i, cnt[i]};
        }
    }
    cout << ans.fi << " " << ans.se << el;

    return 0;
}