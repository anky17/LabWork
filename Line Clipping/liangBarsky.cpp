// WAP TO IMPLEMENT THE LINE CLIPPING ALGORITHM USING LIANG-BARSKY ALGORITHM.

#include <graphics.h>
#include <stdio.h>

#define X_MIN 100
#define X_MAX 300
#define Y_MIN 100
#define Y_MAX 200

// Liang-Barsky line clipping function
void liangBarsky(float x0, float y0, float x1, float y1, int offsetX,
                 int offsetY) {
  float p[4], q[4], t1 = 0.0, t2 = 1.0;
  float dx = x1 - x0, dy = y1 - y0;
  p[0] = -dx;
  q[0] = x0 - X_MIN;
  p[1] = dx;
  q[1] = X_MAX - x0;
  p[2] = -dy;
  q[2] = y0 - Y_MIN;
  p[3] = dy;
  q[3] = Y_MAX - y0;

  for (int i = 0; i < 4; i++) {
    if (p[i] == 0) {
      if (q[i] < 0) return;  // Line is parallel and outside the clipping area
    } else {
      float u = q[i] / p[i];
      if (p[i] < 0)
        t1 = (u > t1) ? u : t1;
      else
        t2 = (u < t2) ? u : t2;
    }
  }

  if (t1 > t2) return;  // Reject the line as it lies outside the viewport

  // Calculate clipped line coordinates and draw
  float nx0 = x0 + t1 * dx;
  float ny0 = y0 + t1 * dy;
  float nx1 = x0 + t2 * dx;
  float ny1 = y0 + t2 * dy;
  // Apply offset when drawing the clipped lines
  line(nx0 + offsetX, ny0, nx1 + offsetX, ny1);
}

// Main function
int main() {
  int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, (char *)"C:/TurboC3/BGI");

  rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX);
  line(150, 150, 250, 180);  // Completely inside
  line(300, 250, 450, 300);  // Completely outside
  line(50, 150, 350, 200);   // Partially inside

  // Set up for clipped lines and draw them on the right side
  int offsetX = getmaxx() / 2;
  int offsetY = 0;  // No vertical offset
  rectangle(X_MIN + offsetX, Y_MIN, X_MAX + offsetX, Y_MAX);

  // Applying Liang-Barsky algorithm and drawing the clipped lines
  liangBarsky(150, 150, 250, 180, offsetX, offsetY);  // Completely inside
  liangBarsky(350, 250, 450, 300, offsetX,
              offsetY);  // Completely outside (won't be drawn)
  liangBarsky(50, 150, 350, 200, offsetX, offsetY);  // Partially inside

  getch();
  closegraph();
  return 0;
}