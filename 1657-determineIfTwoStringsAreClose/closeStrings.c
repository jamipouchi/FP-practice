#define TRUE 1
#define FALSE 0

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

char closeStrings(char *word1, char *word2)
{
    if (strlen(word1) != strlen(word2))
    {
        return FALSE;
    }
    int freq1[26] = {0};
    int freq2[26] = {0};
    for (int i = 0; word1[i] != '\0'; i++)
    {
        freq1[word1[i] - 'a']++;
    }
    for (int i = 0; word2[i] != '\0'; i++)
    {
        if (freq1[word2[i] - 'a'] == 0)
        {
            return FALSE;
        }
        freq2[word2[i] - 'a']++;
    }
    // Here we know that both strings have the same characters
    // Now we need to check if they have the same frequency distribution
    // We can do this by sorting the frequency arrays and comparing them
    qsort(freq1, 26, sizeof(int), &compare);
    qsort(freq2, 26, sizeof(int), &compare);
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] != freq2[i])
        {
            return FALSE;
        }
    }
    // Here we know that both strings have the same characters and the same frequency distribution
    return TRUE;
}

/*
    LEMA:
    If two strings contain the same letters && they have the same frequency
    distribution, then they are close.
*/
/*
    PROOF:

    Given that both strings have the same characters. By applying Operation 2,
    we can always swap from equal frequency distribution to same character
    frequency being equal.
    PROOF:
        If they only have one character, they must be equal
        If they have two characters, swap them
        If they have more than two characters, you can always make a move
        turning  a character into matching frequency

    Given that both strings hagve the same character frequencies. By applying
    Operation 1, we can always swap from equal character frequency
    to equal strings
    PROOF:
        If they only have one character, they must be equal.
        If they have two characters, swap them
        If they have more than two characters, you can always move the next
        character into position
*/