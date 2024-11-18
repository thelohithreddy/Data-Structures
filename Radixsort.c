#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* createNode(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

int isEmpty(struct Node* head) {
    return head == NULL;
}

struct Node* insert(struct Node* head, int data, int priority) {
    struct Node* newNode = createNode(data, priority);
    if (head == NULL || head->priority > priority) {
        newNode->next = head;
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->priority <= priority) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node* removeNode(struct Node* head) {
    if (isEmpty(head)) return NULL;
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

int peek(struct Node* head) {
    if (isEmpty(head)) return -1;
    return head->data;
}

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("Data: %d, Priority: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main() {
    struct Node* pq = NULL;
    int n, data, priority;
    
    printf("Enter the number of elements in the queue: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter data and priority for element %d: ", i + 1);
        scanf("%d %d", &data, &priority);
        pq = insert(pq, data, priority);
    }
    
    printf("\nPriority Queue:\n");
    display(pq);
    
    if (!isEmpty(pq)) {
        printf("\nElement with highest priority: %d\n", peek(pq));
        pq = removeNode(pq);
        printf("\nPriority Queue after removing highest priority element:\n");
        display(pq);
    }
    
    return 0;
}
