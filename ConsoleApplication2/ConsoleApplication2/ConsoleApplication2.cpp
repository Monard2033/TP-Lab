#include <iostream>

using namespace std;
void afisare(int n, char l)
{
	
	cout << "Ati introdus: " << n <<" "<< l;
	
}
int main(int n, char l)
{
	cout << "Introduceti un numar: ";
	cin >> n;
	cout << "Introduceti o litera: ";
	cin >> l;
	afisare(n, l);
	cout << endl;
}
