/*============================================================================================+
 | Game System (GS) Library                                                                   |
 |--------------------------------------------------------------------------------------------|
 | FILES: gs_demo.cpp, gs_demo.h                                                              |
 |--------------------------------------------------------------------------------------------|
 | CLASS: GS_Demo                                                                             |
 |--------------------------------------------------------------------------------------------|
 | ABOUT: ...                                                                                 |
 |--------------------------------------------------------------------------------------------|
 |                                                                                    08/2003 |
 +============================================================================================*/

#ifndef GS_DEMO_H
#define GS_DEMO_H

//================================================================================================
// Include Game System (GS) header files.
// -----------------------------------------------------------------------------------------------
#include "gs_main.h"
//================================================================================================

//================================================================================================
// Include standard C library header files.
// -----------------------------------------------------------------------------------------------
#include <math.h>
#include <stdio.h>
#include <time.h>
//================================================================================================

//==============================================================================================
// Game defines.
// ---------------------------------------------------------------------------------------------
#define GAME_VERSION "1.2.4"
#define SETTINGS_FILE "settings.ini"
#define HISCORES_FILE "hiscores.ini"
// ---------------------------------------------------------------------------------------------
#define INTERNAL_RES_X 960
#define INTERNAL_RES_Y 540
// ---------------------------------------------------------------------------------------------
#define DEFAULT_WIDTH 960
#define DEFAULT_HEIGHT 540
#define DEFAULT_DEPTH 32
#define DEFAULT_MODE 1
#define DEFAULT_VSYNC 0
#define DEFAULT_ALIAS 0
#define DEFAULT_MUSIC 255
#define DEFAULT_SOUND 255
// ---------------------------------------------------------------------------------------------
#define GAME_INTRO 0
#define GAME_OUTRO 1
#define TITLE_INTRO 2
#define TITLE_SCREEN 3
#define TITLE_OUTRO 4
#define OPTION_INTRO 5
#define OPTION_SCREEN 6
#define OPTION_OUTRO 7
#define PLAY_INTRO 8
#define PLAY_GAME 9
#define PLAY_UPDATE 10
#define PLAY_PAUSE 11
#define PLAY_EXIT 12
#define PLAY_OUTRO 13
#define SCORES_INTRO 14
#define SCORES_VIEW 15
#define SCORES_ADD 16
#define SCORES_OUTRO 17
// ---------------------------------------------------------------------------------------------
#define MAX_SCORES 10
// ---------------------------------------------------------------------------------------------
#define MUSIC_TITLE 0
#define MUSIC_GAME 1
// ---------------------------------------------------------------------------------------------
#define SAMPLE_OPTION 0
#define SAMPLE_SELECT 1
//==============================================================================================

//==============================================================================================
// Game structures.
// ---------------------------------------------------------------------------------------------
typedef struct GS_SETTINGS
{
    int nDisplayWidth;    // The width (in pixels) of the display area.
    int nDisplayHeight;   // The height (in pixels) of the display area.
    int nColorDepth;      // The color depth of the display (8, 16, 24 or 32).
    BOOL bWindowedMode;   // Wether game is in fullscreen or windowed mode.
    BOOL bEnableVSync;    // Wether to syncronize rendering with refresh rate.
    BOOL bEnableAliasing; // Wether to enable anti-aliasing or not.
    int nMusicVolume;     // The volume of the music (0-255).
    int nEffectsVolume;   // The volume of the sound effects (0-255).
} GS_Settings;
// ---------------------------------------------------------------------------------------------
typedef struct GS_HISCORES
{
    char szName[11];
    long lScore;
} GS_Hiscores;
//==============================================================================================

////////////////////////////////////////////////////////////////////////////////////////////////
// Class Definition. ///////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

class GS_Demo : public GS_Application
{

private:
    GS_Settings m_gsSettings; // Option settings.

