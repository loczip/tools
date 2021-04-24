#include <iostream>
#include <vector>
#include <random>
using namespace std;

#define ANS1 answers.at(num)
#define ANS2 answers2.at(num)

vector<string> answers = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};
vector<string> answers2 = {"suiso", "heriumu", "ritiumu", "beririumu", "houso", "tannso", "tisso", "sannso", "husso", "neonn", "natoriumu", "magunesiumu", "aruminiumu", "keiso", "rinn", "iou", "ennso", "arugonn", "kariumu", "karusiumu", "sukannjiumu", "titann", "banajiumu", "kuromu", "manngann", "tetu", "kobaruto", "nikkeru", "dou", "aenn", "gariumu", "gerumaniumu", "hiso", "serenn", "syuuso", "kuriputonn", "rubijiumu", "sutoronntiumu", "ittoriumu", "jirukoniumu", "niobu", "moribudenn", "tekunetiumu", "ruteniumu", "rojiumu", "parajiumu", "ginn", "kadomiumu", "innjiumu", "suzu", "anntimonn", "teruru", "youso", "kisenonn", "sesiumu", "bariumu", "ranntann", "seriumu", "puraseojimu", "neojimu", "purometiumu", "samariumu", "yuuropiumu", "gadoriniumu", "terubiumu", "jisupurosiumu", "horumiumu", "erubiumu", "turiumu", "itterubiumu", "rutetiumu", "hahuniumu", "tanntaru", "tanngusutenn", "reniumu", "osumiumu", "irijiumu", "puratina", "kinn", "suiginn", "tariumu", "namari", "bisumasu", "poroniumu", "asutatinn", "radonn", "hurannsiumu", "rajiumu", "akutiniumu", "toriumu", "purotoakutiniumu", "urann", "neputuniumu", "purutoniumu", "amerisiumu", "kyuriumu", "ba-kuriumu", "karihoruniumu", "ainnsutainiumu", "ferumiumu", "mennderebiumu", "no-beriumu", "ro-rennsiumu", "razaho-jiumu", "dobuniumu", "si-bo-giumu", "bo-riumu", "hassiumu", "maitoneriumu", "da-musutatiumu", "renntogeniumu", "koperunisiumu", "nihoniumu", "hurerobiumu", "mosukobiumu", "ribamoriumu", "tenesinn", "oganesonn"};

int rnd118() {
	random_device rnd;
	mt19937 mt(rnd());
	return mt() % 118;
}

void printans(int i, int num) {
	switch (i) {
		case 0:
			cout << ANS1;
			break;
		case 1:
			cout << num + 1;
			break;
		case 2:
			cout << ANS2;
	}
}

void quiz(int q, int a, int rps) {
	int corrects = 0;
	vector<int> mis(0);
	for (int i = 0; i < rps; i++) {
		string ans;
		int num = rnd118();
		printans(q, num);
		cout << ": ";
		cin >> ans;
		bool isans = false;
		switch (a) {
			case 0:
				isans = ans == ANS1;
				break;
			case 1:
				isans = atoi(ans.c_str()) == num + 1;
				break;
			case 2:
				isans = ans == ANS2;
		}
		if (isans) {
			cout << "Good!" << endl;
			corrects++;
		}
		else {
			cout << "Mistake... The answer is: ";
			mis.push_back(num);
			printans(a, num);
			cout << endl;
		}
	}
	cout << "Result is... " << corrects << "/" << rps << endl << "Mistakes are:" << endl;
	if (mis.size() == 0) cout << "None!" << endl;
	for (int i = 0; i < mis.size(); i++) {
		printans(q, mis.at(i));
		cout << ": ";
		printans(a, mis.at(i));
		cout << endl;
	}
}

int main() {
	int rps;
	cout << "How namy questions do you ask? ";
	cin >> rps;
	int q, a;
	bool same = true;
	while(same) {
		cout << "Which do you want to be asked? sign: 0 number: 1 element name: 2 -> ";
		cin >> q;
		cout << "Which do you want to answer? The numbers are the same as before. -> ";
		cin >> a;
		same = false;
		if (q == a) {
			cout << "Question and answer are the same. One more time, please." << endl;
			same = true;
		}
	}
	cout << "ready... Go!" << endl;
	quiz(q, a, rps);
	cout << "Thank you for playing!" << endl;
	return 0;
}