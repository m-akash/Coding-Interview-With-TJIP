class Solution {
public:
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n) {
        int left = m-1; int right = n-1;
        int index = m + n -1;
        while(right >= 0) {
            if(left >= 0 and arr1[left] > arr2[right]) {
                arr1[index] = arr1[left];
                left--, index--;
            }
            else {
                arr1[index] = arr2[right];
                right--, index--;
            }
        }
    }
};
