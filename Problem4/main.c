#include <stdio.h>
#include <stdlib.h>

// Substitution cipher or Caesar's cipher.

// This program which reads a natural number n and a string s. The string s is encoded using Caesar�s cipher with a displacement of n (either positive or negative).
// The program decodes the message and display it on the screen. Punctuation marks and numbers are left as they are.

int main(int argc, char* argv[])
{
    char text[255], character;
    int i, shift;
    scanf("%d\n", &shift);
    scanf("%[^\n]", &text, sizeof(text));
    if (shift > 0)
    {
        for (i = 0; text[i] != '\0'; i++)
        {
            if (text[i] >= 'a' && text[i] <= 'z')
            {
                text[i] = ((text[i] - 97 + shift) % 26) + 97;
            }
            else if (text[i] >= 'A' && text[i] <= 'Z')
            {
                text[i] = ((text[i] - 65 + shift) % 26) + 65;
            }
        }
        printf("%s", text);
    }
    else
    {
        shift = shift * -1;
        while (shift > 26)
        {
            shift = shift - 26;
        }

        for (i = 0; text[i] != '\0'; i++)
        {
            if (text[i] >= 'a' && text[i] <= 'z')
            {
                text[i] = ((text[i] - 97 + (26 - shift)) % 26) + 97;
            }
            else if (text[i] >= 'A' && text[i] <= 'Z')
            {
                text[i] = ((text[i] - 65 + (26- shift)) % 26) + 65;
            }
        }
        printf("%s", text);
    }
}