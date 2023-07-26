#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> temples(n);
    for (int i = 0; i < n; i++) {
        cin >> temples[i];
    }

    // Sort the temples' positions in ascending order
    sort(temples.begin(), temples.end());

    // Initialize a priority queue to store the distances
    priority_queue<pair<int, int>> distances;

    // Calculate the initial distances between adjacent temples
    for (int i = 1; i < n; i++) {
        int dist = (temples[i] - temples[i - 1]) / 2;
        distances.push({dist, temples[i - 1] + dist});
    }

    // Initialize the result vector to store the saints' positions
    vector<int> saints;

    // Place the saints based on the distances
    while (m > 0 && !distances.empty()) {
        int dist = distances.top().first;
        int position = distances.top().second;
        distances.pop();

        // Add the saint's position to the result vector
        saints.push_back(position);

        // Decrease the remaining number of saints
        m--;

        // Update the distances by splitting the range into two parts
        if (dist > 1) {
            distances.push({dist - 1, position - (dist - 1)});
            distances.push({dist - 1, position + (dist - 1)});
        }
    }

    // If there are still remaining saints, add them at the ends
    while (m > 0) {
        saints.push_back(temples[0] - 1);
        saints.push_back(temples[n - 1] + 1);
        m -= 2;
    }

    // Sort the saint's positions in ascending order
    sort(saints.begin(), saints.end());

    // Calculate the sum of distances
    long long sumDistances = 0;
    for (int i = 0; i < n; i++) {
        int closestTemple = *lower_bound(saints.begin(), saints.end(), temples[i]);
        sumDistances += abs(closestTemple - temples[i]);
    }

    // Print the result
    cout << sumDistances << endl;
    for (int i = 0; i < saints.size(); i++) {
        cout << saints[i] << " ";
    }
    cout << endl;

    return 0;
}
