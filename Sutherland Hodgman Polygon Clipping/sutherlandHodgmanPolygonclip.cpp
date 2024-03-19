//*******************************************************
//----------Sutherland Hodgeman Polygon Clipping--------
//*******************************************************
// © 2024 Ankit Diyal.

#include <graphics.h>
#include <stdio.h>

// Define the maximum number of vertices in the polygon
#define MAX_VERTICES 8

// Define the clipping window coordinates
#define XMIN 40
#define YMIN 40
#define XMAX 160
#define YMAX 160

// Define the structure for storing coordinates of a vertex
struct Vertex {
  int x;
  int y;
};

// Array to store the vertices of the polygon
struct Vertex vertices[MAX_VERTICES] = {
    {20, 20},    // Vertex 1
    {100, 20},   // Vertex 2
    {180, 60},   // Vertex 3
    {180, 140},  // Vertex 4
    {100, 180},  // Vertex 5
    {20, 140},   // Vertex 6
    {20, 60},    // Vertex 7
    {60, 100}    // Vertex 8
};

// Temporary array used to store the new coordinates of the vertices after
// clipping
struct Vertex new_vertices[MAX_VERTICES] = {{0}};

// Function prototypes
int leftClip(int, int);
int topClip(int, int);
int rightClip(int, int);
int bottomClip(int, int);

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, (char*)"C:/TurboC3/BGI");
  int result, i;

  // Perform left, top, right, and bottom clipping successively
  result = leftClip(MAX_VERTICES, XMIN);
  result = topClip(result, YMIN);
  result = rightClip(result, XMAX);
  result = bottomClip(result, YMAX);

  // Draw the clipping window
  rectangle(XMIN, YMIN, XMAX, YMAX);

  // Draw the clipped polygon
  for (i = 0; i < result; i++)
    line(vertices[i].x, vertices[i].y, vertices[(i + 1) % result].x,
         vertices[(i + 1) % result].y);

  getch();
  closegraph();
  return 0;
}

// Function to clip against the left edge of the clipping window
int leftClip(int limit, int xmin) {
  int i, j = 0;
  float slope;

  for (i = 0; i < limit; i++) {
    int x1 = vertices[i].x;
    int y1 = vertices[i].y;
    int x2 = vertices[(i + 1) % limit].x;
    int y2 = vertices[(i + 1) % limit].y;

    // Calculate the slope of the line segment
    if (x2 - x1)
      slope = (y2 - y1) * 1.0 / (x2 - x1);
    else
      slope = 0;

    // Check if both endpoints are outside the clipping window
    if (x1 < xmin && x2 < xmin) continue;
    // Check if both endpoints are inside the clipping window
    if (x1 >= xmin && x2 >= xmin) {
      new_vertices[j].x = x2;
      new_vertices[j++].y = y2;
      continue;
    }
    // Handle cases where one endpoint is inside and the other is outside the
    // clipping window
    if (x1 >= xmin && x2 < xmin) {
      new_vertices[j].x = xmin;
      new_vertices[j++].y = y1 + slope * (xmin - x1);
      continue;
    }
    if (x1 < xmin && x2 >= xmin) {
      new_vertices[j].x = xmin;
      new_vertices[j++].y = y1 + slope * (xmin - x1);
      new_vertices[j].x = x2;
      new_vertices[j++].y = y2;
    }
  }

  // Copy the clipped vertices back to the original array
  for (i = 0; i < j; i++) {
    vertices[i].x = new_vertices[i].x;
    vertices[i].y = new_vertices[i].y;
    new_vertices[i].x = new_vertices[i].y = 0;
  }

  // Set the remaining vertices to (0, 0)
  if (j < limit)
    for (; i < limit; i++) vertices[i].x = vertices[i].y = 0;

  return j;
}

