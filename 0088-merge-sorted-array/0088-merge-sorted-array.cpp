/*Intuition
We have to Merge two sorted arrays to single array keeping all the elements in a sorted order. So i will use Two Pointer Concept to compare elemets .

Approach
I will Create Three variables p1,p2 and p3. p1 will hold the last index nums1. p2 will hold the last index nums2 and p3 will keep track of index where we will place the element.

i am starting from and comparing elements of both arrays and placing maximum value at the end to mantain a sorted order.

i will repeat this step untill all the elements of both the arrays get compared*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1,j = n-1,k = m+n-1;

        while(i >= 0 and j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            }else{
                nums1[k--] = nums2[j--];
            }
        }
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};