#include <stdio.h>

void first_racket_down(void);
void first_racket_up(void);
void second_racket_down(void);
void second_racket_up(void);
void reset(void);
void print_win_1(void);
void print_win_2(void);

//глобальные переменные
int curr_x_1 = 10;
int curr_y_1_1 = 11;
int curr_y_1_2 = 12;
int curr_y_1_3 = 13;
int curr_x_2 = 70;
int curr_y_2_1 = 11;
int curr_y_2_2 = 12;
int curr_y_2_3 = 13;
int ball_x = 40;
int ball_y = 12;
int ball_speed_x = -1;
int ball_speed_y = 1;
int score_1 = 0, score_2 = 0;
int x_score_1 = 15, y_score_1 = 5;
int x_score_2 = 63, y_score_2 = 5;

int main(void) {
    while (1) {
        int y_curr = 0;
        printf(
            "\n\033[01;32m------------Player 1----------------------------------------Player "
            "2------------\n");
        y_curr += 2;

        //рисовка
        while (y_curr < 24) {
            int x_curr = 0;
            while (x_curr < 80) {
                if ((x_curr == curr_x_1 && y_curr == curr_y_1_1) ||
                    (x_curr == curr_x_1 && y_curr == curr_y_1_2) ||
                    (x_curr == curr_x_1 && y_curr == curr_y_1_3) ||
                    (x_curr == curr_x_2 && y_curr == curr_y_2_1) ||
                    (x_curr == curr_x_2 && y_curr == curr_y_2_2) ||
                    (x_curr == curr_x_2 && y_curr == curr_y_2_3)) {
                    printf("\u2588");
                }
                else if (x_curr == ball_x && y_curr == ball_y) {
                    printf("\u2B24");
                }
                else if (x_curr == x_score_1 && y_curr == y_score_1) {
                    if (score_1 > 9) {
                        printf("%d", score_1);
                        x_curr++;
                    }
                    else {
                        printf("%d", score_1);
                    }
                }
                else if (x_curr == x_score_2 && y_curr == y_score_2) {
                    if (score_2 > 9) {
                        printf("%d", score_2);
                        x_curr++;
                    }
                    else {
                        printf("%d", score_2);
                    }
                }
                else if (x_curr == 39) {
                    printf("|");
                }
                else {
                    printf(" ");
                }
                x_curr++;
            }
            y_curr++;
        }

        //изменение координат ракеток
        printf("--------------------------------------------------------------------------------\n");

        char input_key;
        if (scanf("%c", &input_key) == 1) {
            if (input_key == 'z') {
                if (curr_y_1_1 < 21) {
                    first_racket_down();
                }
            }
            else if (input_key == 'a') {
                if (curr_y_1_1 > 2) {
                    first_racket_up();
                }
            }
            else if (input_key == 'm') {
                if (curr_y_2_1 < 21) {
                    second_racket_down();
                }
            }
            else if (input_key == 'k') {
                if (curr_y_2_1 > 2) {
                    second_racket_up();
                }
            }
            else if (input_key == ' ') {
                ;
            }
            else {
                continue;
            }
        }

        //изменение скорости по у
        if (ball_y < 3) {
            ball_speed_y = -ball_speed_y;
            ball_y = 3;
        }
        else if (ball_y > 22) {
            ball_speed_y = -ball_speed_y;
            ball_y = 22;
        }
        else {
            ball_x += ball_speed_x;
            ball_y += ball_speed_y;
        }

        //изменение скорости по х
        if (ball_x > 68 && (ball_y == curr_y_2_1 - 1 || ball_y == curr_y_2_1 || ball_y == curr_y_2_2 ||
            ball_y == curr_y_2_3 || ball_y == curr_y_2_3 + 1)) {
            ball_speed_x = -ball_speed_x;
            ball_x = 66;
        }
        else if (ball_x < 12 && (ball_y == curr_y_1_1 - 1 || ball_y == curr_y_1_1 || ball_y == curr_y_1_2 ||
            ball_y == curr_y_1_3 || ball_y == curr_y_1_3 + 1)) {
            ball_speed_x = -ball_speed_x;
            ball_x = 13;
        }
        else {
            ball_x += ball_speed_x;
        }

        //гол
        if (ball_x + ball_speed_x < 9) {
            score_2++;
            reset();
        }
        else if (ball_x + ball_speed_x > 71) {
            score_1++;
            reset();
        }

        //остановка игры
        if (score_1 > 20) {
            print_win_1();
            break;
        }
        else if (score_2 > 20) {
            print_win_2();
            break;
        }
    }
}

