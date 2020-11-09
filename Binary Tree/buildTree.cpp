#include <iostream>
#include <queue>
#include <utility>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
class Pair
{
public:
    int height;
    int diameter;
};

void printPreorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
    return;
}
int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}
void printKthLevel(node *root, int h, int height)
{
    if (root == NULL)
        return;
    if (h == height)
    {
        cout << root->data << " ";
    }
    printKthLevel(root->left, h, height - 1);
    printKthLevel(root->right, h, height - 1);
    return;
}

node *buildTree()
{
    int d;
    cin >> d;
    if (d == -1)
        return NULL;
    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
// Print level order by BFS
void BFS(node *root)
{
    if (root == NULL)
        return;
    queue<node *> q;
    q.push(root);
    // For new line
    q.push(NULL);

    while (!q.empty())
    {
        node *f = q.front();
        if (f == NULL)
        {
            cout << "\n";
            q.pop();
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << f->data << " ";
            q.pop();
            if (f->left)
                q.push(f->left);
            if (f->right)
                q.push(f->right);
        }
    }

    return;
}

void LevelOrderPrint(node *root)
{
    if (root == NULL)
        return;
    int h = height(root);
    for (int i = h; i >= 1; i--)
    {
        printKthLevel(root, i, h);
        cout << endl;
    }
    return;
}

// Time Complexity O(n^2)
int diameter(node *root)
{
    if (root == NULL)
        return 0;
    int h1 = height(root->left);
    int h2 = height(root->right);

    int ans1 = h1 + h2;
    int ans2 = diameter(root->left);
    int ans3 = diameter(root->right);

    return max(ans1, max(ans2, ans3));
}

//Time Complexity O(n)
Pair fastDiameter(node *root)
{
    Pair p;
    if (root == NULL)
    {
        p.diameter = p.height = 0;
        return p;
    }

    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));

    return p;
}

int replaceSum(node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL and root->right == NULL)
    {
        return root->data;
    }
    int leftSum = replaceSum(root->left);
    int rightSum = replaceSum(root->right);

    int temp = root->data;
    root->data = leftSum + rightSum;

    return temp + root->data;
}

pair<int, bool> IsHeightTree(node *root)
{
    pair<int, bool> p;
    if (root == NULL)
    {
        p.first = 0;
        p.second = 1;
        return p;
    }
    pair<int, bool> left = IsHeightTree(root->left);
    pair<int, bool> right = IsHeightTree(root->right);

    p.first = max(left.first, right.first) + 1;
    if (abs(left.first - right.first) <= 1 and left.second and right.second)
    {
        p.second = 1;
    }
    else
    {
        p.second = 0;
    }

    return p;
}

node *buildTreeFromArray(int arr[], int s, int e)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    node *root = new node(arr[mid]);
    root->left = buildTreeFromArray(arr, s, mid - 1);
    root->right = buildTreeFromArray(arr, mid + 1, e);

    return root;
}

int main()
{
    // int n;
    // cin >> n;
    // node *root = buildTree();
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    node *root = buildTreeFromArray(arr, 0, n - 1);
    cout << "Level Order Print \n";
    BFS(root);
    Pair p = fastDiameter(root);
    cout << "Height of Tree " << p.height << endl;
    cout << "Diameter of Tree " << p.diameter << endl;
    pair<int, bool> ans = IsHeightTree(root);
    cout << "Is Height Tree " << ans.second << endl;
    // replaceSum(root);
    // BFS(root);

    return 0;
}