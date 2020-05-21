#include<bits/stdc++.h>

using namespace std;

void showMatrix(vector<vector<int>> A){
  int n = A.size();
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
}

int baseD(vector<vector<int>> A){
  if(A.size() == 2){
    return (A[0][0]*A[1][1] - A[0][1]*A[1][0]);
  }else{
    return 0;
  }
}

vector<vector<int>> coFactor(vector<vector<int>> A, int i, int j){
  int n = A.size();
  vector<vector<int>> newA(n-1, vector<int>(n-1));
  int n_c = 0;
  int n_r = 0;
  for(int r = 0; r < n; r++){
    if(r == i) continue;
    for(int c = 0; c < n; c++){
      if(c == j) continue;
      newA[n_r][n_c] = A[r][c];
      n_c++;
    }
    n_c = 0;
    n_r++;
  }
  return newA;
}

int calculateD(vector<vector<int>> A){
  if(A.size() == 2){
    return baseD(A);
  }
  int d = 0;
  for(int i = 0; i < A.size(); i++){
    vector<vector<int>> cofactor = coFactor(A, 0, i);
    d += (i%2 == 0 ? 1 : -1)*A[0][i]*calculateD(cofactor);
  }
  return d;
}

int main(int argc, char const *argv[]) {
  int n;
  scanf("%d", &n);
  vector<vector<int>> A(n, vector<int>(n));
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      scanf("%d", &A[i][j]);
    }
  }
  int d = calculateD(A);
  cout << d << endl;
  return 0;
}
