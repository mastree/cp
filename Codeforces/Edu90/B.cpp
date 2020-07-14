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

const int N = 110;

string win[2] = {"DA", "NET"};
int q, len;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> s;
        len = s.length();
        s = "*" + s;

        stack<int> st;
        int cnt = 0;
        for (int i=1;i<=len;i++){
            int dig = (int)(s[i] - '0');
            if (st.empty()){
                st.push(dig);continue;
            }
            if (st.top() != dig){
                cnt++;
                st.pop();
            } else{
                st.push(dig);
            }
        }
        if (cnt & 1){
            cout << win[0] << el;
        } else{
            cout << win[1] << el;
        }
    }

    return 0;
}