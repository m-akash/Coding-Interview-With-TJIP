class RandomizedSet {
public:
    vector<int> randomSet;
    unordered_map<int, int> value_to_index;
    RandomizedSet() {
        randomSet.clear();
        value_to_index.clear();
    }
    
    bool insert(int val) {
        if(value_to_index.find(val) != value_to_index.end()) {
            return false;
        }
        value_to_index[val] = randomSet.size();
        randomSet.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(value_to_index.find(val) == value_to_index.end()) {
            return false;
        }
        int target_index = value_to_index[val];
        int last_element = randomSet.back();
        swap(randomSet[target_index], randomSet[randomSet.size() - 1]);
        randomSet.pop_back();
        value_to_index[last_element] = target_index;
        value_to_index.erase(val);
        return true;
    }
    
    int getRandom() {
        int random_index = rand() % randomSet.size();
        return randomSet[random_index];
    }
};
