#include "UI.h"
#include <iostream>

using namespace std;

void UI::Start()
{
	gameInterface = new AnagramGame();
	string anagramWord = "areallylongword";
	gameInterface->setAnagramWord(anagramWord);
	string userWord = "";
	string pathToWordList = "wordlist.txt";

	while (true)
	{
		cout << "\nEnter a word using letters from : " + anagramWord + "\n\n>";
		cin >> userWord;
		cout << "\n";
		
		// Check if submitted word is valid 
		if (gameInterface->CheckSubmittedWord())
		{
			cout << "Submitting word " + userWord << endl;
			gameInterface->setSubmittedWord(userWord);
			gameInterface->isAnagram(pathToWordList);
			PrintScores();
		}
		// Otherwise ask again for user input
		else
		{
			cout << "\nWRONG INPUT, Start again. Enter a word using letters from : " + anagramWord + "\n\n>";
			cin >> userWord;
			cout << "\n";
		}
	}
}

void UI::PrintScores()
{
	cout << "\n";
	for (int i = 0; i < 10; i++)
	{
		int score = gameInterface->GetScoreAtPosition(i);
		string word = gameInterface->GetWordEntryAtPosition(i);
		string line = word + " " + to_string(score) + "\n";
		cout << line;
	}
	cout << "\n";
}
