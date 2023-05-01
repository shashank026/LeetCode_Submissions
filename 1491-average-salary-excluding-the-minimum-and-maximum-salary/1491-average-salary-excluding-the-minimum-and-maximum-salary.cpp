class Solution {
public:
    double average(vector<int>& salary) {
        int Max_Salary = INT_MIN, Min_Salary = INT_MAX;
        double ans = 0;
        for(int i=0;i<salary.size();++i){
            ans += salary[i];
            Max_Salary = max(Max_Salary, salary[i]);
            Min_Salary = min(Min_Salary, salary[i]);
        }
        ans -= (Max_Salary + Min_Salary);
        return ans/(salary.size()-2);
    }
};