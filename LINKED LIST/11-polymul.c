#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coeff;
    int exp;
    struct node* link;
} node;

void insertpoly(node* header, int exp, int coeff) {
    node* newnode, *temp;
    newnode = (node*)malloc(sizeof(node));
    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->link = NULL;

    if (header->link == NULL) {
        header->link = newnode;
        return;
    }

    temp = header;
    while (temp->link != NULL) {
        temp = temp->link;
    }

    temp->link = newnode;
}

void display(node* header) {
    node* ptr = header->link;

    if (ptr == NULL) {
        printf("0\n");
        return;
    }

    while (ptr != NULL) {
        printf("%dx^%d", ptr->coeff, ptr->exp);

        if (ptr->link != NULL) {
            printf(" + ");
        }

        ptr = ptr->link;
    }

    printf("\n");
}

void multiplypoly(node* poly1, node* poly2, node* result) {
    node* p1 = poly1->link;

    while (p1 != NULL) {
        node* p2 = poly2->link;
        while (p2 != NULL) {
            int coeff = p1->coeff * p2->coeff;
            int exp = p1->exp + p2->exp;

            // Check if a term with the same exponent already exists in the result
            node* existing = result->link;
            while (existing != NULL) {
                if (existing->exp == exp) {
                    // Combine coefficients if the same exponent is found
                    existing->coeff += coeff;
                    break;
                }
                existing = existing->link;
            }

            // If no term with the same exponent is found, insert a new term
            if (existing == NULL) {
                insertpoly(result, exp, coeff);
            }

            p2 = p2->link;
        }

        p1 = p1->link;
    }
}

int main() {
    int m, n, x;
    node* P, * Q, * R;
    P = (node*)malloc(sizeof(node));
    Q = (node*)malloc(sizeof(node));
    R = (node*)malloc(sizeof(node));
    P->link = NULL;
    Q->link = NULL;
    R->link = NULL;

    printf("Enter degrees of first and second polynomial: ");
    scanf("%d%d", &m, &n);

    printf("Enter first polynomial:\n");
    for (int i = m; i >= 0; i--) {
        printf("Enter coefficient for x^%d: ", i);
        scanf("%d", &x);
        if (x != 0) {
            insertpoly(P, i, x);
        }
    }

    printf("Enter second polynomial:\n");
    for (int i = n; i >= 0; i--) {
        printf("Enter coefficient for x^%d: ", i);
        scanf("%d", &x);
        if (x != 0) {
            insertpoly(Q, i, x);
        }
    }

    multiplypoly(P, Q, R);

    // Display the result of polynomial multiplication
    printf("Polynomials are:\n");
    printf("P: ");
    display(P);
    printf("Q: ");
    display(Q);
    printf("Product is: ");
    display(R);

    return 0;
}

