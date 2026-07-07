#pragma once
#include <conio.h>

enum class Keys {
	None,
	W, S, A, D,
	ArrowUp, ArrowDown, ArrowLeft, ArrowRight,
	Enter, Escape, Backspace, Other
};

namespace KeyCode {
	constexpr int EXTENDED_PREFIX_1 = 0;
	constexpr int EXTENDED_PREFIX_2 = 224;
	constexpr int ARROW_UP = 72;
	constexpr int ARROW_DOWN = 80;
	constexpr int ARROW_LEFT = 75;
	constexpr int ARROW_RIGHT = 77;
	constexpr int ENTER = 13;
	constexpr int ESCAPE = 27;
	constexpr int BACKSPACE = 8;
}

inline int ReadChar() {
	return _getch();
}

inline Keys ReadKey() {
	int ch = _getch();
	if (ch == KeyCode::EXTENDED_PREFIX_1 || ch == KeyCode::EXTENDED_PREFIX_2) {
		int ext = _getch();
		switch (ext) {
			case KeyCode::ARROW_UP: return Keys::ArrowUp;
			case KeyCode::ARROW_DOWN: return Keys::ArrowDown;
			case KeyCode::ARROW_LEFT: return Keys::ArrowLeft;
			case KeyCode::ARROW_RIGHT: return Keys::ArrowRight;
			default: return Keys::Other;
		}
	}
	else {
		if (ch == KeyCode::ENTER) return Keys::Enter;
		if (ch == KeyCode::ESCAPE) return Keys::Escape;
		if (ch == KeyCode::BACKSPACE) return Keys::Backspace;
		unsigned char uc = static_cast<unsigned char>(ch);
		switch (uc) {
			case 'W': case 'w': return Keys::W;
			case 'S': case 's': return Keys::S;
			case 'A': case 'a': return Keys::A;
			case 'D': case 'd': return Keys::D;
			default: return Keys::Other;
		}
	}
}