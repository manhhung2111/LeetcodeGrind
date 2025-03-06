/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> mp;
        for (Employee* employee : employees) {
            mp[employee->id] = employee;
        }

        int result = 0;
        queue<int> q;
        q.push(id);

        while (!q.empty()) {
            Employee* employee = mp[q.front()]; q.pop();
            result += employee->importance;

            for (int id : employee->subordinates) {
                q.push(id);
            }
        }

        return result;
    }
};