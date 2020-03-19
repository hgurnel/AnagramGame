#pragma once
#include <string>
#include <map>

using namespace std;

class AnagramGame
{
public:
	AnagramGame() {}
	AnagramGame(const string& word);
	virtual ~AnagramGame() {}

	/// <summary>
	/// Submit a word on behalf of a user. A word is accepted if its letters are 
	/// contained in the original string submitted in the constructor, and if it 
	/// is in the word list at https://sites.google.com/a/ifyoucan.org/downloads/downloads/wordlist.txt. 
	/// If the word is accepted and its score is high enough, the submission 
	/// should be added to the high score list. If there are multiple submissions 
	/// with the same score, all are accepted, but the first submission with that 
	/// score should rank higher. 
	/// </summary>
	/// <param name="word">Word submitted by the user</param>
	void SubmitWord(string &word);

	// Check if submittedWord is a substring of anagramWord
	bool IsUserWordValid(const string &userWord, const string &anagramWord);

	// Check if string 1 is a substring of string 2 (no order)
	bool IsSubstring(const string& s1, const string& s2);

	// Check if submittedWord belongs to the word list
	bool IsAnagram(const string &filePath);

	/// <summary>
	/// Return word entry at given position in the high score list, 0 being the 
	/// highest (best score) and 9 the lowest. 
	/// </summary>
	/// <returns>The word entry at the position in the high score list, 0 being the 
	/// highest (best score) and 9 the lowest, or null if there is no entry at that position</returns>
	/// <param name="position">Position index inot the high score list.</param>
	string GetWordEntryAtPosition(int position);

	/// <summary>
	/// Return the score at given position in the high score list, 0 being the 
	/// highest (best score) and 9 the lowest.
	/// </summary>
	/// <returns>The score at the position in the high score list, or -1 if there is no entry at that position.</returns>
	/// <param name="position">Position index in the high score list.</param>
	int GetScoreAtPosition(int position);

private:
	string m_anagramWord;
	string m_userWord;

	multimap<int, string> m_scores;
};

