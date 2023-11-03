#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

int main() {

	cout << "Greetings and good times, Dr.Afshari Rad\n\n";

	double lg = pow(10, -3);;
	double li = 79.9 * pow(10, -2);
	double Agi = 225 * M_PI * pow(10, -4);
	double N = 600.0;

	double mu = 4 * M_PI * pow(10, -7);
	double b[4] = {1.2, 1.1, 1.0, 0.9};
	double hc[4] = {1000, 800, 700, 600};
	double* hg = new double[4];
	double* fc = new double[4];
	double* fg = new double[4];
	double* f = new double[4];
	double* ii = new double[4];

	for (int i = 0; i < 4; i++) {
		hg[i] = b[i] / mu;
		fc[i] = hc[i] * li;
		fg[i] = hg[i] * lg;
		f[i] = fc[i] + fg[i];
		ii[i] = f[i] / N;
	}

	double this_fi = b[3] * Agi;
	double this_fii = this_fi * pow(10, 3);

	for (int i = 0; i < 4; i++)
		cout << "b = " << b[i] << "--> " << ii[i] << endl;
	
	cout << endl;
	cout << "According to the above results, for b = 0.9 with a reach a current almost equivalent to 2A. Therefore, the required flux is equal to: " << this_fii << " mwb" << endl << endl;

	double* p = new double[11];
	double* o = new double[11];
	double* fih = new double[11];
	double* negative_o = new double[11];

	ofstream MyFile("data_set.dat");
	MyFile << "\"Foolad\"\n";
	double fi[] = {0, 0.1, 0.32, 0.6, 0.9, 1.08, 1.18, 1.27, 1.33, 1.36, 1.4};
	double F[] = {0, 200, 400, 600, 800, 1000, 1200, 1400, 1600, 1800, 2020};
	for (int i = 0; i < 11; i++) {
		p[i] = fi[i] * Agi;
		o[i] = F[i] * li;
		fih[i] = F[i] * lg;
		negative_o[i] = -o[i];
		cout << "fi = " << fi[i] << " --> " << p[i] << "    F = " << F[i] << " --> " << o[i] << endl;
		MyFile << o[i] << ", " << p[i] << "\n";
	}
	MyFile << "\n\n";

	MyFile << "\"Foolad2\"\n";
	for (int i = 0; i < 11; i++) {
		MyFile << negative_o[i] << ", " << p[i] << "\n";
	}
	MyFile << "\n\n";

	MyFile << "\"Foolad3\"\n";
	for (int i = 0; i < 11; i++) {
		MyFile << fih[i]+1200 << ", " << p[i] << "\n";
	}

	// Close the file
	MyFile.close();

	return 0;
}