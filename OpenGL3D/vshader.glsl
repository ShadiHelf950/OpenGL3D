	#version 440

	// Layout input

	layout (location = 0) in vec3 position;
	layout (location = 1) in vec3 color;
	layout (location = 2) in vec2 texcoord;
	layout (location = 3) in vec3 normal;


	// Output for the fragment shader

	out vec3 output_position;
	out vec3 output_color;
	out vec2 output_texcoord;
	out vec3 output_normal;


	// Input transformation matrices

	uniform mat4 Projection;
	uniform mat4 View;
	uniform mat4 Model;


void main()
{
	
	output_position = vec4(Model * vec4(position,1.0f)).xyz;

	output_color = color;

	output_texcoord = vec2(texcoord.x, texcoord.y * -1.f);

	output_normal = mat3(Model) * normal;

	gl_Position = Projection * View * Model * vec4(position,1.0f);
	
}