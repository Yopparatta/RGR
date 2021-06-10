#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
using namespace std;
void viginer(int status) {
		int a = 0;
		map<int, char> alphabet;
		while (a < 26) {
			alphabet[a] = 'a' + a++;//Создание массива(вектора) с буквами из алфавита
		}
		alphabet[a] = ' ';
		vector<vector<char>> code(27, vector<char>(27));
		for (int i = 0; i < 27; i++)
			for (int j = 0; j < 27; j++)
			{
				code[i][j] = alphabet[(j + i) % 27];//Создание матрицы вижинера
			}
		vector<pair<char, char>> mess;
		if (status ==1){
		cout << "Введите текст для шифрования\n";
		string text = "";
		cin.ignore();
		getline(cin, text);
		cout << "Введите ключ\n";
		string key = "";
		getline(cin, key);

		for (int i = 0; i < text.size(); i++)
		{
			mess.push_back(make_pair(text[i], key[i % key.size()]));//Каждой букве из текста сопоставляется буква, по которой будет происходить шифрования
		}
		string crypt = text;
		int cs = 0, ts = 0, i = 0;
		for (auto it : mess)
		{
			for (auto it_1 : alphabet)
			{
				if (it_1.second == it.first)//Сравнение букв из алфавита с буквой из текста
					ts = it_1.first;//Присваивание числового значения, принадлежащего букве
			}
			for (auto it_2 : alphabet)
			{
				if (it_2.second == it.second)//Сравнение букв из алфавита с ключом
					cs = it_2.first;//Присваивание числового значения, принадлежащего букве
			}
			crypt[i++] = code[ts][cs];
		}
		ofstream file;
		file.open("Viginer.txt");
		file << crypt << "\n" << key;
		file.close();
	}
	if (status == 2) {
		string crypt="";
		string key = "";
		ifstream fileIn;
		fileIn.open("Viginer.txt");
		getline(fileIn, crypt);
		getline(fileIn, key);
		fileIn.close();
		mess.clear();
		for (int i = 0; i < crypt.size(); i++)
		{
			mess.push_back(make_pair(crypt[i], key[i % key.size()]));
		}
		string uncrypt = "";
		int cs = 0,	ts = 0,	i = 0;
		for (auto it : mess)
		{
			for (auto it_1 : alphabet)
			{
				if (it_1.second == it.first)
					ts = it_1.first;
			}
			for (auto it_2 : alphabet)
			{
				if (it_2.second == it.second)
					cs = it_2.first;
			}
			uncrypt.push_back(alphabet[(ts - cs + 27) % 27]);
		}
		cout << endl << uncrypt << endl;
	}

}

void caesar(int status) {
	if (status == 1) {
		cout << "Введите текст для шифрования\n";
		string text = "";
		cin.ignore();
		getline(cin, text);
		cout << "Введите число для сдвига\n";
		int key;
		cin >> key;
		for (int i = 0; i < text.length(); i++) {
			if (text[i] != ' ') {
				text[i] = text[i] + key;
			}
			else { continue; }
		}
		text.push_back(key + 48);
		ofstream file;
		file.open("Caesar.txt");
		file << text;
		file.close();
	}
	if (status == 2) {
		string text = "";
		int key;
		//Расшифровка
		ifstream fileIn;
		fileIn.open("Caesar.txt");
		getline(fileIn, text);
		fileIn.close();
		key = text[text.length() - 1] - 48;
		for (int i = 0; i < text.length() - 1; i++) {
			if (text[i] == ' ') { continue; }
			text[i] = text[i] - key;
		}
		cout << endl << text.substr(0, text.length() - 1) << endl;
	}
}

void polibia(int status) {
	vector<vector<char>> square;
	vector<char> column;
	int n = 0;
	for (int i = 0; i < 6; i++) {//Заполнение квадрата полибия числами
		for (int j = 0; j < 5; j++) {
			column.push_back('a' + n++);
		}
		square.push_back(column);
		column.clear();
	}
	if (status == 1) {
		cout << "Введите текст для шифрования\n";
		string text = "";
		cin.ignore();
		getline(cin, text);
		string crypt = "";
		while (text != "") {
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 5; j++) {
					if (square[i][j] == text[0]) {
						crypt.push_back(i + 49);
						crypt.push_back(j + 49);
						text = text.substr(1);
					}
					else if (text[0] == ' ') {
						crypt.push_back(' ');
						text = text.substr(1);
					}
				}
			}
		}



		string str = "";
		ofstream file;
		file.open("Polibia.txt");
		file << crypt;
		file.close();
	}
	if (status == 2) {
		string str = "";
		//Расшифровка
		ifstream fileIn;
		fileIn.open("Polibia.txt");
		getline(fileIn, str);
		fileIn.close();
		int i, j;
		string uncrypt = "";
		while (str != "") {
			if (str[0] == ' ') { uncrypt.push_back(' '); str = str.substr(1); }
			i = str[0] - 49;
			j = str[1] - 49;
			uncrypt.push_back(square[i][j]);
			str = str.substr(2);
		}
		cout << endl << uncrypt << endl;
	}
}

void atbash(int status) {
	map<char, char> alphabet;
	int n = 0;
	while (n < 27) {
		alphabet['a' + n] = 'z' - n++;
	}
	if (status == 1) {
		cout << "Введите текст для шифрования\n";
		string text = "";
		cin.ignore();
		getline(cin, text);
		string crypt = "";
		while (text != "") {
			for (auto alph : alphabet) {
				if (alph.first == text[0]) {
					crypt.push_back(alph.second);
					text = text.substr(1);
				}
			}
		}
		string str = "";
		ofstream file;
		file.open("Atbash.txt");
		file << crypt;
		file.close();
	}
	if (status == 2) {
		//Расшифровка
		string str = "";
		string uncrypt = "";
		ifstream fileIn;
		fileIn.open("Atbash.txt");
		getline(fileIn, str);
		fileIn.close();
		while (str != "") {
			for (auto alph : alphabet) {
				if (alph.first == str[0]) {
					uncrypt.push_back(alph.second);
					str = str.substr(1);
				}
			}
		}
		cout << endl << uncrypt << endl;
	}
}