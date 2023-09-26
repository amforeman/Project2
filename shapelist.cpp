#include "shape.h"
#include "shapelist.h"

ShapeList::ShapeList() {
  //Empty
}

void ShapeList::moveToFront(Shape *sp) {
  Shape *temp = sp;
  for (int i = 0; i < this->size()-1; i++) {
    if (this->at(i) == temp) {
        this->erase(this->begin() + i);
	this->insert(this->begin(), 1, temp);
    }
  }
}

void ShapeList::moveToBack(Shape *sp) {
  Shape *temp = sp;
  for (int i = 0; i < this->size()-1; i++) {
    if (this->at(i) == temp) {
       this->erase(this->begin() + i);
       this->push_back(temp);
    }
  }
}

void ShapeList::moveForward(Shape *sp) {
  Shape *temp = sp;
  for (int i = 0; i < this->size()-1; i++) {
    if (this->at(i) == temp) {
       this->erase(this->begin() + i);
       this->insert(this->begin() + (i-1), 1, temp);
    }
  }
}

void ShapeList::moveBackward(Shape *sp) {
  Shape *temp = sp;
  for (int i = 0; i < this->size()-1; i++) {
    if (this->at(i) == temp) {
      this->erase(this->begin() + i);
      this->insert(this->begin() + (i+1), 1, temp);
    }
  }
}

Shape* ShapeList::getShapeAt(int x, int y) {
  for (int i = 0; i < this->size()-1; i++) {
    if (this->at(i)->contains(x, y)) {
      std::cout<<"i: "<<i<<std::endl;
      std::cout<<"Size: "<<this->size()-1<<std::endl;
      std::cout<<"Shape "<<i<<" contains ("<<x<<", "<<y<<") \n";
      return this->at(i);
    }
  }
  std::cout<<"There are no shapes at those coordinates."<<std::endl;
  return nullptr;
}
