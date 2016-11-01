#include "sdl_shim.h"
#include "shimmer.h"

#include <stdio.h>


shimmer::shimmer *shim;

int SDL_Init ( Uint32 flags )
{
        SHIM_LOG();
        shim = new shimmer::shimmer();
        return sdl::SDL_Init ( flags );
}

void SDL_Quit()
{
        SHIM_LOG();
        delete shim;
}


SDL_Surface * SDL_SetVideoMode ( int width, int height, int bpp, Uint32 flags )
{
        SHIM_LOG();
        if ( shim->source() ) {
                sdl::SDL_FreeSurface ( shim->source() );
        }
        shim->source ( sdl::SDL_CreateRGBSurface ( flags, width, height, bpp, 0,0,0,0 ) );

        if ( flags & SDL_OPENGL ) {
                printf ( "==> Application requested an OpenGL context.\n" );
        }

        shim->setup_video();
        return shim->source();
}

SDL_Surface * SDL_GetVideoSurface()
{
        SHIM_LOG();
        return shim->source();
}


int SDL_Flip ( SDL_Surface* screen )
{
        SHIM_LOG();
        shim->update_video();
        return 0;
}

void SDL_GL_SwapBuffers()
{
        SHIM_LOG();
        shim->update_video();
}


void SDL_UpdateRect ( SDL_Surface* screen, Sint32 x, Sint32 y, Sint32 w, Sint32 h )
{
        SHIM_LOG();
        sdl::SDL_UpdateRect ( screen, x, y, w, h );
        if ( screen == shim->source() ) {
                SDL_Rect rect = { ( Sint16 ) x, ( Sint16 ) y, ( Sint16 ) w, ( Sint16 ) h};
                shim->update_video ( 1, &rect );
        }
}

void SDL_UpdateRects ( SDL_Surface* screen, int numrects, SDL_Rect* rects )
{
        SHIM_LOG();

        sdl::SDL_UpdateRects ( screen, numrects, rects );
        if ( screen == shim->source() ) {
                shim->update_video ( numrects, rects );
        }
}

int SDL_UpperBlit ( SDL_Surface* src, SDL_Rect* srcrect, SDL_Surface* dst, SDL_Rect* dstrect )
{
        SHIM_LOG();
        int result = sdl::SDL_UpperBlit ( src, srcrect, dst, dstrect );
        if ( dst == shim->source() ) {
                shim->update_video ( 1, dstrect );
        }
        return result;

}

int SDL_LockSurface ( SDL_Surface* surface )
{
        SHIM_LOG();
        return sdl::SDL_LockSurface ( surface );
}

void SDL_UnlockSurface ( SDL_Surface* surface )
{
        SHIM_LOG();
        sdl::SDL_UnlockSurface ( surface );
}

void SDL_FreeSurface ( SDL_Surface* surface )
{
        SHIM_LOG();
        if ( surface == shim->source() ) {
                shim->source ( nullptr );
        }
        sdl::SDL_FreeSurface ( surface );
}

SDL_GrabMode SDL_WM_GrabInput ( SDL_GrabMode mode )
{
        SHIM_LOG();
        return sdl::SDL_WM_GrabInput ( mode );
}

Uint8 SDL_GetMouseState ( int* x, int* y )
{
        SHIM_LOG();
        Uint8 result = sdl::SDL_GetMouseState ( x, y );
        shim->warp_coord ( x, y );
        return result;
}

Uint8 SDL_GetRelativeMouseState ( int* x, int* y )
{
        SHIM_LOG();
        Uint8 result = sdl::SDL_GetRelativeMouseState ( x, y );
        shim->warp_coord ( x, y );
        return result;
}

void SDL_WarpMouse ( Uint16 x, Uint16 y )
{
        SHIM_LOG();
        shim->warp_coord ( &x, &y );
        sdl::SDL_WarpMouse ( x, y );
}

int SDL_PollEvent ( SDL_Event* event )
{
        SHIM_LOG();
        int result = sdl::SDL_PollEvent ( event );
        shim->process_event ( event );
        shim->refresh_video();
        return result;
}

int SDL_SetColorKey ( SDL_Surface* surface, Uint32 flag, Uint32 key )
{
        SHIM_LOG();
        return sdl::SDL_SetColorKey ( surface, flag, key );
}


int SDL_SetAlpha ( SDL_Surface* surface, Uint32 flag, Uint8 alpha )
{
        SHIM_LOG();
        return sdl::SDL_SetAlpha ( surface, flag, alpha );
}

SDL_Surface * SDL_DisplayFormat ( SDL_Surface* surface )
{
        SHIM_LOG();
        return sdl::SDL_DisplayFormat ( surface );
}

SDL_Surface * SDL_CreateRGBSurface ( Uint32 flags, int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask )
{
        SHIM_LOG();
        SDL_Surface *surface = sdl::SDL_CreateRGBSurface ( flags, width, height, depth, Rmask, Gmask, Bmask, Amask );
        return surface;
}

SDL_Surface * SDL_CreateRGBSurfaceFrom ( void* pixels, int width, int height, int depth, int pitch, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask )
{
        SHIM_LOG();
        return sdl::SDL_CreateRGBSurfaceFrom ( pixels, width, height, depth, pitch, Rmask, Gmask, Bmask, Amask );
}

Uint32 SDL_GetTicks()
{
        SHIM_LOG();
        return sdl::SDL_GetTicks();
}

