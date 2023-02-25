// v0.1 with arrays
#include "myLib.h"

struct student {
    string name,
           surname;
    int   *grade;
    int    exam,
           counter = 0;
};
int randomize(int beg, int end) { // beginning, ending
    mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    uniform_int_distribution<int> dis(beg, end);
    return dis(mt);
}
void input(student &tmp) {
    string opt;     // option
    int    grd,     // generated grade
           sum = 0; // sum of entered grades
    cout << "Enter the student's name and surname: "; cin >> tmp.name >> tmp.surname;
    cout << "Would you like to randomize the grades (type 'ran') or enter yourself? (any key to continue): "; cin >> opt;
    if(opt == "ran") {
        tmp.exam = randomize(1, 10); // generated grade in a ten point system without 0 (student must participate in an exam)
        cout << "The exam grade: " << tmp.exam << endl;
        tmp.counter = randomize(1, max);
        tmp.grade = new int[tmp.counter];
        cout << "The grades: ";
        for(int i = 0; i < tmp.counter; i ++) {
            tmp.grade[i] = randomize(0, 10); // generated grade in a ten point system with 0 (student may not submit his homework)
            i != tmp.counter - 1 ? cout << tmp.grade[i] << " " : cout << tmp.grade[i] << endl;
        }
    }
    else {
        cout << "Enter the exam grade: "; cin >> tmp.exam;
        while(cin.fail() || tmp.exam < 0 || tmp.exam > 10) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Incorrect form. Try again: "; cin >> tmp.exam;
        }
        cout << "Enter the grades (any other symbol to stop): ";
        int arr[max];
        while(cin >> grd && grd >= 0 && grd <= 10) {
            if(tmp.counter >= max) {
                cout << "You can enter a maximum of " << max << " grades per student." << endl;
                break;
            }
            arr[tmp.counter] = grd;
            sum += grd;
            tmp.counter ++;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(tmp.counter == 0 || sum == 0) {
            cout << "At least one grade that is not a symbol and higher than 0 must be entered! Try from the beginning." << endl;
            tmp.counter = 0;
            input(tmp); // recursion
        }
        else cout << "In total " << tmp.counter << " grades entered." << endl;
        tmp.grade = new int[tmp.counter];
        copy(arr, arr + tmp.counter, tmp.grade);
    }
}
double medium(student &tmp) {
    int sum = 0;
    for(int i = 0; i < tmp.counter; i ++) {
        sum += tmp.grade[i];
    }
    return 0.4 * ((double)sum / tmp.counter) + 0.6 * tmp.exam;
}
double median(student &tmp) {
    sort(tmp.grade, tmp.grade + tmp.counter);
    return tmp.counter % 2 == 0 ? 0.4 * ((tmp.grade[tmp.counter / 2 - 1] + tmp.grade[tmp.counter / 2]) / 2.0) + 0.6 * tmp.exam : 0.4 * tmp.grade[tmp.counter / 2] + 0.6 * tmp.exam;
}
void output(student &tmp, string opt) {
    opt == "vid" ? cout << setw(10) << left << tmp.name << setw(14) << left << tmp.surname << setw(19) << left << fixed << setprecision(2) << medium(tmp) << "-" << endl : cout << setw(10) << left << tmp.name << setw(14) << left << tmp.surname << setw(19) << left << fixed << setprecision(2) << "-" << median(tmp) << endl;
}
int main() {
    int      num = 0;                // number
    string   req;                    // request
    string   opt;                    // option
    student *arr = new student[num]; // array
    //----------INPUT----------
    do {
        student *tmp = new student[num]; // temporary
        copy(arr, arr + num, tmp);
        delete [] arr;
        arr = new student[num + 1];
        copy(tmp, tmp + num, arr);
        delete [] tmp;
        input(arr[num]);
        cout << "Enter 'end' if all students are entered or any key to continue: "; cin >> req;
        if(req != "end") num ++;
    } while(req != "end");
    //----------END OF THE PROGRAM----------
    cout << "How would you like to calculate the final mark? Type 'vid' or 'med': "; cin >> opt;
    while(opt != "vid" && opt != "med") {
        cout << "Incorrect form. Try again: "; cin >> opt;
    }
    cout << "-----------------------------------------------------------" << endl; 
    cout << left << setw(10) << "Vardas" << left << setw(14) << "Pavarde" << left << setw(12) << "Galutinis (Vid.) / Galutinis (Med.)" << endl;
    cout << "-----------------------------------------------------------" << endl;
    //----------OUTPUT----------
    for(int i = 0; i < num + 1; i ++) {
        output(arr[i], opt);
    }
    //----------FREE UP THE MEMORY----------
    delete [] arr->grade;
    delete [] arr;

    return 0;
}
