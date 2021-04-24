#include <iostream>
using namespace std;

int main() {
	string r;
	cin >> r;
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < r.size(); j++) {
			if (r.at(j) == 122) r.at(j) = 96;
			r.at(j) += 1;
		}
		cout << r << endl;
	}
}