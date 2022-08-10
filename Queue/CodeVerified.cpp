#include <vector>

using namespace std;


vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    // write your code here
    sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
        return u[0] > v[0] || (u[0] == v[0] && u[1] < v[1]);
    });
    vector<vector<int>> ans;
    for (const vector<int>& person: people) {
        ans.insert(ans.begin() + person[1], person);
    }
    return ans;
}

vector<vector<int>> initial_data(){
    vector<vector<int>> raw = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    return raw;
}

bool varify(vector<vector<int>> test){
    vector<vector<int>> raw = initial_data();
    vector<vector<int>> target = reconstructQueue(raw);
    bool result = test == target;
    return result;
}