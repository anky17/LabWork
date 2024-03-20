### Algorithm: ClippingPolygon(Polygon, ClippingWindow)

**Inputs:**
- Polygon: a set of vertices representing the polygon
- ClippingWindow: a rectangular region defining the clipping window

**Steps:**
1. **Initialize a temporary array TempArray to store the clipped vertices.**
2. **For each edge in the polygon:**
   - a. **Check if the edge is entirely outside the clipping window:**
     - If yes, discard the edge.
   - b. **Check if the edge is entirely inside the clipping window:**
     - If yes, retain the edge.
   - c  **If the edge intersects with the clipping window:**
     - Clip the edge against each boundary of the clipping window.
     - Retain the clipped portion of the edge.
3. **Display the clipped polygon using the retained edges.**

### Output
![Output Photo](https://github.com/anky17/LabWork/blob/main/Sutherland%20Hodgeman%20Polygon%20Clipping/output.png)

