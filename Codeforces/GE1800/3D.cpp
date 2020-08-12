#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e4 + 10;

int n;
string s;
int ar[N];
ll ans;

vector<int> pos;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.length();
    int none = 0;
    for (int i=0;i<n;i++){
        if (s[i] == '?'){
            none++;
            pos.pb(i);
        }
    }
    for (int i=1;i<=none;i++){
        int a, b;
        cin >> a >> b;
        ans += b;
        ar[i] = a - b;
    }
    int id = 1;
    int cnt = 0;
    priority_queue<pii> pq;
    for (auto x : s){
        if (x == '('){
            cnt++;
        } else if (x == ')'){
            cnt--;
        } else{
            pq.push(mp(-ar[id], pos[id - 1]));
            cnt--;
            id++;
        }
        if (cnt < 0){
            if (pq.empty()){
                cout << -1 << el;
                return 0;
            }
            ans += -pq.top().fi;
            s[pq.top().se] = '(';
            cnt += 2;
            pq.pop();
        }
    }
    cnt = 0;
    for (auto& x : s){
        if (x == '?') x = ')';
    }
    for (auto x : s){
        if (x == '(') cnt++;
        else cnt--;
        if (cnt < 0){
            cout << -1 << el;
            return 0;
        }
    }
    if (cnt != 0){
        cout << -1 << el;
        return 0;
    }
    cout << ans << el;
    cout << s << el;

    return 0;
}