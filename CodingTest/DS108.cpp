#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> my;
    int num;
    cin >> num;

    int score;
    for (int i = 0; i < num; i++) {
        cin >> score;
        my.push_back(score);
    }

    int maxCount = 0;
    int maxElement = my[0];

    for (int i = 0; i < num; i++) {
        int coun = count(my.begin(), my.end(), my[i]);
        if (coun > maxCount) {
            maxCount = coun;
            maxElement = my[i];
        }
    }

    cout << maxElement << endl;

    return 0;
}
