#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

int n,m;
string s;

vector <int> a1,a2,a3;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    cin >> s;

    bool state[n+6];
    for (int i=0;i<n+6;i++) state[i]=0;

    for (int i=0;i<n;i++){
        if (s[i]=='1'){
            if (!state[i] && !state[i+2]){
                state[i+1]=1;
                a1.pb(i+1);
            }
        } 
    }

    for (int i=0;i<n;i++){
        if (s[i]=='0'){
            if (!state[i] && !state[i+2]){
                state[i+1]=1;
                a2.pb(i+1);
            }
        }
    }

    for (int i=0;i<n;i++){
        if (s[i]=='1' && !state[i+1]){
            a3.pb(i+1);
        }
    }

    int len1=a1.size(),len2=a2.size(),len3=a3.size();

    cout << len1*3 + len2*2 + len3 << el;

    for (auto x : a1) cout << 1 << " " << x << el;
    for (auto x : a2) cout << 1 << " " << x << el;
    for (auto x : a3){
        if (!state[x-1] && !state[x+1]){
            cout << 1 << " " << x << el;
            state[x]=1;
        }
    }
    for (auto x : a3){
        if (!state[x]) cout << 1 << " " << x << el;
        state[x]=1;
    }
    for (auto x : a1){
        cout << 2 << el;
        state[x]=0;
    }
    for (auto x : a1){
        if (!state[x-1] && !state[x+1]){
            cout << 1 << " " << x << el;
            state[x]=1;
        }
    }
    for (auto x : a1){
        if (!state[x]) cout << 1 << " " << x << el;
    }
    for (auto x : a2) cout << 2 << el;
    
    return 0;
}