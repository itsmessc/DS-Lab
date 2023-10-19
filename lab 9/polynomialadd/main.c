#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coef;
    int exp;
    struct Node* next;
};
typedef struct Node Node;
void insert(Node** poly, int coef, int exp) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->coef = coef;
    temp->exp = exp;
    temp->next = NULL;

    if (*poly == NULL) {
        *poly = temp;
        return;
    }

    Node* current = *poly;
    Node* tem;
    if((*poly)->exp<exp)
    {
        temp->next=(*poly);
        (*poly)=temp;
        return 0;
    }
    while (current->next != NULL) {
            if(current->next->exp<exp)
            break;
        current = current->next;
    }
    tem=current->next;
    current->next = temp;
    temp->next=tem;
}
void print(Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    Node* current = poly;

    while (current != NULL) {
        printf("%dx^%d", current->coef, current->exp);
        if (current->next != NULL) {
            printf(" + ");
        }
        current = current->next;
    }

    printf("\n");
}
Node* add(Node* poly1, Node* poly2) {
    Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp == poly2->exp) {
            insert(&result, poly1->coef + poly2->coef, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exp > poly2->exp) {
            insert(&result, poly1->coef, poly1->exp);
            poly1 = poly1->next;
        } else {
            insert(&result, poly2->coef, poly2->exp);
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insert(&result, poly1->coef, poly1->exp);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insert(&result, poly2->coef, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}
int main()
{
    Node* poly1=NULL;
    Node *poly2=NULL;
    Node *result=NULL;
    int s,c,e,i;
    do
    {
        printf("1.insert in 1st\n2.Insert in 2nd\n3.add\n4.exit\n");
        scanf("%d",&s);
        switch(s)
        {
            case 1:
                printf("Enter coeff,exp:");
                scanf("%d %d",&c,&e);
                insert(&poly1,c,e);
                break;
            case 2:
                printf("Enter coeff,exp:");
                scanf("%d %d",&c,&e);
                insert(&poly2,c,e);
                break;
            case 3:
                result=add(poly1,poly2);
                print(poly1);
                print(poly2);
                print(result);
                break;
            case 4:
                return 0;
        }
    }while(1);
    return 0;
}
