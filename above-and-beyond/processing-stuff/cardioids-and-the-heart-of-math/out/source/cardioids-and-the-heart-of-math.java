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

public class cardioids-and-the-heart-of-math extends PApplet {
  public void setup() {


// An object to describe a spot in the grid
class Spot {
    int i;
    int j;
    //f, g, and h values for A*
    float f = 0;
    float g = 0;
    float heuristic = 0;
    
    //Neighbors
    List<Spot> neighbors = new ArrayList<Spot>();
    
    //Where did I come from?
    Spot previous = null;
    
    boolean wall = false;
    
    Spot(int i_, int j_) {
        
        // Location
        i = i_;
        j = j_;
        
        // Am I a wall?
        wall= false;
        if (random(1) < 0.4f) {
            wall =true;
        }
}
    
    //Display me
    public void show() {
        if (wall) {
            fill(0);
            noStroke();
            ellipse(i * w + w / 2.0f, j * h + h / 2.0f, w / 2.0f, h / 2.0f);
        }
}
    
    public void show(int col) {
        if (wall) {
            fill(0);
            noStroke();
            ellipse(i * w + w / 2.0f, j * h + h / 2.0f, w / 2.0f, h / 2.0f);
        } else {
            fill(col);
            rect(i* w, j * h, w, h);
        }
}
    
    //Figure out who my neighbors are
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
    noLoop();
  }

  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "cardioids-and-the-heart-of-math" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
