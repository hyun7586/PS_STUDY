#include <bits/stdc++.h>
using namespace std;

int n;

typedef struct Node *ptr;
typedef struct Node
{
    int data;
    vector<ptr> ptrs;

    Node(int k)
    {
        data = k;
    }

    ~Node(){};

} Node;

ptr search_node(ptr root, int k);
ptr create_node(int k);
void insert_node(ptr parent, int child);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    ptr root_node = create_node(1);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        ptr parent = search_node(root_node, a);
        if (parent)
            insert_node(parent, b);
        else
            insert_node(search_node(root_node, b), a);
    }

    return 0;
}

ptr search_node(ptr root, int value)
{
    if (root == NULL || root->data == value)
        return root;

    for (auto each : root->ptrs)
    {
        return search_node(each, value);
    }
}

ptr create_node(int k)
{
    return new Node(k);
}

void insert_node(ptr parent, int k)
{
    parent->ptrs.push_back(create_node(k));
}