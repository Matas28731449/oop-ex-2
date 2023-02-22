// v0.1 with arrays
#include "myLib.h"

struct student {
    string name,
           surname;
    int*   grade;
    int    exam,
           counter = 0;
};
int randomizer(int beg, int end) {
    return beg + (double)rand() / RAND_MAX * (end - beg + 1);
}
void input(student &tmp) {
    string opt;     // option
    int    grd,     // generated grade
           sum = 0; // sum of entered grades
    cout << "Enter the student's name and surname: "; cin >> tmp.name >> tmp.surname;
    cout << "Would you like to randomize the grades (type 'ran') or enter yourself? (any key to continue): "; cin >> opt;
    if(opt == "ran") {
        randomizer(0, 100); // tmp.exam always stays the same without this
        tmp.exam = randomizer(1, 10); // generated grade in a ten point system without 0 (student must participate in an exam)
        cout << "The exam grade: " << tmp.exam << endl;
        tmp.counter = randomizer(1, 100); // maximum of 100 grades per student
        cout << "The grades: ";
        int arr[tmp.counter];
        for(int i = 0; i < tmp.counter; i ++) {
            grd = randomizer(0, 10); // generated grade in a ten point system with 0 (student may not submit his homework)
            arr[i] = grd;
            sum += grd; // if sum equals 0 - error
            cout << grd << " ";
        }
        tmp.grade = new int[tmp.counter];
        copy(arr, arr + tmp.counter, tmp.grade);
        if(sum == 0) {
            cout << "0" << endl;
            cout << "RANDOMIZER ERROR: division by zero is not possible." << endl;
            input(tmp); // recursion
        }
        cout << endl;
    }
    else {
        cout << "Enter the exam grade: "; cin >> tmp.exam;
        while(cin.fail() || (tmp.exam < 0 || tmp.exam > 10)) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Incorrect form. Try again: "; cin >> tmp.exam;
        }
        cout << "Enter the grades (any other symbol to stop): ";
        int arr[100];
        while(cin >> grd && (grd >= 0 && grd <= 10)) {
            if(tmp.counter >= 100) {
                cout << "You can enter a maximum of 100 grades per student." << endl;
                break;
            }
            arr[tmp.counter] = grd;
            sum += grd;
            tmp.counter ++;
        }
        tmp.grade = new int[tmp.counter];
        copy(arr, arr + tmp.counter, tmp.grade);
        if(tmp.counter != 0) cout << "In total " << tmp.counter << " grades entered." << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(tmp.counter == 0 || sum == 0) {
            cout << "At least one grade that is not a symbol and higher than 0 must be entered! Try from the beginning." << endl;
            input(tmp); // recursion
        }
    }
}
double medium(student &tmp) {
    int sum = 0;
    for(int i = 0; i < tmp.counter; i ++) {
        sum += tmp.grade[i];
    }
    return 0.4 * (sum / (double)tmp.counter) + 0.6 * tmp.exam;
}
double median(student &tmp) {
    bool sort = true; // bubble sort
    while(sort)
    {
        sort = false;
        for(int i = 0; i < tmp.counter - 1; i ++) {
            if(tmp.grade[i] > tmp.grade[i + 1]) {
                swap(tmp.grade[i], tmp.grade[i + 1]);
                sort = true;
            }
        }
    }
    // sort(tmp.grade[0], tmp.grade[tmp.counter]);
    if(tmp.counter % 2 == 0) return 0.4 * ((tmp.grade[tmp.counter / 2 - 1] + tmp.grade[tmp.counter / 2]) / 2.0) + 0.6 * tmp.exam;
    else return 0.4 * tmp.grade[tmp.counter / 2] + 0.6 * tmp.exam;
}
void output(student &tmp, string opt) {
    if(opt == "vid") {
        cout << setw(10) << left << tmp.name << setw(14) << left << tmp.surname << setw(19) << left << fixed << setprecision(2) << medium(tmp) << "-" << endl;
    }
    else cout << setw(10) << left << tmp.name << setw(14) << left << tmp.surname << setw(19) << left << fixed << setprecision(2) << "-" << median(tmp) << endl;
    delete [] tmp.grade; // free up the memory
}
int main() {
    srand(time(NULL));
    string opt; // option
    int    num; // number
    //----------PERMANENT INPUT----------
    cout << "Enter how many students you would like to record: "; cin >> num;
    while(cin.fail() || num <= 0) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Incorrect form. Try again: "; cin >> num;
    }
    student *arr = new student[num];
    for(int i = 0; i < num; i ++) {
        input(arr[i]);
    }
    //----------END OF THE PROGRAM----------
    cout << "How would you like to calculate the final mark? Type 'vid' or 'med': "; cin >> opt;
    while(opt != "vid" && opt != "med") {
        cout << "Incorrect form. Try again: "; cin >> opt;
    }
    cout << "-----------------------------------------------------------" << endl; 
    cout << left << setw(10) << "Vardas" << left << setw(14) << "Pavarde" << left << setw(12) << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
    cout << "-----------------------------------------------------------" << endl;
    //----------FINAL OUTPUT----------
    for(int i = 0; i < num; i ++) {
        output(arr[i], opt);
    }
    //----------FREE UP THE MEMORY----------
    delete [] arr;

    return 0;
}