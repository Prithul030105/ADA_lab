#include <iostream>
#include <algorithm>

using namespace std;

struct Activity
{
    int start, end;
};

bool compare(Activity a, Activity b)
{
    return a.end < b.end;
}

void activitySelection(Activity activities[], int n)
{

    sort(activities, activities + n, compare);

    cout << "Selected activities: \n";

    int lastEndTime = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (activities[i].start >= lastEndTime)
        {
            cout << "(" << activities[i].start << ", " << activities[i].end << ")\n";
            lastEndTime = activities[i].end;
            count++;
        }
    }

    cout << "Maximum number of activities: " << count << endl;
}

int main()
{
    Activity activities[] = {{1, 3}, {2, 5}, {3, 9}, {6, 8}, {8, 9}, {5, 7}};
    int n = sizeof(activities) / sizeof(activities[0]);

    activitySelection(activities, n);

    return 0;
}
