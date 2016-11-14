#ifndef SHIMMER_VIDEO_OPENGL_QUAD_HPP
#define SHIMMER_VIDEO_OPENGL_QUAD_HPP

#include "shader.hpp"
#include "texture.hpp"
#include "../../common/types.hpp"
#include <GL/glew.h>

namespace shimmer
{
class quad
{
public:
        quad ();
        quad ( const dimensions<GLfloat>& ratio );
        virtual ~quad();

        void shape ( const dimensions<GLfloat>& ratio );
        void render ();
        void bind (const shader* shader);
private:
        GLuint _vbo;
        GLuint _vao;
        const shader* _shader;
private:
        void _setup_vertex_attribs();
};
}

#endif