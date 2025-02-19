#include "asf.h"
#include <stdbool.h>

volatile bool btn_pressed = false; // Variável global necessária para a ISR

// ISR: Apenas seta a flag para indicar que o botão foi pressionado.
void btn_callback(void) {
    btn_pressed = true;
}

void main(void) {
    int count = 0;
    char progress[10] = {0};
    int batata = 0;

    while (1) {
        if (btn_pressed) {
            if (count >= 8)
                count = 0;
            else
                count++;

            for (int i = 0; i < count; i++) {
                progress[i] = '*';
            }
            progress[count] = '\0';

            gfx_mono_draw_string(progress, 0, 0, &sysfont);

            btn_pressed = false;
        }


        batata++;
    }
}
