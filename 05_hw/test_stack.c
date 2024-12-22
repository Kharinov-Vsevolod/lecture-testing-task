#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void test_push() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Проверяем, что верхний элемент стека - это 30
    Node* top = getTop(&stack);
    assert(top != NULL && top->data == 30);

    destroyStack(&stack);
    printf("test_push: SUCCESS\n");
}

void test_pop() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    pop(&stack);
    Node* top = getTop(&stack);
    assert(top != NULL && top->data == 20);

    pop(&stack);
    top = getTop(&stack);
    assert(top != NULL && top->data == 10);

    pop(&stack);
    assert(isEmpty(&stack));

    destroyStack(&stack);
    printf("test_pop: SUCCESS\n");
}

void test_isEmpty() {
    Stack stack;
    initStack(&stack);

    assert(isEmpty(&stack));

    push(&stack, 10);
    assert(!isEmpty(&stack));

    pop(&stack);
    assert(isEmpty(&stack));

    destroyStack(&stack);
    printf("test_isEmpty: SUCCESS\n");
}

void test_searchByValue() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    Node* result = searchByValue(&stack, 20);
    assert(result != NULL && result->data == 20);

    result = searchByValue(&stack, 40);
    assert(result == NULL);

    destroyStack(&stack);
    printf("test_searchByValue: SUCCESS\n");
}

void test_searchByIndex() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    Node* result = searchByIndex(&stack, 0);
    assert(result != NULL && result->data == 30);

    result = searchByIndex(&stack, 2);
    assert(result != NULL && result->data == 10);

    result = searchByIndex(&stack, 3);
    assert(result == NULL);

    destroyStack(&stack);
    printf("test_searchByIndex: SUCCESS\n");
}

void test_getTop() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);

    Node* top = getTop(&stack);
    assert(top != NULL && top->data == 20);

    pop(&stack);
    top = getTop(&stack);
    assert(top != NULL && top->data == 10);

    pop(&stack);
    top = getTop(&stack);
    assert(top == NULL);

    destroyStack(&stack);
    printf("test_getTop: SUCCESS\n");
}

void test_destroyStack() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    destroyStack(&stack);
    assert(getTop(&stack) == NULL);

    printf("test_destroyStack: SUCCESS\n");
}

void test_createNode() {
    Node* node = createNode(42);
    assert(node != NULL && node->data == 42 && node->next == NULL);
    free(node);
    printf("test_createNode: SUCCESS\n");
}

void test_initStack() {
    Stack stack;
    initStack(&stack);
    assert(stack.top == NULL);
    printf("test_initStack: SUCCESS\n");
}

void test_traverseStack() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Expected output: Stack elements: 30 20 10\n");
    printf("Actual output:   ");
    traverseStack(&stack);

    destroyStack(&stack);
    printf("test_traverseStack: SUCCESS\n");
}

int main() {
    printf("Running tests...\n");

    test_createNode();
    test_initStack();
    test_destroyStack();
    test_push();
    test_pop();
    test_searchByValue();
    test_searchByIndex();
    test_getTop();
    test_traverseStack();
    test_isEmpty();

    printf("All tests completed.\n");

    return 0;
}