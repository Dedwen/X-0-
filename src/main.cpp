/* Un simplu joc de X si O */
#include <iostream>
using namespace std;

char matrice[3][3]; // Matricea de X si O
char verifica();
void matriceInit();
void mutaJucatorul();
void mutaCalculatorul();
void afisMatrice();

int main() {

	char gata;

	cout << " Acesta este jocul X si O" << endl;
	cout << " Veti juca cu calculatorul" << endl;

	gata = ' ';
	matriceInit();
	do {
		afisMatrice();
		mutaJucatorul();
		gata = verifica(); // Verifica daca exista invingator
		if (gata != ' ') break; // Daca se gasesti invingator iese din structura repetitiva aproapiata
		mutaCalculatorul();
		gata = verifica(); // Verifica daca exista invingator
	} while (gata == ' ');

	if (gata == 'X') cout << " Ai castigat ! " << endl;
	else {
		cout << " Calculatorul a castigat ! " << endl;
		afisMatrice(); // Afiseaza pozitia finala
	}

	system("pause");
	return 0;
}

/* Initializeaza matricea
*/
void matriceInit() {

	int i, j;

	for (i = 0; i < 3; ++i)
		for (j = 0; j < 3; ++j) matrice[i][j] = ' ';
}

/* Muta jucatorul
*/
void mutaJucatorul() {

	int x, y;

	cout << " Introduceti coordonatele pt X-ul dvs. :" << endl;
	cin >> x >> y;
	x--;
	y--;
	if (matrice[x][y] != ' ') {
		cout << " Mutare incorecta ! Mai incercati.. " << endl;
		mutaJucatorul();
	}
	else matrice[x][y] = 'X';
}

/* Muta calculatorul
*/
void mutaCalculatorul() {

	int i, j;

	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 3; ++j)
			if (matrice[i][j] == ' ')
				break;
		if (matrice[i][j] == ' ')
			break;

	}

	if (i*j == 9) {
		cout << "Gata." << endl;
		exit(0);
	}
	else matrice[i][j] = 'O';
}

/* Afiseaza matricea pe ecran
*/
void afisMatrice() {

	int t;

	for (t = 0; t < 3; ++t) {
		cout << matrice[t][0] << "  | " << matrice[t][1] << " |  " << matrice[t][2];
		if (t != 2) cout << "\n---|---|---\n";
	}
	cout << endl;
}

/* Verifica daca exista invingator */
char verifica() {

	int i;

	for (i = 0; i < 3; ++i) // Verifica randurile
		if (matrice[i][0] == matrice[i][1] && matrice[i][0] == matrice[i][2]) return matrice[i][0];
	for (i = 0; i < 3; ++i) // Verifica coloanele
		if (matrice[0][i] == matrice[1][i] && matrice[0][i] == matrice[2][i]) return matrice[0][i];
	/* Verifica diagonalele */
	if (matrice[0][0] == matrice[1][1] && matrice[0][0] == matrice[2][2]) return matrice[0][0];
	if (matrice[0][2] == matrice[1][1] && matrice[1][1] == matrice[2][0]) return matrice[0][2];

	return ' ';
}
