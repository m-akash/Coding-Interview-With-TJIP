class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        map<int, int> index_of_element;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            int a = arr[i]; 
            int needed = target - a;
            if(index_of_element.find(needed) != index_of_element.end()){
                return {index_of_element[needed], i};
            }
            index_of_element[a] = i;
        }
        return {};
    }
};
