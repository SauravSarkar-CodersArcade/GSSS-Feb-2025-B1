#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
struct Item {
    int value;
    int weight;
};
class Solution {
public:
    static bool compare(pair<double, Item> a, pair<double, Item> b){
        return a.first > b.first;
    }
    static double fractionalKnapsack(int w, Item arr[], int n){
        // Store the per unit value
        vector<pair<double, Item>> v;
        for(int i=0; i<n; i++){
            double perUnitValue = (1.0 * arr[i].value / arr[i].weight);
            pair<double, Item> p = make_pair(perUnitValue, arr[i]);
            v.push_back(p);
        }
        // Sort the per unit value in descending order
        sort(v.begin(), v.end(), compare);
        double totalValue = 0;
        for(int i=0; i<n; i++){
            if(v[i].second.weight > w){
                // I can only take a fraction of the weight
                totalValue += w * v[i].first;
                w = 0;
            }else{
                // I can take the whole value & weight
                totalValue += v[i].second.value;
                w = w - v[i].second.weight;
            }
        }
        return totalValue;
    }
};
int main() {
    int w = 50;
    Item arr[] = {{60,10},{100,20},{120,30}};
    int n = 3;
    cout << Solution::fractionalKnapsack(w, arr, n) << endl;
    printf("%0.6lf\n", Solution::fractionalKnapsack(w,arr,n));
    return 0;

}
