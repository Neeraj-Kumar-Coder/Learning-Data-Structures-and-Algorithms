#include <bits/stdc++.h>

using namespace std;

vector<int> findPoint(vector<vector<int>> &points)
{
    vector<int> answer;
    double low = -1e9, high = 1e9, eps = 0.000001, distx = DBL_MAX, disty = DBL_MAX, x, y;

    while (abs(low - high) >= eps)
    {
        double mid = low + (high - low) / 2;
        double dist = 0, temp = 0;

        for (auto &&p : points)
        {
            double x1, x2;
            if (p[0] > p[2])
            {
                x1 = p[2];
                x2 = p[0];
            }
            else
            {
                x1 = p[0];
                x2 = p[2];
            }

            if (mid < x1 || mid > x2)
            {
                dist += min(abs(mid - p[2]), abs(mid - p[0]));
            }
        }

        if (dist < distx)
        {
            distx = dist;
            x = mid;
        }

        double check = mid + eps;
        for (auto &&p : points)
        {
            double x1, x2;
            if (p[0] > p[2])
            {
                x1 = p[2];
                x2 = p[0];
            }
            else
            {
                x1 = p[0];
                x2 = p[2];
            }

            if (check < x1 || check > x2)
            {
                temp += min(abs(check - p[2]), abs(check - p[0]));
            }
        }

        if (temp < dist)
        {
            low = mid + eps;
        }
        else
        {
            high = mid - eps;
        }
    }

    low = -1e9, high = 1e9, eps = 0.000001, y = DBL_MAX;

    while (abs(low - high) >= eps)
    {
        double mid = low + (high - low) / 2;
        double dist = 0, temp = 0;

        for (auto &&p : points)
        {
            double y1, y2;
            if (p[1] > p[3])
            {
                y1 = p[3];
                y2 = p[1];
            }
            else
            {
                y1 = p[1];
                y2 = p[3];
            }

            if (mid < y1 || mid > y2)
            {
                dist += min(abs(mid - p[3]), abs(mid - p[1]));
            }
        }

        if (dist < disty)
        {
            disty = dist;
            y = mid;
        }

        double check = mid + eps;
        for (auto &&p : points)
        {
            double y1, y2;
            if (p[1] > p[3])
            {
                y1 = p[3];
                y2 = p[1];
            }
            else
            {
                y1 = p[1];
                y2 = p[3];
            }

            if (check < y1 || check > y2)
            {
                temp += min(abs(check - p[3]), abs(check - p[1]));
            }
        }

        if (temp < dist)
        {
            low = mid + eps;
        }
        else
        {
            high = mid - eps;
        }
    }

    return {int(x), int(y)};
}

int main(void)
{
    vector<vector<int>> points = {{0, 0, 2, 0}, {0, 2, 3, 2}, {3, 1, 3, 4}};
    vector<int> ans = findPoint(points);
    for (auto &&p : ans)
    {
        cout << p << ' ';
    }
    return 0;
}