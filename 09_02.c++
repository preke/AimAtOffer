# include <iostream>
# include <cstdlib>
# define MAXSIZE 2
using namespace std;

class Matrix {
	private:
		unsigned long long  row;
		unsigned long long  column;
		 unsigned long long array[MAXSIZE][MAXSIZE];
	public:	
		Matrix(unsigned long long  r, unsigned long long  c) {
			if (r > MAXSIZE || c > MAXSIZE) {
				cout << "Wrong" << endl;
				r = 0;
				c = 0;
			}
			row = r;
			column = c;
			for (unsigned long long  i = 0; i < row; i ++) {
				for (unsigned long long  j = 0; j < column; j ++) {
					cin >> array[i][j];
				}
			}

		}

		Matrix(unsigned long long  r, unsigned long long  c, unsigned long long  a) {
			if (r > MAXSIZE || c > MAXSIZE) {
				cout << "Wrong" << endl;
				r = 0;
				c = 0;
			}
			row = r;
			column = c;
			
			for (unsigned long long  i = 0; i < row; i ++) {
				for (unsigned long long  j = 0; j < column; j ++) {
					array[i][j] = a;
				}
			}

		}

		Matrix(const Matrix& m) {
			row = m.row;
			column = m.column;
			
			for (unsigned long long  i = 0; i < row; i ++) {
				for (unsigned long long  j = 0; j < column; j ++) {
					array[i][j] = m.array[i][j];
				}
			}

		}

		Matrix & operator = (const Matrix & m) {
			
			if (&m == this)		return *this;

			row = m.row;
			column = m.column;
			
			for (unsigned long long  i = 0; i < row; i ++) {
				for (unsigned long long  j = 0; j < column; j ++) {
					array[i][j] = m.array[i][j];
				}
			}

			return *this;
		}

		Matrix operator * (const Matrix & m) const {
			if (column != m.row ) {
				cout << "Wrong!" << endl;
				return Matrix(1, 1, -1);
			}
			Matrix ans(row, m.column, 0);
			for (unsigned long long  i = 0; i < ans.row; i ++) {
				for (unsigned long long  j = 0; j < ans.column; j ++) {
					unsigned long long  temp = 0;
					for (unsigned long long  k = 0; k < ans.row; k ++) {
						temp += this->array[i][k] * m.array[k][j];	
					}
					ans.array[i][j] = temp;

				}
			}
			return ans;
		}

		Matrix operator ^ (unsigned long long  n) const {
			if (n <= 0) {
				cout << "Wrong!" << endl;
				return Matrix(1, 1, -1);
			}
			Matrix ans = *this;
			for (unsigned long long  i = 1; i < n; i ++) {
				ans = ans * (*this);
			}
			return ans;
		}

		void print() {
			cout << "row: " << row << endl;
			cout << "column: " << column << endl;
			for (unsigned long long  i = 0; i < row; i ++) {
				for (unsigned long long  j = 0; j < column; j ++) {
					cout << array[i][j] << " "; 
				}
				cout << endl;
			}
		}

		 unsigned long long get(unsigned long long  i, unsigned long long  j){
			if (i < 0 || j < 0 || i >= row || j >= column) {
				cout << "Wrong input!" << endl;
				return -1;
			}
			return array[i][j];
		}

};

Matrix FastPower(const Matrix & m, unsigned long long  n) {
	if (n == 1) {
		return m;
	}
	if (n % 2 == 0) {
		return FastPower(m, n/2) * FastPower(m, n/2);
	} else {
		return FastPower(m, (n - 1)/2) * FastPower(m, (n - 1)/2) * m;
	}
}

Matrix m = Matrix(2, 2); //在此我们输入 1,1,1,0 初始化这个矩阵
 unsigned long long Fibonacci(unsigned long long  n) {
	if (n <= 0) return 0;
	if (n == 1) return 1;	
	Matrix m1 = m;
	m1 = FastPower(m1, n-1);
	return m1.get(0, 0); //为f(n)
}

//怎么突破unsigned long long 呢？

int main() {
	for(unsigned long long  i = 0; i < 100; i ++)
		cout << i << ": " << Fibonacci(i) << endl;

}