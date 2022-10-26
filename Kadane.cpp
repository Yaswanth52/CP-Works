// Time Complexity: O(n)
// Maximum subarray sum


1. Without dp:


ll kadane(ll a[], ll n)
{
    ll max_total = 0, max_now = 0;
    for (ll i = 0; i < n; i++)
    {
        max_now = max_now + a[i];
        if (max_now < 0)
            max_now = 0;
        else if (max_total < max_now)
            max_total = max_now;
    }
    if (max_total > 0)
        return max_total;
    else
    {
        ll *z = max_element(a, a + n);
        ll k = *z;
        return k;
    }
}

2. With dp:

ll kadane_with_dp(ll a[], ll n)
{
    ll dp[n] = {0};
    dp[0] = a[0];
    for (ll i = 0; i < n; i++)
    {
        dp[i] = max(dp[i - 1] + a[i], a[i]);
    }
    ll max_overall = LLONG_MIN;
    for (ll i = 0; i < n; i++)
        max_overall = max(max_overall, dp[i]);
    return max_overall;
}
