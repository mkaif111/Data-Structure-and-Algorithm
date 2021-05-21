#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    int x, y;
    Point()
    {
    }
    Point(int x1, int y1)
    {
        x = x1;
        y = y1;
    }
};

class Compare
{
public:
    bool operator()(Point p1, Point p2)
    {
        if (p1.x == p2.x)
            return p1.y < p2.y;
        return p1.x < p2.x;
    }
};

int countRec(vector<Point> points)
{
    int n = points.size();
    //insert all points in the set
    // for custom obj compare func or class needed
    set<Point, Compare> s;
    for (int i = 0; i < n; i++)
        s.insert(points[i]);
    int ans = 0;
    for (auto it = s.begin(); it != prev(s.end()); it++)
    {
        // set is not linear ds to get next step next operator is used
        for (auto jt = next(it); jt != s.end(); jt++)
        {
            Point p1 = *it;
            Point p2 = *jt;
            if (p1.x == p2.x or p2.y == p1.y)
                continue;
            Point p3(p2.x, p1.y);
            Point p4(p1.x, p2.y);
            if (s.find(p3) != s.end() and s.find(p4) != s.end())
                ans++;
        }
    }

    return ans / 2;
}

int main()
{
    int n; cin>>n;
    vector<Point> points;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        Point p(x, y);
        points.push_back(p);
    }
    int ans = countRec(points);
    cout << ans << endl;

    return 0;
}