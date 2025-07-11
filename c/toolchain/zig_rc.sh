#!/bin/sh

# Find zig executable
find_zig() {
    # Common locations where zig might be installed
    local paths="zig /usr/local/bin/zig /usr/bin/zig /opt/zig/zig $HOME/zig/zig $HOME/.local/bin/zig $HOME/.cargo/bin/zig"
    
    # Add system-specific paths
    case "$(uname -s)" in
        Darwin*)  # macOS
            paths="$paths /opt/homebrew/bin/zig $HOME/homebrew/bin/zig"
            ;;
        MINGW*|MSYS*|CYGWIN*)  # Windows
            paths="$paths /c/zig/zig.exe /c/Program\ Files/zig/zig.exe $HOME/zig/zig.exe"
            ;;
        Linux*)  # Linux - already covered above
            ;;
    esac
    
    for path in $paths; do
        if [ -x "$path" ] || command -v "$path" >/dev/null 2>&1; then
            echo "$path"
            return 0
        fi
    done
    return 1
}

ZIG_EXE=$(find_zig)
if [ $? -ne 0 ]; then
    echo "Error: Could not find zig executable" >&2
    exit 1
fi

"$ZIG_EXE" rc "$@"
