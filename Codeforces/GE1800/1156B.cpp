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

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        string s;
        cin >> s;
        int len = s.length();

        int cnt[26];
        vector<int> v;
        fill(cnt, cnt + 26, 0);
        for (int i=0;i<len;i++){
            int dig = s[i] - 'a';
            if (!cnt[dig]) v.pb(dig);
            cnt[dig]++;
        }

        int vlen = v.size();
        if (vlen == 1){
            cout << s << el;
            continue;
        }
        sort(v.begin(), v.end());
        if (vlen <= 3){
            if (vlen == 2){
                if (v[0]+1 == v[1]){
                    cout << "No answer" << el;
                    continue;
                } else{
                    cout << s << el;
                    continue;
                }
            } else{
                if (v[0]+1 == v[1] && v[1]+1 == v[2]){
                    cout << "No answer" << el;
                    continue;
                } else{
                    while (abs(v[0]-v[1]) == 1 || abs(v[1]-v[2]) == 1){
                        next_permutation(v.begin(), v.end());
                    }
                    for (auto x : v){
                        while (cnt[x]){
                            cnt[x]--;
                            cout << char(x + 'a');
                        }
                    }
                    cout << el;
                    continue;
                }
            }
        }
        if (vlen == 4){
            while (abs(v[0]-v[1]) == 1 || abs(v[1]-v[2]) == 1 || abs(v[2]-v[3]) == 1){
                next_permutation(v.begin(), v.end());
            }
            for (auto x : v){
                while (cnt[x]){
                    cnt[x]--;
                    cout << char(x + 'a');
                }
            }
            cout << el;
            continue;
        }

        for (int i=0;i<vlen;i+=2){
            while(cnt[v[i]]--){
                cout << char(v[i] + 'a');
            }
        }
        for (int i=1;i<vlen;i+=2){
            while(cnt[v[i]]--){
                cout << char(v[i] + 'a');
            }
        }
        cout << el;
    }

    return 0;
}