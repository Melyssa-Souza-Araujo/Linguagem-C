//https://www.onlinegdb.com/online_c_compiler
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 30
#define HEIGHT 15

typedef struct Snake {
    int x[100], y[100];
    int length;
    char direction;
} Snake;

typedef struct Food {
    int x, y;
} Food;

void initialize(Snake *snake, Food *food) {
    snake->length = 1;
    snake->x[0] = WIDTH / 2;
    snake->y[0] = HEIGHT / 2;
    snake->direction = 'R';

    food->x = rand() % WIDTH;
    food->y = rand() % HEIGHT;
}

void draw(Snake *snake, Food *food) {
    clear();

    // Desenhar limites
    for (int i = 0; i <= WIDTH + 1; i++) {
        mvprintw(0, i, "#");          // Topo
        mvprintw(HEIGHT + 1, i, "#"); // Fundo
    }
    for (int i = 0; i <= HEIGHT + 1; i++) {
        mvprintw(i, 0, "#");          // Esquerda
        mvprintw(i, WIDTH + 1, "#");  // Direita
    }

    mvprintw(food->y + 1, food->x + 1, "*");  // Símbolo para comida

    for (int i = 0; i < snake->length; i++) {
        if (i == 0) {
            mvprintw(snake->y[i] + 1, snake->x[i] + 1, "D"); // Cabeça
        } else {
            mvprintw(snake->y[i] + 1, snake->x[i] + 1, "o"); // Corpo
        }
    }

    refresh();
}

void move_snake(Snake *snake) {
    for (int i = snake->length - 1; i > 0; i--) {
        snake->x[i] = snake->x[i - 1];
        snake->y[i] = snake->y[i - 1];
    }

    switch (snake->direction) {
        case 'U': snake->y[0]--; break;
        case 'D': snake->y[0]++; break;
        case 'L': snake->x[0]--; break;
        case 'R': snake->x[0]++; break;
    }
}

int check_collision(Snake *snake) {
    if (snake->x[0] < 0 || snake->x[0] >= WIDTH || 
        snake->y[0] < 0 || snake->y[0] >= HEIGHT) {
        return 1;
    }

    for (int i = 1; i < snake->length; i++) {
        if (snake->x[i] == snake->x[0] && snake->y[i] == snake->y[0]) {
            return 1;
        }
    }

    return 0;
}

void check_food(Snake *snake, Food *food) {
    if (snake->x[0] == food->x && snake->y[0] == food->y) {
        snake->length++;
        food->x = rand() % WIDTH;
        food->y = rand() % HEIGHT;
    }
}

void explode_animation() {
    const char *frames[] = {
        "   *   ",
        "  * *  ",
        " * *** *",
        "SE FUDEU :C",
        " * *** *",
        "  * *  ",
        "   *   "
    };

    for (int i = 0; i < 7; i++) {
        clear();
        for (int j = 0; j < 7; j++) {
            mvprintw(HEIGHT / 2 - 3 + j, (WIDTH / 2) - 4, "%s", frames[j]);
        }
        refresh();
        usleep(100000);  // Atraso para a animação
    }
}

void game_over(int score) {
    clear();
    mvprintw(HEIGHT / 2, (WIDTH / 2) - 7, "Game Over! Your score: %d", score);
    mvprintw(HEIGHT / 2 + 1, (WIDTH / 2) - 10, "Press 'r' to restart or 'q' to quit.");
    refresh();
}

int main() {
    Snake snake;
    Food food;
    int ch;

    srand(time(NULL));
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    timeout(150);  // Delay para controlar a velocidade

    while (1) {
        initialize(&snake, &food);
        while (1) {
            draw(&snake, &food);
            ch = getch();

            switch (ch) {
                case KEY_UP: snake.direction = 'U'; break;
                case KEY_DOWN: snake.direction = 'D'; break;
                case KEY_LEFT: snake.direction = 'L'; break;
                case KEY_RIGHT: snake.direction = 'R'; break;
            }

            move_snake(&snake);
            check_food(&snake, &food);

            if (check_collision(&snake)) {
                break;  // Termina o jogo se houver colisão
            }
        }

        explode_animation();  // Animação de explosão
        game_over(snake.length);  // Exibe a tela de Game Over

        while (1) {
            ch = getch();
            if (ch == 'r') break;  // Reiniciar o jogo
            if (ch == 'q') {
                endwin();  // Finaliza o modo ncurses
                printf("Saindo do jogo. Até logo!\n");
                return 0; // Sair do jogo
            }
        }
    }

    endwin();
    return 0;
}