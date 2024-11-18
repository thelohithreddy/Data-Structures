#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertSorted(struct Node* head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);

    if (head == NULL || head->exp < exp) {
        newNode->next = head;
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL && current->next->exp > exp) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}


void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->exp == 0) {
            printf("%d", current->coeff);
        } else {
            printf("%dx^%d", current->coeff, current->exp);
        }
        if (current->next != NULL)
            printf(" + ");
        current = current->next;
    }
    printf("\n");
}

struct Node* addPolynomials(struct Node* A, struct Node* B) {
    struct Node* result = NULL;
    struct Node* temp = NULL;

    while (A != NULL && B != NULL) {
        if (A->exp > B->exp) {
            insertSorted(&result, A->coeff, A->exp);
            A = A->next;
        } else if (A->exp < B->exp) {
            insertSorted(&result, B->coeff, B->exp);
            B = B->next;
        } else {
            int sumCoeff = A->coeff + B->coeff;
            if (sumCoeff != 0)
                insertSorted(&result, sumCoeff, A->exp);
            A = A->next;
            B = B->next;
        }
    }

    while (A != NULL) {
        insertSorted(&result, A->coeff, A->exp);
        A = A->next;
    }

    while (B != NULL) {
        insertSorted(&result, B->coeff, B->exp);
        B = B->next;
    }

    return result;
}

int main() {
    int n1, n2, coeff, exp;
    struct Node *A = NULL, *B = NULL;
    printf("Enter the number of terms in polynomial A: ");
    scanf("%d", &n1);
    printf("Enter the coefficients and exponents for polynomial A:\n");
    for (int i = 0; i < n1; i++) {
        printf("Term %d - Coefficient and Exponent: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertSorted(&A, coeff, exp);
    }

    printf("Enter the number of terms in polynomial B: ");
    scanf("%d", &n2);
    printf("Enter the coefficients and exponents for polynomial B:\n");
    for (int i = 0; i < n2; i++) {
        printf("Term %d - Coefficient and Exponent: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertSorted(&B, coeff, exp);
    }

    printf("Polynomial A: ");
    display(A);
    printf("Polynomial B: ");
    display(B);

    struct Node* result = addPolynomials(A, B);

    printf("Resultant Polynomial: ");
    display(result);

    return 0;
}
