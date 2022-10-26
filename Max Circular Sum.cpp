// Time Complexity: O(n)
// Maximum circular subarray sum

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

ll max_circular_sum(ll a[], ll n)
{
    ll max_kadane = kadane(a, n);
    ll max_wrap = 0, i;
    for (i = 0; i < n; i++)
    {
        max_wrap += a[i]; // Calculate array-sum
        a[i] = -a[i];     // invert the array (change sign)
    }
    max_wrap = max_wrap + kadane(a, n);

    ll k = (max_wrap > max_kadane) ? max_wrap : max_kadane;
    if (k > 0)
        return k;
    else
        return -1ll * (*min_element(a, a + n));
}
