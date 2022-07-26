import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import java.util.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class AStarJava extends PApplet {

// An educated guess of how far it is between two points
public float heuristic(Spot a, Spot b) {
  float d = dist(a.i, a.j, b.i, b.j);
  // float d = abs(a.i - b.i) + abs(a.j - b.j);
  return d;
}

// How many columns and rows?
int cols = 50;
int rows = 50;

// This will be the 2D array
Spot[][] grid = new Spot[cols][rows];

// Open and closed set
List<Spot> openSet = new ArrayList<Spot>();
List<Spot> closedSet = new ArrayList<Spot>();

// Start and end
Spot start;
Spot end;
Spot current;

// Width and height of each cell of grid
float w, h;

// The road taken
List<Spot> path = new ArrayList<Spot>();

public void setup() {
  
  println("A*");

  // Grid cell size
  w = PApplet.parseFloat(width) / cols;
  h = PApplet.parseFloat(height) / rows;

  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      grid[i][j] = new Spot(i, j);
    }
  }

  // All the neighbors
  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      grid[i][j].addNeighbors(grid);
    }
  }

  // Start and end
  start = grid[0][0];
  end = grid[cols - 1][rows - 1];
  start.wall = false;
  end.wall = false;

  // openSet starts with beginning only
  openSet.add(start);
}

public void draw() {
  // Am I still searching?
  if (openSet.size() > 0) {

    // Best next option
    int winner = 0;
    for (int i = 0; i < openSet.size(); i++) {
      if (openSet.get(i).f < openSet.get(winner).f) {
        winner = i;
      }
    }
    current = openSet.get(winner);

    // Did I finish?
    if (current == end) {
      noLoop();
      println("DONE!");
    }

    // Best option moves from openSet to closedSet
    //openSet = removeFromArray(openSet, current);
    openSet.remove(current);
    closedSet.add(current);

    // Check all the neighbors
    List<Spot> neighbors = current.neighbors;
    for (int i = 0; i < neighbors.size(); i++) {
      Spot neighbor = neighbors.get(i);

      // Valid next spot?
      if (!closedSet.contains(neighbor) && !neighbor.wall) {
        float tempG = current.g + heuristic(neighbor, current);

        // Is this a better path than before?
        boolean newPath = false;
        if (openSet.contains(neighbor)) {
          if (tempG < neighbor.g) {
            neighbor.g = tempG;
            newPath = true;
          }
        } else {
          neighbor.g = tempG;
          newPath = true;
          openSet.add(neighbor);
        }

        // Yes, it's a better path
        if (newPath) {
          neighbor.heuristic = heuristic(neighbor, end);
          neighbor.f = neighbor.g + neighbor.heuristic;
          neighbor.previous = current;
        }
      }
    }
  } else {
    // Uh oh, no solution
    println("no solution");
    noLoop();
    return;
  }

  // Draw current state of everything
  background(255);

  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      grid[i][j].show();
    }
  }

  for (int i = 0; i < closedSet.size(); i++) {
    closedSet.get(i).show(color(255, 0, 0, 50));
  }

  for (int i = 0; i < openSet.size(); i++) {
    openSet.get(i).show(color(0, 255, 0, 50));
  }

  // Find the path by working backwards
  List<Spot> path = new ArrayList<Spot>();
  Spot temp = current;
  path.add(temp);
  while (temp.previous != null) {
    path.add(temp.previous);
    temp = temp.previous;
  }

  // for (var i = 0; i < path.length; i++) {
    // path[i].show(color(0, 0, 255));
  //}

  // Drawing path as continuous line
  noFill();
  stroke(255, 0, 200);
  strokeWeight(w / 2);
  beginShape();
  for (int i = 0; i < path.size(); i++) {
    vertex(path.get(i).i * w + w / 2, path.get(i).j * h + h / 2);
  }
  endShape();
}


// An object to describe a spot in the grid
class Spot {
  int i;
  int j;
  // f, g, and h values for A*
  float f = 0;
  float g = 0;
  float heuristic = 0;
  
  // Neighbors
  List<Spot> neighbors = new ArrayList<Spot>();

  // Where did I come from?
  Spot previous = null;

  boolean wall = false;
  
  Spot(int i_, int j_) {

    // Location
    i = i_;
    j = j_;

    // Am I a wall?
    wall = false;
    if (random(1) < 0.4f) {
      wall = true;
    }
  }
  
  // Display me
  // void show() {
  //   if (wall) {
  //     fill(0);
  //     noStroke();
  //     ellipse(i * w + w / 2.0, j * h + h / 2.0, w / 2.0, h / 2.0);
  //   }
  // }
  
  public void show(int col) {
    if (wall) {
      fill(0);
      noStroke();
      ellipse(i * w + w / 2.0f, j * h + h / 2.0f, w / 2.0f, h / 2.0f);
    } else {
      fill(col);
      rect(i * w, j * h, w, h);
    }
  }

  // Figure out who my neighbors are
  public void addNeighbors(Spot[][] grid) {
    if (i < cols - 1) {
      neighbors.add(grid[i + 1][j]);
    }
    if (i > 0) {
      neighbors.add(grid[i - 1][j]);
    }
    if (j < rows - 1) {
      neighbors.add(grid[i][j + 1]);
    }
    if (j > 0) {
      neighbors.add(grid[i][j - 1]);
    }
    if (i > 0 && j > 0) {
      neighbors.add(grid[i - 1][j - 1]);
    }
    if (i < cols - 1 && j > 0) {
      neighbors.add(grid[i + 1][j - 1]);
    }
    if (i > 0 && j < rows - 1) {
      neighbors.add(grid[i - 1][j + 1]);
    }
    if (i < cols - 1 && j < rows - 1) {
      neighbors.add(grid[i + 1][j + 1]);
    }
  }
};
  public void settings() {  size(800, 800); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "AStarJava" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
