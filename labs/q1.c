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

int circular_left_shift(int a[], int output[], int n, int k) {
  // WRITE YOUR CODE HERE
  for (int i = 0; i < n; i++) {
      if (i-k < 0) {
          output[(i-k+n) % n] = a[i];
      } else {
          output[i-k] = a[i];
      }
  }
  return 1;
}

// DO NOT MODIFY THE CODE BELOW
int print_output(int output[], int n) {
  int i = 0;
  for (i = 0; i < n; i++) {
    printf("%d ", output[i]);
  }
  printf("\n");
  return 0;
}

int main() {
  int a[10240];
  int output[10240];
  int n, k, i;

  // read the input array and k
  scanf("%d", &n);
  scanf("%d", &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // initialize the array output
  for (i = 0; i < n; i++) {
    output[i] = 0;
  }

  int res = circular_left_shift(a, output, n, k);
  print_output(output, n);
  return 0;
}



/*
-----------------------------------------End of Code-----------------------------------------

Input:
The first line contains two integers: N and k (k can be 0);
The second line contains a, an array of N integers, a_0, a_1, ..., a_(N-1);
0 <= N <= 10^3

Output:
The shifted array.

Sample Input 1:
4 3
1 2 3 4

The first shift: 	
2 3 4 1
The second shift: 	
3 4 1 2
The third shift: 	
4 1 2 3
Therefore, Sample Output 1:
4 1 2 3

Sample Input 2:
1 5   
100
Sample Output 2:
100

Sample Input 3:
3 0 
3 2 1
Sample Output 3:
3 2 1
*/