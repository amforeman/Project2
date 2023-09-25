/*
 * File: gwindow.h
 * ---------------
 * This class defines a graphics window.
 */
#ifndef _gwindow_h
#define _gwindow_h
#include <string>
#include "gtypes.h"
#include "vector.h"
/*
 * Class: GWindow
 * --------------
 * This class represents a graphics window that can be displayed on the
 * screen.
 */
class GWindow {
public:
/*
 * Constructor: GWindow
 * Usage: GWindow gw(width, height);
 * ---------------------------------
 * Creates a window of the specified size but does not display it on the
 * screen until the client calls setVisible(true).
 */
 GWindow(double width, double height);
/*
 * Method: close
 * Usage: gw.close();
 * ------------------
 * Deletes the window from the screen. Calling any method on a window that
 * has been closed generates an error.
 */
 void close();
/*
 * Method: clear
 * Usage: gw.clear();
 * ------------------
 * Clears the contents of the graphics window.
 */
 void clear();
 /*
 * Method: setVisible
 * Usage: gw.setVisible(flag);
 * ---------------------------
 * Determines whether the window is visible on the screen. Windows start
 * out in an invisible state and must be made visible before they appear.
 */
 void setVisible(bool flag);
/*
 * Method: isVisible
 * Usage: if (gw.isVisible()) . . .
 * --------------------------------
 * Tests whether the window is visible.
 */
 bool isVisible() const;
/*
 * Method: drawArc
 * Usage: gw.drawArc(bounds, start, sweep);
 * gw.drawArc(x, y, width, height, start, sweep);
 * -----------------------------------------------------
 * Draws an elliptical arc inscribed in a rectangle. The parameters x, y,
 * width, and height (or, equivalently, the GRectangle bounds) specify the
 * coordinates and dimensions of the bounding rectangle. The start
 * parameter indicates the angle at which the arc begins and is measured in
 * degrees counterclockwise from the +x axis. Thus, a start angle of 0
 * indicates an arc that begins along the line running eastward from the
 * center, a start angle of 135 begins along the line running northwest,
 * and a start angle of -90 begins along the line running south. The sweep
 * parameter indicates the extent of the arc and is also measured in
 * degrees counterclockwise. A sweep angle of 90 defines a quarter circle
 * extending counterclockwise from the start angle, and a sweep angle of
 * -180 defines a semicircle extending clockwise.
 */
 void drawArc(const GRectangle & bounds, double start, double sweep);
 void drawArc(double x, double y, double width, double height,
 double start, double sweep);
/*
 * Method: fillArc
 * Usage: gw.fillArc(bounds, start, sweep);
 * gw.fillArc(x, y, width, height, start, sweep);
 * -----------------------------------------------------
 * Fills a wedge-shaped area of an elliptical arc. The parameters are
 * interpreted in the same way as those for drawArc.
 */
 void fillArc(const GRectangle & bounds, double start, double sweep);
 void fillArc(double x, double y, double width, double height,
 double start, double sweep);
 /*
 * Method: drawImage
 * Usage: gw.drawImage(filename, pt);
 * gw.drawImage(filename, x, y);
 * gw.drawImage(filename, bounds);
 * gw.drawImage(filename, x, y, width, height);
 * ---------------------------------------------------
 * Draws the image from the specified file with its upper left corner at
 * the specified point. The forms of the call that include the bounds
 * scale the image so that it fits inside the specified rectangle.
 */
 void drawImage(std::string filename, const GPoint & pt);
 void drawImage(std::string filename, double x, double y);
 void drawImage(std::string filename, const GRectangle & bounds);
 void drawImage(std::string filename, double x, double y,
 double width, double height);
/*
 * Method: drawLine
 * Usage: gw.drawLine(p0, p1);
 * gw.drawLine(x0, y0, x1, y1);
 * -----------------------------------
 * Draws a line connecting the specified points.
 */
 void drawLine(const GPoint & p0, const GPoint & p1);
 void drawLine(double x0, double y0, double x1, double y1);
/*
 * Method: drawPolarLine
 * Usage: GPoint p1 = gw.drawPolarLine(p0, r, theta);
 * GPoint p1 = gw.drawPolarLine(x0, y0, r, theta);
 * ------------------------------------------------------
 * Draws a line of length r in the direction theta from the initial point.
 * The angle theta is measured in degrees counterclockwise from the +x
 * axis. The method returns the end point of the line.
 */
GPoint drawPolarLine(const GPoint & p0, double r, double theta);
GPoint drawPolarLine(double x0, double y0, double r, double theta);
/*
 * Method: drawOval
 * Usage: gw.drawOval(bounds);
 * gw.drawOval(x, y, width, height);
 * ----------------------------------------
 * Draws the frame of a oval with the specified bounds.
 */
 void drawOval(const GRectangle & bounds);
 void drawOval(double x, double y, double width, double height);
 /*
 * Method: fillOval
 * Usage: gw.fillOval(bounds);
 * gw.fillOval(x, y, width, height);
 * ----------------------------------------
 * Fills the frame of a oval with the specified bounds.
 */
 void fillOval(const GRectangle & bounds);
 void fillOval(double x, double y, double width, double height);
/*
 * Method: drawRect
 * Usage: gw.drawRect(bounds);
 * gw.drawRect(x, y, width, height);
 * ----------------------------------------
 * Draws the frame of a rectangle with the specified bounds.
 */
 void drawRect(const GRectangle & bounds);
 void drawRect(double x, double y, double width, double height);
/*
 * Method: fillRect
 * Usage: gw.fillRect(bounds);
 * gw.fillRect(x, y, width, height);
 * ----------------------------------------
 * Fills the frame of a rectangle with the specified bounds.
 */
 void fillRect(const GRectangle & bounds);
 void fillRect(double x, double y, double width, double height);
/*
 * Method: drawPolygon
 * Usage: gw.drawPolygon(polygon);
 * gw.drawPolygon(polygon, pt);
 * gw.drawPolygon(polygon, x, y);
 * -------------------------------------
 * Draws the outline of the specified polygon. The optional pt or x and y
 * parameters shift the origin of the polygon to the specified point.
 */
 void drawPolygon(const Vector<GPoint> & polygon);
 void drawPolygon(const Vector<GPoint> & polygon, const GPoint & pt);
 void drawPolygon(const Vector<GPoint> & polygon, double x, double y);
 /*
 * Method: fillPolygon
 * Usage: gw.fillPolygon(polygon);
 * gw.fillPolygon(polygon, pt);
 * gw.fillPolygon(polygon, x, y);
 * -------------------------------------
 * Fills the frame of the specified polygon. The optional pt or x and y
 * parameters shift the origin of the polygon to the specified point.
 */
 void fillPolygon(const Vector<GPoint> & polygon);
 void fillPolygon(const Vector<GPoint> & polygon, const GPoint & pt);
 void fillPolygon(const Vector<GPoint> & polygon, double x, double y);
/*
 * Method: drawString
 * Usage: gw.drawString(str, pt);
 * gw.drawString(str, x, y);
 * --------------------------------
 * Draws the string str so that its origin appears at the specified point.
 * The text appears in the current font and color.
 */
 void drawString(std::string str, const GPoint & pt);
 void drawString(std::string str, double x, double y);
/*
 * Method: getStringWidth
 * Usage: double width = gw.getStringWidth(str);
 * ---------------------------------------------
 * Returns the width of the string str when displayed in the current font.
 */
 double getStringWidth(std::string str);
/*
 * Method: setFont
 * Usage: gw.setFont(font);
 * ------------------------
 * Sets a new font. The font parameter is a string in the form
 * family-style-size. In this string, family is the name of the font
 * family; style is either missing (indicating a plain font) or one of the
 * strings Bold, Italic, or BoldItalic; and size is an integer indicating
 * the point size. If any of these components is specified as an asterisk,
 * the existing value is retained.
 */
 void setFont(std::string font);
 /*
 * Method: getFont
 * Usage: string font = gw.getFont();
 * ----------------------------------
 * Returns the current font.
 */
 std::string getFont() const;
/*
 * Method: getFontHeight
 * Usage: double height = getFontHeight();
 * ---------------------------------------
 * Returns the height of the current font, which is the separation in
 * pixels between successive text lines.
 */
 double getFontHeight() const;
/*
 * Method: getFontAscent
 * Usage: double height = getFontAscent();
 * ---------------------------------------
 * Returns the ascent of the current font, which is defined to be the
 * maximum distance in pixels that characters rise above the baseline.
 */
 double getFontAscent() const;
/*
 * Method: getFontDescent
 * Usage: double height = getFontDescent();
 * ----------------------------------------
 * Returns the descent of the current font, which is defined to be the
 * maximum distance in pixels that characters extend below the baseline.
 */
 double getFontDescent() const;
 /*
 * Method: setColor
 * Usage: gw.setColor(color);
 * --------------------------
 * Sets the color used for drawing. The color parameter is usually one of
 * the predefined color names from Java: BLACK, BLUE, CYAN, DARK_GRAY,
 * GRAY, GREEN, LIGHT_GRAY, MAGENTA, ORANGE, PINK, RED, WHITE, or YELLOW.
 * The case of the individual letters in the color name is ignored, as are
 * spaces and underscores, so that the Java color DARK_GRAY could be
 * written as "Dark Gray".
 *
 * The color can also be specified as a string in the form "#rrggbb" where
 * rr, gg, and bb are pairs of hexadecimal digits indicating the red,
 * green, and blue components of the color.
 */
 void setColor(std::string color);
/*
 * Method: getColor
 * Usage: string color = gw.getColor();
 * ------------------------------------
 * Returns the current color as a string in the form "#rrggbb". In this
 * string, the values rr, gg, and bb are two-digit hexadecimal values
 * representing the red, green, and blue components of the color,
 * respectively.
 */
 std::string getColor() const;
/*
 * Method: saveGraphicsState
 * Usage: gw.saveGraphicsState();
 * ------------------------------
 * Saves the state of the graphics context. This function is used in
 * conjunction with restoreGraphicsState() to avoid changing the state set
 * up by the client.
 */
 void saveGraphicsState();
/*
 * Method: restoreGraphicsState
 * Usage: gw.restoreGraphicsState();
 * ---------------------------------
 * Restores the graphics state from the most recent call to
 * saveGraphicsState().
 */
 void restoreGraphicsState();
 /*
 * Method: getWindowWidth
 * Usage: double width = gw.getWindowWidth();
 * ------------------------------------------
 * Returns the width of the graphics window in pixels.
 */
 double getWindowWidth() const;
/*
 * Method: getWindowHeight
 * Usage: double height = gw.getWindowHeight();
 * --------------------------------------------
 * Returns the height of the graphics window in pixels.
 */
 double getWindowHeight() const;
/*
 * Method: repaint
 * Usage: gw.repaint();
 * --------------------
 * Schedule a repaint on this window.
 */
 void repaint();
/*
 * Method: setWindowTitle
 * Usage: gw.setWindowTitle(title);
 * --------------------------------
 * Sets the title of the graphics window.
 */
 void setWindowTitle(std::string title);
/*
 * Method: getWindowTitle
 * Usage: string title = gw.getWindowTitle();
 * ------------------------------------------
 * Returns the title of the graphics window.
 */
 std::string getWindowTitle() const;
#include "private/gwindowpriv.h"
};
/*
 * Function: getFullScreenWidth
 * Usage: width = getFullScreenWidth();
 * ------------------------------------
 * Returns the width of the entire display screen.
 */
double getFullScreenWidth();
/*
 * Function: getFullScreenHeight
 * Usage: height = getFullScreenHeight();
 * --------------------------------------
 * Returns the height of the entire display screen.
 */
double getFullScreenHeight();
/*
 * Function: getGraphicsWindow
 * Usage: getGraphicsWindow();
 * ---------------------------
 * Returns a reference to the graphics window created by initGraphics.
 * Because GWindow objects cannot be copied, the result of
 * getGraphicsWindow must be used directly and cannot be assigned to a
 * variable.
 */
GWindow & getGraphicsWindow();
/*
 * Function: convertColorToRGB
 * Usage: int rgb = convertColorToRGB(colorName);
 * ----------------------------------------------
 * Converts a color name into an integer that encodes the red, green, and
 * blue components of the color.
 */
int convertColorToRGB(std::string colorName);
/*
 * Function: convertRGBToColor
 * Usage: int colorName = convertRGBToColor(rgb);
 * ----------------------------------------------
 * Converts an rgb value into a color name in the form "#rrggbb". Each of
 * the rr, gg, and bb values are two-digit hexadecimal numbers indicating
 * the intensity of that component.
 */
std::string convertRGBToColor(int rgb);
#endif
