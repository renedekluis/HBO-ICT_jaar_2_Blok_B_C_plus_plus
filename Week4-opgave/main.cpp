#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include <map>


using namespace std;

struct counted_letters { 
	char letter; int amount; 
};

bool sort_letters(counted_letters a, counted_letters b){
	return a.amount > b.amount;
}

bool sortPair(pair<string, int>  p1, pair<string, int> p2){
	return p1.second > p2.second;
}


int main() {
	std::clock_t start;
	double duration;
	ifstream input("bible.txt");
	vector<char>the_bible;
	char charToAdd;

	if (!input.is_open()) {
		std::cout << "File could not be opened.\n";
		return 1;
	}



	//1.	Lees alle characters van deze file in een vector.
	start = std::clock();
	cout << "Adding all bible characters to vector.";
	while (input.get(charToAdd)) {
		the_bible.push_back(charToAdd);
	}
	cout << "\tDone\n";
	duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
	cout	<< "Took: "
			<< duration
			<< " seconds.\n\n";

	//2.	Print hoeveel characters de file bevat(vraag het aan de vector).
	cout	<< "\nNumber of characters in file: "
			<< the_bible.size() 
			<< "\n";
	



	//3.	Print hoeveel regels de file bevat(gebruik de vector en een STL algorithme).
	cout	<< "\nNumber of lines in file: "
			<< count(the_bible.begin(),the_bible.end(),'\n')
			<<"\n";


	//4.	Print hoeveel alfabetische characters de file bevat(vector + algorithme).
	cout	<< "\nNumber of alphabetic characters in file: "
			<< count_if(the_bible.begin(), the_bible.end(), isalpha)
			<< "\n";


	//5.	Zet de letters in de vector om in kleine letters(max 3 regels code).
	cout << "\nConverting characters to lowercase.";
	vector<char>the_bible_in_lowercase;
	for (char c : the_bible) {
		the_bible_in_lowercase.push_back(tolower(c));
	}
	cout << "\tDone\n";
	
	
	//6.	Tel in een lijst voor iedere letter(a..z) hoe vaak hij voorkomt in de vector(diverse manieren mogelijk).
	//7.	Druk deze lijst af 
	
	//1) op lettervolgorde.
	cout << "\nNumber of times letter in file(Alphabetic):\n";
	string a = "abcdefghijklmnopqrstuvwxyz";
	vector<counted_letters>letter_count = {
		{ 'a', 0 },
		{ 'b', 0 },
		{ 'c', 0 },
		{ 'd', 0 },
		{ 'e', 0 },
		{ 'f', 0 },
		{ 'g', 0 },
		{ 'h', 0 },
		{ 'i', 0 },
		{ 'j', 0 },
		{ 'k', 0 },
		{ 'l', 0 },
		{ 'm', 0 },
		{ 'n', 0 },
		{ 'o', 0 },
		{ 'p', 0 },
		{ 'q', 0 },
		{ 'r', 0 },
		{ 's', 0 },
		{ 't', 0 },
		{ 'u', 0 },
		{ 'v', 0 },
		{ 'w', 0 },
		{ 'x', 0 },
		{ 'y', 0 },
		{ 'z', 0 },
	};

	for (auto & letter : letter_count) {
		letter.amount = count(the_bible.begin(), the_bible.end(), letter.letter);
		cout << letter.letter
			<< ": "
			<< letter.amount
			<< "\n";
	}


	//2) op hoe vaak een letter voorkomt(gebruikt een algoritme).
	sort(letter_count.begin(), letter_count.end(), sort_letters);
	cout << "\nNumber of times letter in file(high to low):\n";
	for (auto & letter : letter_count) {
		cout << letter.letter
			<< ": "
			<< letter.amount
			<< "\n";
	}
	
	
	//8.	Bepaal welke woorden er in de tekst voorkomen en druk de 10 meest voorkomende woorden af.
	//		Een woord is aaneengesloten reeks letters. (gebruik een map)
	std::map<string, int>words;
	string word = "";
	ifstream file("bible.txt");
	cout << "\nChecking most used words.";
	for (string word; file >> word;) {
		auto p = words.find(word);
		if (p == words.end()) {
			words.insert(std::pair<string, int>(word, 1));
		}
		else {
			p->second = p->second + 1;
		}
	}
	cout << "\tDone\n";
	vector<pair<string, int>>vec;
	copy(words.begin(), words.end(), back_inserter(vec));
	sort(vec.begin(), vec.end(), sortPair);
	for (int i = 0; i < 10;i++){
		cout	<< i+1 << ") " 
				<< vec[i].first << " : " 
				<< vec[i].second << " times\n";
	}
	
	return 0;
}
