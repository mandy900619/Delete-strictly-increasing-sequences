#include <iostream>

using namespace std;
struct sequence {
    int value;
    int Tcount = 1;
    struct sequence* nextptr = NULL;
    struct sequence* preptr = NULL;
};
typedef struct sequence listnode;
int main() {
    int T = 0;
    int input;
    int count = 0;
    listnode* startnode = NULL;
    listnode* currentptr = NULL;
    listnode* preptr = NULL;
    cin >> count >> T;
    for (int i = 0; i < count; i++) {
        cin >> input;
        listnode* newptr = new listnode;
        newptr->value = input;
        newptr->nextptr = NULL;
        if (i == 0) {
            startnode = newptr;
            currentptr = newptr;
            preptr = newptr;
        }
        else {
            currentptr->nextptr = newptr;
            currentptr = newptr;
            currentptr->preptr = preptr;
            preptr = preptr->nextptr;
        }
    }
    listnode* nowptr = startnode;
    listnode* headptr = NULL;
    listnode* tailptr = NULL;
    while (nowptr->nextptr != NULL) {
        if (count < T) {
            break;
        }
        nowptr = nowptr->nextptr;
        if (nowptr->value > nowptr->preptr->value) {
            nowptr->Tcount = nowptr->preptr->Tcount + 1;
        }
        if (nowptr->Tcount >= T) {
            count -= T;
            headptr = nowptr;
            for (int i = 1; i < T; i++) {
                headptr = headptr->preptr;
            }
            if (nowptr->nextptr == NULL) {
                headptr = headptr->preptr;
                headptr->nextptr = NULL;
            }
            else if (headptr->preptr == NULL) {
                nowptr = nowptr->nextptr;
                startnode = nowptr;
                nowptr->preptr = NULL;
            }
            else {
                tailptr = nowptr->nextptr;
                headptr = headptr->preptr;
                headptr->nextptr = tailptr;
                tailptr->preptr = headptr;
                nowptr = headptr;
                nowptr->Tcount = 1;
                for (int i = 1; i < T - 1; i++) {
                    if (nowptr->preptr == NULL) {
                        break;
                    }
                    else {
                        nowptr = nowptr->preptr;
                        nowptr->Tcount = 1;
                    }
                }
            }
        }
    }
    nowptr = startnode;
    if (count != 0) {
        cout << nowptr->value;
        nowptr = nowptr->nextptr;
        for (int i = 1; i < count; i++) {
            cout << " " << nowptr->value;
            nowptr = nowptr->nextptr;
        }
    }
}