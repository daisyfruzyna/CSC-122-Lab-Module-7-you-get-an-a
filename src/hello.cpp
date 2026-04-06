#include <string>
#include <vector>

#include "hello.hpp"

#include <iostream>
#include <ostream>

using namespace std;

std::string hello() {
   return "Hello World!";
}




Assignment::Assignment(const string &name, const int maxGrade) {
   this->name = name;
   this->maxGrade = maxGrade;
}
string Assignment::get_grade() {
   return to_string(maxGrade);
}
string Assignment::get_name() {
   return name;
}

Student::Student(const string& name, const string &studentID) {
   firstName = name.substr(0, name.find(' '));
   lastName = name.substr(name.find(' ') + 1);
   this->studentID = studentID;
}

void Student::add_grade(const string &name, int grade) {
   assignments.push_back(Assignment(name, grade));
}
string Student::get_grade() const {
   string gradeList;
   for (Assignment a : assignments) {
      gradeList.append(a.get_grade() + ", ");
   }
   return gradeList;
}
string Student::get_name() const {
   return firstName + " " + lastName;
}
string Student::get_name_report() const {
   return lastName + ", " + firstName + ", " + studentID;
}
int Student::contains_assignment(string name) {
   for (int i = 0; i < assignments.size(); i++) {
      if (assignments.at(i).get_name() == name) {
         return i;
      }
   }


   return -1;
};



Gradebook::Gradebook() = default;

void Gradebook::add_student(const string &name, const string &studentID) {
   students.push_back(Student(name, studentID));
}
void Gradebook::add_assignment(const string &name, const int grade) {
   assignments.push_back(Assignment(name, grade));
}
void Gradebook::enter_grade(const string& name, const string& assignment, int grade) {
   Student tempStudent(name, " ");
   for (Student & student : students) {
      if (student == tempStudent) {
         student.add_grade(assignment, grade);
      }
   }
}

Student Gradebook::find(const string& name) {
   Student tempStudent(name, " ");
   for (Student s : students) {
      if (s == tempStudent) {
         return s;
      }
   }
   return tempStudent;
}


string Gradebook::get_students() const {
   string stuList;
   for (Student s : students) {
      stuList.append(s.get_name() + ", ");
   }
   return stuList;
}
string Gradebook::get_grades(const string& studentName) {
   return find(studentName).get_grade();
}

string Gradebook::report() {
   string report = "Last_Name, First_Name, Student_Id, ";
   for (Assignment a : assignments) {
      report += a.get_name() + ", ";
   }
   report += "\n";
   for (Student s : students) {
      report += s.get_name_report() + ", ";
      // report += s.get_grade() + ", ";
      for (Assignment a : assignments) {

         if (s.contains_assignment(a.get_name()) >= 0) {
            report += a.get_name() + ", ";
         }
      }
   report += "\n";
   }

   return report;
}