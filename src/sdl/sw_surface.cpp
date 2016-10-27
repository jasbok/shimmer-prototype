#include "sw_surface.h"
#include "sw_scaler.h"
#include "sdl_shim.h"
sw_surface::sw_surface ( SDL_Surface* source, SDL_Surface* target )
        : _source ( source ) , _target ( target )
{}

sw_surface::~sw_surface()
{}


SDL_Surface * sw_surface::source()
{
        return _source;
}

void sw_surface::source ( SDL_Surface* source )
{
        _source = source;
}

SDL_Surface * sw_surface::target()
{

        return _target;
}

void sw_surface::target ( SDL_Surface* target )
{
        _target = target;
}

void sw_surface::update()
{
        if ( SDL_MUSTLOCK ( _target ) ) sdl::SDL_LockSurface ( _target );
        sw_scaler_nn ( _source, _target );
        if ( SDL_MUSTLOCK ( _target ) ) sdl::SDL_UnlockSurface ( _target );
        sdl::SDL_Flip ( _target );
}





