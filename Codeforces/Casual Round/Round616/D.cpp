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

string s;
int q, n, l, r;
int pc[N][26];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.length();
    s = "*" + s;

    for (int i=1;i<=n;i++){
        for (int j=0;j<26;j++){
            pc[i][j] = pc[i-1][j];
        }
        pc[i][(s[i] - 'a')]++;
    }

    cin >> q;
    while (q--){
        cin >> l >> r;
        vector<int> v;
        int cur[26];
        for (int i=0;i<26;i++){
            cur[i] = pc[r][i] - pc[l-1][i];
            if (cur[i]) v.pb(i);
        }

        if (v.size() > 2 || l == r){
            cout << "Yes" << el;
            continue;
        } else if (v.size() == 2){
            if (s[l] != s[r]){
                cout << "Yes" << el;
                continue;
            } else{
                cout << "No" << el;
            }
        } else{
            cout << "No" << el;
        }

    }

    return 0;
}