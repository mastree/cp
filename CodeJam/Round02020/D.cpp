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

int q, b;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q >> b;

    while (q--){
        if (b == 10){
            bitset<10> bit;
            vector<int> sama, beda;
            int n = 10;
            int last = 0;

            bool com = 0, rev = 0;
            for (int i=1;i<=150;i++){
                // cout << "ask #" << i << el;
                int feed;
                if (i > 10 && (i % 10) == 1){
                    if (!sama.empty()){
                        cout << sama[0] << endl;
                        cin >> feed;
                        if (feed != bit[sama[0] - 1]){
                            com = 1;
                        }
                    } else{
                        cout << 1 << endl;
                        cin >> feed;
                    }
                } else if (i > 10 && (i % 10) == 2){
                    if (!beda.empty()){
                        cout << beda[0] << endl;
                        cin >> feed;
                        if (feed != bit[beda[0] - 1]){
                            if (!com){
                                rev = 1;
                            }
                        } else{
                            if (com){
                                rev = 1;
                            }
                        }
                    } else{
                        cout << 1 << endl;
                        cin >> feed;
                    }

                    if (com){
                        bit.flip();
                    }
                    if (rev){
                        for (int pos = 0;pos < n / 2;pos++){
                            bool temp = bit[pos];
                            bit[pos] = bit[n - pos - 1];
                            bit[n - pos - 1] = temp;
                        }
                    }
                    com = rev = 0;
                } else if (i % 10 == 1){
                    cout << last + 1 << endl;
                    cin >> feed;
                    bit[last] = feed;
                } else{
                    if (i & 1){
                        cout << last + 1 << endl;
                        cin >> feed;
                        bit[last] = feed;
                    } else{
                        cout << n - last << endl;
                        cin >> feed;
                        bit[n - last - 1] = feed;
                        if (bit[last] == bit[n - last - 1]){
                            sama.pb(last + 1);
                        } else{
                            beda.pb(last + 1);
                        }
                        last++;
                    }
                }
                // cout << "feed: " << feed << el;
                if (last == n / 2) break;
            }

            for (int i=0;i<n;i++){
                cout << bit[i];
            }
            cout << endl;
            char cek;
            cin >> cek;

            if (cek == 'N') return 0;
        } else if (b == 20){
            bitset<20> bit;
            vector<int> sama, beda;
            int n = 20;
            int last = 0;

            bool com = 0, rev = 0;
            for (int i=1;i<=150;i++){
                int feed;
                // cout << "ask #" << i << el;
                if (i > 10 && (i % 10) == 1){
                    if (!sama.empty()){
                        cout << sama[0] << endl;
                        cin >> feed;
                        if (feed != bit[sama[0] - 1]){
                            com = 1;
                        }
                    } else{
                        cout << 1 << endl;
                        cin >> feed;
                    }
                } else if (i > 10 && (i % 10) == 2){
                    if (!beda.empty()){
                        cout << beda[0] << endl;
                        cin >> feed;
                        if (feed != bit[beda[0] - 1]){
                            if (!com){
                                rev = 1;
                            }
                        } else{
                            if (com){
                                rev = 1;
                            }
                        }
                    } else{
                        cout << 1 << endl;
                        cin >> feed;
                    }

                    if (com){
                        bit.flip();
                    }
                    if (rev){
                        for (int pos = 0;pos < n / 2;pos++){
                            bool temp = bit[pos];
                            bit[pos] = bit[n - pos - 1];
                            bit[n - pos - 1] = temp;
                        }
                    }
                    com = rev = 0;
                } else if (i % 10 == 1){
                    cout << last + 1 << endl;
                    cin >> feed;
                    bit[last] = feed;
                } else{
                    if (i & 1){
                        cout << last + 1 << endl;
                        cin >> feed;
                        bit[last] = feed;
                    } else{
                        cout << n - last << endl;
                        cin >> feed;
                        bit[n - last - 1] = feed;
                        if (bit[last] == bit[n - last - 1]){
                            sama.pb(last + 1);
                        } else{
                            beda.pb(last + 1);
                        }
                        last++;
                    }
                }
                // cout << "feed: " << feed << el;
                if (last == n / 2) break;
            }

            for (int i=0;i<n;i++){
                cout << bit[i];
            }
            cout << endl;
            char cek;
            cin >> cek;

            if (cek == 'N') return 0;
        } else {
            bitset<100> bit;
            vector<int> sama, beda;
            int n = 100;
            int last = 0;

            bool com = 0, rev = 0;
            for (int i=1;i<=150;i++){
                int feed;
                if (i > 10 && (i % 10) == 1){
                    if (!sama.empty()){
                        cout << sama[0] << endl;
                        cin >> feed;
                        if (feed != bit[sama[0] - 1]){
                            com = 1;
                        }
                    } else{
                        cout << 1 << endl;
                        cin >> feed;
                    }
                } else if (i > 10 && (i % 10) == 2){
                    if (!beda.empty()){
                        cout << beda[0] << endl;
                        cin >> feed;
                        if (feed != bit[beda[0] - 1]){
                            if (!com){
                                rev = 1;
                            }
                        } else{
                            if (com){
                                rev = 1;
                            }
                        }
                    } else{
                        cout << 1 << endl;
                        cin >> feed;
                    }

                    if (com){
                        bit.flip();
                    }
                    if (rev){
                        for (int pos = 0;pos < n / 2;pos++){
                            bool temp = bit[pos];
                            bit[pos] = bit[n - pos - 1];
                            bit[n - pos - 1] = temp;
                        }
                    }
                    com = rev = 0;
                } else if (i % 10 == 1){
                    cout << last + 1 << endl;
                    cin >> feed;
                    bit[last] = feed;
                } else{
                    if (i & 1){
                        cout << last + 1 << endl;
                        cin >> feed;
                        bit[last] = feed;
                    } else{
                        cout << n - last << endl;
                        cin >> feed;
                        bit[n - last - 1] = feed;
                        if (bit[last] == bit[n - last - 1]){
                            sama.pb(last + 1);
                        } else{
                            beda.pb(last + 1);
                        }
                        last++;
                    }
                }
                if (last == n / 2) break;
            }

            for (int i=0;i<n;i++){
                cout << bit[i];
            }
            cout << endl;
            char cek;
            cin >> cek;

            if (cek == 'N') return 0;
        }
    }

    return 0;
}