void first_racket_down(void) {
    curr_y_1_1++;
    curr_y_1_2++;
    curr_y_1_3++;
}
void first_racket_up(void) {
    curr_y_1_1--;
    curr_y_1_2--;
    curr_y_1_3--;
}
void second_racket_down(void) {
    curr_y_2_1++;
    curr_y_2_2++;
    curr_y_2_3++;
}
void second_racket_up(void) {
    curr_y_2_1--;
    curr_y_2_2--;
    curr_y_2_3--;
}

void reset(void) {  // сброс настроек игры до дефолта
    ball_x = 40;
    ball_y = 13;
    curr_x_1 = 10;
    curr_y_1_1 = 11;
    curr_y_1_2 = 12;
    curr_y_1_3 = 13;
    curr_x_2 = 70;
    curr_y_2_1 = 11;
    curr_y_2_2 = 12;
    curr_y_2_3 = 13;
}

void print_win_1(void) {
    printf("\n\n\n\n\n");
    printf("   ########   ##           ###    ##    ##  ########  ########           ## \n");
    printf("   ##     ##  ##          ## ##    ##  ##   ##        ##     ##        #### \n");
    printf("   ##     ##  ##         ##   ##    ####    ##        ##     ##          ##\n");
    printf("   ########   ##        ##     ##    ##     ######    ########           ##  \n");
    printf("   ##         ##        #########    ##     ##        ##   ##            ##\n");
    printf("   ##         ##        #########    ##     ##        ##   ##            ##\n");
    printf("   ##         ########  ##     ##    ##     ########  ##     ##        ######\n");
    printf("\n");
    printf("\n");
    printf("                  ##      ##  ####  ##    ##   ######  \n");
    printf("                  ##  ##  ##   ##   ###   ##  ##    ##\n");
    printf("                  ##  ##  ##   ##   ####  ##  ##    \n");
    printf("                  ##  ##  ##   ##   ## ## ##   ######\n");
    printf("                  ##  ##  ##   ##   ##  ####        ##\n");
    printf("                  ##  ##  ##   ##   ##   ###  ##    ##\n");
    printf("                   ###  ###   ####  ##    ##   ######\n");
    printf("\n\n\n\n\n");
}

void print_win_2(void) {
    printf("\n\n\n\n\n");
    printf("   ########   ##           ###    ##    ##  ########  ########         #######\n");
    printf("   ##     ##  ##          ## ##    ##  ##   ##        ##     ##       ##     ##\n");
    printf("   ##     ##  ##         ##   ##    ####    ##        ##     ##              ##\n");
    printf("   ########   ##        ##     ##    ##     ######    ########         ####### \n");
    printf("   ##         ##        #########    ##     ##        ##   ##         ##\n");
    printf("   ##         ##        #########    ##     ##        ##   ##         ##\n");
    printf("   ##         ########  ##     ##    ##     ########  ##     ##       ########\n");
    printf("\n");
    printf("\n");
    printf("                  ##      ##  ####  ##    ##   ######  \n");
    printf("                  ##  ##  ##   ##   ###   ##  ##    ##\n");
    printf("                  ##  ##  ##   ##   ####  ##  ##    \n");
    printf("                  ##  ##  ##   ##   ## ## ##   ######\n");
    printf("                  ##  ##  ##   ##   ##  ####        ##\n");
    printf("                  ##  ##  ##   ##   ##   ###  ##    ##\n");
    printf("                   ###  ###   ####  ##    ##   ######\n");
    printf("\n\n\n\n\n");
}