    GS_Keyboard m_gsKeyboard;     // Keyboard object.
    GS_Mouse m_gsMouse;           // Mouse object.
    GS_Controller m_gsController; // Controller object.

    GS_OGLDisplay m_gsDisplay; // OpenGL display object.
    GS_FmodSound m_gsSound;    // FMOD sound object.

    GS_Timer m_gsTimer; // Timer object.

    GS_OGLSprite m_gsBackSprite;   // Sprite used for the game background.
    GS_OGLSprite m_gsCursorSprite; // Sprite used for the mouse cursor.
    GS_OGLSprite m_gsTileSprite;   // Sprite used for tile background.
    GS_OGLSprite m_gsTitleSprite;  // Sprite used for the title.

    GS_OGLTexture m_gsFontTexture; // Texture used to create the font end menu.
    GS_OGLFont m_gsFont;           // Game font.
    GS_OGLMenu m_gsMenu;           // Game menu.

    GS_OGLCollide m_gsCollide; // Object for collision detection.

    RECT m_rcScreen;         // Screen coordinates for rendering tiles.
    bool m_bKeepAspectRatio; // Whether to keep the aspect ratio for up/down scaling

    int m_nGameProgress; // Keeps track of the game progress.
    int m_nPrevProgress; // Previous stage.
    int m_nNextProgress; // Next stage.

    BOOL m_bIsInitialized;    // Has a method been initialized?
    BOOL m_bWasKeyReleased;   // Wether a key has been released.
    BOOL m_bWasMouseReleased; // Wether the left mouse button was released.
    int m_nOldMouseX;         // Previous mouse x coordinate.
    int m_nOldMouseY;         // Previous mouse y coordinate.
    int m_nOptionSelected;    // Which menu option was selected.
    int m_nCounter;           // Used for counting throughout the game.

    float m_fInterval; // Used for game timing.
    float m_fRotate;   // Used for rotation effects.
    float m_fScale;    // Used for scale effects.
    float m_fAlpha;    // Transparency for fade effects.

    GS_OGLColor m_gsMenuTextColor; // Normal menu text color.
    GS_OGLColor m_gsMenuHighColor; // Menu highlight text color.

    GS_Hiscores m_gsHiscores[MAX_SCORES]; // Hiscores.

    long m_lScore;     // Keeps track of the game score.
    int m_nScoreIndex; // Keeps track of the last score.

protected:
    // Methods that override base class methods.
    BOOL GameInit();
    BOOL GameShutdown();
    BOOL GameRelease();
    BOOL GameRestore();
    BOOL GameLoop();
    void OnChangeMode();

public:
    // The constuctor & destructor.
    GS_Demo();
    ~GS_Demo();

    // Message procedure that override the base class message procedure.
    LRESULT MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    // Game setup methods.
    BOOL GameSetup();

    // Game progress methods.
    BOOL GameIntro();
    BOOL GameOutro();

    BOOL TitleIntro();
    BOOL TitleScreen();
    BOOL TitleOutro();

    BOOL OptionIntro();
    BOOL OptionScreen();
    BOOL OptionOutro();

    BOOL PlayIntro();
    BOOL PlayGame();
    BOOL PlayUpdate();
    BOOL PlayPause();
    BOOL PlayExit();
    BOOL PlayOutro();

    BOOL ScoresIntro();
    BOOL ScoresView();
    BOOL ScoresAdd();
    BOOL ScoresOutro();

    // Methods for loading and saving data.
    BOOL LoadSettings();
    BOOL SaveSettings();
    BOOL LoadHiscores();
    BOOL SaveHiscores();

    // Helper methods.
    void RenderBackground(float fAlpha = 1.0f);
    void RenderCursor(float fAlpha = 1.0f);
    void RenderFrameRate(float fAlpha = 1.0f);
    void SetRenderScaling(int nWidth, int nHeight, bool bKeepAspect);
    float GetActionInterval(float fActionsPerSecond);
};

////////////////////////////////////////////////////////////////////////////////////////////////

#endif
