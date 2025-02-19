#include "asf.h"
#include <stdbool.h>

volatile bool btn_pressed = false; 
int g_cnt = 0;
char g_str[10];
int batata = 0;

void btn_callback(void) {
    btn_pressed = true;
}


void update_progress_bar(void) {
    if (g_cnt >= 8)
        g_cnt = 0;
    else
        g_cnt++;

    for (int i = 0; i < g_cnt; i++) {
        g_str[i] = '*';
    }
    g_str[g_cnt] = '\0';  

    gfx_mono_draw_string(g_str, 0, 0, &sysfont);
}

void main(void) {

    while (1) {

        if (btn_pressed) {
            update_progress_bar();
            btn_pressed = false; 
        }


        batata++; 
    }
}
