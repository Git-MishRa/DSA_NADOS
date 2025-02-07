#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

int idx = 0;
Node *constructTree(vector<int> &arr)
{

    if (idx == arr.size() || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }
    Node *node = new Node(arr[idx++]);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
}

void display(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    string str = "";
    str += node->left == nullptr ? "." : to_string(node->left->data) + "";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right == nullptr ? "." : to_string(node->right->data) + "";
    cout << str << endl;

    display(node->left);
    display(node->right);
}

void pathToLeafFromRoot(Node *node, string path, int sum, int lo, int hi)
{
    // write your code here
    // base case in case of single child
    if (node == NULL)
    {
        return;
    }

    // found the leaf
    if (node->left == NULL && node->right == NULL)
    {
        sum = sum + node->data;
        if (sum <= hi && sum >= lo)
        {
            string temp = to_string(node->data) + " ";
            path += temp;
            cout << path << endl;
        }
    }
    path += to_string(node->data) + " ";
    sum += node->data;
    pathToLeafFromRoot(node->left, path, sum, lo, hi);
    pathToLeafFromRoot(node->right, path, sum, lo, hi);
}

int main()
{
    vector<int> arr;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string inp;
        cin >> inp;
        if (inp != "n")
        {
            arr.push_back(stoi(inp));
        }
        else
        {
            arr.push_back(-1);
        }
    }

    int lo;
    cin >> lo;
    int hi;
    cin >> hi;

    Node *root = constructTree(arr);
    pathToLeafFromRoot(root, "", 0, lo, hi);
    return 0;
}