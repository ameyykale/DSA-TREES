#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student Record
struct Student
{
    int id;
    char name[50];
    char department[30];
    int semester;
    struct Student *left;
    struct Student *right;
};
typedef struct Student Node;
// Create New Node
Node* createNode(int id, char name[], char dept[], int sem)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    strcpy(newNode->name, name);
    strcpy(newNode->department, dept);
    newNode->semester = sem;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert Student
Node* insert(Node *root, int id, char name[], char dept[], int sem)
{
    if(root == NULL)
        return createNode(id, name, dept, sem);
    if(id < root->id)
        root->left = insert(root->left, id, name, dept, sem);
    else if(id > root->id)
        root->right = insert(root->right, id, name, dept, sem);
    return root;
}

// Search Student
Node* search(Node *root, int id)
{
    if(root == NULL || root->id == id)
        return root;
    if(id < root->id)
        return search(root->left, id);
    return search(root->right, id);
}
// Find Minimum Node
Node* findMin(Node *root)
{
    while(root->left != NULL)
        root = root->left;
    return root;
}

// Delete Student
Node* deleteNode(Node *root, int id)
{
    if(root == NULL)
        return root;
    if(id < root->id)
        root->left = deleteNode(root->left, id);
    else if(id > root->id)
        root->right = deleteNode(root->right, id);
    else
    {
        // Node with one child or no child
        if(root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // Node with two children
        Node *temp = findMin(root->right);
        root->id = temp->id;
        strcpy(root->name, temp->name);
        strcpy(root->department, temp->department);
        root->semester = temp->semester;
        root->right = deleteNode(root->right, temp->id);
    }
    return root;
}

// Display Records in Sorted Order
void inorder(Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("\nStudent ID : %d", root->id);
        printf("\nName       : %s", root->name);
        printf("\nDepartment : %s", root->department);
        printf("\nSemester   : %d\n", root->semester);
        inorder(root->right);
    }
}

// Main Function
int main()
{
    Node *root = NULL;
    int choice, id, sem;
    char name[50], dept[30];
    while(1)
    {
        printf("\n\n===== Student Record Management BST =====");
        printf("\n1. Insert Student");
        printf("\n2. Search Student");
        printf("\n3. Display All Students");
        printf("\n4. Delete Student");
        printf("\n5. Exit");
        printf("\nEnter Choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter Student ID : ");
                scanf("%d", &id);
                printf("Enter Name : ");
                scanf("%s", name);
                printf("Enter Department : ");
                scanf("%s", dept);
                printf("Enter Semester : ");
                scanf("%d", &sem);
                root = insert(root, id, name, dept, sem);
                printf("Student Inserted Successfully!");
                break;

            case 2:
            {
                printf("Enter Student ID to Search : ");
                scanf("%d", &id);
                Node *result = search(root, id);
                if(result)
                {
                    printf("\nStudent Found");
                    printf("\nID         : %d", result->id);
                    printf("\nName       : %s", result->name);
                    printf("\nDepartment : %s", result->department);
                    printf("\nSemester   : %d", result->semester);
                }
                else
                {
                    printf("\nStudent Not Found!");
                }
                break;
            }
            case 3:
                printf("\n\nStudent Records (Sorted Order)\n");
                inorder(root);
                break;
            case 4:
                printf("Enter Student ID to Delete : ");
                scanf("%d", &id);
                root = deleteNode(root, id);
                printf("Record Deleted Successfully!");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice!");
        }
    }
    return 0;
}
