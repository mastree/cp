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

int n;
string s;

int ans = 0;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> s;
    s = "*" + s;

    int c0 = 0, c1 = 0;
    for (int i=1;i<=n;i++){
        if (s[i] == '(') c0++;
        else c1++;
    }
    if (c1 != c0){
        cout << -1 << el;
        return 0;
    }

    int last = 0;
    int mn = 0;
    int cur = 0;
    for (int i=1;i<=n;i++){
        if (s[i] == '(') cur++;
        else cur--;

        if (cur < 0){
            if (mn >= 0){
                last = i;
                mn = cur;
                continue;
            } else{
                mn = min(mn, cur);
                continue;
            }
        } else{
            if (mn >= 0) continue;
            else{
                ans += i - last + 1;
                mn = cur;
                continue;
            }
        }

    }

    cout << ans << el;

    return 0;
}