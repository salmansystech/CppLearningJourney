#include <iostream>
#include <vector>

using namespace std;

struct Student
{
    string name_;
    string birth_day_;
};
void print(Student* student, const string& pre_text = "")
{
    cout << pre_text;
    if(student)
    {
        cout << student->name_ << " --- " << student->birth_day_ << endl;
    }
    else
    {
        cout << "None" << endl;
    }
}
Student* find_first_occurrence(const string& name, const string& birth_day, const vector<Student*>& course)
{
    for(Student* student : course)
    {
        if(student && student->name_ == name && student->birth_day_ == birth_day)
        {
            return student;
        }
    }
    return nullptr;
}
void find_same(const vector<Student*>& course1, const vector<Student*>& course2)
{
    for(Student* student1 : course1)
    {
        if(student1 == nullptr)
        {
            continue;
        }

        for(Student* student2 : course2)
        {
            if(student2 == nullptr)
            {
                continue;
            }
            if(student1 == student2)
            {
                print(student1, "* Same student in two courses: ");
            }
        }
    }
}
void find_identical(const vector<Student*>& course)
{
    for(size_t i = 0; i < course.size(); ++i)
    {
        Student* student1 = course[i];
        if(student1 == nullptr)
        {
            continue;
        }

        for(size_t j = i + 1; j < course.size(); ++j)
        {
            Student* student2 = course[j];
            if(student2 == nullptr)
            {
                continue;
            }
            if(student1 != student2 && student1->name_ == student2->name_ && student1->birth_day_ == student2->birth_day_)
            {
                print(student1, "* Identical students in a course: ");
            }
        }
    }
}


// Don't remove! Needed for tests.
#ifndef POINTERS_TEST
#define POINTERS_TEST
// Don't remove! Needed for tests.

// Main function (an example test case)
int main()
{
    // Students
    Student stud1{"Mortti", "2001-01-01"};
    Student stud2{"Vertti", "2002-02-02"};
    Student stud3{"Mortti", "2001-01-01"};

    // Assigning students to courses
    vector<Student*> prog1 = {nullptr, &stud1, &stud2};
    vector<Student*> prog2 = {&stud1, &stud2, &stud3};
    vector<Student*> prog3 = {&stud1, &stud3};

    // Different seaches
    cout << "Seaching for same students from two different courses" << endl;
    find_same(prog1, prog2);

    cout << endl << "Searching for identical students from a course" << endl;
    find_identical(prog3);

    cout << endl << "Searching for a certain student from a course" << endl;
    Student* wanted = find_first_occurrence("Mortti", "2001-01-01", prog1);
    print(wanted, "* ");
    wanted = find_first_occurrence("Mortti", "2002-02-02", prog1);
    print(wanted, "* ");

    return 0;
}

// Don't remove! Needed for tests.
#endif //POINTERS_TEST
// Don't remove! Needed for tests.
