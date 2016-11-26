#include "glsl_variable.hpp"
#include <algorithm>

const std::unordered_map<std::string, enum shimmer::glsl_variable::type> shimmer::glsl_variable::_type_from_str_map = {
        {"bool", shimmer::glsl_variable::type::BOOL},
        {"int", shimmer::glsl_variable::type::INT},
        {"uint", shimmer::glsl_variable::type::UINT},
        {"float", shimmer::glsl_variable::type::FLOAT},
        {"double", shimmer::glsl_variable::type::DOUBLE},

        {"bvec2", shimmer::glsl_variable::type::BVEC2},
        {"bvec3", shimmer::glsl_variable::type::BVEC3},
        {"bvec4", shimmer::glsl_variable::type::BVEC4},

        {"ivec2", shimmer::glsl_variable::type::IVEC2},
        {"ivec3", shimmer::glsl_variable::type::IVEC3},
        {"ivec4", shimmer::glsl_variable::type::IVEC4},

        {"uvec2", shimmer::glsl_variable::type::UVEC2},
        {"uvec3", shimmer::glsl_variable::type::UVEC3},
        {"uvec4", shimmer::glsl_variable::type::UVEC4},

        {"vec2", shimmer::glsl_variable::type::VEC2},
        {"vec3", shimmer::glsl_variable::type::VEC3},
        {"vec4", shimmer::glsl_variable::type::VEC4},

        {"dvec2", shimmer::glsl_variable::type::DVEC2},
        {"dvec3", shimmer::glsl_variable::type::DVEC3},
        {"dvec4", shimmer::glsl_variable::type::DVEC4},

        {"sampler1D", shimmer::glsl_variable::type::SAMPLER1D},
        {"sampler2D", shimmer::glsl_variable::type::SAMPLER2D},
        {"sampler3D", shimmer::glsl_variable::type::SAMPLER3D},

        {"isampler1D", shimmer::glsl_variable::type::ISAMPLER1D},
        {"isampler2D", shimmer::glsl_variable::type::ISAMPLER2D},
        {"isampler3D", shimmer::glsl_variable::type::ISAMPLER3D},

        {"usampler1D", shimmer::glsl_variable::type::USAMPLER1D},
        {"usampler2D", shimmer::glsl_variable::type::USAMPLER2D},
        {"usampler3D", shimmer::glsl_variable::type::USAMPLER3D},

        {"mat2", shimmer::glsl_variable::type::MAT2},
        {"mat3", shimmer::glsl_variable::type::MAT3},
        {"mat4", shimmer::glsl_variable::type::MAT4},

        {"mat2x3", shimmer::glsl_variable::type::MAT2X3},
        {"mat3x2", shimmer::glsl_variable::type::MAT3X2},

        {"mat2x4", shimmer::glsl_variable::type::MAT2X4},
        {"mat4x2", shimmer::glsl_variable::type::MAT4X2},

        {"mat3x4", shimmer::glsl_variable::type::MAT3X4},
        {"mat4x3", shimmer::glsl_variable::type::MAT4X3}
};

shimmer::glsl_variable::glsl_variable()
        : _size ( 1 ), _name(), _location ( -1 )
{}

shimmer::glsl_variable::glsl_variable ( enum qualifier qualifier, enum type type, const std::string& name )
        : _qualifier ( qualifier ), _type ( type ), _size ( 1 ), _name ( name ), _location ( -1 )
{}

shimmer::glsl_variable::glsl_variable ( enum qualifier qualifier, enum type type, unsigned int size, const std::string& name )
        : _qualifier ( qualifier ), _type ( type ), _size ( size ), _name ( name ), _location ( -1 )
{}

shimmer::glsl_variable::~glsl_variable()
{}

enum shimmer::glsl_variable::qualifier shimmer::glsl_variable::qualifier_from ( const std::string& str )
{
        if ( str.compare ( "uniform" ) == 0 ) {
                return qualifier::UNIFORM;
        } else if ( str.compare ( "attribute" ) == 0 ) {
                return qualifier::ATTRIBUTE;
        } else if ( str.compare ( "varying" ) == 0 ) {
                return qualifier::VARYING;
        }
        return qualifier::UNKNOWN;
}

enum shimmer::glsl_variable::type shimmer::glsl_variable::type_from ( const std::string& str )
{
        if ( _type_from_str_map.find ( str ) != _type_from_str_map.end() ) {
                return _type_from_str_map.at ( str );
        }
        return type::UNKNOWN;
}

std::string shimmer::glsl_variable::str_from ( enum qualifier qualifier )
{
        switch ( qualifier ) {
        case qualifier::ATTRIBUTE:
                return "attribute";
        case qualifier::UNIFORM:
                return "uniform";
        case qualifier::VARYING:
                return "varying";
        default:
                return "unknown";
        }
}

std::string shimmer::glsl_variable::str_from ( enum type type )
{
        for ( auto it = _type_from_str_map.begin(); it != _type_from_str_map.end(); it++ ) {
                if ( it->second == type ) {
                        return it->first;
                }
        }
        return "unknown";
}
