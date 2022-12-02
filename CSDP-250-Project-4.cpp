//Name: Israel Showell
//Date Created: 11/28/2022
//Project Name: CSDP-250-Project-4
//Project Desc: This program asks the user to input some integer values, offers the user to remove some, and
//offers to find a certain node.




#include <iostream>
using namespace std;
//Node data
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}; 

//Searching the linked list for the smallest node.
Node* FindMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
        return root;
    }
}


Node* FindNode(Node* root, int data) {
        if (data == root->data) {
            cout << "Found it! " << root << endl;
            return root;
        }
        else if (data < root->data) {
            root = root->left;
        }
        else if (data > root->data) {
            root = root->right;
        }
        else {
            cout << "Root not found." << endl;
        }
}

//Deleting the nodes
struct Node* Delete(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    }
    else if(data < root->data){
        root->left = Delete(root->left, data);
    }
    else if (data > root->data) {
        root->right = Delete(root->right, data);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL) {
            struct Node* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            struct Node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

//Displaying the nodes
void Inorder(Node* root) {
    if (root == NULL) return;
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
}

//Inserting nodes
Node* Insert(Node* root, char data) {
    if (root == NULL) {
        root = new Node();
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->data) {
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}


int main()
{
    //Variables 
    Node* root = NULL;
    int x = 0;
    int i = 0;
    int k = 0;
    int choice = 0;
    int choice2 = 0;


    //Gathering the users input.
    cout << "How many integers would like to input? ";
    cin >> k;
    cout << "Please input your numbers: " << endl;
    for (i = 1; i <= k; i++) {
        cout << "Number "<<i<<": ";
        cin >> x;
        root = Insert(root, x);
    }

    //Showing the user their nodes.
    cout << "Your nodes in Inorder form: ";
    Inorder(root);
    cout << endl;
    
    //Controls the deleting part for the program. Deleting parent nodes, seem to cause a node.
    cout << "Would you like to delete a node? (1 for yes, anything else for no.)" << endl;
    cin >> choice;
    if (choice == 1) {
        while (choice == 1) {
            cout << "Which node do you want to delete? (Input the number to delete it.) " << endl;
            cin >> x;
            Delete(root, x);
            cout << "Would you like to delete more nodes? (1 for yes, anything else for no.)" << endl;
            cin >> choice;
        }
    }
    //Working on this part, may not finish it though...
    cout << "Would you like to find a certain node? (1 for yes, anything else for no.)" << endl;
    cin >> choice2;
    if (choice2 == 1) {
        while (choice2 == 1) {
            cout << "Which node do you want to find? (Input the number to try to find it.) " << endl;
            cin >> x;
            FindNode(root, x);
            cout << "Would you like to look for more nodes? (1 for yes, anything else for no.)" << endl;
            cin >> choice2;
        }
    }



    //The final result of the nodes.
    cout << "Your nodes in Inorder form: ";
    Inorder(root);
    cout << endl;

    //Pauses the program so the user can read the output.
   system("PAUSE");
}