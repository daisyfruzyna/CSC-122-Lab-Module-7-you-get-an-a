#include <string>
#include <vector>


std::string hello();
using namespace std;



class Assignment {
  string name;
  int maxGrade;
  public:
    Assignment(const string &name, int maxGrade);

  string get_grade();

  string get_name();
};

class Student {
  string firstName;
  string lastName;
  string studentID;
  vector<Assignment> assignments;
public:
  Student(const string& name, const string &studentID);
  void add_grade(const string &name, int grade);
  string get_name() const;

  string get_name_report() const;


  string get_grade() const;
  bool operator==(const Student & stu2) const {
    if (this->firstName == stu2.firstName && this->lastName == stu2.lastName) {return true;}
    return false;
  }
   int contains_assignment(string name);
};

class Gradebook {
  vector<Student> students;
  vector<Assignment> assignments;

  public:
    Gradebook();
    void add_student(const string &name, const string &studentID);
    void add_assignment(const string &name, int grade);
    void enter_grade(const string& name, const string& assignment, int grade);


    Student find(const string& name);
    string get_students() const;
    string get_grades(const string& studentName);
    string report();
};

