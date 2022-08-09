/*
    Problem Link : https://atcoder.jp/contests/dp/tasks/dp_j
*/
double dp[310][310][310];
void solve(){
    // dp[i][j][k] -> expected no of times the operation is performed where i is the number of plates with 3 shushi , similiarly j for 2 and k for 1
    // dp[i][j][k] =
    // if zero plate is picked then 
    // (n - (i + j + k))/n * (1 + dp[i][j][k]) + 
    // if three plate is picked
    // (i/n)(1 + dp[i-1][j+1][k]) + 
    // if two plate is picked 
    // (j/n)(1 + dp[i][j-1][k+1]) + 
    // at last if one plate is picked
    // (k/n)(1 + dp[i][j][k-1])
    // complete equation is dp[i][j][k] = (n - (i + j + k))/n * (1 + dp[i][j][k]) + (i/n)(1 + dp[i-1][j+1][k]) + (j/n)(1 + dp[i][j-1][k+1]) + (k/n)(1 + dp[i][j][k-1])
    int cnt[4] = {0};
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        cnt[v[i]]++;
    }
    for(int three = 0; three <= n; three++){
        for(int two = 0; two <= n; two++){
            for(int one = 0; one <= n; one++){
                int zero = n - (three + two + one);
                if(zero == n) continue;
                if(three + one + two > n) continue;
                double val = 0;
                if(three > 0) val += three * (1 + dp[three-1][two+1][one]);
                if(two > 0) val += two * (1 + dp[three][two-1][one+1]);
                if(one > 0) val += one * (1 + dp[three][two][one-1]);
                val += zero;
                val /= (n - zero);
                dp[three][two][one] = val;
            }
        }
    }
    cout<<fixed<<setprecision(9);
    cout<<dp[cnt[3]][cnt[2]][cnt[1]]<<endl;
}
