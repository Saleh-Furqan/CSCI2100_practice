// Time limit: 5ms
// Memory limit: 256mb

// Description:
// Given an array of positive integers nums and two positive integer L and R, 
// return the number of contiguous subarrays where the product of all the elements 
// in the subarray is strictly between L and R, i.e. (L, R).

// -----------------------Copy the following code, complete it and submit-----------------------

/*
I, Saleh Furqan, am submitting the assignment for
an individual project.
I declare that the assignment here submitted is original except for
source material explicitly acknowledged, the piece of work, or a part
of the piece of work has not been submitted for more than one purpose
(i.e. to satisfy the requirements in two different courses) without
declaration. I also acknowledge that I am aware of University policy
and regulations on honesty in academic work, and of the disciplinary
guidelines and procedures applicable to breaches of such policy and
regulations, as contained in the University website
http://www.cuhk.edu.hk/policy/academichonesty/.
It is also understood that assignments without a properly signed
declaration by the student concerned will not be graded by the
teacher(s).
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>





#define MAX_LEN 1024
#define INT_MIN -2147483648

int num_subarrays_product_between_L_and_R(int* nums, int numsSize, int L, int R) {
    // WRITE YOUR CODE HERE
    int count = 0, left = 0, right = 0;
    long long product = 1;

    for (right = 0; right < numsSize; ++right) {
        product *= nums[right];
        while (left <= right && product >= L) {
            product /= nums[left++];
        }
        if (product < R) {
            count += right - left + 1;
        }
    }
    return count;
}

int main() {
    int L = 10;
    int R = 100;

    int size_nums;
    int nums[MAX_LEN];
    
    scanf("%d", &size_nums);
    scanf("%d", &L);
    scanf("%d", &R);

    for (int i = 0; i < size_nums; i++) {
        scanf("%d", &nums[i]);
    }
    
    int result = num_subarrays_product_between_L_and_R(nums, size_nums, L, R);
    printf("%d\n", result);

    return 0;
}





// -----------------------------------------End of Code-----------------------------------------

// Input:
// First line consists of three integers N, L and R;
// Second line is an array A of N positive integers;

// Output:
// The number of subarrays with product between L and R.
// If there exist no subarray with sum at least K, return 0.

// Sample Input 1:		
// 4 10 100
// 10 5 2 6
// Sample output 2:
// 3