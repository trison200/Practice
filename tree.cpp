#include <iostream>
using namespace std;

// Cấu trúc Node của cây BST
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Thêm phần tử vào BST
TreeNode *insert(TreeNode *root, int key)
{
    if (root == nullptr)
        return new TreeNode(key);
    if (key < root->val)
        root->left = insert(root->left, key);
    else if (key > root->val)
        root->right = insert(root->right, key);
    return root;
}

// Tìm kiếm phần tử trong BST
TreeNode *search(TreeNode *root, int key)
{
    if (root == nullptr || root->val == key)
        return root;
    if (key < root->val)
        return search(root->left, key);
    return search(root->right, key);
}

// Tìm node có giá trị nhỏ nhất trong cây (hữu ích khi xóa)
TreeNode *findMin(TreeNode *node)
{
    while (node->left != nullptr)
        node = node->left;
    return node;
}

// Xóa phần tử trong BST
TreeNode *deleteNode(TreeNode *root, int key)
{
    if (root == nullptr)
        return root;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == nullptr)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }
        TreeNode *temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

// Duyệt Inorder (in theo thứ tự tăng dần)
void inorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// === HÀM MAIN ===
int main()
{
    TreeNode *root = nullptr;

    // Thêm các giá trị vào BST
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int val : values)
    {
        root = insert(root, val);
    }

    cout << "Inorder traversal of the BST: ";
    inorder(root);
    cout << endl;

    // Tìm kiếm giá trị
    int searchKey = 40;
    TreeNode *found = search(root, searchKey);
    if (found)
        cout << "Found " << searchKey << " in the BST.\n";
    else
        cout << searchKey << " not found in the BST.\n";

    // Xóa một node
    int deleteKey = 30;
    cout << "Deleting " << deleteKey << " from the BST...\n";
    root = deleteNode(root, deleteKey);

    cout << "Inorder after deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}
