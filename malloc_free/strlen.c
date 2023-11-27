/**
 * _strlen - returns length of string
 * @s: pointer to char
 * Return: lengh of string
 */
int _strlen(char const *s)
{
	char const *start = s;
	char const *current = s;

	while (*current)
	{
		current++;
	}
	return (current - start);
}
