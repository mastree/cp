#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

bool is_low(char c){
    return ('a' <= c && c <= 'z');
}
char to_up(char c){
    return char(c + ('A' - 'a')); 
}
char to_low(char c){
    return char(c + ('a' - 'A'));
}
char rot13low(char c){
    int dig = c - 'a';
    dig = (dig + 13) % 26;
    return char(dig + 'a');
}
char rot13up(char c){
    int dig = c - 'A';
    dig = (dig + 13) % 26;
    return char(dig + 'A');
}

const int N = 110;

int q;
int n;
string s;

void solve(){
    cin >> s;
    n = s.size();
    reverse(s.begin(), s.end());
    for (int i=0;i<n;i++){
        if (is_low(s[i])){
            s[i] = rot13low(s[i]);
            s[i] = to_up(s[i]);
        } else{
            s[i] = rot13up(s[i]);
            s[i] = to_low(s[i]);
        }
    }
    cout << s << el;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}