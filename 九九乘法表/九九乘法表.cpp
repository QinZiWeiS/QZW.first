#include<iostream>
using namespace std;

int main() {
	//大循环，行不断加一，i
	for (int i = 1; i < 10; i++) {
		for (int n = 1; n<=i; n++) {
			cout << n << "*" << i << "=" << n * i << "  ";
		}
		cout << endl;

	}
	//每一列都从第几列列数开始增加，n，
	//


	
	
	system("pause");
	return 0;
}