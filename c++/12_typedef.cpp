#include <iostream>
#include <vector>

typedef void (*FuncPtr)(int);

void printNbr(int n) {
	std::cout << "Number: " << n << std::endl;
}

typedef int* intPtr;


struct Point {
	int x, y;
};

typedef struct Point Point2D;


typedef std::vector<std::vector<int> > intMatrix;
typedef std::vector<std::vector<std::string> > strMatrix;

int	main() {
	using namespace std;
	using std::cout;
	// using std::endl;

	FuncPtr f = printNbr;
	f(42);

	intPtr ptr;
	int x = 10;
	ptr = &x;
	f(*ptr);

	cout << endl;
	Point2D p = {20, 30};
	f(p.x);
	f(p.y);



	// std::vector <std::vector<int>  >  matrix(3, std::vector<int>(3, 0));

	intMatrix matrix(3, std::vector<int>(3, 0));
    // Assign values
    matrix[0][0] = 1; matrix[0][1] = 2; matrix[0][2] = 3;
    matrix[1][0] = 4; matrix[1][1] = 5; matrix[1][2] = 6;
    matrix[2][0] = 7; matrix[2][1] = 8; matrix[2][2] = 9;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

	return 0;
}