#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

//declaration of compute_score function
int compute_score(string word);

int main(void)
{
    //Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    //Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

//compute score function used for word1 and word2
int compute_score(string word)
{
    //create an integer value type to store our total score
    int total_score = 0;

    //for loop that converts each character of "word" string to a lowercase character
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        char lowercase_char = tolower(word[i]);

        //then the loop checks if the lowercase character is alphabetical
        if (isalpha(lowercase_char))
        {
            //finally, if the lowercase character is alpha, subtract 'a' from the character (which gives us the appropriate index value)
            int index = lowercase_char - 'a';

            //total score is then assigned based on this index value. for example, a-a = 0, 0 in the array POINTS is 1, so 1 point is added to total_score and assigned to total_score. 0+1=1, thus a gives us 1 point, and the loop continues throught the word to the next letter.
            total_score += POINTS[index];
        }
    }
    return total_score;
}
