# GameSystem Template Project

A complete project template for creating 2D/3D games using the GameSystem (GS) Library - a cross-platform game development framework built with OpenGL and SDL2.

## Description

This template provides a ready-to-use foundation for developing games with the GameSystem library. It includes a complete game structure with menu systems, settings management, high score tracking, and example game states that you can customize for your own game.

The template demonstrates best practices for:
- Game state management (intro, menu, gameplay, pause, game over)
- Settings persistence (display and audio configuration)
- High score tracking and player name entry
- Menu system with keyboard and mouse input
- 2D sprite rendering with effects (rotation, scaling, transparency)
- Background scrolling and tile rendering
- Audio playback (music and sound effects)
- Frame rate management

### Template Features

The included template game structure provides:

1. **Game Intro/Outro** - Company logo display with fade effects
2. **Title Screen** - Main menu with options (Play, High Scores, Options, Quit)
3. **Options Menu** - Display settings (fullscreen/windowed, VSync) and audio controls
4. **Difficulty Selection** - Pre-game difficulty menu (Beginner, Intermediate, Expert)
5. **Gameplay** - Template game loop with scoring and pause functionality
6. **Pause Screen** - Game pause state with resume option
7. **Exit Confirmation** - Yes/No dialog when exiting during gameplay
8. **Game Over** - End game screen with score display
9. **High Scores** - View top 10 scores with player names
10. **High Score Entry** - Interactive name entry system for new high scores
11. **Settings Persistence** - INI file-based configuration storage

### Interactive Controls

- **Space** - Advance through menus / End game
- **P** - Pause/Resume during gameplay
- **ESC** - Back/Cancel/Quit
- **Arrow Keys** - Navigate menus, control gameplay
- **Enter** - Select menu option / Confirm
- **Home** - Reset settings (context-dependent)
- **F1-F5** - Quick resolution change (320x240, 400x300, 640x480, 800x600, 1024x768)
- **1-5** - Play sound samples (for testing audio)
- **+/-** - Adjust master volume
- **M** - Mute/Unmute music
- **S** - Mute/Unmute sound effects
- **B** - Toggle blending (transparency)
- **L** - Toggle lighting (OpenGL lighting)
- **V** - Toggle VSync
- **T** - Toggle frame rate cap (turbo mode)

## Tech Stack

### Core Technologies
- **C++** (C++98/C++11 compatible)
- **OpenGL 2.1** - Fixed-function pipeline graphics
- **SDL2** - Cross-platform window management and input
- **SDL2_mixer** - Audio playback (music and sound effects)

### Build System
- **CMake 3.10+** - Cross-platform build configuration
- **GCC/Clang/MSVC** - Compiler support

### Platform Abstraction Layer
The `gs_platform.*` files provide seamless compatibility between Windows API and SDL2, allowing the same codebase to compile on multiple platforms with minimal changes.

## File Structure

### Core Framework Files
```
gs_app.cpp/h              - Application framework and main loop
gs_main.cpp/h             - Entry point (WinMain/main)
gs_platform.cpp/h         - Platform abstraction (Windows/SDL2)
gs_demo.cpp/h             - Template game implementation
```

### Game System Library Components
```
gs_error.cpp/h            - Error reporting and logging
gs_file.cpp/h             - File I/O with cross-platform paths
gs_ini_file.cpp/h         - INI file parsing
gs_keyboard.cpp/h         - Keyboard input handling
gs_mouse.cpp/h            - Mouse input and cursor management
gs_object.cpp/h           - Base object class
gs_timer.cpp/h            - Frame timing and FPS monitoring
```

### OpenGL Rendering System
```
gs_ogl_collide.cpp/h      - 2D collision detection
gs_ogl_display.cpp/h      - OpenGL context and rendering setup
gs_ogl_font.cpp/h         - Bitmap font rendering
gs_ogl_image.cpp/h        - TGA/PCX image loading
gs_ogl_map.cpp/h          - Tile-based map system
gs_ogl_menu.cpp/h         - Interactive menu system
gs_ogl_particle.cpp/h     - Particle effects
gs_ogl_sprite.cpp/h       - Basic sprite rendering
gs_ogl_sprite_ex.cpp/h    - Animated sprite rendering
gs_ogl_texture.cpp/h      - Texture loading and management
gs_ogl_color.cpp/h        - Color utilities
```

