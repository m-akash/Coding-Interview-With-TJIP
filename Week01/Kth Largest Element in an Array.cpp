mt19937 rng(0);
class Solution {
public:
    int partition(vector<int> &arr, int L, int R) {
        int pivot = arr[R];
        int i = L - 1;
        for(int j = L; j < R; j++) {
            if(arr[j] <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[R]);
        return i + 1;
    }
    void partial_sort(vector<int> & arr, int k) {
        shuffle(arr.begin(), arr.end(), rng);
        int L = 0; int R = arr.size() - 1;
        int threshold = 2 * log2(arr.size());
        while(L < R and threshold--) {
            int p = partition(arr, L, R);
            if(p < k) {
                L = p + 1;
            }
            else if(p > k) {
                R = p - 1;
            }
            else{
                break;
            }
        }
    }
    int findKthSmallest(vector<int>& arr, int k) {
        partial_sort(arr, k);
        return arr[k];
    }
    int findKthLargest(vector<int>& arr, int k) {
        return findKthSmallest(arr, arr.size() - k);
    }
};
