#include <iostream>
using namespace std;

class Matrix {
private:
  int rows;
  int cols;
  int **arr;

public:
  void init() {
    this->arr = new int *[rows];
    for (int i = 0; i < this->rows; i++) {
      arr[i] = new int[this->cols];
    }
  }

  Matrix() {
    this->rows = 1;
    this->cols = 1;
    this->init();
  }

  Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    init();
  }
  Matrix(Matrix *m) {
    this->rows = m->get_rows();
    this->cols = m->get_cols();
    this->arr = m->get_arr();
  }

  int **get_arr() { return this->arr; }
  int get_rows() { return this->rows; }
  int get_cols() { return this->cols; }

  void set_cols(int value) { this->cols = value; }
  void set_rows(int value) { this->rows = value; }

  void display_array() {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        cout << this->arr[i][j] << " ";
      }
      cout << "\n";
    }
  }

  void input_arr() {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        cin >> this->arr[i][j];
      }
    }
  }

  // Overloading +
  Matrix *operator+(Matrix &m) {
    Matrix *res = new Matrix(m.get_rows(), m.get_cols());
    for (int i = 0; i < m.get_rows(); i++) {
      for (int j = 0; j < m.get_cols(); j++) {
        res->arr[i][j] = this->arr[i][j] + m.arr[i][j];
      }
    }
    return res;
  }

  // Overloading -
  Matrix *operator-(Matrix &m) {
    Matrix *res = new Matrix(m.get_rows(), m.get_cols());
    for (int i = 0; i < m.get_rows(); i++) {
      for (int j = 0; j < m.get_cols(); j++) {
        res->arr[i][j] = this->arr[i][j] - m.arr[i][j];
      }
    }
    return res;
  }

  // Overloading &
  Matrix *operator&(int m) {
    Matrix *res = new Matrix(this->get_rows(), this->get_cols());
    for (int i = 0; i < this->get_rows(); i++) {
      for (int j = 0; j < this->get_cols(); j++) {
        res->arr[i][j] = this->arr[i][j] - m;
      }
    }
    return res;
  }
};

int main() {
  Matrix m;
  int rows;
  int cols;
  cout << "Nhap dong: ";
  cin >> rows;
  cout << "Nhap cot: ";
  cin >> cols;
  m.set_rows(rows);
  m.set_cols(cols);
  m.init();
  cout << "Nhap phan tu\n";
  m.input_arr();
  Matrix n(m);

  Matrix *y = m & 1;
  y->display_array();

  return 0;
}
