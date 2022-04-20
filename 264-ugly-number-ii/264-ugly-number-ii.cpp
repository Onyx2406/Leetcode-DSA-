class Solution {
public:
    int nthUglyNumber(int n) {
    vector<int> dp(n);
    dp[0] = 1;

    int two, three, five;
    two = three = five = 0;
    for (int i = 1; i < n; i++) {
        int two_multiple = dp[two] * 2;
        int three_multiple = dp[three] * 3;
        int five_multiple = dp[five] * 5;

        dp[i] = min({two_multiple, three_multiple, five_multiple});

        if (dp[i] == two_multiple)
            two++;
        if (dp[i] == three_multiple)
            three++;
        if (dp[i] == five_multiple)
            five++;
    }
    return dp[n - 1];
}
};