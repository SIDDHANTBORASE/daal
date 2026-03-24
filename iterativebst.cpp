#include <iostream>
#include <algorithm>
#include <stack> 
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int key) {
    Node* newNode = new Node(key);
    if (root == NULL) return newNode;

    Node* curr = root;
    Node* parent = NULL;

    while (curr != NULL) {
        parent = curr;
        if (key < curr->data)
            curr = curr->left;
        else if (key > curr->data)
            curr = curr->right;
        else {
            delete newNode;
            return root;
        }
    }

    if (key < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

void inorder(Node* root) {
    stack<Node*> s;
    Node* curr = root;

    while (curr != NULL || !s.empty()) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void preorder(Node* root) {
    if (root == NULL) return;
    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        cout << curr->data << " ";

        if (curr->right) s.push(curr->right);
        if (curr->left) s.push(curr->left);
    }
}

void postorder(Node* root) {
    if (root == NULL) return;
    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left) s1.push(curr->left);
        if (curr->right) s1.push(curr->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int height(Node* root) {
    if (root == NULL) return 0;
    
    
    queue<Node*> q;
    q.push(root);
    int h = 0;
    while (!q.empty()) {
        int size = q.size();
        h++;
        while (size--) {
            Node* curr = q.front();
            q.pop();
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    return h;
}

int countLeaves(Node* root) {
    if (root == NULL) return 0;
    int count = 0;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        if (curr->left == NULL && curr->right == NULL) count++;
        if (curr->right) s.push(curr->right);
        if (curr->left) s.push(curr->left);
    }
    return count;
}

int countInternal(Node* root) {
    if (root == NULL) return 0;
    int count = 0;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        if (curr->left != NULL || curr->right != NULL) {
            count++;
            if (curr->right) s.push(curr->right);
            if (curr->left) s.push(curr->left);
        }
    }
    return count;
}

int main() {
    Node* root = NULL;
    int n, val;
    cout << "Enter the Number of Nodes: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter the Value of Node " << i + 1 << ": ";
        cin >> val;
        root = insert(root, val);
    }

    cout << "\n--- Traversals ---" << endl;
    cout << "In-order:   "; inorder(root); cout << endl;
    cout << "Pre-order:  "; preorder(root); cout << endl;
    cout << "Post-order: "; postorder(root); cout << endl;

    cout << "\n--- Requested Operations ---" << endl;
    cout << "Height of the tree: " << height(root) << endl;
    cout << "Number of leaf nodes: " << countLeaves(root) << endl;
    cout << "Number of internal nodes: " << countInternal(root) << endl;

    return 0;
}
