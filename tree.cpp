#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(const int &data) { this->data = data; }
};

class BinarySearchTree
{
private:
    Node *root;

protected:
    bool addRec(Node *&root, const int &value);
    bool removeRec(Node *&, const int &);
    int getSizeRec(Node *);
    void printInOrderRec(Node *node) const
    {
        if (node != NULL)
        {
            printInOrderRec(node->left);
            cout << node->data << " ";
            printInOrderRec(node->right);
        }
    }

public:
    BinarySearchTree()
    {
        this->root = NULL;
    }
    bool add(const int &value);
    bool remove(const int &value);
    int getSize();
    void printInOrder() const
    {
        printInOrderRec(root);
        cout << endl;
    }
};

bool BinarySearchTree::addRec(Node *&root, const int &value)
{
    if (root == NULL)
    {
        root = new Node(value);
        return true;
    }
    if (value < root->data)
    {
        return addRec(root->left, value);
    }
    else if (value > root->data)
    {
        return addRec(root->right, value);
    }
    else
    {
        return false;
    }
}

bool BinarySearchTree::add(const int &value)
{
    return addRec(root, value);
}

bool BinarySearchTree::removeRec(Node *&root, const int &value)
{
    if (root == NULL)
    {
        return false;
    }
    if (value < root->data)
    {
        return removeRec(root->left, value);
    }
    else if (value > root->data)
    {
        return removeRec(root->right, value);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node *tmp = root;
            root = root->left;
            delete tmp;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            Node *tmp = root;
            root = root->right;
            delete tmp;
        }
        else
        {
            Node *maxLeft = root->left;
            while (maxLeft->right != NULL)
            {
                maxLeft = maxLeft->right;
            }
            root->data = maxLeft->data;
            removeRec(root->left, maxLeft->data);
        }
        return true;
    }
}

bool BinarySearchTree::remove(const int &value)
{
    return removeRec(root, value);
}

int BinarySearchTree::getSizeRec(Node *root)
{
    int cnt = 0;
    if (root)
    {
        cnt++;
        if (root->left != NULL)
        {
            cnt += getSizeRec(root->left);
        }
        if (root->right != NULL)
        {
            cnt += getSizeRec(root->right);
        }
    }
    return cnt;
}

int BinarySearchTree::getSize()
{
    return getSizeRec(root);
}

int main()
{
    BinarySearchTree bst;

    // Test 1: Empty tree
    cout << "Test 1: Empty tree size: " << bst.getSize() << endl;

    // Test 2: Add elements
    cout << "\nTest 2: Adding elements" << endl;
    cout << "Adding 10: " << (bst.add(10) ? "Success" : "Failed") << endl;
    cout << "Adding 5: " << (bst.add(5) ? "Success" : "Failed") << endl;
    cout << "Adding 15: " << (bst.add(15) ? "Success" : "Failed") << endl;
    cout << "Adding 3: " << (bst.add(3) ? "Success" : "Failed") << endl;
    cout << "Adding 7: " << (bst.add(7) ? "Success" : "Failed") << endl;
    cout << "Adding 12: " << (bst.add(12) ? "Success" : "Failed") << endl;
    cout << "Adding 18: " << (bst.add(18) ? "Success" : "Failed") << endl;

    // Test 3: Try adding duplicate
    cout << "\nTest 3: Adding duplicate" << endl;
    cout << "Adding 10 again: " << (bst.add(10) ? "Success" : "Failed (Expected, no duplicates allowed)") << endl;

    // Test 4: Check size after additions
    cout << "\nTest 4: Tree size after additions: " << bst.getSize() << endl;
    // Test 5: Remove leaf node
    cout << "\nTest 5: Removing leaf node" << endl;
    cout << "Removing 3: " << (bst.remove(3) ? "Success" : "Failed") << endl;
    cout << "Tree size after removal: " << bst.getSize() << endl;

    // Test 6: Remove node with one child
    cout << "\nTest 6: Removing node with one child" << endl;
    cout << "Removing 12: " << (bst.remove(12) ? "Success" : "Failed") << endl;
    cout << "Tree size after removal: " << bst.getSize() << endl;

    // Test 7: Remove node with two children
    cout << "\nTest 7: Removing node with two children" << endl;
    cout << "Removing 15: " << (bst.remove(15) ? "Success" : "Failed") << endl;
    cout << "Tree size after removal: " << bst.getSize() << endl;

    // Test 8: Remove root
    cout << "\nTest 8: Removing root" << endl;
    cout << "Removing 10: " << (bst.remove(10) ? "Success" : "Failed") << endl;
    cout << "Tree size after removal: " << bst.getSize() << endl;

    // Test 9: Remove non-existing element
    cout << "\nTest 9: Removing non-existing element" << endl;
    cout << "Removing 100: " << (bst.remove(100) ? "Success (Unexpected)" : "Failed (Expected)") << endl;

    // Test 10: Add after removals
    cout << "\nTest 10: Adding after removals" << endl;
    cout << "Adding 22: " << (bst.add(22) ? "Success" : "Failed") << endl;
    cout << "Tree size: " << bst.getSize() << endl;

    return 0;
}