### Audio System
```
gs_sdl_mixer_sound.cpp/h  - SDL2_mixer implementation (recommended)
gs_fmod_sound.cpp/h       - FMOD implementation (legacy, optional)
```

### Configuration & Resources
```
gs_resource.h             - Resource ID definitions
settings.ini              - Display and audio settings
hiscores.ini              - High score data
data/                     - Game assets (textures, sounds, maps)
```

## Platform Support

### Windows

#### Prerequisites
- Visual Studio 2017+ or MinGW-w64
- CMake 3.10+
- SDL2 development libraries
- SDL2_mixer development libraries

#### Building with Visual Studio + vcpkg
```cmd
vcpkg install sdl2:x64-windows sdl2-mixer:x64-windows
mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=[vcpkg]/scripts/buildsystems/vcpkg.cmake
cmake --build . --config Release
```

#### Building with MinGW/MSYS2
```bash
# Install MSYS2 from https://www.msys2.org/
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake \
          mingw-w64-x86_64-SDL2 mingw-w64-x86_64-SDL2_mixer \
          mingw-w64-x86_64-make

mkdir build && cd build
cmake .. -G "MinGW Makefiles"
mingw32-make -j$(nproc)
```

#### Running
```cmd
cd build
Demo.exe
```

### Linux

#### Prerequisites
```bash
# Ubuntu/Debian
sudo apt-get install build-essential cmake libsdl2-dev libsdl2-mixer-dev \
                     libgl1-mesa-dev libglu1-mesa-dev

# Fedora/RHEL
sudo dnf install gcc-c++ cmake SDL2-devel SDL2_mixer-devel \
                 mesa-libGL-devel mesa-libGLU-devel

# Arch Linux
sudo pacman -S base-devel cmake sdl2 sdl2_mixer mesa
```

#### Building
```bash
chmod +x build.sh
./build.sh
```

Or manually:
```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
```

#### Running
```bash
./build/Demo
```

### macOS

#### Prerequisites
```bash
# Install Homebrew if not already installed
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Install dependencies
brew install cmake pkg-config sdl2 sdl2_mixer
```

#### Building
```bash
chmod +x build_macos.sh
./build_macos.sh
```

Or manually:
```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -j$(sysctl -n hw.ncpu)
cd ..
```

#### Running
```bash
open build/Demo.app
```

Or from Finder, navigate to the `build` directory and double-click `Demo.app`.

## Automated Builds & Releases

`.github/workflows/release.yml` builds Linux, macOS, and Windows binaries automatically on every push of a `v*` tag (e.g. `v1.0.0`), or on a manual run from the Actions tab (`workflow_dispatch`). Each platform's build is attached to a GitHub Release as a ready-to-run download — no compiler, SDK, or dev libraries required on the end user's machine.

### What each platform produces

