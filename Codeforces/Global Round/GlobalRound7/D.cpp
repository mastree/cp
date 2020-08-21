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

bool isPalindrom(int l, int r){
    for (l;l<r;l++){
        if (s[l] != s[r]){
            return 0;
        }
        r--;
    }
    return 1;
}

int hitung(int l, int r){
    return n - (r - l + 1);
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    // cout << q << el;
    while (q--){
        cin >> s;
        n = s.length();

        s = "*" + s;
        int l = 1, r = n;
        pii ans = mp(l, r);
        int len = 0;

        int le[n + 2], ri[n + 2];
        for (int i=0;i<=n + 1;i++){
            le[i] = i;
            ri[i] = i;
        }

        for (int i=1;i<=n;i++){
            int low = 0, high = min(i - 1, n - i);
            while (low < high){
                int mid = (low + high + 1) / 2;

                if (isPalindrom(i - mid, i + mid)){
                    low = mid;
                } else{
                    high = mid - 1;
                }
            }
            le[i - low] = max(le[i - low], i + low);
            ri[i + low] = min(ri[i + low], i - low);
        }

        for (int i=1;i<n;i++){
            int low = 0, high = min(i, n - i);
            while (low < high){
                int mid = (low + high + 1) / 2;
                
                if (isPalindrom(i - mid + 1, i + mid)){
                    low = mid;
                } else{
                    high = mid - 1;
                }
            }

            le[i - low + 1] = max(le[i - low + 1], i + low);
            ri[i + low] = min(ri[i + low], i - low + 1);
        }

        for (int i=2;i<=n;i++){
            le[i] = max(le[i], le[i - 1] - 1);
        }
        for (int i=n - 1;i>=1;i--){
            ri[i] = min(ri[i], ri[i + 1] + 1);
        }

        // cout << le[1] << el;
        ans = mp(le[1] + 1, n);
        len = le[1];
        if (hitung(1, ri[n] - 1) > len){
            ans = mp(1, ri[n] - 1);
            len = hitung(1, ri[n] - 1);
        }

        while (l <= r){
            if (s[l] == s[r]){
                l++;
                r--;
                int temp = hitung(min(le[l] + 1, r + 1), r);
                if (temp > len){
                    ans = mp(le[l] + 1, r);
                    len = temp; 
                } 

                temp = hitung(l, max(ri[r] - 1, l - 1));
                if (temp > len){
                    ans = mp(l, ri[r] - 1);
                    len = temp;
                }

            } else break;
        }

        for (int i=1;i<ans.fi;i++){
            cout << s[i];
        }
        for (int i=ans.se+1;i<=n;i++){
            cout << s[i];
        }
        cout << el;

    }

    return 0;
}