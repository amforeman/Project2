/*
 * File: shape.h
 * -----------------------
 * This file defines a simple hierarchy of graphical shape classes.
 */

#ifndef _shape_h
#define _shape_h

#include <string>
#include "gwindow.h"

/*
 * Class: Shape
 * -----------------------
 * This class is the root of the hierarchy and encompasses all shapes.
 */

class Shape {
  
 public:
  
  /*
   * Method: setLocation
   * Usage: shape.setLocation(x, y);
   * ---------------------------------
   * Sets the x and y coordinates of the shape to the specified values.
   */

  void setLocation(double x, double y);
  
  /*
   * Method: move
   * Usage: shape.move(dx, dy);
   * ---------------------------
   * Adds dx and dy to the coordinates of the shape.
   */

  void move(double x, double y);

  /*
   * Method: setColor
   * Usage: shape.setColor(color);
   * -------------------------------
   * Sets the color of the shape. The names of the available colors are described 
   * in the gwindow.h interface.
   */

  void setColor(std::string color);

  /*
   * Abstract method: draw
   * Usage: shape.draw(gw);
   * -------------------------
   * Draws the shape in the GraphicsWindow specified by gw.
   * This method is implemented by the specific shape subclasses.
   */

  virtual void draw (GWindow & gw) = 0;

  /*
   *
   */

  virtual bool contains(double x, double y) = 0;

protected:

  /* The following methods and fields are available to the subclasses */
  Shape();                          // Superclass constructor
  std::string color;                // The color of the object
  double x, y;                      // The coordinate of the object

};

/*
 * Subclass: Line
 * ---------------------
 * The Line subclass represents a line segment on the window.
 */

class Line : public Shape {
  
public:

  /*
   * Constructor: Line
   * Usage: Line line(x1, y1, x2, y2);
   * ------------------------------------
   * Creates a line segment that extends from (x1, y1) to (x2, y2)/
   */

  Line(double x1, double y1, double x2, double y2);

  // Prototypes for the overridden virtual methods

  virtual void draw(GWindow & gw);

private:
  double dx;                     // Horizontal distance from x1 to x2
  double dy;                     // Vertical distance from y1 to y2

};

/*
 * Subclass: Rect
 * --------------------
 * The Rect subclass represents a solid rectangle.
 */

class Rect : public Shape {

public:

  /*
   * Constructor: Rect
   * Usage: Rect rect(x, y, width, height);
   * -----------------------------------------
   * Creates a rectangle of the specified size and upper left corner at (x,y).
   */

  Rect(double x, double y, double width, double height);

  // Prototypes for the overridden virtual methods

  virtual void draw(GWindow & gw);

private:

  double width, height;                // Dimensions of the rectangle

};

/*
 * Subclass: Oval
 * -----------------------
 * The Oval sublcass represents a solid oval defined by a bounding rectangle.
 */

class Oval : public Shape {

public:
  /*
   * Constructor: Oval
   * Usage: Oval oval(x, y, width, height);
   * ---------------------------------------
   * Creates an oval that fits inside the rectangle indicated by the arguments.
   */

  Oval(double x, double y, double width, double height);

  // Prototypes for the overridden virtual methods

  virtual void draw(GWindow & gw);

private:
  double width, height;               //Dimensions of the bounding rectangle

};


/*
 * Subclass: Square
 * ----------------------
 * The square subclass represents a solid square.
 */

class Square : public Rectangle {

public:
  /*
   * Constructor: Square
   * Usage: Square square(x, y, width);
   * -------------------------------------
   * Creates a square of the specified size with the upper left corner at (x, y).
   */

  Square(double x, double y, double width);

  // Prototypes for the overridden virtual methods

  virtual void draw(GWindow & gw);

private:
  double width;                      // Dimensions of the square
#endif
