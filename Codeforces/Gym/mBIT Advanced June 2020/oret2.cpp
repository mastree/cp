#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 3e2;

bool ada[N];
vector<char> ch;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    for (auto& x : s){
        ada[x] = 1;
    }
    for (char i='a';i<='z';i++){
        ch.push_back(i);
    }
    for (char i='A';i<='Z';i++){
        ch.push_back(i);
    }
    for (char i='0';i<='9';i++){
        ch.push_back(i);
    }
    for (auto& x : ch){
        if (ada[x]) cout << 'Y' << el;
        else cout << 'N' << el;
    }

    return 0;
}