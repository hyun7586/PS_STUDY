#include <bits/stdc++.h>
using namespace std;

typedef struct Node *ptr;
typedef struct Node
{
    char data;
    Node *left;
    Node *right;

    Node(char k)
    {
        data = k;
        left = NULL;
        right = NULL;
    }
    ~Node() {}
} Node;

ptr create_node(char temp);
ptr search_node(ptr root, char value);
void inorder_traversal(ptr root);
void preorder_traversal(ptr root);
void postorder_traversal(ptr root);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    char a, b, c;

    cin >> n >> a >> b >> c;
    ptr root_node = create_node(a);
    if (b != '.')
        root_node->left = create_node(b);
    if (c != '.')
        root_node->right = create_node(c);

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        ptr parent = search_node(root_node, a);
        if (b != '.')
            parent->left = create_node(b);
        if (c != '.')
            parent->right = create_node(c);
    }

    preorder_traversal(root_node);
    cout << '\n';
    inorder_traversal(root_node);
    cout << '\n';
    postorder_traversal(root_node);

    return 0;
}

ptr create_node(char temp)
{
    return new Node(temp);
}

ptr search_node(ptr root, char value)
{
    if (root == NULL || root->data == value)
        return root;

    ptr left_node = search_node(root->left, value);
    if (left_node != NULL)
        return left_node;

    return search_node(root->right, value);
}

void inorder_traversal(ptr root)
{
    if (root)
    {
        inorder_traversal(root->left);
        cout << root->data;
        inorder_traversal(root->right);
    }
}

void preorder_traversal(ptr root)
{
    if (root)
    {
        cout << root->data;
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void postorder_traversal(ptr root)
{
    if (root)
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        cout << root->data;
    }
}