/* FIXME: Implement! */
#include <stdlib.h>
#include <stdio.h>
#include <limits.h> 

int maxSubArray(int A[], int n) {
    return findMaxSub(A, 0, n-1, INT_MIN);
}

int findMaxSub(int A[], int left, int right, int tmax) {
    if(left > right) return INT_MIN;
    

    int mid = left + (right - left) / 2;
    //得到子区间[left, mid - 1]最大值
    int lmax = findMaxSub(A, left, mid - 1, tmax);
    //得到子区间[mid + 1, right]最大值
    int rmax = findMaxSub(A, mid + 1, right, tmax);

    //tmax = max(tmax, lmax);
    if(lmax>tmax) tmax=lmax;
    //tmax = max(tmax, rmax);
    if(rmax>tmax) tmax=rmax;

    int sum = 0;
    int mlmax = 0;
    //得到[left, mid - 1]最大值
    for(int i = mid - 1; i >= left; i--) {
        sum += A[i];
        //mlmax = max(mlmax, sum);
        if(sum>mlmax) mlmax=sum;
    }

    sum = 0;
    int mrmax = 0;
    //得到[mid + 1, right]最大值
    for(int i = mid + 1; i <= right; i++) {
        sum += A[i];
        //mrmax = max(mrmax, sum);
        if(sum>mrmax) mrmax=sum;
    }

    //tmax = max(tmax, A[mid] + mlmax + mrmax);
    if(A[mid]+mlmax+mrmax>tmax) tmax=A[mid]+mlmax+mrmax;
    return tmax;
}

int main()
{
    int array[9] =  {-2,1,-3,4,-1,2,1,-5,4};

    int len = sizeof(array)/sizeof(array[0]);
    int result = maxSubArray(array, len);
    printf("%d\n",result);

    return 0;
}
