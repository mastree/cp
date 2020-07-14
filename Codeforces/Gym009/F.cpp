#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 110;

int n;
string s[N];
string ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("fygon.in", "r", stdin);
    // freopen("fygon.out", "w", stdout);

    string line;
    while (getline(cin, line)){
        s[++n] = line;
    }

    string cur;
    int dep = 0;
    for (int i=1;i<=n;i++){
        int mul = 0;
        int len = s[i].length();
        for (int j=0;j<len;j++){
            if (s[i] != ' '){
                mul = j;
                break;
            }
        }
        if (mul + 1 != dep * 4){
            
        }

    }

    return 0;
}