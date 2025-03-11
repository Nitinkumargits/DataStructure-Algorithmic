#include <stdio.h>
#include <string.h>

int characterReplacementOptimized(char s[], int k)
{
    int count[26] = {0}, maxLen = 0, maxFreq = 0, left = 0, n = strlen(s);

    for (int right = 0; right < n; right++)
    {
        count[s[right] - 'A']++;
        maxFreq = maxFreq > count[s[right] - 'A'] ? maxFreq : count[s[right] - 'A'];

        if ((right - left + 1) - maxFreq > k)
        {
            count[s[left] - 'A']--;
            left++;
        }

        maxLen = (right - left + 1) > maxLen ? (right - left + 1) : maxLen;
    }
    return maxLen;
}

int main()
{
    char s[] = "AABABBA";
    int k = 1;
    printf("Optimized Output: %d\n", characterReplacementOptimized(s, k));
    return 0;
}
