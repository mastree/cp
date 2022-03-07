#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

string a, b;
bool is_num(const string& s){
    if (s.empty()) return 0;
    if ('1' <= s[0] && s[0] <= '9'){
        for (auto& x : s){
            if ('0' <= x && x <= '9') continue;
            return 0;
        }    
        return 1;
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;
    if (!is_num(a) || !is_num(b)){
        cout << "NaN\n";
    } else{
        cout << stoi(a) - stoi(b) << el;
    }

    return 0;
}