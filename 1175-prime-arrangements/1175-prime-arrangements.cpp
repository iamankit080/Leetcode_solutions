class Solution {
public:
    const int modulo = 1000000007;

    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num <= 3) return true;

        if (num % 2 == 0 || num % 3 == 0) return false;

        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }

        return true;
    }

    long long factorial(int n) {
        if (n == 0) return 1;
        return (n * factorial(n - 1)) % modulo;
    }
    int numPrimeArrangements(int n) {
        if (n <= 1) return 1; 

        int primeCount = 0;
        for (int i = 2; i <= n; ++i) {
            if (isPrime(i)) primeCount++;
        }

        int nonPrimeCount = n - primeCount;

        long long primePermutations = factorial(primeCount) % modulo;
        long long nonPrimePermutations = factorial(nonPrimeCount) % modulo;

        long long result = (primePermutations * nonPrimePermutations) % modulo;

        return (result);
    }
};