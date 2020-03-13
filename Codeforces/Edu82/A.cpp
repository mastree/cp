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

int q;
string s;
int ans;
int pc[105];
int n;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    // cout << q << el;
    while (q--){
        cin >> s;

        n = s.length();
        int aw = MOD, ak = 0;
        fill(pc, pc + n + 1, 0);
        // for (int i=0;i<=n;i++) pc[i] = 0;
        for (int i=1;i<=n;i++){
            if (s[i-1] == '1'){
                aw = min(aw, i);
                ak = max(ak, i);
            }
            pc[i] = pc[i-1] + (s[i-1] == '1');
        }
        if (aw == MOD){
            cout << 0 << el;
            continue;
        }
        // cout << s << el;
        cout << ak-aw-(pc[ak]-pc[aw]) << el;
    }

    return 0;
}