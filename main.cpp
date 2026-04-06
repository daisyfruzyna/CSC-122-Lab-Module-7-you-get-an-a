#include <iostream>

#include "src/hello.hpp"

int main() {
  Gradebook gradebook;

  gradebook.add_student("Bob Bobberson", "ABC123");
  gradebook.add_student("Sam Sammerson", "DEF456");
  gradebook.add_student("Jess Jesserson", "HIJ789");

  gradebook.add_assignment("Quiz 1", 100);
  gradebook.add_assignment("Lab 1", 50);

  gradebook.enter_grade("Sam Sammerson", "Quiz 1", 95);
  gradebook.enter_grade("Bob Bobberson", "Quiz 1", 85);

  string studentID = gradebook.get_students();
  string sam = gradebook.get_grades("Sam Sammerson");

  cout << studentID << endl;
  cout << sam << endl;
  cout << endl;
  cout << endl;
  cout << gradebook.report();

}
