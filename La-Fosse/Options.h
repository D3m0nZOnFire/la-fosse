#pragma once

struct Options {
    bool showTypeHints = true;

    static Options& get() {
        static Options instance;
        return instance;
    }

private:
    Options() = default;
};
