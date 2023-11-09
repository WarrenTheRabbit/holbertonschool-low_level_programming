#include <stdio.h>
#include "main.h"
#define HOURS_IN_A_DAY	24
#define MINUTES_IN_AN_HOUR 60
/**
 * jack_bauer - writes the character c to stdout
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
void jack_bauer(void)
{
	int current_minute, minutes, hours;
	int minutes_in_day = HOURS_IN_A_DAY * MINUTES_IN_AN_HOUR;

	for (current_minute = 0; current_minute <= minutes_in_day; ++current_minute)
	{
		hours = current_minute / 60;
		minutes = current_minute % 60;

		printf("%02d:%02d\n", hours, minutes);
	}
}
