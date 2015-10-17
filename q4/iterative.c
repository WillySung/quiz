/* FIXME: Implement! */
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int maxSubArray(int A[], int n)
{
    if(n<=0) return 0;
    int maxSum = A[0], curSum = A[0];
    for(int i=1; i<n; i++) {
        curSum =  curSum<=0 ? A[i] : A[i]+curSum;
        if(maxSum<curSum) maxSum=curSum;
    }
    return maxSum;
}

int main()
{
    int array[9] =  {-2,1,-3,4,-1,2,1,-5,4};

    int len = sizeof(array)/sizeof(array[0]);
    int result = maxSubArray(array, len);
    printf("%d\n",result);

    return 0;
}
