/*
** EPITECH PROJECT, 2020
** strcmp
** File description:
** strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i;

    for (i = 0; s1[i] == s2[i] && s1[i]; ++i);
    if (s1[i] == s2[i])
        return (0);
    if (s1[i] < s2[i])
        return (-1);
    return (1);
}