/*
Time limit: 180ms
Memory limit: 256mb

Description:
A valley element is an element that is strictly less than its neighbors(neighbor elements is adjacent to the current element).
Given a 0-indexed integer array nums, find a valley element, and return its index. 
If the array contains multiple valleys, return the index to any of the valleys.
You may imagine that nums[-1] = nums[n] = +∞. In other words, 
an element is always considered to be strictly less than a neighbor that is outside the array.
Hint: You must write an algorithm that runs in O(log n) time.


-----------------------Copy the following code, complete it and submit-----------------------
*/
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
#include <string.h>


int findValleyIndex(int arr[], int n) {
	// WRITE YOUR CODE HERE
    int low = 0;
    int high = n-1;
    while (low < high) {
        int mid = low + (high - low) / 2;

        // Comparing the middle element with the next element to decide the direction
        if (arr[mid] > arr[mid + 1]) {
            // Valley is on the right
            low = mid + 1;
        } else {
            // Valley is on the left
            high = mid;
        }
    }
    return low; 
}



int main(int argc, char *argv[]) {
	

	int N;
	scanf("%d", &N);
	
	int nums[N];
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &nums[i]);
	}
	
	int index;
	
	for(int i = 0; i < 50; i++){
		index = findValleyIndex(nums, N);
	}
	printf("%d", index);
	
}














/*
-----------------------------------------End of Code-----------------------------------------

Input:
First line is two integers N, k;
Second line is the array of N integers;
Next k lines are k left endpoint and right endpoint.
0 <= N <= 10^8

Output:
The index of the valley element

Sample Input 1:			
4
9 5 3 8	
Sample Output 1:
2

Sample Input 2:
6
8 5 4 3 6 7
Sample Output 2:
3
*/