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

const int N = 1e6 + 10;

int n;
string s, t;
set<int> setdah[2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> s >> t;
    s = "*" + s;
    t = "*" + t;
    for (int i=1;i<=n;i++){
        int dig1 = s[i] - '0';
        int dig2 = t[i] - '0';
        if (dig1 == dig2) continue;
        setdah[dig1].insert(i);
    }
    if (setdah[0].size() != setdah[1].size()){
        cout << -1 << el;
        return 0;
    }
    int turn = 0;
    while (!setdah[0].empty()){
        turn++;
        bool id;
        int d0 = *setdah[0].begin();
        int d1 = *setdah[1].begin();
        if (d0 < d1){
            id = 0;
        } else{
            id = 1;
        }

        int cur = *setdah[id].begin();
        vector<pair<int, bool>> pus;
        while (1){
            pus.pb(mp(cur, id));
            id = !id;
            auto temp = setdah[id].upper_bound(cur);
            if (temp == setdah[id].end()) break;
            cur = *temp;
        }
        int len = pus.size();
        if (len & 1) len--;
        for (int i=0;i<len;i++){
            setdah[pus[i].se].erase(pus[i].fi);
        }
    }
    cout << turn << el;

    return 0;
}