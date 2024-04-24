#pragma once
#include "../global.h"

namespace slisc {

// number of prime numbers smaller than n
// verified with leetcode 204
inline Long nprimes(Long_I N)
{
	if (N <= 2) return 0;
	if (N == 3) return 1;
	Long Nh = N/2;
	vector<bool> isprime(Nh, true); // isprime[i] for (2*i+1)
	for (Long i = 1; sqr(2*i+1) < N; ++i)
		if (isprime[i])
			for (Long p = 2*i+1, j = i+p; j < Nh; j += p)
				isprime[j] = false;
	Long ret = 2;
	for (Long i = 2; i < Nh; ++i)
		if (isprime[i])
			++ret;
	return ret;
}

// get all the prime numbers smaller than n
inline void primes(vecLong_O v, Long_I N)
{
	v.clear();
	if (N <= 2) return;
	v.push_back(2);
	if (N == 3) return;
	Long i, Nh = N/2;
	vector<bool> isprime(Nh, true); // isprime[i] for (2*i+1)
	for (i = 1; sqr(2*i+1) < N; ++i) {
		if (isprime[i]) {
			v.push_back(2*i+1);
			for (Long p = 2*i+1, j = i+p; j < Nh; j += p)
				isprime[j] = false;
		}
	}
	for (; i < Nh; ++i)
		if (isprime[i])
			v.push_back(2*i+1);
}

// extend a list of ordered prime numbers to smaller than N
// v = [2,3,5,7,11....]
inline void primes_ext(vecLong_IO v, Long_I N)
{
	// N_old is even
	Long Nv = v.size(), N_old = v.back()+1;
	assert(Nv >= 5);
	assert(N > N_old);
	Long i = 0, Nb = N/2-N_old/2;
	// isprime[i] for (N_old+2*i+1)
	vector<bool> isprime(Nb, true);
	for (Long i = 1; i < Nv; ++i) {
		Long p = v[i];
		Long n = N_old/p + 1;
		if (!isodd(n)) ++n;
		Long j_beg = (n*p - N_old)/2;
		for (Long j = j_beg; j < Nb; j += p)
			isprime[j] = false;
	}
	if (N_old+1 < sqrt(N))
		for (; sqr(N_old+2*i+1) < N; ++i) {
			if (isprime[i]) {
				v.push_back(N_old+2*i+1);
				for (Long p = N_old+2*i+1, j = i+p; j < Nb; j += p)
					isprime[j] = false;
			}
		}
	for (; i < Nb; ++i)
		if (isprime[i])
			v.push_back(N_old+2*i+1);
}

// get the at least first N prime numbers
inline void primes2(vecLong_O v, Long_I Nprime)
{
	Long N = 2*Nprime;
	primes(v, N);
	while (size(v) < Nprime) {
		N = max(Long(N*1.1), N/size(v)*Nprime);
		primes_ext(v, N);
	}
}

} // namespace slisc
