#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0;
    int j = numbers.size() - 1;

    while(i < j) {
        if(numbers[i] + numbers[j] == target) {
            return {i + 1, j + 1};
        }
        else if(numbers[i] + numbers[j] > target) {
            j--;
        }
        else {
            i++;
        }
    }
    return {-1, -1};
}

int main() {
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> numbers(n);

    cout << "Enter sorted array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    cout << "Enter target: ";
    cin >> target;

    vector<int> result = twoSum(numbers, target);

    cout << "Indices: " << result[0] << " " << result[1] << endl;

    return 0;
}