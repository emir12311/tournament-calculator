#include <stdio.h>
#include <stdlib.h>

int main() {
    int player_count;
    float sum = 0;
    float avg;
    FILE *score_file = fopen("scores.txt", "w");
    if (score_file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }   
    printf("How many players are in the tournament?: ");
    scanf("%d", &player_count);

    fprintf(score_file, "Amount of players in the tournament: %d\n", player_count);

    float *scores = malloc(player_count * sizeof(float));
    if (scores == NULL) {
        printf("Memory allocation failed!\n");
        return 1; 
    }

    int i;
    for (i = 0; i < player_count; i++) {
        printf("Enter Player %d's score: ", i+1);
        scanf("%f", &scores[i]);
        fprintf(score_file, "Player %d's score: %.0f\n", i, scores[i]);
    }

    for (i = 0; i < player_count; i++) {
        sum = sum + scores[i];
    }

    printf("Sum of all scores: %.0f\n", sum);
    fprintf(score_file, "Sum of all scores: %.0f\n", sum);

    avg = sum / player_count;


    printf("Average score: %.2f", avg);
    fprintf(score_file, "Average score: %.2f\n", avg);


    fclose(score_file);
    free(scores);
}