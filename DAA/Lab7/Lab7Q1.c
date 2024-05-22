#include <stdio.h>
#include <stdlib.h>

struct Node {
    char character;
    double probability;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;


Node* createNode(char character, double probability) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->character = character;
    newNode->probability = probability;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* buildHuffmanTree(Node* nodes[], int n) {
    while (n > 1) {
        int min1 = 0;
        int min2 = 1;
        if (nodes[min1]->probability > nodes[min2]->probability) {
            int temp = min1;
            min1 = min2;
            min2 = temp;
        }
        for (int i = 2; i < n; i++) {
            if (nodes[i]->probability < nodes[min1]->probability) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->probability < nodes[min2]->probability) {
                min2 = i;
            }
        }

        Node* combinedNode = createNode('\0', nodes[min1]->probability + nodes[min2]->probability);
        combinedNode->left = nodes[min1];
        combinedNode->right = nodes[min2];

        nodes[min1] = combinedNode;
        nodes[min2] = nodes[n - 1];
        n--;
    }

    return nodes[0]; 
}

void printHuffmanCodes(Node* root, int code[], int top) {
    if (root->left) {
        code[top] = 0;
        printHuffmanCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = 1;
        printHuffmanCodes(root->right, code, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
    }
}

int main() {
    
    int n;
    printf("Enter Number of Characters:");
    scanf("%d",&n);
    char characters[n];
    double probabilities[n];

    printf("Enter %d characters and their probabilities:\n",n);
    for (int i = 0; i < n; i++) {
        scanf(" %c %lf", &characters[i], &probabilities[i]);
    }

    Node* nodes[n];
    for (int i = 0; i < n; i++) {
        nodes[i] = createNode(characters[i], probabilities[i]);
    }

    Node* root = buildHuffmanTree(nodes, n);
    int code[n];
    int top = 0;
    printf("Huffman Codes:\n");
    printHuffmanCodes(root, code, top);

    return 0;
}