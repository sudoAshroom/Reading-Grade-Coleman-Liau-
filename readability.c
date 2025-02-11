#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    string input = get_string("Text: "); // get sentence
    int inputlength = strlen(input);  // get length of text

    int words = 1; //start at one to catch the last word that has no space
    int sentences = 0;
    int letters = 0;
    
    for (int i = 0; i < inputlength; i++)    // read through input and
    {                                        // increase counters
        if (isalpha(input[i]))
        {
            letters++;
        }
        if (input[i] == '.' || input[i] == '?' || input[i] == '!')
        {
            sentences++;
        }
        if (input[i] == ' ')
        {
            words++;
        }
    }
    
    // calculations
    double lettersper100 = ((double)letters/words) * 100; // double allows float, without the double before
                                                    // "letters" I would not get a decimal answer
    double sentencesper100 = ((double)sentences/words) * 100;

    double grade = (0.0588 * lettersper100) - (0.296 * sentencesper100) - 15.8; // grade calc

    int graderound = round(grade);  // round grade

    if (grade < 1) // uses grade not the rounded one incase its 0.5-0.9
    {
        printf("Before Grade 1\n");
        exit(0);
    }

    if (grade > 16)
    {
        printf("Grade 16+\n");
        exit(0);
    }

    else
    {
        printf("Grade %i\n", graderound);
        exit(0);
    }
}
