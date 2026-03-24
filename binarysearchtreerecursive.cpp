#include <iostream>
#include <algorithm> 
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
    if (root == NULL) {
        return new Node(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int height(Node* root) {
    if (root == NULL) {
        return 0; 
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}


int countLeaves(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

int countInternal(Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0;
    }
    return 1 + countInternal(root->left) + countInternal(root->right);
}

int main() {
    Node* root = NULL;
    int n,val;
    cout<<"Enter the Number of Nodes: "<<endl;
    cin>>n;
    for (int i = 0; i < n; i++) {
    	cout<<"Enter the Value of Nodes: "<<endl;
    	cin>>val;
	    root = insert(root, val);
    }

    cout << "Traversals" << endl;
    cout << "In-order:  ";
    inorder(root);
    cout << endl;
    cout << "Pre-order: ";
    preorder(root);
    cout << endl;
    cout << "Post-order:";
    postorder(root);
    cout << endl << endl;
    cout << "Requested Operations" << endl;
    cout << "Height of the tree: " << height(root) << endl;
    cout << "Number of leaf nodes: " << countLeaves(root) << endl;
    cout << "Number of internal nodes: " << countInternal(root) << endl;
    return 0;
}
