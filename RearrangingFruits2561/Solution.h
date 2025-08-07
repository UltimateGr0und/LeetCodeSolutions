#pragma once
#include<vector>
#include<functional>
#include<algorithm>
#include<iterator>

using std::vector;

class Solution {
    void swap(vector<int>::iterator a, vector<int>::reverse_iterator b);
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2);
};