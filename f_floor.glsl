#version 330

out vec4 pixelColor; //Output variable. Almost final pixel color.

//Varying variables
in vec4 n1;
in vec4 l1;
in vec4 v1;
in vec4 n2;
in vec4 l2;
in vec4 v2;
in vec2 iTexCoord; //globalnie

uniform sampler2D tex0; //globalnie


void main(void) {
	//Normalized, interpolated vectors
	vec4 ml1 = normalize(l1); // LIGHT DIRECTION
	vec4 mn1 = normalize(n1); // NORMAL 
	vec4 mv1 = normalize(v1); // VIEWER DIRECTION
	//Reflected vector
	vec4 mr1 = reflect(-ml1, mn1);

	//Normalized, interpolated vectors
	vec4 ml2 = normalize(l2); // LIGHT DIRECTION
	vec4 mn2 = normalize(n2); // NORMAL 
	vec4 mv2 = normalize(v2); // VIEWER DIRECTION

	//Surface parameters
	vec4 kd = texture(tex0,iTexCoord); // texture color
	vec4 ks1 = vec4(0.991,0.907,0.692,1); // Sun1 color
	vec4 ks2 = vec4(0.95,0.89,0.73,1); // Sun2 color

	//Lighting model computation
	float nl1 = clamp(dot(mn1, ml1), 0, 1);
	float nl2 = clamp(dot(mn2, ml2), 0, 1);

	pixelColor = vec4(kd.rgb * nl1, kd.a) + vec4(kd.rgb * nl2 * ks2, kd.a);
}
