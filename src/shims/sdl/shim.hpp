#ifndef SHIMS_SDL_SHIM_H
#define SHIMS_SDL_SHIM_H

#include "shimmer.hpp"
#include "../shim_macros.h"
#include <SDL.h>

extern class::shimmer::shimmer *shimmer_;

SHIM ( int, SDL_Init, Uint32 flags );
SHIM ( void, SDL_Quit, void );

SHIM ( SDL_Surface*, SDL_SetVideoMode, int width, int height, int bpp, Uint32 flags );
SHIM ( SDL_Surface*, SDL_GetVideoSurface, void );
SHIM ( int, SDL_Flip, SDL_Surface* screen );
SHIM ( void, SDL_UpdateRect, SDL_Surface *screen, Sint32 x, Sint32 y, Sint32 w, Sint32 h );
SHIM ( void, SDL_UpdateRects, SDL_Surface *screen, int numrects, SDL_Rect *rects );
SHIM ( int, SDL_UpperBlit, SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect );
SHIM ( int, SDL_FillRect, SDL_Surface *dst, SDL_Rect *dstrect, Uint32 color);
SHIM ( int, SDL_LockSurface, SDL_Surface *surface );
SHIM ( void, SDL_UnlockSurface, SDL_Surface *surface );

SHIM ( void, SDL_FreeSurface, SDL_Surface *surface );

SHIM ( SDL_GrabMode, SDL_WM_GrabInput, SDL_GrabMode mode );

SHIM ( void, SDL_GL_SwapBuffers, void );

SHIM ( int, SDL_SetColorKey ,SDL_Surface *surface, Uint32 flag, Uint32 key );
SHIM ( int, SDL_SetAlpha, SDL_Surface *surface, Uint32 flag, Uint8 alpha );

SHIM ( SDL_Surface*, SDL_DisplayFormat, SDL_Surface *surface );
SHIM ( SDL_Surface*, SDL_CreateRGBSurface, Uint32 flags, int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask );
SHIM ( SDL_Surface*, SDL_CreateRGBSurfaceFrom, void *pixels, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask );

SHIM ( Uint32, SDL_GetTicks, void );

SHIM ( Uint32, SDL_MapRGB, const SDL_PixelFormat* format, Uint8 r, Uint8 g, Uint8 b);

#endif