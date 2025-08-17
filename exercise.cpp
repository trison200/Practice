#include <iostream>
#include <queue>

using namespace std;

// Định nghĩa node của cây nhị phân
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};
int N = 100;

// Breadth-First Traversal (Level Order Traversal)
void breadthFirstTraversal(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *tmp = q.front();
        q.pop();
        if (tmp->left != NULL)
        {
            q.push(tmp->left);
        }
        if (tmp->right != NULL)
        {
            q.push(tmp->right);
        }
        cout << tmp->data << " ";
    }
}

Node *insertBST(Node *root, int value)
{
    if (root == NULL)
    {
        return new Node(value);
    }
    if (value < root->data)
    {
        root->left = insertBST(root->left, value);
    }
    else
    {
        root->right = insertBST(root->right, value);
    }
    return root;
}

Node *deleteBST(Node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (value < root->data)
    {
        root->left = deleteBST(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteBST(root->right, value);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *tmp = root->right;
            delete root;
            return tmp;
        }
        else if (root->right == NULL)
        {
            Node *tmp = root->left;
            delete root;
            return tmp;
        }
        else
        {
            Node *p = root->right;
            while (p->left != NULL)
            {
                p = p->left;
            }
            root->data = p->data;
            root->right = deleteBST(root->right, p->data);
        }
    }

    return root;
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    Node *root = nullptr;

    // Danh sách insert
    int insertValues[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 85, 5, 15, 33, 37, 90};
    int n = sizeof(insertValues) / sizeof(insertValues[0]);

    // Insert các phần tử
    for (int i = 0; i < n; i++)
    {
        root = insertBST(root, insertValues[i]);
    }

    cout << "Cay BST ban dau (in-order):\n";
    inorder(root);
    cout << "\n\n";

    // Danh sách cần xóa
    int deleteValues[] = {
        5,  // Node lá
        15, // Node lá
        30, // Node có 2 con
        60, // Node có 1 con
        50, // Root có 2 con
        100 // Không tồn tại
    };
    int m = sizeof(deleteValues) / sizeof(deleteValues[0]);

    for (int i = 0; i < m; i++)
    {
        cout << "Xoa " << deleteValues[i] << "...\n";
        root = deleteBST(root, deleteValues[i]);
        cout << "Cay sau khi xoa " << deleteValues[i] << " (in-order): ";
        inorder(root);
        cout << "\n\n";
    }

    return 0;
}
