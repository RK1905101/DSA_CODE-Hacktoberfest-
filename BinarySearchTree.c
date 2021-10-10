#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *leftlink, *rightlink;
} * node;

node create(int data){
    node temp = (node)malloc(sizeof(struct node));
    temp->data = data;
    temp->leftlink = NULL;
    temp->rightlink = NULL;
    return temp;
}

node insertBST(node nod, int data){
    if (nod != NULL){
        if (data > nod->data)
            nod->rightlink = insertBST(nod->rightlink, data);
        else if (data < nod->data)
            nod->leftlink = insertBST(nod->leftlink, data);
    }
    else
        return create(data);
    return nod;
}

void pre_order(node root){
    if (root != NULL){
        printf("%d ", root->data);
        pre_order(root->leftlink);
        pre_order(root->rightlink);
    }
}

void in_order(node root){
    if (root != NULL){
        in_order(root->leftlink);
        printf("%d ", root->data);
        in_order(root->rightlink);
    }
}

void post_order(node root){
    if (root != NULL){
        post_order(root->leftlink);
        post_order(root->rightlink);
        printf("%d ", root->data);
    }
}

node minInorderSuccessor(node nod){
    if (nod->leftlink == NULL)
        return nod;
    else
        return minInorderSuccessor(nod->leftlink);
}

node deletion(node nod, int key){
    if (nod != NULL){
        if (key < nod->data)
            nod->leftlink = deletion(nod->leftlink, key);
        else if (key > nod->data)
            nod->rightlink = deletion(nod->rightlink, key);
        else{
            if (nod->leftlink == NULL && nod->rightlink == NULL){
                free(nod);
                return NULL;
            }
            else if (nod->leftlink == NULL){
                node temp = nod->rightlink;
                free(nod);
                return temp;
            }
            else if (nod->rightlink == NULL){
                node temp = nod->leftlink;
                free(nod);
                return temp;
            }
            else{
                node temp = minInorderSuccessor(nod->rightlink);
                nod->data = temp->data;
                nod->rightlink = deletion(nod->rightlink, temp->data);
            }
        }
    }
    return nod;
}

void main(){
    int key,ch;
    node root = NULL;
    printf("\tBINARY SEARCH TREE\n0.Exit\n1.Insert a new node\n2.Display tree\n3.Delete a node");
    while(1){
        printf("\nEnter your choice of operation : ");
        scanf("%d",&ch);
        switch(ch){
            case 0:
                exit(0);
            case 1:
                printf("Enter element : ");
                scanf("%d", &key);
                getchar();
                root = insertBST(root, key);
                break;
            case 2:
                printf("\nPRORDER TRAVERSAL\t: ");
                pre_order(root);
                printf("\nINORDER TRAVERSAL\t: ");
                in_order(root);
                printf("\nPOSTORDER TRAVERSALt\t: ");
                post_order(root);
                break;
            case 3:
                printf("\nEnter the element to Delete : ");
                scanf("%d", &key);
                root = deletion(root, key);
                break;
            default:
                printf("\nInvalid Entry");
        }
    }
}