#include <iostream>
using namespace std;

void bubble_sort(int *polje, int duljina) {
    int tmp;
    for(int i=duljina - 1; i>0; i--) {
        for(int j=0; j<i; j++) {
            if(polje[j + 1] < polje[j]){
                tmp = polje[j];
                polje[j] = polje[j+1];
                polje[j+1] = tmp;
            }
        }
    }
}
int main() {
    int i;
    int niz[10] = {9, 8, 7, 10, 6, 4, 3, 2, 5, 1};
    for(i=0; i<10; i++)
        cout << niz[i] <<" ";
    cout << "\nSortiram ..." << endl;
    bubble_sort(niz, 10);
    for(i=0; i<10; i++)
        cout << niz[i] <<" ";
    cin >> i;
    return 0;
}
