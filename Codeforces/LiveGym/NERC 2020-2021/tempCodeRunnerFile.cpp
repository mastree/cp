
        vector<int> temp = vec;
        int cur = 0;
        while (!is_sorted(temp) && cur < N + N){
            cur++;
            if (cur & 1){
                operasi1(temp);
            } else{
                operasi2(temp);
            }
        }
        if (cur != N + N){
            ans = min(ans, cur);
        }
    }