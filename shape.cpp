
/*
 * File: shape.cpp
 * -----------------
 * This file implements the shape.h interface.
 */

//#include "gwindow.h"
#include "shape.h"
#include <string>
#include <vector>

/*
 * Implementation notes: Shape class 
 * -----------------------------------------
 * The constructor for the superclass sets all shapes to BLACK, which is the
 * default color. The remaining methods simple set the instance variables.
 */

Shape::Shape() {
  setColor("BLACK");
}

void Shape::setLocation(double x, double y) {
  this->x = x;
  this->y - y;
}

void Shape::move(double dx, double dy) {
  x += dx;
  y += dy;
}

void Shape::setColor(std::string color) {
  this->color = color;
}

int Shape::get_x() {
  return this->x;
}

int Shape::get_y() {
  return this->y;
}

std::string Shape::get_color() {
  return this->color;
}

/*
 * Implementation notes: Line class
 * ------------------------------------
 * The constructor for the Line class has to chnage the specification of the
 * line from the endpoints passed the constructor to the representation that
 * uses a starting point along with dx, dy values.
 */

Line::Line(double x1, double y1, double x2, double y2) {
  this->x = x1;
  this->y = y1;
  this->dx = x2 - x1;
  this->dy = y2 - y1;
}


int Line::get_x2() {
  return (this->dx + this->x);
}

int Line::get_y2() {
  return (this->dy + this->y);
}

//void Line::draw(GWindow & gw) {
//  gw.setColor(color);
//  gw.drawLine(x, y, x + dx, y + dy);
//}

bool Line::contains(double a, double b) {
  if (a >= x && a <= (x + dx)) {
    if (b >= (y - 0.5) && b <= (y + 0.5)) {
      return true;
    }
    else {
      return false;
    }
  }
  else {
    return false;
  }
}

/*
 * Implementation notes: Rect, Oval, and Square classes
 * ----------------------------------------------
 * The constructors for these classes store thier arguments in the corresponding
 * instance variables. The draw method for the shape just forwards the request
 * to the GWindow class;
 */

Rect::Rect(double x, double y, double width, double height) {
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
}

int Rect::get_width() {
  return this->width;
}

int Rect::get_height() {
  return this->height;
}

//void Rect::draw(GWindow & gw) {
//  gw.setColor(color);
//  gw.fillRect(x, y, width, height);
//}

bool Rect::contains(double a, double b) {
  if (a >= x && a <= (x + width)){
    if (b <= y && b >= (y - height)) {
	return true;
    }
    else {
      return false;
    }
  }
  else {
    return false;
  }
}

  Oval::Oval(double x, double y, double width, double height) {
  this->x = x;
  this->y = y;
  this->width = width;
  this->height = height;
}

int Oval::get_width() {
  return this->width;
}

int Oval::get_height() {
  return this->height;
}

//void Oval::draw(GWindow & gw) {
//  gw.setColor(color);
//  gw.fillOval(x, y, width, height);
//}

 bool Oval::contains(double a, double b) {
   int center_x = (x + (width/2));
   int center_y = (y - (height/2));
   double check = (std::pow((a-center_x), 2) / std::pow(width, 2))
     + (std::pow((b-center_y), 2) / std::pow(height, 2));
   if (check <= 1) {
     return true;
   }
   else {
     return false;
   }
 }

Square::Square(double x, double y, double width) {
  this->x = x;
  this->y = y;
  this->width = width;
}

int Square::get_width() {
  return this->width;
}

//void Square::draw(GWindow & gw) {
//  gw.setColor(color);
//  gw.fillRect(x, y, width, width);
//}

 bool Square::contains(double a, double b) {
  if (a >= x && a <= (x + width)){
    if (b <= y && b >= (y - width)) {
      return true;
    }
    else {
      return false;
    }
  }
  else {
    return false;
  }
}
