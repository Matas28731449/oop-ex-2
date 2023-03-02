#include "headers/library.h"
#include "headers/references.h"

int main() {
    vector<student> arr;       // array
    string          opt = " "; // option
    //----------INPUT----------
    input(arr, opt);
    //----------OUTPUT----------
    output(arr, opt);
    //----------FREE UP THE MEMORY----------
    cout << "\nFreeing memory...\nEnd of the program.\n";
    for(int i = 0; i < arr.size(); i ++) {
        arr[i].grade.clear();
    }
    arr.clear();

    return 0;
}
