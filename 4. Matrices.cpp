#include <iostream>
using namespace std;

class matrix{
	int rows = 0;
	int cols = 0;
	int a[20][20] = {0};
public :
	matrix(){};
	matrix(int r, int c): rows(r),cols(c){};

	void accept(){
		cout << "Enter the number of rows: ";
		cin >> rows;
		cout << "Enter the number of columns: ";
		cin >> cols;
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				cout << "Enter element at [" << i <<","<<j <<"]: ";
				cin >> a[i][j];
			}
		}
		cout << "Your matrix is :" << endl;
		this->display();
	}

	void display(){
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				cout << a[i][j]<<" ";
			}
			cout << endl;
		}
	}

	void isSquare(){
		if (rows == cols)
			cout << "\nThe matrix is a square matrix."<<endl;
		else
			cout <<"\nThe matrix isn't square matrix." << endl;
	}

	void isUpperTriangular(){
		if (rows != cols)
		{
			cout << "\nMatrix is not upper triangular."<< endl;
			return;
		}
		for (int i = 0; i < rows; i++){
			for(int j = 0; j < i; j++){
				if (a[i][j] != 0)
				{
					cout << "\nMatrix is not upper triangular."<< endl;
					return;
				}
			}
		}
		cout << "\nMatirx is upper triangular."<< endl;
		return;
	}

	void add(matrix b){
		if (this->rows != b.rows || this->cols != b.cols)
		{
			cout << "Addition not possible." << endl;
			return;
		}
		matrix added(rows,cols);
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				added.a[i][j] = this->a[i][j] + b.a[i][j];
			}
		}
		cout << "The addition is :" << endl;
		added.display();
	}

	void product(matrix b){
		if (this->cols != b.rows)
		{
			cout << "Multiplication not possible." << endl;
			return;
		}
		matrix prod(this->rows,b.cols);
		for(int i = 0; i < prod.rows; i++){
			for (int j = 0; j < prod.cols; j++){
				prod.a[i][j] = 0;
				for (int k = 0; k < b.rows; k++){
					prod.a[i][j] += this->a[i][k] * b.a[k][j];
				}
			}
		}
		cout << "The product is :" << endl;
		prod.display();
	}

	void transpose(){
		int temp = 0;
		int maxdim = (rows > cols)? rows : cols;
		for(int i = 0; i < maxdim; i++){
			for(int j = 0; j < i; j ++){
				temp = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = temp;
			}
		}
		temp = rows;
		rows = cols;
		cols = temp;
		cout << "Transpose of matrix A :" << endl;
		this->display();
	}

};

int main(){
	matrix a,b;
	int choice = -1;
	do{
	    cout << "\n\t***MENU***" << endl;
    	cout << "1: Accept matrix A" << endl;
    	cout << "2: Display matrix A" << endl;
    	cout << "3: Check if A is square" << endl;
    	cout << "4: Check if A is upper triangular" << endl;
    	cout << "5: Add matrix A and B" << endl;
    	cout << "6: Multiply matrix A and B" << endl;
    	cout << "7: Transpose of matrixA" << endl;
    	cout << "0: Exit" << endl;
		cout << "ENTER CHOICE: ";
		cin >> choice;
		
		switch (choice){
		    case 1 : 
		        cout << "\nEnter matrixA" << endl;
				a.accept();
				break;
		    case 2:
		        cout << "\nMatrix A :" << endl;
				a.display();
				break;
		    case 3 : 
		        a.isSquare();
		        break;
		    case 4 : 
    		    a.isUpperTriangular();
    		    break;
		    case 5 : 
		        cout << "\nEnter matrix B :" << endl;
		    	b.accept();
		        a.add(b);
		        break;
		    case 6 :
		        cout << "\nEnter matrix B :" << endl;
		    	b.accept();
    		    a.product(b);
    		    break;
		    case 7 : 
		        a.transpose();
		        break;
		    case 0 : 
		        cout << "***END***"<< endl;
		        break;
		    default : 
		        cout << "Invalid choice." << endl; 
		        break;
		}

	} while(choice != 0);

	return 0;

}