| Platform | Artifact | How it's made self-contained |
|---|---|---|
| Linux | `Demo-linux-x86_64.AppImage` (single file) | [`linuxdeploy`](https://github.com/linuxdeploy/linuxdeploy) bundles SDL2/SDL2_mixer and their full transitive dependency chain (FLAC, mpg123, opus, vorbis, ~25 libs total) into the AppImage |
| macOS | `Demo-macOS.zip` (contains `Demo.app`) | [`dylibbundler`](https://github.com/auriamg/macdylibbundler) copies Homebrew's SDL2/SDL2_mixer dylibs into `Demo.app/Contents/Frameworks` and rewrites the executable's load paths, so it doesn't depend on Homebrew being installed |
| Windows | `Demo-windows-x64.zip` (contains `Demo.exe` + DLLs) | Built via vcpkg's dynamic `x64-windows` triplet; every DLL vcpkg produces is copied next to `Demo.exe` so nothing needs to be installed separately |

Each platform job also runs an automated smoke test (headless via Xvfb on Linux, a real launch-and-check on macOS, `Start-Process` on Windows) before uploading its artifact, to catch a build that compiles but doesn't actually run.

### Why macOS also bundles `libSDL3.dylib`

Homebrew's `sdl2` formula is actually [`sdl2-compat`](https://github.com/libsdl-org/sdl2-compat) — a thin compatibility shim that implements the SDL2 API on top of the real SDL3 library, loaded at runtime via `dlopen()` rather than a normal linked dependency. `dylibbundler` only follows `otool -L` dependencies, so it never bundles SDL3, and the resulting app fails on launch with `Failed loading SDL3 library.` on any machine that doesn't happen to have Homebrew's SDL3 installed. sdl2-compat's dlopen search (visible in its own binary's embedded strings) includes `@loader_path/libSDL3.dylib` — i.e. right next to `libSDL2`, which is exactly where `dylibbundler` places things — so the workflow copies it there explicitly after the normal bundling step. Confirmed by reproducing the crash locally (installing `sdl2-compat`/`sdl3` via Homebrew and launching the bundled, unfixed app) and then confirming the fix resolves it.

### Cutting a release

```bash
git tag v1.0.0
git push origin v1.0.0
```

This triggers all three builds; once they finish, the release (with all three files attached) appears automatically on the repo's Releases page.

### Unsigned binaries

None of these builds are code-signed (that requires a paid Apple Developer ID / Microsoft certificate), so:
- **macOS**: Gatekeeper will say the app is from an "unidentified developer" — right-click → Open the first time.
- **Windows**: SmartScreen will show a warning — click "More info" → "Run anyway".

This is normal for free/indie-distributed builds and doesn't indicate a problem with the download.

### Why Windows uses dynamic linking (not a single static .exe)

An earlier version of this workflow tried statically linking SDL2/SDL2_mixer via vcpkg's `x64-windows-static` triplet, for a single self-contained `.exe` with no DLLs at all. That failed at link time: SDL2_mixer's static library pulls in a long, version-dependent chain of optional codec libraries (FLAC, mpg123, opus, vorbis, wavpack, ...) that are only exposed via pkg-config's `Libs.private`, which the CMakeLists.txt here doesn't request. Dynamic linking (the current approach) sidesteps this entirely and mirrors the same "bundle whatever the tool produces" strategy already used for Linux and macOS.

### Why `pkg-config` comes from vcpkg, not Chocolatey

The Windows job originally installed `pkg-config` via `choco install pkgconfiglite`, which downloads from a SourceForge mirror -- one that's become unreliable (404s / reset connections), causing intermittent CI failures unrelated to anything in this repo. Since the job already depends on vcpkg for SDL2/SDL2_mixer, it now installs vcpkg's own `pkgconf` port instead, removing that third-party dependency entirely. vcpkg's port only produces `pkgconf.exe` (no `pkg-config` alias), so the workflow copies it to both names, since which one CMake's `FindPkgConfig` looks for has varied across CMake versions.

### The Windows platform abstraction bridge

Getting a real Windows build working also required finishing `gs_platform.h`/`gs_platform.cpp`'s native Win32 implementations — `GS_Platform::GetTickCount`, `Sleep`, `GetClientRect`, `SetRect`, `PtInRect`, `OutputDebugString`, `MessageBox`, `GetCurrentDirectory`, and `NormalizePath` previously had no Windows-side implementation at all (only the SDL/non-Windows branch was ever finished), so any Windows build — MSVC or MinGW — would have failed to link the moment those functions were actually called. If you add new `GS_Platform` functions, make sure both the `#ifdef GS_PLATFORM_WINDOWS` and non-Windows branches in `gs_platform.cpp` are implemented, not just one.

One subtlety worth knowing if you touch this file: `windows.h` `#define`s several of these names to their `A`-suffixed forms (`OutputDebugStringA`, `MessageBoxA`, `GetCurrentDirectoryA`), and since the call sites are namespace-qualified (`GS_Platform::OutputDebugString(...)`), that macro substitution applies to the declaration and definition too — so the Windows implementations are written under the same (post-macro-expansion) names, explicitly calling through to the real global function via `::`.

### Why `add_executable()` needs the `WIN32` keyword

`gs_main.cpp` defines `WinMain` on Windows (a native Win32 GUI entry point) rather than `main`. CMake's `add_executable(Demo ${SOURCES})` defaults to the console subsystem, whose CRT startup expects `main` — without the `WIN32` keyword, MSVC fails to link with `unresolved external symbol main`. `add_executable(Demo WIN32 ${SOURCES})` fixes this by selecting the GUI subsystem instead. This is a documented no-op on non-Windows platforms, so it doesn't affect the Linux/macOS builds. (GCC/mingw doesn't have this problem — its linker auto-selects the console vs. GUI CRT startup stub based on which entry symbol is actually defined, which is why a manual mingw-w64 cross-compile can succeed even without this keyword, while MSVC strictly requires it.)

## Platform Differences

### Windows-Specific Features

The Windows build includes additional features not available on SDL2 platforms:

- **Menu Bar** - Access to display settings, sound controls, and program options
- **Accelerator Keys** - Alt+X to quit, Alt+Enter to toggle fullscreen
- **Native Window Chrome** - Standard Windows title bar and controls

### SDL2 Platforms (Linux/macOS)

SDL2 builds use keyboard-only controls since native menu bars aren't supported. All functionality is available via keyboard shortcuts (see Interactive Controls section above).

## Configuration

### Display Settings (settings.ini)
```ini
[Display]
DisplayWidth=960        ; Window width (internal resolution is 960x540)
DisplayHeight=540       ; Window height
ColorDepth=32          ; Bits per pixel
WindowMode=1           ; 0=Fullscreen, 1=Windowed
EnableVSync=0          ; 0=Disabled, 1=Enabled
EnableAliasing=0       ; 0=Disabled, 1=Enabled
```

### Audio Settings
```ini
[Sound]
MusicVolume=255        ; 0-255 (default: 255)
EffectsVolume=255      ; 0-255 (default: 255)
```

### High Scores (hiscores.ini)
```ini
[Score0]
Name=PLAYER.1..
Score=500000
```

## Using This Template

### Quick Start

1. **Clone or download this template**
2. **Rename the project** - Update `CMakeLists.txt` project name
3. **Replace template assets** - Add your game graphics and sounds to `data/`
4. **Customize game logic** - Modify `gs_demo.cpp` game states
5. **Build and run** - Follow platform-specific build instructions

### Creating Your Game

#### 1. Customize Game States

The template uses a state machine in `GameLoop()`. Modify these methods in `gs_demo.cpp`:

```cpp
BOOL GS_Demo::PlayGame() {
    // Replace template game logic with your gameplay
    // Handle player input
    // Update game objects
    // Check win/lose conditions
    // Render your game
}
```

#### 2. Replace Template Assets

Update files in the `data/` directory:
- `image_01.pcx` - Background image
- `image_02.tga` - Tile texture
- `image_03.tga` - Title screen graphic
- `cursor_01.tga` - Mouse cursor
- `menu_01.tga` - Menu background
- `font_01.tga` - Bitmap font texture
- `music_01.mp3` - Title music
- `music_02.mp3` - Gameplay music
- `sound_01.wav` - Menu sound effect
- `sound_02.wav` - Selection sound effect

#### 3. Modify Constants

Update game constants in `gs_demo.h`:

```cpp
#define GAME_VERSION  "1.0.0"     // Your game version
#define INTERNAL_RES_X 960        // Internal rendering width
#define INTERNAL_RES_Y 540        // Internal rendering height
#define MAX_SCORES 10             // Number of high scores to track
```

#### 4. Add Custom Classes

Create new game object classes:
- Inherit from `GS_Object` for base functionality
- Use `GS_OGLSprite` or `GS_OGLSpriteEx` for visual objects
- Use `GS_OGLCollide` for collision detection

#### 5. Implement Game Logic

Key areas to customize:
- **PlayIntro()** - Pre-game setup and difficulty selection
- **PlayGame()** - Main gameplay loop
- **PlayUpdate()** - Level transitions or game updates
- **PlayPause()** - Pause screen (already implemented)
- **PlayExit()** - Exit confirmation (already implemented)
- **PlayOutro()** - Game over sequence (already implemented)

### Example: Adding a New Game Object

```cpp
// In your game class
class MyGameObject {
    GS_OGLSprite sprite;
    float x, y;
    float velocityX, velocityY;
    
public:
    void Create(const char* imagePath) {
        sprite.Create(imagePath);
    }
    
    void Update(float deltaTime) {
        x += velocityX * deltaTime;
        y += velocityY * deltaTime;
        sprite.SetDestXY(x, y);
    }
    
    void Render() {
        sprite.Render();
    }
};
```

## Architecture

### Design Patterns
- **State Machine** - Game progress managed via state enumeration
- **Inheritance-based framework** - Extend `GS_Application`
- **Platform abstraction** - Single codebase, multiple platforms
- **Object-oriented OpenGL** - C++ wrappers around OpenGL
- **Resource management** - Automatic texture/sprite cleanup

### Rendering Pipeline
1. `BeginRender2D()` - Set up 2D orthographic projection
2. Render sprites, fonts, particles, maps
3. `EndRender2D()` - Restore 3D projection (if needed)
4. `SwapBuffers()` - Display frame

### Game Loop Structure
```
GameInit() → GameLoop() → GameShutdown()
              ↓
    [State-based method calls]
              ↓
         Render frame
              ↓
    Check for state transition
```

## Best Practices

### Resource Management
- Create all textures/sprites in `GameInit()`
- Destroy them implicitly (automatic cleanup) or explicitly in `GameShutdown()`
- Use INI files for persistent settings

### Performance
- Use `GetActionInterval()` for frame-rate independent timing
- Enable VSync for smooth animation (or cap frame rate)
- Profile with frame rate display (`RenderFrameRate()`)

### Input Handling
- Use `m_gsKeyboard.GetBufferedKey()` for menu navigation
- Use `m_gsKeyboard.IsKeyPressed()` for continuous input
- Implement key release detection to prevent double-triggering

### Audio
- Use streams for music (MP3 format recommended)
- Use samples for sound effects (WAV format)
- Remember to stop/pause audio during state transitions

## Troubleshooting

### Linux: "Failed to initialize SDL"
- Ensure SDL2 packages are installed
- Check X11/Wayland is running

### macOS: "Library not loaded"
- Verify SDL2 frameworks are in the correct path
- Use `install_name_tool` if needed

### Windows: "Cannot find SDL2.dll"
- Copy SDL2.dll and SDL2_mixer.dll to executable directory

### Performance Issues
- Disable VSync (press 'V')
- Reduce resolution (F1-F5 keys)
- Check GPU drivers are up to date

### Asset Loading Failures
- Verify file paths are relative to executable location
- Check `data/` directory exists and contains required files
- Ensure image formats are correct (TGA/PCX for sprites)

## Template Version History

_The current version number is set by `GAME_VERSION` in [`gs_demo.h`](gs_demo.h)._

**v1.2.6** (Current)
- Fixed Windows builds failing to play MP3 music ("Unrecognized audio format") by enabling vcpkg's mpg123 codec feature

**v1.2.5**
- Fixed ini/hiscore files not loading or saving when launched from a directory other than the executable's own

**v1.2.4**
- Fixed real Windows build failures (missing native Win32 GS_Platform bridge, missing WIN32 subsystem keyword)
- Fixed macOS release builds crashing with "Failed loading SDL3 library" (Homebrew's sdl2-compat shim)
- Automated cross-platform release builds via GitHub Actions

**v1.2.2**
- Complete game template with all core systems
- Cross-platform support via SDL2
- CMake build system
- Aspect-ratio preserving scaling
- INI-based settings and high score persistence

## Learn More About GameSystem

This template showcases the GameSystem library's capabilities:
- Complete game framework with state management
- Cross-platform compatibility (Windows, Linux, macOS)
- OpenGL rendering abstraction
- Input handling (keyboard/mouse)
- Audio playback (music and sound effects)
- Collision detection
- Resource management
- Menu systems
- Settings persistence
- High score tracking

Perfect for creating 2D games, educational projects, and retro-style game development!

## License

This template is provided as-is for creating GameSystem-based games.

Libraries used:
- **SDL2** - zlib License
- **SDL2_mixer** - zlib License
- **OpenGL** - Vendor-specific implementations

## Getting Help

When developing your game:
1. Review the template code to understand the structure
2. Examine the GameSystem library headers for available features
3. Modify incrementally and test frequently
4. Keep settings.ini and hiscores.ini in the same directory as your executable

Good luck with your game development!

