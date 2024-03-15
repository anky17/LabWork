// WAP TO IMPLEMENT THE LINE CLIPPING ALGORITHM USING COHEN SUTHERLAND ALGORITHM.

#include <graphics.h>
#include <stdio.h>

// Define window boundaries
#define X_MIN 100
#define X_MAX 300
#define Y_MIN 100
#define Y_MAX 200

// Define screen division for before and after clipping
#define DIVIDE_X getmaxx() / 2

// Define region codes
#define INSIDE 0  // 0000
#define LEFT 1    // 0001
#define RIGHT 2   // 0010
#define BOTTOM 4  // 0100
#define TOP 8     // 1000

// Function to compute region code for a point(x, y)
int computeCode(double x, double y) {
  int code = INSIDE;

  if (x < X_MIN)  // to the left of rectangle
    code |= LEFT;
  else if (x > X_MAX)  // to the right of rectangle
    code |= RIGHT;
  if (y < Y_MIN)  // below the rectangle
    code |= BOTTOM;
  else if (y > Y_MAX)  // above the rectangle
    code |= TOP;

  return code;
}

// Implementing Cohen-Sutherland algorithm
void cohenSutherlandClip(double x0, double y0, double x1, double y1,
                         double offsetX, double offsetY) {
  int code0 = computeCode(x0, y0), code1 = computeCode(x1, y1);
  int accept = 0;

  while (1) {
    if (!(code0 | code1)) {  // Both endpoints lie within rectangle
      accept = 1;
      break;
    } else if (code0 & code1) {  // Both endpoints are outside rectangle
      break;
    } else {
      double x, y;
      int outcodeOut = code0 ? code0 : code1;

      // Find intersection point
      if (outcodeOut & TOP) {  // point is above the clip rectangle
        x = x0 + (x1 - x0) * (Y_MAX - y0) / (y1 - y0);
        y = Y_MAX;
      } else if (outcodeOut & BOTTOM) {  // point is below the clip rectangle
        x = x0 + (x1 - x0) * (Y_MIN - y0) / (y1 - y0);
        y = Y_MIN;
      } else if (outcodeOut &
                 RIGHT) {  // point is to the right of clip rectangle
        y = y0 + (y1 - y0) * (X_MAX - x0) / (x1 - x0);
        x = X_MAX;
      } else if (outcodeOut & LEFT) {  // point is to the left of clip rectangle
        y = y0 + (y1 - y0) * (X_MIN - x0) / (x1 - x0);
        x = X_MIN;
      }

      // Replace point outside rectangle by intersection point
      if (outcodeOut == code0) {
        x0 = x;
        y0 = y;
        code0 = computeCode(x0, y0);
      } else {
        x1 = x;
        y1 = y;
        code1 = computeCode(x1, y1);
      }
    }
  }
  if (accept) {
    // Draw the line after clipping
    line(x0 + offsetX, y0, x1 + offsetX, y1);
  }
}

int main() {
  int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, (char *)"C:/TurboC3/BGI");

  // Draw the original lines and clipping rectangle on the left half
  rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);
  line(120, 150, 200, 180);  // Line completely inside
  line(50, 250, 70, 300);    // Line completely outside
  line(50, 150, 350, 200);   // Line partially inside

  // Draw the clipping rectangle on the right half
  rectangle(X_MIN + DIVIDE_X, Y_MIN, X_MAX + DIVIDE_X, Y_MAX);
  // Clip lines and draw them on the right half
  cohenSutherlandClip(120, 150, 200, 180, DIVIDE_X, 0);
  cohenSutherlandClip(50, 250, 70, 300, DIVIDE_X, 0);
  cohenSutherlandClip(50, 150, 350, 200, DIVIDE_X, 0);

  getch();
  closegraph();
  return 0;
}
