#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;

int n;
vector<pair<int, bool>> vec; // stamina, right

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        pair<int, bool> a;
        cin >> a.first >> a.second;
        if (a.second) vec.push_back(a);
        else{
            while (a.fi > 0 && vec.size() && vec.back().se == 1){
                int mn = min(a.fi, vec.back().fi);
                a.fi -= mn;
                vec.back().fi -= mn;
                if (vec.back().fi == 0) vec.pop_back();
            }
            if (a.fi) vec.push_back(a);
        }
    }    
    cout << vec.size() << el;
    for (auto& x : vec){
        cout << x.fi << " " << x.se << el;
    }

    return 0;
}