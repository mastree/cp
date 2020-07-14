struct BigInt{
    vector<int> dig;
    int length = 0;

    BigInt(int sz){
        length = sz;
        dig.resize(sz, 0);
    }
    BigInt(ll x){
        while (x > 0){
            dig.pb(x % 10);
            x /= 10;
            length++;
        }
    }

    const BigInt operator+(const BigInt& b){
        int rlen = max(length, b.length);
        BigInt ret = BigInt(rlen);
        int carry = 0;
        for (int i=0;i<rlen;i++){
            int cur = carry;
            if (length > i){
                cur += dig[i];
            }
            if (b.length > i){
                cur += b.dig[i];
            }
            ret.dig[i] = cur % 10;
            carry = cur / 10;
        }
        if (carry){
            ret.length++;
            ret.dig.pb(carry);
        }
        return ret;
    }

    void printBI(){
        bool udh = 0;
        for (int i=length - 1;i>=0;i--){
            if (dig[i]) udh = 1;
            if (udh) cout << dig[i];
        }
    }
};