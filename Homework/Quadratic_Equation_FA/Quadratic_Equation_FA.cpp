//*A fun thing - 24/02/2025*//

#include <iostream>
#include <cmath>
using namespace std;

int main() {

	double A, B, C;

	cout << "What is your A, B, C: ";
	cin >> A >> B >> C;

	if (A == 0) {

		cout << "Can't do it, too bad." << endl;
		return 0;

	}

	double D = (B * B) - (4 * A * C);
	cout.precision(3);

	if (D > 0) {

		cout << "There are two roots: ";
		double root1 = (-B + sqrt(D)) / (2 * A);
		cout.precision(3);
		double root2 = (-B - sqrt(D)) / (2 * A);
		cout.precision(3);
		cout << "Your two roots are: " << root1 << ", " << root2 << "." << endl;
		return 0;

	} else if (D == 0) {

		cout << "There is one real root: ";
		double root = -B / (2 * A);
		cout.precision(3);
		cout << "Root is real and repeated: " << root << endl;
		return 0;

	} else {
		
		cout << "This is a complex root: ";
		double real = (- B / (2 * A));
		cout.precision(3);
		double imag = (sqrt(-D)) / (2 * A);
		cout.precision(3);
		cout << "Your roots are complex, so this is your real root: " << real << " plus minus " << imag << endl;
		return 0;

	}

	return 0;

}