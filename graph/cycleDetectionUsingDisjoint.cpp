#include <bits/stdc++.h>
using namespace std;

int findParent(int i, int parent[])
{
    if (parent[i] == i)
    {
        return i;
    }
    return findParent(parent[i],parent);
}
void makeUnion(int u, int v, int parent[])
{
    int s1 = findParent(u, parent);
    int s2 = findParent(v, parent);
    if (s1 != s2)
        parent[s1] = s2;
    return;
}
bool isCycle(list<pair<int, int>> l)
{
    int *parent = new int[l.size() + 1];
    for (int i = 0; i <= l.size(); i++)
        parent[i] = i;
    for (auto it : l)
    {
        int s1 = findParent(it.first, parent);
        int s2 = findParent(it.second, parent);

        if (s1 != s2)
        {
            makeUnion(s1, s2, parent);
        }
        else
        {
            cout << "Cycle is " << s1 << " and " << s2 << endl;
            return true;
        }
    }
    delete[] parent;
    return false;
}

int main()
{

    list<pair<int, int>> edges;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    bool cycle = isCycle(edges);
    if (cycle)
    {
        cout << "Contain cycle" << endl;
    }
    else
        cout << "Not contain cycle" << endl;

    return 0;
}