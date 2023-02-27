#version 450                          
layout (location = 0) in vec3 vPos;  
layout (location = 1) in vec3 vNormal;
layout (location = 2) in vec2 vTexCoord;

out struct Vertex
{
    vec3 Normal;
    vec3 WorldPos;
    vec3 WorldNormal;
    vec2 UV;
}vert_out;

uniform mat4 _Model;
uniform mat4 _View;
uniform mat4 _Projection;

uniform mat4 _NormalMatrix;

void main(){    
    vert_out.Normal = vNormal;
    vert_out.WorldPos = vec3(_Model * vec4(vPos, 1));
    vert_out.WorldNormal = normalize(mat3(_NormalMatrix) * vert_out.Normal);
    vert_out.UV = vTexCoord;
    gl_Position = _Projection * _View * _Model * vec4(vPos,1);
}
