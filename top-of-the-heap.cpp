// Top of the heap
#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int>& tree, int a, int b) {
    int aux = tree[a];
    tree[a] = tree[b];
    tree[b] = aux;
}

void enqueue(vector<int>& tree, int item) {
    int currentIndex = tree.size();
    int parentIndex = currentIndex / 2;

    tree.push_back(item);

    while (item > tree[parentIndex]) {
        swap(tree, currentIndex, parentIndex);
        currentIndex = parentIndex;
        parentIndex = currentIndex / 2;
    }
}

void dequeue(vector<int>& tree) {
    if (tree.size() == 0) return;

    int item = tree[tree.size() - 1];
    tree.pop_back();

    if (tree.size() == 0) return;
    
    tree[0] = item;
    int currentIndex = 0;

    while (true) {
        int leftIndex = currentIndex * 2 + 1;
        int rightIndex = currentIndex * 2 + 2;
        int largestIndex = leftIndex;

        if (rightIndex < tree.size() && tree[rightIndex] > tree[largestIndex]) {
            largestIndex = rightIndex;
        }

        if (largestIndex < tree.size() && tree[largestIndex] > tree[currentIndex]) {
            swap(tree, currentIndex, largestIndex);
            currentIndex = largestIndex;
        } else {
            break;
        }
    }
}

int main() {

    vector<int> tree;

    int numOps;
    cin >> numOps;
    cin.ignore();

    for (int i = 0; i < numOps; ++i) {
        char op;
        int item;
        cin >> op;

        switch (op) {
            case 'E':
                cin >> item;
                cin.ignore();
                enqueue(tree, item);
                break;
            case 'D':
                cin.ignore();
                dequeue(tree);
                break;
        }
    }

    cout << tree.size() << endl;
    for (int item : tree)
        cout << item << endl;

    return 0;
}