#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
 
 
 
bool is_prime(long long n) {
    if (n <= 1) {
        return false;
    }
    for (long long i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
 
int main() {
    time_t start_time = time(NULL);
    long long num = 2;
    while (difftime(time(NULL), start_time) < 60.0) {  
        if (is_prime(num)) {
            printf("%lld ", num);
        }
        num++;
    }
    return 0;
}
 