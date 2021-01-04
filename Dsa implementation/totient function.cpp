vt<ll> phi(maxN + 2);

void computeTotient(ll n = maxN)
{
  // Create and initialize an array to store
  // phi or totient values
  for (ll i = 1; i <= n; i++)
    phi[i] = i; // indicates not evaluated yet
  // and initializes for product
  // formula.

  // Compute other Phi values
  for (ll p = 2; p <= n; p++)
  {
    // If phi[p] is not computed already,
    // then number p is prime
    if (phi[p] == p)
    {
      // Phi of a prime number p is
      // always equal to p-1.
      phi[p] = p - 1;

      // Update phi values of all
      // multiples of p
      for (ll i = 2 * p; i <= n; i += p)
      {
        // Add contribution of p to its
        // multiple i by multiplying with
        // (1 - 1/p)
        phi[i] = (phi[i] / p) * (p - 1);
      }
    }
  }
}
