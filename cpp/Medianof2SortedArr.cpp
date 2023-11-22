#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
/**
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 * (naive solution using standard merge lib)
 * 
 * To be improved using binary search to make it O(log (m+n));
*/
using namespace std;

double findMedian(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
        return nums[0];
    }
    if (n % 2 == 0) { //even
        int mid_1 = n / 2;
        int mid_2 = mid_1 - 1;
       // cout << nums[mid_1] << " " << nums[mid_2] << endl;
        return (double) (nums[mid_1] + nums[mid_2]) / 2;
    } else {
        return nums[floor(n / 2)];
    }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    if (m == 0 && n == 0) {
        return 0;
    }
    if (m == 0) {
        return findMedian(nums2);
    }
    if (n == 0) {
        return findMedian(nums1);
    }
    if (m == 1 && n == 1) {
        return (double) (nums1[0] + nums2[0]) / 2;
    }
    int s1 = nums1[0];
    int e1 = nums1[m-1];
    int s2 = nums2[0];
    int e2 = nums2[n-1];

    int total = m + n;

    if (s2 >= e1) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        return findMedian(nums1);
        
    } else if (s1 >= e2) {
        nums2.insert(nums2.end(), nums1.begin(), nums1.end());
        return findMedian(nums2);
    } else {
        vector<int> vec3(total);
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),vec3.begin());
        return findMedian(vec3);
        /*
        if (n % 2 == 0 && m % 2 == 0) { // both even    
            vector<int> temp;
            int m1 = nums1[m / 2];
            int m2 = nums1[m / 2 - 1];
            int n1 = nums2[n / 2];
            int n2 = nums2[n / 2 - 1];
            temp.push_back(m1);
            temp.push_back(m2);
            temp.push_back(n1);
            temp.push_back(n2);
            sort(temp.begin(), temp.end());

            return findMedian(temp);

        } else if (n % 2 == 0 && m % 2 != 0) { // m is odd
            vector<int> temp;
            int m1 = findMedian(nums1);
            int n1 = nums2[n / 2];
            int n2 = nums2[n / 2 - 1];
            temp.push_back(m1);
            temp.push_back(n1);
            temp.push_back(n2);
            sort(temp.begin(), temp.end());

            return findMedian(temp);

        } else if (n % 2 != 0 && m % 2 == 0) { // n is odd

            vector<int> temp;
            int n1 = findMedian(nums2);
            int m1 = nums1[m / 2];
            int m2 = nums1[m / 2 - 1];
            temp.push_back(n1);
            temp.push_back(m1);
            temp.push_back(m2);
            sort(temp.begin(), temp.end());
            
            return findMedian(temp);
        } else { // both odd
            return (findMedian(nums1) + findMedian(nums2)) / 2;
        }
        */
    }
}


int main() {
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2};

    vector<int> nums3 = {1,3,5};
    vector<int> nums4 = {2,4,7,8};

    vector<int> nums5 = {1,2};
    vector<int> nums6 = {3,4};

    vector<int> nums7 = {3};
    vector<int> nums8 = {-2,-1};

    vector<int> nums9 = {2};
    vector<int> nums10 = {1,3,4,5,6};

    cout << findMedianSortedArrays(nums1, nums2) << "\n";// 2
    cout << findMedianSortedArrays(nums3, nums4) << "\n"; // 4
    cout << findMedianSortedArrays(nums5, nums6) << "\n"; // 2.5
    cout << findMedianSortedArrays(nums7, nums8) << "\n"; // -1
    cout << findMedianSortedArrays(nums9, nums10) << "\n"; // 3.5
   // vector<int> nums = {1};
   // cout << findMedian(nums) << "\n";
   // cout << ceil(3/2) << endl;
    return 0;
}
