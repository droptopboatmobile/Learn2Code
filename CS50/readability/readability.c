#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
bool end_of_sentence(char c);
float reading_level(string text);

int main(void)
{
    // get user string
    string text = get_string("Text: ");

    float level = reading_level(text);
    if (level < 1.0)
    {
        printf("Before Grade 1\n");
    }
    else if (level == 16.0)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", round(level));
    }
}

int count_letters(string text)
{
    // declare and assign an integer to receive my letter count
    int total_letters = 0;

    // for each character of the string
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // if the character is alphabetical, count it
        if (isalpha(text[i]))
        {
            total_letters++;
        }
    }
    // have the function return the total amount of letters
    return total_letters;
}

// function that counts the number of words in a text using the number of spaces, assuming there will always be 1 more word than spaces.
int count_words(string text)
{
    // initialize an integer to store the number of words. We start at 1 because each text will start with 1 word, not a space.
    int total_words = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {

        // if the character is a space, count it as a new word
        if (text[i] == ' ')
        {
            total_words++;
        }
    }

    // have the function return the total number of words
    return total_words;
}

// end_of_sentece helper function to specify the characters that end sentences
bool end_of_sentence(char c)
{
    return c == '.' || c == '?' || c == '!';
}

int count_sentences(string text)
{
    // initialize an integer to receive the sentence count
    int total_sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)

        // if the boolean end_of_sentence function is true for text increment, increment total sentences by 1
    {
        if (end_of_sentence(text[i]))
        {
            total_sentences++;
        }
    }
    // have the function return the total amount of sentences
    return total_sentences;
}

float avg_per_100(float numerator, int denominator)
{
    return numerator / denominator * 100;
}

float reading_level(string text)
{
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    float L = avg_per_100(letters, words);
    float S = avg_per_100(sentences, words);
    // calculating the reading level with the Coleman-Liau index formula
    float index = .0588 * L - .296 * S - 15.8;

// where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
    // simplifying the return value of the function

    if (index < 1.0)
    {
        return 0.0;
    }
    else if (index >= 16.0)
    {
        return 16.0;
    }
    else
    {
        return index;
    }
}