#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int q;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> s;
        int len = s.length();
        int cnt[3] = {0, 0, 0};
        for (auto c : s){
            if (c == 'R') cnt[0]++;
            else if (c == 'S') cnt[1]++;
            else cnt[2]++;
        }
        char pil;
        if (cnt[0] >= cnt[1] && cnt[0] >= cnt[2]){
            pil = 'P';
        } else if (cnt[1] >= cnt[0] && cnt[1] >= cnt[2]){
            pil = 'R';
        } else{
            pil = 'S';
        }
        for (int i=0;i<len;i++) cout << pil;
        cout << el;
    }

    return 0;
}