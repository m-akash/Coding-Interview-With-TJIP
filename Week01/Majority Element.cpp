class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        int majority = arr[0]; int vote = 1;
        for(int i = 1; i < n; i++) {
            if(vote == 0) {
                vote = 1;
                majority = arr[i];
            }
            else if(arr[i] == majority) {
                vote++;
            }
            else{
                vote--;
            }
        }
        return majority;
    }
};
