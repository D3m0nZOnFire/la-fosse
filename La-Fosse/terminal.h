#pragma once
#include <iostream>
#include "ansi.h"

inline void clearScreen() { std::cout << ERASE_SCREEN << "\033[H"; }
inline void moveCursor(int row, int col) { std::cout << "\033[" << row << ";" << col << "H"; }
inline void hideCursor() { std::cout << CURSOR_HIDE; }
inline void showCursor() { std::cout << CURSOR_SHOW; }