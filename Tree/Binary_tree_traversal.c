#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};
struct node *tree(){
    int data, choice;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    printf("Press 1 for new node");
    printf("\nPress 0 for change");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice == 0){
        return 0;
    }
    else{
        printf("Enter the data: ");
        scanf("%d", &data);
        temp->data = data;

        printf("Enter the left child of %d\n", data);
        temp->left = tree();

        printf("Enter the right child of %d\n", data);
        temp->right = tree();
        return temp;
    }
}
void preorder(struct node *root){
    if(root!=NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main(){
    struct node *root;
    root = tree();
    printf("Preorder traversal: ");
    preorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);
    printf("\nInorder traversal: ");
    inorder(root);
return 0;
}