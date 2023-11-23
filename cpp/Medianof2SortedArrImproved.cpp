#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
/**
 * We check if the maximum element of the left half of nums1 is less than or equal to the minimum element of the right half of nums2 and 
 * the maximum element of the left half of nums2 is less than or equal to the minimum element of the right half of nums1. 
 * If this condition is true, we have found the partition such that the number of elements on the left side of the combined array is equal to the number of elements on the right side of the combined array. 
 
If the condition is false, we adjust the partition of nums1 by changing l to mid1 + 1 if the maximum element of the left half of nums1 is greater than the minimum element of the right half of nums2, 
or by changing r to mid1 - 1 otherwise. We continue the binary search until we find the partition such that the condition is true or until the search space is exhausted.
*/
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
        
    // If nums1 is larger than nums2, swap them to ensure n1 <= n2.
    if (n1 > n2) {
        return findMedianSortedArrays(nums2, nums1);
    }
        
    int l = 0;
    int r = n1;

    while (l <= r) {
        int mid1 = (l + r) / 2;
        int mid2 = (n1 + n2 + 1) / 2 - mid1;
            
        int maxLeft1 = (mid1 == 0) ? INT_MIN : nums1[mid1-1];
        int minRight1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
            
        int maxLeft2 = (mid2 == 0) ? INT_MIN : nums2[mid2-1];
        int minRight2 = (mid2 == n2) ? INT_MAX : nums2[mid2];
            
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((n1 + n2) % 2 == 0) { // even length
                return (double)(max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2;
            } else {
                return (double)max(maxLeft1, maxLeft2);
            }
        } else if (maxLeft1 > minRight2) {
            r = mid1 - 1;
        } else {
            l = mid1 + 1;
        }
    }
        
    return -1;
}


int main() {
    return 0; 
}