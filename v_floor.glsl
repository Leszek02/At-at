#version 330

//Uniform variables
uniform mat4 P;
uniform mat4 V;
uniform mat4 M;
//uniform vec3 cameraPosition;

//Attributes
in vec4 vertex; //Vertex coordinates in model space; FRAG POS
in vec4 normal; //Vertex normal in model space
in vec2 texCoord;
//in vec3 cameraPosition;

//Varying variables
out vec4 l1;
out vec4 n1;
out vec4 v1;
out vec4 l2;
out vec4 n2;
out vec4 v2;
out vec2 iTexCoord; //globalnie

void main(void) {
    vec4 lp1 = vec4(-11111, 100000, 0, 1); //light position, world space; LIGHT POSITION
    l1 = normalize(V * lp1 - V * M * vertex); //vector towards the light in eye space; LIGHT DIRECTION
    v1 = normalize(vec4(0, 0, 0, 1) - V * M * vertex); //vector towards the viewer in eye space; VIEWER DIRECTION
    n1 = normalize(V * M * normal); //normal vector in eye space // NORMAL

    vec4 lp2 = vec4(100000, 100000, -100000, 1); //light position, world space; LIGHT POSITION
    l2 = normalize(V * lp2 - V * M * vertex); //vector towards the light in eye space; LIGHT DIRECTION
    v2 = normalize(vec4(0, 0, 0, 1) - V * M * vertex); //vector towards the viewer in eye space; VIEWER DIRECTION
    n2 = normalize(V * M * normal); //normal vector in eye space // NORMAL

    iTexCoord=texCoord; //w main 

    gl_Position = P * V * M * vertex;
}
