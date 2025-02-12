import processing.serial.*;

Serial arduino;

int w = 500;
int h = 500;

int rows;
int cols;
int[][] distanceMatrix;

void setup(){
  size(500, 500);
  String portName = Serial.list()[Serial.list().length-1];
  arduino = new Serial(this, portName, 9600);
  arduino.bufferUntil('\n');
  colorMode(HSB, 360, 100, 100);
  noStroke();
  background(0);
}

void draw(){
  displayMatrix(distanceMatrix);
}

void serialEvent(Serial ardu){
  String inputString = ardu.readStringUntil('\n');
  inputString = inputString.trim();
  println(inputString);
  
  String[] splitted = split(inputString, ' ');
  if(splitted[0].charAt(0) == '$'){
    splitted[0] = splitted[0].substring(1);
    if(splitted[0].equals("steps")){
      rows = int(splitted[1]) + 1;
      cols = int(splitted[2]) + 1;
      distanceMatrix = new int[rows][cols];
      println(rows + " " + cols);
    } else if(splitted[0].equals("distance") && distanceMatrix != null){
      distanceMatrix[int(splitted[1])][int(splitted[2])] = int(splitted[3]);
      printMatrix(distanceMatrix);
    }
  }
}

void printMatrix(int[][] m){
  for(int i = 0; i < m.length; i++){
    for(int j = 0; j < m[i].length; j++){
      print(m[i][j] + " ");
    }
    println();
  }
}

void displayMatrix(int[][] m){
  if(m != null){
    for(int i = 0; i < rows; i++){
      for(int j = 0; j < cols; j++){
        int cellX = w * j / cols;
        int cellWidth = w / cols + 1;
        int cellY = h * i / rows;
        int cellHeight = h / rows + 1;
        int hue = m[i][j] > 1200 ? 120 : ((120 * m[i][j]) / 1200);
        if(m[i][j] != 0){
          fill(color(hue, 100, 100));
          rect(cellX, cellY, cellWidth, cellHeight);
        }
      }
    }
  }
}
