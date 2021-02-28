#version 440

struct Material
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
};

in vec3 output_position;
in vec3 output_color;
in vec2 output_texcoord;
in vec3 output_normal;

uniform Material material;

uniform sampler2D texture0;

uniform vec3 light_position;

uniform vec3 camera_position;

out vec4 final_color;

void main()
{
	// Ambient
    vec3 ambientFinal =  material.ambient;

	// Diffuse
	vec3 posToLightDirVec = normalize(light_position - output_position);
	float diffuse = clamp(dot(posToLightDirVec, normalize(output_normal)), 0, 1);

	//Diffuse Toon Shading

	//float level1 = floor(diffuse * 6);

	//diffuse = level1 / 6;

	vec3 diffuseFinal = material.diffuse * diffuse;

	// Specular
	vec3 direction = normalize(output_position - light_position);
	vec3 reflection = normalize(reflect(direction, normalize(output_normal)));
	vec3 camera_view = normalize(camera_position - output_position);
	float specular = pow(max(dot(camera_view, reflection), 0), 20);

	//Specular Toon Shading

	//float level2 = floor(specular * 6);

	//specular = level2 / 6;

	vec3 specularFinal = material.specular * specular;

    //final_color = vec4(1.0,0.6,0.4f,1) * vec4(output_color, 1.f) * (vec4(ambientFinal, 1.f) + vec4(diffuseFinal, 1.f) + vec4(specularFinal, 1.f));

   final_color = texture(texture0,output_texcoord) * vec4(output_color, 1.f) * (vec4(ambientFinal, 1.f) + vec4(diffuseFinal, 1.f) + vec4(specularFinal, 1.f));

}