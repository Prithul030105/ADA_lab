#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight, value;
};

// Comparator to sort items by value/weight ratio
bool cmp(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

// Function to solve the Fractional Knapsack problem
double fractionalKnapsack(int W, vector<Item> &items) {
    sort(items.begin(), items.end(), cmp); // Sort items by value/weight ratio

    double maxValue = 0.0;
    for (auto &item : items) {
        if (W >= item.weight) { // If the full item fits
            maxValue += item.value;
            W -= item.weight;
        } else { // If only part of the item fits
            maxValue += (double)item.value * ((double)W / item.weight);
            break;
        }
    }
    return maxValue;
}

int main() {
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}}; // {weight, value}
    int W = 50; // Maximum weight of knapsack

    cout << "Maximum Value in Knapsack = " << fractionalKnapsack(W, items) << endl;
    return 0;
}
