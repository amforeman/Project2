#include "shape.h"
#include "shapelist.h"

ShapeList::ShapeList() {
  //Empty
}

void ShapeList::moveToFront(Shape *sp) {
  Shape *temp = sp;
  for (int i = 0; i < this->size()-1; i++) {     //Iterate through shapelist
    if (this->at(i) == temp) {                   //If value at index is equal to the given shape pointer 
      this->erase(this->begin() + i);            //Remove shape pointer from current position
      this->insert(this->begin(), 1, temp);      //Add shape pointer to the front of the vector
      return;
    }
  }
  std::cout<<"Error: Shape is not in list."<<std::endl;
  return;
}

void ShapeList::moveToBack(Shape *sp) {
  Shape *temp = sp;
  for (int i = 0; i < this->size()-1; i++) {
    if (this->at(i) == temp) {                   
      this->erase(this->begin() + i);           
      this->push_back(temp);                    //Add shape pointer to the end of the vector
      return;
    }
  }
  std::cout<<"Error: Shape is not in list."<<std::endl;
  return;
}

void ShapeList::moveForward(Shape *sp) {
  Shape *temp = sp;
  for (int i = 0; i < this->size()-1; i++) {
    if (this->at(i) == temp) {
       this->erase(this->begin() + i);
       this->insert(this->begin() + (i-1), 1, temp);    //Insert shape pointer 1 position in front of where it previously was
       return;
    }
  }
  std::cout<<"Error: Shape is not in list."<<std::endl;
  return;
}

void ShapeList::moveBackward(Shape *sp) {
  Shape *temp = sp;
  for (int i = 0; i < this->size()-1; i++) {
    if (this->at(i) == temp) {
      this->erase(this->begin() + i);                   
      this->insert(this->begin() + (i+1), 1, temp);     //Insert shape pointer 1 position behind where is previously was
      return;
    }
  }
  std::cout<<"Error: Shape is not in list."<<std::endl;
}

Shape* ShapeList::getShapeAt(int x, int y) {
  for (int i = 0; i < this->size()-1; i++) {
    if (this->at(i)->contains(x, y)) {                  //If shape at index i contains given point
      std::cout<<"Shape "<<i<<" contains ("<<x<<", "<<y<<") \n";
      return this->at(i);
    }
  }
  std::cout<<"There are no shapes at those coordinates."<<std::endl;
  return nullptr;
}
