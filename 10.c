#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left, *right;
};

struct node* Create(int ele){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=ele;
    temp->left=temp->right=NULL;
    return temp;
}

struct node* ins(struct node* root, int ele){
    if(root==NULL)
        return Create(ele);
    else if(root->data==ele)
        printf("\nAlready exist\n");
    else if(ele<root->data)
        root->left=ins(root->left,ele);
    else    
        root->right=ins(root->right,ele);
    return root;
}

void pre(struct node* root){
    if(root!=NULL){
        printf("%d\t",root->data);
        pre(root->left);
        pre(root->right);
    }
}

void in(struct node* root){
    if(root!=NULL){
        in(root->left);
        printf("%d\t",root->data);
        in(root->right);
    }
}

void post(struct node* root){
    if(root!=NULL){
        post(root->left);
        post(root->right);
        printf("%d\t",root->data);
    }
}

void search(struct node* root, int ele){
    if(root==NULL)
        printf("\nNot found\n");
    else if(root->data==ele)
        printf("\nElement found\n");
    else if(root->data>ele)
        search(root->left,ele);
    else    
        search(root->right,ele);
}

void main(){
    struct node* root = NULL; 
    int ele, ch;
    while(1){
        printf("\nMENU\n1 Insert\n2 Traversal\n3 Search key\n4 Exit\nEnter ur choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("\nEnter element: ");
                scanf("%d",&ele);
                root=ins(root,ele);
                break;
            case 2: 
                if(root==NULL){
                    printf("\nTree empty\n");
                    break;
                }
                printf("\n1 Preorder\n2 Inorder\n3 Postorder\nEnter choice: ");
                scanf("%d",&ch);
                switch(ch){
                    case 1:pre(root);
                        break;
                    case 2:in(root);
                        break;
                    case 3:post(root);
                        break;
                }
                break;
            case 3:printf("\nEnter key: ");
                scanf("%d",&ele);
                search(root,ele);
                break;
            default:exit(0);
        }
    }
}
