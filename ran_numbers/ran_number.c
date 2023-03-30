/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ran_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:42:55 by vvu               #+#    #+#             */
/*   Updated: 2023/03/30 10:48:25 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	main()
{
	int	random_number, guess, attempts = 0;

	srand(time(NULL));
	random_number = rand() % 100 + 1;

	printf("Welcome to the number guessing game!\n");
	printf("The machine will generated a random number between 1 and 100\n");
	printf("Guess what is the number\n");

	while(1)
	{
		printf("Enter your guess: ");
		scanf("%d", &guess);
		attempts++;

		if (guess == random_number)
		{
			printf("Oh wow!!!! after %d guessed, you make it\n", attempts);
			break;
		}
		else if (guess < random_number)
			printf("Too low! try again.\n");
		else
			printf("too high! try again.\n");
	}
	return (0);
}
