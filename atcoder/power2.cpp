#include <bits/stdc++.h>
using namespace std;

signed main()
{
    string binary;
    getline(cin, binary); // Read the entire line as a string
    istringstream iss(binary); // Create an input string stream
    vector<bool> bin(64, false);
    int sum = 0;
    int i = 0;
    int l;
    while (iss >> l) {
        bin[i] = (l == 1);
        if (bin[i])
        {
            int lambda = 1;
            for (int j = 0; j < i; j++)
            {
                lambda *= 2;
            }
            sum += lambda;
        }
        i++;
    }
    cout << sum << endl;
    return 0;
}
