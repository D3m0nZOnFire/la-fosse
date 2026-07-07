#pragma once

// Text styles
inline constexpr const char* RESET         = "\033[0m";
inline constexpr const char* BOLD          = "\033[1m";
inline constexpr const char* DIM           = "\033[2m";
inline constexpr const char* ITALIC        = "\033[3m";
inline constexpr const char* UNDERLINE     = "\033[4m";
inline constexpr const char* BLINK         = "\033[5m";
inline constexpr const char* INVERSE       = "\033[7m";
inline constexpr const char* STRIKETHROUGH = "\033[9m";

// Foreground colors
inline constexpr const char* FG_BLACK      = "\033[30m";
inline constexpr const char* FG_RED        = "\033[31m";
inline constexpr const char* FG_GREEN      = "\033[32m";
inline constexpr const char* FG_YELLOW     = "\033[33m";
inline constexpr const char* FG_BLUE       = "\033[34m";
inline constexpr const char* FG_MAGENTA    = "\033[35m";
inline constexpr const char* FG_CYAN       = "\033[36m";
inline constexpr const char* FG_WHITE      = "\033[37m";

// Bright foreground colors
inline constexpr const char* FG_BRIGHT_BLACK   = "\033[90m";
inline constexpr const char* FG_BRIGHT_RED     = "\033[91m";
inline constexpr const char* FG_BRIGHT_GREEN   = "\033[92m";
inline constexpr const char* FG_BRIGHT_YELLOW  = "\033[93m";
inline constexpr const char* FG_BRIGHT_BLUE    = "\033[94m";
inline constexpr const char* FG_BRIGHT_MAGENTA = "\033[95m";
inline constexpr const char* FG_BRIGHT_CYAN    = "\033[96m";
inline constexpr const char* FG_BRIGHT_WHITE   = "\033[97m";

// Background colors
inline constexpr const char* BG_BLACK      = "\033[40m";
inline constexpr const char* BG_RED        = "\033[41m";
inline constexpr const char* BG_GREEN      = "\033[42m";
inline constexpr const char* BG_YELLOW     = "\033[43m";
inline constexpr const char* BG_BLUE       = "\033[44m";
inline constexpr const char* BG_MAGENTA    = "\033[45m";
inline constexpr const char* BG_CYAN       = "\033[46m";
inline constexpr const char* BG_WHITE      = "\033[47m";

// Bright background colors
inline constexpr const char* BG_BRIGHT_BLACK   = "\033[100m";
inline constexpr const char* BG_BRIGHT_RED     = "\033[101m";
inline constexpr const char* BG_BRIGHT_GREEN   = "\033[102m";
inline constexpr const char* BG_BRIGHT_YELLOW  = "\033[103m";
inline constexpr const char* BG_BRIGHT_BLUE    = "\033[104m";
inline constexpr const char* BG_BRIGHT_MAGENTA = "\033[105m";
inline constexpr const char* BG_BRIGHT_CYAN    = "\033[106m";
inline constexpr const char* BG_BRIGHT_WHITE   = "\033[107m";

// Cursor control
inline constexpr const char* CURSOR_HIDE    = "\033[?25l";
inline constexpr const char* CURSOR_SHOW    = "\033[?25h";
inline constexpr const char* CURSOR_SAVE    = "\033[s";
inline constexpr const char* CURSOR_RESTORE = "\033[u";

// Erase
inline constexpr const char* ERASE_LINE   = "\033[2K";
inline constexpr const char* ERASE_SCREEN = "\033[2J";

// https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
