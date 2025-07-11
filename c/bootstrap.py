#!/usr/bin/env python3
import json
import subprocess
import sys
import os

def find_zig_executable():
    """Find the zig executable in common locations."""
    # Common locations where zig might be installed
    possible_paths = [
        'zig',  # Try PATH first
        '/usr/local/bin/zig',
        '/usr/bin/zig',
        '/opt/zig/zig',  # Common installation path
        os.path.expanduser('~/zig/zig'),
        os.path.expanduser('~/.local/bin/zig'),
        os.path.expanduser('~/.cargo/bin/zig'),  # If installed via cargo
    ]
    
    # Add system-specific paths
    import platform
    system = platform.system().lower()
    
    if system == 'windows':
        possible_paths.extend([
            'C:\\zig\\zig.exe',
            'C:\\Program Files\\zig\\zig.exe',
            os.path.expanduser('~\\zig\\zig.exe'),
        ])
    elif system == 'darwin':  # macOS
        possible_paths.extend([
            '/opt/homebrew/bin/zig',
            '/usr/local/bin/zig',
            os.path.expanduser('~/homebrew/bin/zig'),
        ])
    # Linux paths are already covered above
    
    for path in possible_paths:
        try:
            # Test if the executable exists and is executable
            if os.path.isfile(path) and os.access(path, os.X_OK):
                return path
            # Also try running it to see if it works
            result = subprocess.run([path, '--version'], 
                                  capture_output=True, 
                                  text=True, 
                                  timeout=5)
            if result.returncode == 0:
                return path
        except (subprocess.TimeoutExpired, FileNotFoundError, OSError):
            continue
    
    return None

def get_zig_exe():
    """Run 'zig env' and extract the zig_exe field from the JSON output."""
    # First try to find the zig executable
    zig_path = find_zig_executable()
    if not zig_path:
        print("Error: Could not find zig executable", file=sys.stderr)
        return None
    
    try:
        # Run zig env and capture the output
        result = subprocess.run([zig_path, 'env'], 
                              capture_output=True, 
                              text=True, 
                              check=True)
        
        # Parse the JSON output
        env_data = json.loads(result.stdout)
        
        # Extract and return the zig_exe field
        zig_exe = env_data.get('zig_exe')
        if zig_exe:
            print(zig_exe)
            return zig_exe
        else:
            print("Error: 'zig_exe' field not found in zig env output", file=sys.stderr)
            return None
            
    except subprocess.CalledProcessError as e:
        print(f"Error running '{zig_path} env': {e}", file=sys.stderr)
        return None
    except json.JSONDecodeError as e:
        print(f"Error parsing JSON output: {e}", file=sys.stderr)
        return None
    except Exception as e:
        print(f"Unexpected error: {e}", file=sys.stderr)
        return None

if __name__ == "__main__":
    get_zig_exe()
