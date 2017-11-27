/*
 * This is a binary search tree created with linked lists and recursive functions.
 * Methods used are : add, printTree, countTree, findMax, findMin, find, delete.
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int data;
    struct tree* right;
    struct tree* left;
}node;

void add(node** root, int data){
    if(*root == NULL){  //Checks if our root is NULL, which will be our base case.
        *root = malloc(sizeof *root);   //If so, initializes the root and its branches...
        (*root)->data = data;           //...and assigns their first value.
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }
    if((*root)->data > data) //Then if the data wanted to add is less than the data we have currently in root.
        add(&((*root)->left),data); //We should add it to the left branch of the tree.
    if((*root)->data < data) //And vice versa.
        add(&((*root)->right), data);
}

void printTree(node* root){ //Prints the tree in pre-order.
    if(root == NULL) //This is our base  case which will return...
        return;      //...if there is nothing left to print. Which means we have reached a NULL branch.
    printf("%d\n",root->data); //Prints the first data of the tree. Which is on top of the tree.
    printTree(root->left);
    printTree(root->right);
}

int countTree(node* root){ //Counts the elements in the tree and returns the count.
    if(root != NULL)
        return 1+countTree(root->right)+countTree(root->left);
}

int findMax(node* root){ //Finds the max value in the tree.
    while(root->right != NULL)
        root = root->right;
    return root->data;
}

int findMin(node* root){ //Finds the min value in the tree.
    while(root->left != NULL)
        root = root->left;
    return root->data;
}

int find(node* root, int data){ //Returns 1 if the data exists in the tree and 0 otherwise.
    if(root == NULL){
        return 0;
    }else if(root->data == data){
        return 1;
    }


    if(root->data > data)
        find(root->left, data);
    else if(root->data < data)
        find(root->right, data);

}

/*
 * The method below deletes a value from the tree depending on...
 * ...whether the node is a leaf, has one child or has two children.
 */
void delete(node** root,int data){
    if((*root)->data == data && (*root)->left == NULL && (*root)->right == NULL) { //When it is leaf.
        //free(*root);
        *root = NULL;
    }else if((*root)->data == data && (*root)->left == NULL){ //When it has one(right) children.
        node* temp;
        temp = *root;
        *root = (*root)->right;
        free(temp);
    }
    else if((*root)->data == data && (*root)->right == NULL){//When it has one(left) children.
        node* temp;
        temp = *root;
        *root = (*root)->left;
        free(temp);
    }else if((*root)->data == data && (*root)->left != NULL && (*root)->right != NULL){ //When it has both the children.
        (*root)->data = findMin((*root)->right);
        delete(&(*root)->right,findMin((*root)->right));

    }else{
        if((*root)->data > data)
            delete(&(*root)->left,data);
        else if((*root)->data < data)
            delete(&(*root)->right,data);
    }
}

int main() {
    node* root = NULL;
    add(&root,5);
    add(&root,7);
    add(&root,8);
    add(&root,9);
    add(&root,6);
    add(&root,3);
    add(&root,1);
    add(&root,32);
    add(&root,20);
    add(&root,21);
    add(&root,15);
    add(&root,19);
    printTree(root);
    int x = 16;
    printf("The max value in the tree is: %d\n",findMax(root));
    printf("The min value in the tree is: %d\n",findMin(root));
    printf("Is there '%d' in the tree ? %d\n",x,find(root,x));

    printf("Here is the count %i\n",countTree(root));
    delete(&root,20);
    puts("\n-----After Deletion-----");
    printTree(root);
    add(&root,17);
    puts("\n-----After Addition-----");
    printTree(root);
    return 0;
}