/*
Complexity Analysis

Time Complexity: O (N)
Space Complexity: O (N)
*/
class Solution {
public:
    unordered_map<int, Employee*> id_to_employee;
    int calcImportanceFrom(int id) {
        auto& current_employee = id_to_employee[id];
        int sum = current_employee->importance;
        for (auto v_id : current_employee->subordinates) {
            sum += calcImportanceFrom(v_id);
        }
        return sum;
    }
    int getImportance(vector<Employee*> employees, int id) {
        id_to_employee.clear();
        for (auto& employee : employees) {
            id_to_employee[employee->id] = employee;
        }
        return calcImportanceFrom(id);
    }
};
