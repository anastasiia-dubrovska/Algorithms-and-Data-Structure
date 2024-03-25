#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Card {
private:
	string name;
	int age;
	int n;
	string* ill;
public:
	Card() :name(""), age(0), n(0), ill(NULL) {}
	Card(const Card& p) {
		if (this != &p) {
			name = p.name;
			age = p.age;
			n = p.n;
			ill = new string[n];
			for (int i = 0; i < n; i++) {
				ill[i] = p.ill[i];
			}
		}
	}
	~Card() {
		delete[]ill;
	}
	Card& operator=(const Card& p) {
		delete[]ill;
		if (this != &p) {
			name = p.name;
			age = p.age;
			n = p.n;
			ill = new string[n];
			for (int i = 0; i < n; i++) {
				ill[i] = p.ill[i];
			}
		}
		return *this;
	}
	friend istream& operator >>(istream& in, Card& p) {
		in >> p.name >> p.age >> p.n;
		p.ill = new string[p.n];
		for (int i = 0; i < p.n; i++) {
			in >> p.ill[i];
		}
		return in;
	}
	friend ostream& operator <<(ostream& out, Card& p) {
		out << p.name << " " << p.age << " " << p.n;
		for (int i = 0; i < p.n; i++) {
			out << p.ill[i] << " ";
		}
		out << "\n";
		return out;
	}
	bool operator<(const Card& p) {
		return name < p.name;
	}
	int getAge() {
		return this->age;
	}
	string getName() {
		return this->name;
	}
	bool isIll(string illness) {
		for (int i = 0; i < n; i++) {
			if (ill[i] == illness) {
				return true;
			}
		}
		return false;
	}
};
void sort(Card* p, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (p[j + 1] < p[j]) {
				swap(p[j], p[j + 1]);
			}
		}
	}
}
string findOldest(Card* p, int n, string ill) {
	int max = 1;
	int age = 0;
	for (int i = 0; i < n; i++) {
		if (p[i].isIll(ill) && (p[i].getAge() > age)) {
			max = i;
		}
	}
	return p[max].getName();
}
int main() {
	int n;
	ifstream input("Card.txt");
	input >> n;
	Card* p = new Card[n];
	for (int i = 0; i < n; i++) {
		input >> p[i];
	}
	sort(p, n);
	for (int i = 0; i < n; i++) {
		cout << p[i];
	}
	string illness;
	cin >> illness;
	cout << findOldest(p, n, illness) << endl;
	delete[]p;
	input.close();
	system("pause");
}