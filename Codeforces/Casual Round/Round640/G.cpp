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

int a4[4] = {3, 1, 4, 2};
int a5[5] = {1, 3, 5, 2, 4};
int a6[6] = {1, 3, 5, 2, 4, 6};
int a7[7] = {1, 3, 5, 2, 6, 4, 7};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> n;
        if (n < 4){
            cout << -1 << el;
            continue;
        }

        int sisa = n % 4;
        // n -= 4;
        sisa += 4;
        if (sisa == 4){
            for (auto x : a4){
                cout << x << " ";
            }
            for (int i=5;i<=n;i+=4){
                if ((i / 4) % 2 == 0){
                    for (auto x : a4){
                        cout << x + i - 1 << " ";
                    }
                }
                else{
                    for (int j=3;j>=0;j--){
                        cout << a4[j] + i - 1 << " ";
                    }
                }
            }
            cout << el;
        } else if (sisa == 5){
            for (auto x : a5){
                cout << x << " ";
            }
            for (int i=6;i<=n;i+=4){
                if ((i / 4) % 2 == 0){
                    for (auto x : a4){
                        cout << x + i - 1 << " ";
                    }
                }
                else{
                    for (int j=3;j>=0;j--){
                        cout << a4[j] + i - 1 << " ";
                    }
                }
            }
            cout << el;
        } else if (sisa == 6){
            for (auto x : a6){
                cout << x << " ";
            }
            for (int i=7;i<=n;i+=4){
                if ((i / 4) % 2 == 0){
                    for (auto x : a4){
                        cout << x + i - 1 << " ";
                    }
                }
                else{
                    for (int j=3;j>=0;j--){
                        cout << a4[j] + i - 1 << " ";
                    }
                }
            }
            cout << el;
        } else{
            for (auto x : a7){
                cout << x << " ";
            }
            for (int i=8;i<=n;i+=4){
                if ((i / 4) % 2 == 0){
                    for (auto x : a4){
                        cout << x + i - 1 << " ";
                    }
                }
                else{
                    for (int j=3;j>=0;j--){
                        cout << a4[j] + i - 1 << " ";
                    }
                }
            }
            cout << el;
        }
    }

    return 0;
}

