#include <iostream>
#include <ctime>
using namespace std;

void init(int*, const int&);
void display(int*, const int&);
void bubbleSort(int*, int);
void barrier_search(int*, const int&, const int&, int&);
void fire_search(int*, const int&, const int&, int&);

int main() {

	int counter;
	int size;
	int key;

	do {
		cout << "Enter size of mas: ";
		cin >> size;
	} while (size < 1);

	int *mas = new int[size];

	init(mas, size);
	display(mas, size);

	cout << "Enter key: ";
	cin >> key;

	cout.fill('-');
	cout.width(size * 8);
	cout << "" << endl;

	counter = 0;
	double time = clock();
	barrier_search(mas, size, key, counter);
	cout << "Time = " << (clock() - time) / 1000 << " ms" << endl << "Stepses: " << counter << endl;

	bubbleSort(mas, size);
	display(mas, size);

	cout.fill('-');
	cout.width(size * 8);
	cout << "" << endl;

	counter = 0;
	time = clock();
	fire_search(mas, size, key, counter);
	cout << "Time = " << (clock() - time) / 1000 << " ms" << endl << "Stepses: " << counter << endl;

	delete[] mas;
	system("pause");
	return 0;
}


void init(int *mas, const int &size) {
	srand(time(NULL));

	for (int i = 0; i < size; i++) {
		mas[i] = rand() % 21 - 10;
	}
}

void display(int *mas, const int &size) {

	for (int i = 0; i < size; i++) {
		cout << mas[i] << "\t";
	}
	cout << endl;
}

void bubbleSort(int *mas, int size) {
	bool exit = false;

	while (!exit) {

		exit = true;

		for (int i = 0; i < size - 1; i++) {
			if (mas[i] > mas[i + 1]) {

				int temp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = temp;
				exit = false;
			}
		}
		size--;
	}
}

void barrier_search(int *mas, const int &size, const int &key, int &counter) {

	int i;
	int last = mas[size - 1];
	mas[size - 1] = key;
	counter++;

	for (i = 0; mas[i] != key; i++) {
		counter++;
	}

	mas[size - 1] = last;
	if (i != size - 1 || key == last) {
		cout << "Posistion is " << i + 1 << endl;
		return;
	}

	cout << "Elem is not found" << endl;
}

void fire_search(int *mas, const int &size, const int &key, int &counter) {

	int m;

	counter++;
	m = ((key - mas[0])*(size - 1)) / (mas[size - 1] - mas[0]); // m = ((key - a[l]) * R) / (a[r] - a[l])

	if (mas[m] == key) {
		cout << "Position is " << m + 1 << endl;
		return;
	}

	if (mas[m] > key) {
		for (int i = m - 1; i != 0; i--) {
			counter++;
			if (mas[i] == key) {
				cout << "Position is " << i + 1 << endl;
				return;
			}
		}
	}
	else {
		for (int i = m + 1; i < size; i++) {
			counter++;
			if (mas[i] == key) {
				cout << "Position is " << i + 1 << endl;
				return;
			}
		}
	}

	cout << "Elem is not found" << endl;
}