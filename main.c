#include "headers/app.h"

int main(int argc, char **argv) {
    Window* w = window_create(800,800);
    int ret = app_run(w,argc,argv);
    window_destroy(w);
    return ret;
}