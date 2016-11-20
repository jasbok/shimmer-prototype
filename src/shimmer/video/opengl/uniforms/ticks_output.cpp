#include "ticks_output.hpp"
#include <chrono>
#include <stdio.h>

shimmer::ticks_output::ticks_output ( GLint location )
{
        uniform_output::location ( location );
}

shimmer::ticks_output::~ticks_output()
{}

void shimmer::ticks_output::process()
{
        using namespace std::chrono;
        auto ticks = std::chrono::duration_cast< milliseconds > (
                             system_clock::now().time_since_epoch()
                     ).count();
        glUniform1ui(uniform_output::location(), ticks);
}
