// Time Complexity: O(n log log n)
// Least prime factor of each number from 1 to n.

vector<ll> find_min_primes(ll n)
{
    vector<ll> min_prime(n + 1, 0ll);
    for (ll i = 2; i * i <= n; i++)
    {
        if (min_prime[i] == 0)
        {
            // if i is prime
            for (ll j = i * i; j <= n; j += i)
            {
                if (min_prime[j] == 0)
                {
                    min_prime[j] = i;
                }
            }
        }
    }

    for (ll i = 2; i <= n; ++i)
    {
        if (min_prime[i] == 0)
        {
            min_prime[i] = i;
        }
    }
    return min_prime;
}
