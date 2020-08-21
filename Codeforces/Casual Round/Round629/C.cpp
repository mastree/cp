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

int q;
int n;
string s;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n >> s;

        char ans1[n], ans2[n];
        int lebih = 0;
        for (int i=0;i<n;i++){
            if (lebih == 0){
                if (s[i] == '0'){
                    ans1[i] = '0';
                    ans2[i] = '0';
                } else if (s[i] == '1'){
                    ans1[i] = '1';
                    ans2[i] = '0';
                    lebih = 1;
                } else{
                    ans1[i] = '1';
                    ans2[i] = '1';
                }
            } else if (lebih == 1){
                if (s[i] == '0'){
                    ans1[i] = '0';
                    ans2[i] = '0';
                } else if (s[i] == '1'){
                    ans1[i] = '0';
                    ans2[i] = '1';
                } else{
                    ans1[i] = '0';
                    ans2[i] = '2';
                }
            }

        }
        for (int i=0;i<n;i++){
            cout << ans1[i];
        }
        cout << el;
        for (int i=0;i<n;i++){
            cout << ans2[i];
        }
        cout << el;
    }

    return 0;
}