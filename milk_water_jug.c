#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int x, y;
} State;

State queue[MAX];
int front = 0, rear = 0;

int visited[100][100];

void enqueue(int x, int y) {
    queue[rear].x = x;
    queue[rear].y = y;
    rear++;
}

State dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void bfs(int jug1, int jug2, int target) {

    enqueue(0, 0);
    visited[0][0] = 1;

    while (!isEmpty()) {
        State current = dequeue();

        int x = current.x;
        int y = current.y;

        printf("(%d, %d)\n", x, y);

        if (x == target || y == target) {
            printf("Target achieved!\n");
            return;
        }

        // Possible operations:
        State nextStates[] = {
            {jug1, y},          // Fill jug1
            {x, jug2},          // Fill jug2
            {0, y},             // Empty jug1
            {x, 0},             // Empty jug2
            {x - (jug2 - y < x ? jug2 - y : x), 
             y + (jug2 - y < x ? jug2 - y : x)},  // Pour jug1 -> jug2
            {x + (jug1 - x < y ? jug1 - x : y), 
             y - (jug1 - x < y ? jug1 - x : y)}   // Pour jug2 -> jug1
        };

        for (int i = 0; i < 6; i++) {
            int newX = nextStates[i].x;
            int newY = nextStates[i].y;

            if (!visited[newX][newY]) {
                visited[newX][newY] = 1;
                enqueue(newX, newY);
            }
        }
    }

    printf("No solution possible\n");
}

int main() {
    int jug1 = 4, jug2 = 3, target = 2;

    bfs(jug1, jug2, target);

    return 0;
}
