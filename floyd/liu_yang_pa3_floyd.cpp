#include <stdlib.h>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// global variable matrix D and matrix P
vector<vector<int> > D_matrix;
vector<vector<int> > P_matrix;
int n; // size of the matrix

//declaration of functions
int getInput();// get size of matrix from user
void setGraph();// prepare the graph by generating random numbers
void shortestPath(); // implement floyd algorithm
void printMatrix(); // print matrix
<<<<<<< HEAD
void correctness(); // check if the matrix is correct
int printPath(int i, int j); // print path from vi to vj
=======
>>>>>>> f1698e2f530f0e29f52fc5a14c98f39b398d5e70

// main function
int main(int argc, char const *argv[]) {
  shortestPath();
  return 0;
}

// implementation of functions
// get the size of matrix from user
int getInput() {
  cout << "Please input a value for n: ";
  int n = 0;
  cin >> n;
  while (cin.fail()) {
    cin.clear();
    cin.ignore();
    cout << "Please input a value for n: ";
    cin >> n;
  }

  while (n < 5 || n >10) {
    cout << "Please input a value between 5 and 10(inclusive): ";
    cin >> n;
    while (cin.fail()) {
      cin.clear();
      cin.ignore();
      cout << "Please input a value between 5 and 10(inclusive): ";
      cin >> n;
    }
  }
  return n;
}

// prepare the graph by generating random numbers
void setGraph() {
  n = getInput();
  D_matrix = vector<vector<int> >(n, vector<int>(n));
  P_matrix = vector<vector<int> >(n, vector<int>(n));
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++){
      if(i == j) {
        D_matrix.at(i).at(j) = 0;
      } else {
        if (D_matrix.at(j).at(i) != 0) {
          D_matrix.at(i).at(j) = D_matrix.at(j).at(i);
        } else {
            D_matrix.at(i).at(j) = rand()%10 +1;
        }
      }
    }
  }
}

// implement floyd algorithm
void shortestPath(){

  string input = "";
  bool sign = true;
  // run the program in a infinite loop and stopped by user
  while (sign) {
    setGraph();
    // print the initial matrix
    printMatrix();
    for (int k = 0; k < n; k++){
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j ++) {
          if (i != k && j != k) {
            int dis = D_matrix.at(i).at(k) + D_matrix.at(k).at(j) ;
            if (dis < D_matrix.at(i).at(j)) {
              D_matrix.at(i).at(j) = dis;
              D_matrix.at(j).at(i) = dis;
              P_matrix.at(i).at(j) = k+1;
              P_matrix.at(j).at(i) = k+1;
            }
          }
        }
      }
      cout << "k = " << k+1 << endl;
      printMatrix();
<<<<<<< HEAD
      correctness();
=======
>>>>>>> f1698e2f530f0e29f52fc5a14c98f39b398d5e70
    }

    cout << "Press any other button to continue." << endl;
    cout << "Press e to Exit." << endl;
    cin >> input;
    if (input[0] == 'e' || input[0] == 'E') {
      sign = false;
    }

    while (cin.fail()) {
      cin.clear();
      cin.ignore();
      cin >> input;
      if (input[0] == 'e' || input[0] == 'E') {
         sign = false;
      }
    }
  }
  cout << "Successfully Exited" << endl;

}

// implement printMatrix
void printMatrix() {
  cout << "D_matrix is :\n";
  for (int i = 0; i < D_matrix.size(); i++) {
    for (int j = 0; j < D_matrix.at(i).size(); j++){
      cout << setw(3) <<  D_matrix.at(i).at(j) << " ";
    }
    cout << endl << endl;
  }
  cout << "P_matrix is :\n";
  for (int i = 0; i < P_matrix.size(); i++) {
    for (int j = 0; j < P_matrix.at(i).size(); j++){
      cout << setw(3) << P_matrix.at(i).at(j) << " ";
    }
    cout << endl << endl;
  }
}
<<<<<<< HEAD

// implement correctness
void correctness() {
  for (int i = 0; i < P_matrix.size(); i++) {
    for (int j = 0; j < i; j++) {
      cout << "Path("<<i+1<< "," <<j+1 << "): ";
      cout << "["<< i+1 <<"]->";
      int length = printPath(i, j);
      cout << "["<< j+1 <<"]" << endl;
      if (length != D_matrix.at(i).at(j)) {
        cout << "This algorithm is not correct." << endl;
        return;
      }
    }
  }
  cout << "This algorithm is correct so far." << endl;
}

// print path between two vertices
int printPath(int i, int j) {
  int v = P_matrix.at(i).at(j);
  int l = 0;
  if (v != 0) {
    l += printPath(i, v-1);
    cout << "[" << v <<"]->";
    l += printPath(v-1, j);
  } else {
    l = D_matrix.at(i).at(j);
  }
  return l;
}
=======
>>>>>>> f1698e2f530f0e29f52fc5a14c98f39b398d5e70
