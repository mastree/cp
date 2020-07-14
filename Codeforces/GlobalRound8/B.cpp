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

ll n;
string s = "codeforces";
ll cnt[20];

ll hitung(){
    ll ret = 1;
    for (int i=0;i<10;i++){
        ret *= cnt[i];
    }
    return ret;
}
void tambah(){
    for (int i=1;i<10;i++){
        if (cnt[i] < cnt[i - 1]){
            cnt[i]++;
            return;
        }
    }
    cnt[0]++;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(cnt, cnt + 20, 1LL);
    cin >> n;
    while (hitung() < n){
        tambah();
    }
    for (int i=0;i<10;i++){
        for (int j=0;j<cnt[i];j++){
            cout << s[i];
        }
    }
    cout << el; 

    return 0;
}