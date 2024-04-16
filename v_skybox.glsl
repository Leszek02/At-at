#version 330

//Zmienne jednorodne
uniform mat4 P;
uniform mat4 V;
uniform mat4 M;

//Atrybuty
in vec3 vertex; //wspolrzedne wierzcholka w przestrzeni modelu

//Zmienne interpolowane
out vec3 skyboxTex;

void main(void) {
    gl_Position=P*V*M*vec4(vertex.xy, -vertex.z, 1.0); // odwracamy z aby tekstury by�y odpowiednio obr�cone
    gl_Position=gl_Position.xyww; // zamieniamy z na 1, bo w/w=1; dzi�ki temu skybox renderuje si� tylko wtedy gdy nie b�dzie obiekt�w po drodze
    skyboxTex=vertex;
}
