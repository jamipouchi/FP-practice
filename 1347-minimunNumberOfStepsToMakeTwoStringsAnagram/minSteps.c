int minSteps(char *s, char *t)
{
    int s_freq[26] = {0};
    for (int i = 0; s[i] != '\0'; i++)
    {
        s_freq[s[i] - 'a']++;
    }
    int count = 0;
    for (int i = 0; t[i] != '\0'; i++)
    {
        if (s_freq[t[i] - 'a'] > 0)
        {
            s_freq[t[i] - 'a']--;
        }
        else
        {
            count++;
        }
    }
    return count;
}