// Function to clip against the top edge of the clipping window
int topClip(int limit, int ymin) {
  int i, j = 0;
  float slope;

  for (i = 0; i < limit; i++) {
    int x1 = vertices[i].x;
    int y1 = vertices[i].y;
    int x2 = vertices[(i + 1) % limit].x;
    int y2 = vertices[(i + 1) % limit].y;

    // Calculate the slope of the line segment
    if (x2 - x1)
      slope = (y2 - y1) * 1.0 / (x2 - x1);
    else
      slope = 0;

    // Check if both endpoints are outside the clipping window
    if (y1 < ymin && y2 < ymin) continue;
    // Check if both endpoints are inside the clipping window
    if (y1 >= ymin && y2 >= ymin) {
      new_vertices[j].x = x2;
      new_vertices[j++].y = y2;
      continue;
    }
    // Handle cases where one endpoint is inside and the other is outside the
    // clipping window
    if (y1 >= ymin && y2 < ymin) {
      new_vertices[j].x = x1 + (ymin - y1) / slope;
      new_vertices[j++].y = ymin;
      continue;
    }
    if (y1 < ymin && y2 >= ymin) {
      new_vertices[j].x = x1 + (ymin - y1) / slope;
      new_vertices[j++].y = ymin;
      new_vertices[j].x = x2;
      new_vertices[j++].y = y2;
    }
  }

  // Copy the clipped vertices back to the original array
  for (i = 0; i < j; i++) {
    vertices[i].x = new_vertices[i].x;
    vertices[i].y = new_vertices[i].y;
    new_vertices[i].x = new_vertices[i].y = 0;
  }

  // Set the remaining vertices to (0, 0)
  if (j < limit)
    for (; i < limit; i++) vertices[i].x = vertices[i].y = 0;

  return j;
}

// Function to clip against the right edge of the clipping window
int rightClip(int limit, int xmax) {
  int i, j = 0;
  float slope;

  for (i = 0; i < limit; i++) {
    int x1 = vertices[i].x;
    int y1 = vertices[i].y;
    int x2 = vertices[(i + 1) % limit].x;
    int y2 = vertices[(i + 1) % limit].y;

    // Calculate the slope of the line segment
    if (x2 - x1)
      slope = (y2 - y1) * 1.0 / (x2 - x1);
    else
      slope = 0;

    // Check if both endpoints are outside the clipping window
    if (x1 > xmax && x2 > xmax) continue;
    // Check if both endpoints are inside the clipping window
    if (x1 <= xmax && x2 <= xmax) {
      new_vertices[j].x = x2;
      new_vertices[j++].y = y2;
      continue;
    }
    // Handle cases where one endpoint is inside and the other is outside the
    // clipping window
    if (x1 <= xmax && x2 > xmax) {
      new_vertices[j].x = xmax;
      new_vertices[j++].y = y1 + slope * (xmax - x1);
      continue;
    }
    if (x1 > xmax && x2 <= xmax) {
      new_vertices[j].x = xmax;
      new_vertices[j++].y = y1 + slope * (xmax - x1);
      new_vertices[j].x = x2;
      new_vertices[j++].y = y2;
    }
  }

  // Copy the clipped vertices back to the original array
  for (i = 0; i < j; i++) {
    vertices[i].x = new_vertices[i].x;
    vertices[i].y = new_vertices[i].y;
    new_vertices[i].x = new_vertices[i].y = 0;
  }

  // Set the remaining vertices to (0, 0)
  if (j < limit)
    for (; i < limit; i++) vertices[i].x = vertices[i].y = 0;

  return j;
}

// Function to clip against the bottom edge of the clipping window
int bottomClip(int limit, int ymax) {
  int i, j = 0;
  float slope;

  for (i = 0; i < limit; i++) {
    int x1 = vertices[i].x;
    int y1 = vertices[i].y;
    int x2 = vertices[(i + 1) % limit].x;
    int y2 = vertices[(i + 1) % limit].y;

    // Calculate the slope of the line segment
    if (x2 - x1)
      slope = (y2 - y1) * 1.0 / (x2 - x1);
    else
      slope = 0;

    // Check if both endpoints are outside the clipping window
    if (y1 > ymax && y2 > ymax) continue;
    // Check if both endpoints are inside the clipping window
    if (y1 <= ymax && y2 <= ymax) {
      new_vertices[j].x = x2;
      new_vertices[j++].y = y2;
      continue;
    }
    // Handle cases where one endpoint is inside and the other is outside the
    // clipping window
    if (y1 <= ymax && y2 > ymax) {
      new_vertices[j].x = x1 + (ymax - y1) / slope;
      new_vertices[j++].y = ymax;
      continue;
    }
    if (y1 > ymax && y2 <= ymax) {
      new_vertices[j].x = x1 + (ymax - y1) / slope;
      new_vertices[j++].y = ymax;
      new_vertices[j].x = x2;
      new_vertices[j++].y = y2;
    }
  }

  // Copy the clipped vertices back to the original array
  for (i = 0; i < j; i++) {
    vertices[i].x = new_vertices[i].x;
    vertices[i].y = new_vertices[i].y;
    new_vertices[i].x = new_vertices[i].y = 0;
  }

  // Set the remaining vertices to (0, 0)
  if (j < limit)
    for (; i < limit; i++) vertices[i].x = vertices[i].y = 0;

  return j;
}
