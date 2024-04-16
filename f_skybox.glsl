#version 330


out vec4 pixelColor; //Zmienna wyjsciowa fragment shadera. Zapisuje sie do niej ostateczny (prawie) kolor piksela

in vec3 skyboxTex;

uniform samplerCube cubemap;

void main(void) {
	pixelColor=texture(cubemap, skyboxTex);
}
