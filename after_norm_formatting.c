/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_norm_formatting.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emir12311 <emir12311.dev@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 08:38:14 by emir12311         #+#    #+#             */
/*   Updated: 2026/03/29 08:38:14 by emir12311        ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	get_player_count(FILE *score_file)
{
	int			player_count;

	printf("How many players are in the tournament?: ");
	scanf("%d", &player_count);
	fprintf(score_file, "Amount of players in the tournament: %d\n",
		player_count);
	return (player_count);
}

float	*get_player_scores(int player_count, FILE *score_file)
{
	int		i;
	float	*scores;

	scores = malloc(player_count * sizeof(float));
	if (scores == NULL)
	{
		printf("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < player_count)
	{
		printf("Enter Player %d's score: ", i + 1);
		scanf("%f", &scores[i]);
		fprintf(score_file, "Player %d's score: %.0f\n", i, scores[i]);
		i++;
	}
	return (scores);
}

void	calculate_sum_average(float *scores, int player_count, FILE *score_file)
{
	float	sum;
	float	avg;
	int		i;

	sum = 0;
	i = 0;
	while (i < player_count)
	{
		sum = sum + scores[i];
		i++;
	}
	fprintf(score_file, "Sum of all scores: %.0f\n", sum);
	printf("Sum of all scores: %.0f\n", sum);
	avg = sum / player_count;
	printf("Average score: %.2f", avg);
	fprintf(score_file, "Average score: %.2f\n", avg);
}

int	main(void)
{
	int		player_count;
	float	sum;
	float	avg;
	float	*scores;
	FILE	*score_file;

	score_file = fopen("scores.txt", "w");
	if (score_file == NULL)
	{
		printf("Error opening file!\n");
		exit(EXIT_FAILURE);
	}
	player_count = get_player_count(score_file);
	scores = get_player_scores(player_count, score_file);
	calculate_sum_average(scores, player_count, score_file);
	fclose(score_file);
	free(scores);
}
