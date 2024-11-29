# include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#include "utils.h"

#define MAX 20000
int log_base_3(long long N) {
    if (N <= 0) return -1; // Logarithm undefined for non-positive numbers

    // Calculate log base 3 using natural logarithm (log(N) / log(3))
    double result = log(N) / log(3);

    // Check if result is close to an integer to determine if N is a power of 3
    if (fabs(result - round(result)) < 1e-10) {  // tolerance to handle floating-point precision
        return (int)round(result);
    } else {
        return -1;  // Not a power of 3
    }
}
int main(){
    long long N; 
    scanf("%lld", &N);
    if (N < 1) {
        printf("%d\n", -1);
        return 0;
    }
    long long powers[MAX+1]; 
    int last = 0;
    powers[last] = 1;
    while (powers[last] < N && last < MAX) {
        powers[last+1] = powers[last] * 3;
        last++;
    }

    while (powers[last] < N){
        N/=powers[last];
    }

    
    if (powers[last] == N) printf("%d\n", log_base_3(N));
    else printf("%d\n", -1);

}
