#include "headers/library.h"
#include "headers/references.h"

int main() {
    vector<student> arr;       // array
    string          opt = " "; // option

    //----------RULE OF FIVE TESTS----------
    student s1;
    s1.setName("Vardenis");
    s1.setSurname("Pavardenis");
    s1.setExam(10);
    s1.setGrade(8); s1.setGrade(9);
    student s2 = s1; // copy c.
    cout << s2.getName() << " " << s2.getSurname() << " " << s2.getExam() << "\n";
    s2.~student();
    student s3 = student(); // move c.
    cout << s3.getName() << " " << s3.getSurname() << " " << s3.getExam() << "\n";
    s3.~student();
    student s4(s1); // copy a.
    cout << s4.getName() << " " << s4.getSurname() << " " << s4.getExam() << "\n";
    s1.~student();
    s4.~student();

    //----------INPUT----------
    auto start = std::chrono::high_resolution_clock::now();
    input(arr, opt);
    //----------OUTPUT----------
    output(arr, opt);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> difference = end - start;
    cout << "Program time: " << difference.count() << " s\n";

    return 0;
}
