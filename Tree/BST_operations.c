#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node *create(int item){
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = item;
    new->left = NULL;
    new->right = NULL;
return new;
}

struct node* search(struct node* root, int key){
    while(root != NULL){
        if(key == root->data){
            return root;
        }
        else if(key < root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
return NULL;
}

void inorder(struct node* root){
    if (root!=NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node *insertion(struct node* root, int item){
    if (root==NULL){
        return create(item);
    }
    if(item < root->data){
        root->left = insertion(root->left, item);
    }
    if(item > root->data){
        root->right= insertion(root->right, item);
    }
return root;
}

struct node* inorderpredecessor(struct node *root){
    root = root->left;
    while (root->right != NULL){
        root = root->right;
    }
return root;
}

struct node* deletion(struct node* root, int value){
    struct node* ipre;
    if (value == root->data){
        free(root);
        return NULL;
    }
    if (root==NULL){
        return NULL;
    }
    if(root->left== NULL && root->right==NULL){
        free(root);
        return NULL;   
    }
    if(value < root->data){
        root->left = deletion(root->left, value);
    }
    if(value > root->data){
        root->right = deletion(root->right, value);
    }
    else{
        ipre = inorderpredecessor(root);
        root->data = ipre->data;
        root->left = deletion(root->left, root->data);
    }
return root;
}
int main(){
    int item, key, value, ch;
    int choice = 0;
    struct node *root = NULL;
    do{
    printf("Enter the element you want to add: ");
    scanf("%d", &item);
    root = insertion(root, item);
    printf("Press 1 for New Node");
    printf("\nPress 0 for change");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    }while(ch==1);

    while(choice != 5){
        printf("\n1.In-order Traversal\n2.Searching\n3.Insert a node\n4.Delete a node\n5.Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Inorder Traversal: ");
            inorder(root);
            break;
        case 2:
            printf("Enter the value you want to search: ");
            scanf("%d", &key);
            struct node*n = search(root, key);
            if (n != NULL){
                printf("Your key %d is in the BST", key);
            }
            else{
                printf("Your key %d is not in the BST");
            }
            break;
        case 3:
            printf("Enter the new element: ");
            scanf("%d", &item);
            root = insertion(root, item);
            break;
        case 4:
            printf("Enter the value you want to delete: ");
            scanf("%d", &value);
            struct node* new = search(root, value);
            if (new != NULL){
                root = deletion(root, value);
                printf("Your Item is been deleted");
            }
            else{
                printf("%d is not in the BST", value);
            }
            break;
        case 5:
            printf("EXIT");
            exit(0);
        
        default:
            printf("Invalid choice!!! Enter the correct choice...");
            break;
        }
    }
}