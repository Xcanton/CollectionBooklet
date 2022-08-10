
/** 
 * 
 * 假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性
 * （不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，
 * 前面 正好 有 ki 个身高大于或等于 hi 的人。
 * 
 * 请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，
 * 其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。
 * 
 * You are given an array of people, people, which are 
 * the attributes of some people in a queue (not necessarily in order). 
 * Each people[i] = [hi, ki] represents the ith person of height hi 
 * with exactly ki other people in front who have a height greater than 
 * or equal to hi.
 * 
 * Reconstruct and return the queue that is represented by the input array
 *  people. The returned queue should be formatted as an array queue, 
 * where queue[j] = [hj, kj] is the attributes of the jth person in 
 * the queue (queue[0] is the person at the front of the queue).
*/

#include "CodeVerified.cpp"
#include <vector>
#include <iostream>

using namespace std;


vector<vector<int>> reconstruct_queue_solution(vector<vector<int>>& people) {
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

int main(){
    vector<vector<int>> raw = initial_data();
    vector<vector<int>> test = reconstruct_queue_solution(raw);
    bool result = varify(test);
    cout << std::boolalpha << result << endl;
    return 0;
}