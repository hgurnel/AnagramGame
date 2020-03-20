#include "UI.h"
#include <iostream>

using namespace std;

void UI::Start()
{
	string anagramWord = "a really long word";
	gameInterface = new AnagramGame(anagramWord);
	string userWord = "";
	string pathToWordList = "wordlist.txt";

	while (true)
	{
		cout << "\n //////////// S T A R T ////////////" << endl;
		cout << "Form an anagram using letters from : " + anagramWord + "\n\n>";
		cin >> userWord;
		cout << "\n";

		gameInterface->SubmitWord(userWord);

		if (gameInterface->IsAnagram(pathToWordList))
		{
			gameInterface->UpdateTopScores(userWord);
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
