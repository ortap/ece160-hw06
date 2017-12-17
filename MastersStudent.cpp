#include "MastersStudent.h"
#include <stdio.h>

// Constructor Implementations
MastersStudent::MastersStudent(Student ug, int msy):
    Student(ug), _ms_grad_year(msy) {}
  
MastersStudent::MastersStudent(std::string fn, std::string ln,
    int ugy, int msy, Major m):
    Student(fn, ln, ugy, m), _ms_grad_year(msy) {}

// New methods specific to MastersStudent
float MastersStudent::getMsGpa() {
  float sum = 0;
  for (int i = 0; i <_ms_grades.size();i++) {
    sum = _ms_grades[i] + sum;
  }
  return sum/_ms_grades.size();
}

void MastersStudent::addMsGrade(float grade) {
  _ms_grades.push_back(grade);
}

// Override Student's printInfo to include new fields
void MastersStudent::printInfo() {
  Student::printInfo();{
    printf("MS %s: %d \n", majorString(_major).c_str(), _ms_grad_year);
    printf("MS GPA: %.2f \n", getMsGpa());
  }
}
