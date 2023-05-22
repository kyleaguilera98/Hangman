/*

- Create a game of hangman that the user can play. The word that is selected
should be randomly selected from a pre-determined word-bank that you have made;
you can fill it up with as many random words as you want.

- The game should be interactive and continuously update. It should show which
letters have been guessed, how many lives they have left, and the status of the
word they are guessing. Here's an example run:





LIVES: 5

Letters Guessed: {}

_ _ _ _ _ _ _ _ _

Guess your letter: A


=== Incorrect Guess! ===



LIVES: 4

Letters Guessed: {A}

_ _ _ _ _ _ _ _ _

Guess your letter: A


=== Letter Already Guessed! ===



LIVES: 4

Letters Guessed: {A}

_ _ _ _ _ _ _ _ _

Guess your letter: G


=== Correct Guess! ===



LIVES: 4

Letters Guessed: {A, G}

G _ _ _ _ _ _ _ G

Guess your letter: R


=== Correct Guess! ===



LIVES: 4

Letters Guessed: {A, G, R}

G R _ _ _ _ _ _ G

Guess your letter: S


=== Incorrect Guess! ===



LIVES: 3

Letters Guessed: {A, G, R, S}

G R _ _ _ _ _ _ G

Guess your letter: O


=== Correct Guess! ===



LIVES: 3

Letters Guessed: {A, G, R, S, O}

G R O _ _ _ _ O G

Guess your letter: U



=== Correct Guess! ===



LIVES: 3

Letters Guessed: {A, G, R, S, O, U}

G R O U _ _ _ O G

Guess your letter: N


=== Correct Guess! ===



LIVES: 3

Letters Guessed: {A, G, R, S, O, U, N}

G R O U N _ _ O G

Guess your letter: D


=== Correct Guess! ===



LIVES: 3

Letters Guessed: {A, G, R, S, O, U, N, D}

G R O U N D _ O G

Guess your letter: D


=== Correct Guess! ===



LIVES: 3

Letters Guessed: {A, G, R, S, O, U, N, D, H}

G R O U N D H O G

YOU WIN!!!




----------------------------------------



Here is another run:

LIVES: 5

Letters Guessed: {}

_ _ _ _ _ _ _ _

Guess your letter: X


=== Incorrect Guess! ===



LIVES: 4

Letters Guessed: {X}

_ _ _ _ _ _ _ _

Guess your letter: Y


=== Incorrect Guess! ===



LIVES: 3

Letters Guessed: {X, Y}

_ _ _ _ _ _ _ _

Guess your letter: Z


=== Incorrect Guess! ===



LIVES: 2

Letters Guessed: {X, Y, Z}

_ _ _ _ _ _ _ _

Guess your letter: W


=== Incorrect Guess! ===



LIVES: 1

Letters Guessed: {X, Y, Z, w}

_ _ _ _ _ _ _ _

Guess your letter: O


=== Correct Guess! ===



LIVES: 1

Letters Guessed: {X, Y, Z, W, O}

_ O _ _ _ _ O _

Guess your letter: T


=== Inorrect Guess! ===



LIVES: 0

Letters Guessed: {X, Y, Z, W, O, T}

_ O _ _ _ _ O _

YOU LOSE!




Some cases to consider: You should only allow uppercase inputs (no need to
forbid the user from entering 'a' or 's', you can just use toupper()). Also, all
words in the word bank should be all uppercase as well.
*/
#include <iostream>
#include <vector>
using namespace std;
#include <cstdlib>
#include <ctime>

// functions
vector<char> upperchar(
    string word);                 // changes word to uppercase and converts string to vector
vector<char> mirror(string word); // creates empty vector of underlines
void guessedletters(
    vector<char> letbank);           // displays what letters have been guessed
void showword(vector<char> empword); // shows letters that have been guessed
                                     // within the word
bool checkguess(vector<char> letbank,
                char letter); // determines if letter was already guessed

int main()
{
  string word = "developer";
  int lives = 7;
  char guessedletter;
  vector<char> wordchar = upperchar(word); // guessing word
  vector<char> emptyword = mirror(word);
  vector<char> letterbank; // letters that have been guessed

  while (lives >= 0)
  {
    bool foundletter = false; // switch to determine if the guess was correct
    bool alreadyguessed = false;
    cout << "LIVES: " << lives << "\n"
         << endl;

    guessedletters(letterbank);

    showword(emptyword);

    // accepts input from user
    if (emptyword == wordchar)
    {
      cout << "\nYOU WIN!!!\n\n"
           << endl;
      break;
    }
    else if (lives == 0)
    {
      cout << "\nYOU LOSE!\n\n"
           << endl;
      break;
    }
    else
    {
      cout << "Guess your letter: ";
      cin >> guessedletter;
      guessedletter = toupper(guessedletter);
    }

    alreadyguessed = checkguess(letterbank, guessedletter);

    if (!alreadyguessed)
    {
      // adds letter to letter bank
      letterbank.push_back(guessedletter);

      // replaces underline value in blank word with correct letter
      for (int i = 0; i < emptyword.size(); i++)
      {
        if (wordchar[i] == guessedletter)
        {
          emptyword[i] = guessedletter;
          foundletter = true;
        }
      }

      // determines if life should be taken based on if you found a letter
      if (foundletter)
      {
        cout << "\n=== Correct Guess! ====\n\n"
             << endl;
      }
      else
      {
        cout << "\n=== Incorrect Guess! ===\n\n"
             << endl;
        lives--;
      }
    }
    else
      cout << "\n=== Letter Already Guessed! ===\n\n"
           << endl;
  }
  return 0;
}

vector<char> upperchar(string word)
{
  vector<char> wordchar;
  for (int i = 0; i < word.size(); i++)
  {
    wordchar.push_back(toupper(word[i]));
  }
  return wordchar;
}

vector<char> mirror(string word)
{
  vector<char> underline;
  for (int i = 0; i < word.size(); i++)
  {
    underline.push_back('_');
  }
  return underline;
}

void guessedletters(vector<char> letbank)
{
  cout << "Letters Guessed: {";
  for (int i = 0; i < letbank.size(); i++)
  {
    cout << letbank[i];
    if (letbank[i] != letbank.back())
      cout << ", ";
  }
  cout << "}\n"
       << endl;
}

void showword(vector<char> empword)
{
  for (int i = 0; i < empword.size(); i++)
  {
    cout << empword[i] << " ";
  }
  cout << "\n"
       << endl;
}

bool checkguess(vector<char> letbank, char letter)
{
  bool guess = false;
  for (int i = 0; i < letbank.size(); i++)
  {
    if (letbank[i] == letter)
      guess = true;
  }
  return guess;
}