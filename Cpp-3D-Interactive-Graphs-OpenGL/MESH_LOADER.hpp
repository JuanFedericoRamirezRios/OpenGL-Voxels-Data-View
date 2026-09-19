#pragma once

/*
Standard C++ 20
GLEW 2.3.1
GLFW 3.4
GLM 1.0.3
*/
#include <vector>
#include "Dependencies/glm/glm/glm.hpp" // OpenGL maths.

using namespace glm;

enum MESH_TYPE {
	Triangle = 0,
	Quad = 1,
	Cube = 2,
	UVsphere = 3,
	Voxels = 4
};
struct VERTEX {
	vec3 pos;
	vec3 normal; // -> lighting.
	vec4 color;
	vec2 textureCoord; // -> texture of objects: U and V coordinates?
};

class MESH_LOADER {
private:

public:
	static void LoadTriangleVertices(std::vector<VERTEX>& vertices, std::vector<uint32_t>& indices) {
		std::vector<VERTEX> _vertices = {
			{ // Vertex 1.
				{0.0f, -1.0f, 0.0f}, // Position
				{0.0f, 0.0f, 1.0f}, // Normal
				{1.0f, 0.0f, 0.0f, 1.0f}, // Color
				{0.0f, 1.0f}, // Texture coordinate
			},
			{ // Vertex 2.
				{1.0f, 1.0f, 0.0f}, // Position
				{0.0f, 0.0f, 1.0f}, // Normal
				{0.0f, 1.0f, 0.0f, 1.0f}, // Color
				{0.0f, 0.0f}, // Texture coordinate
			},
			{ // Vertex 3.
				{-1.0f, 1.0f, 0.0f}, // Position
				{0.0f, 0.0f, 1.0f}, // Normal
				{0.0f, 0.0f, 1.0f, 1.0f}, // Color
				{1.0f, 0.0f}, // Texture coordinate
			}
		};
		std::vector<uint32_t> _indices = { 0, 1, 2 };

		vertices.clear(); indices.clear();
		vertices = _vertices;
		indices = _indices;
	}
	static void LoadQuadVertices(std::vector<VERTEX>& vertices, std::vector<uint32_t>& indices) {
		std::vector<VERTEX> _vertices = {
		{ 
			{ -1.0f, -1.0f, 0.0f },
			{ 0.0f, 0.0f, 1.0 },
			{ 1.0f, 0.0f, 0.0f, 1.0f},
			{ 0.0, 1.0 } 
		},
		{ 
			{ -1.0f, 1.0f, 0.0f },
			{ 0.0f, 0.0f, 1.0 },
			{ 0.0f, 1.0f, 0.0f, 1.0f},
			{ 0.0, 0.0 } 
		},
		{ 
			{ 1.0f, 1.0f, 0.0f },
			{ 0.0f, 0.0f, 1.0 },
			{ 0.0f, 0.0f, 1.0f, 1.0f},
			{ 1.0, 0.0 } 
		},
		{ 
			{ 1.0f, -1.0f, 0.0f },
			{ 0.0f, 0.0f, 1.0 },
			{ 1.0f, 0.0f, 1.0f, 1.0f},
			{ 1.0, 1.0 } 
		}
		};

		std::vector<uint32_t> _indices = {
			0, 1, 2, // The first triangle of mesh.
			0, 2, 3 // The second triangle of mesh.
		};

		vertices.clear(); indices.clear();
		vertices = _vertices;
		indices = _indices;
	}
	static void LoadCubeVertices(std::vector<VERTEX>& vertices, std::vector<uint32_t>& indices) {
		
		std::vector<VERTEX> _vertices = {
			//front
			{ { -1.0f, -1.0f, 1.0f },{ 0.0f, 0.0f, 1.0 },{ 1.0f, 0.0f, 0.0f, 1.0f},{ 0.0, 1.0 } }, //0
			{ { -1.0f, 1.0f, 1.0f },{ 0.0f, 0.0f, 1.0 },{ 0.0f, 1.0f, 0.0f, 1.0f},{ 0.0, 0.0 } }, //1
			{ { 1.0f, 1.0f, 1.0f },{ 0.0f, 0.0f, 1.0 },{ 0.0f, 0.0f, 1.0f, 1.0f},{ 1.0, 0.0 } }, //2
			{ { 1.0f, -1.0f, 1.0f },{ 0.0f, 0.0f, 1.0 },{ 1.0f, 0.0f, 1.0f, 1.0f},{ 1.0, 1.0 } }, //3
			// back 
			{ { 1.0, -1.0, -1.0 },{ 0.0f, 0.0f, -1.0 },{ 1.0f, 0.0f, 1.0f, 1.0f},{ 0.0, 1.0 } }, //4
			{ { 1.0f, 1.0, -1.0 },{ 0.0f, 0.0f, -1.0 },{ 0.0f, 1.0f, 1.0f, 1.0f},{ 0.0, 0.0 } }, //5
			{ { -1.0, 1.0, -1.0 },{ 0.0f, 0.0f, -1.0 },{ 0.0f, 1.0f, 1.0f, 1.0f},{ 1.0, 0.0 } }, //6
			{ { -1.0, -1.0, -1.0 },{ 0.0f, 0.0f, -1.0 },{ 1.0f, 0.0f, 1.0f, 1.0f},{ 1.0, 1.0 } }, //7
			//left
			{ { -1.0, -1.0, -1.0 },{ -1.0f, 0.0f, 0.0 },{ 0.0f, 0.0f, 1.0f, 1.0f},{ 0.0, 1.0 } }, //8
			{ { -1.0f, 1.0, -1.0 },{ -1.0f, 0.0f, 0.0 },{ 0.0f, 0.0f, 1.0f, 1.0f},{ 0.0, 0.0 } }, //9
			{ { -1.0, 1.0, 1.0 },{ -1.0f, 0.0f, 0.0 },{ 0.0f, 0.0f, 1.0f, 1.0f},{ 1.0, 0.0 } },   //10
			{ { -1.0, -1.0, 1.0 },{ -1.0f, 0.0f, 0.0 },{ 0.0f, 0.0f, 1.0f, 1.0f},{ 1.0, 1.0 } }, //11
			//right
			{ { 1.0, -1.0, 1.0 },{ 1.0f, 0.0f, 0.0 },{ 0.0f, 0.0f, 1.0f, 1.0f},{ 0.0, 1.0 } }, // 12
			{ { 1.0f, 1.0, 1.0 },{ 1.0f, 0.0f, 0.0 },{ 0.0f, 0.0f, 1.0f, 1.0f},{ 0.0, 0.0 } }, //13
			{ { 1.0, 1.0, -1.0 },{ 1.0f, 0.0f, 0.0 },{ 0.0f, 0.0f, 1.0f, 1.0f},{ 1.0, 0.0 } }, //14
			{ { 1.0, -1.0, -1.0 },{ 1.0f, 0.0f, 0.0 },{ 0.0f, 0.0f, 1.0f, 1.0f},{ 1.0, 1.0 } }, //15
			//top
			{ { -1.0f, 1.0f, 1.0f },{ 0.0f, 1.0f, 0.0 },{ 0.0f, 0.0f, 1.0f, 1.0f},{ 0.0, 1.0 } }, //16
			{ { -1.0f, 1.0f, -1.0f },{ 0.0f, 1.0f, 0.0 },{ 0.0f, 0.0f, 1.0f, 1.0f},{ 0.0, 0.0 } }, //17
			{ { 1.0f, 1.0f, -1.0f },{ 0.0f, 1.0f, 0.0 },{ 0.0f, 0.0f, 1.0f, 1.0f},{ 1.0, 0.0 } }, //18
			{ { 1.0f, 1.0f, 1.0f },{ 0.0f, 1.0f, 0.0 },{ 0.0f, 0.0f, 1.0f, 1.0f},{ 1.0, 1.0 } }, //19
			//bottom 
			{ { -1.0f, -1.0, -1.0 },{ 0.0f, -1.0f, 0.0 },{ 0.0f, 0.0f, 1.0f, 1.0f},{ 0.0, 1.0 } }, //20
			{ { -1.0, -1.0, 1.0 },{ 0.0f, -1.0f, 0.0 },{ 0.0f, 0.0f, 1.0f, 1.0f},{ 0.0, 0.0 } }, //21
			{ { 1.0, -1.0, 1.0 },{ 0.0f, -1.0f, 0.0 },{ 0.0f, 0.0f, 1.0f, 1.0f},{ 1.0, 0.0 } },  //22
			{ { 1.0, -1.0, -1.0 },{ 0.0f, -1.0f, 0.0 },{ 0.0f, 0.0f, 1.0f, 1.0f},{ 1.0, 1.0 } }, //23
		};

		std::vector<uint32_t> _indices = {
			0, 1, 2,
			2, 3, 0,

			4, 5, 6,
			4, 6, 7,

			8, 9, 10,
			8, 10, 11,

			12, 13, 14,
			12, 14, 15,

			16, 17, 18,
			16, 18, 19,

			20, 21, 22,
			20, 22, 23
		};

		vertices.clear(); indices.clear();
		vertices = _vertices;
		indices = _indices;
	}
	static void LoadUVSphereVertices(std::vector<VERTEX>& vertices, std::vector<uint32_t>& indices) {
		std::vector<VERTEX> _vertices;
		std::vector<uint32_t> _indices;

		float latitudeBands = 20.0f;
		float longitudeBands = 20.0f;
		float radius = 1.0f;

		for (float latNumber = 0; latNumber <= latitudeBands; latNumber++) {
			float theta = latNumber * 3.14f / latitudeBands;
			float sinTheta = sin(theta);
			float cosTheta = cos(theta);

			for (float longNumber = 0; longNumber <= longitudeBands; longNumber++) {

				float phi = longNumber * 2.0f * 3.147f / longitudeBands;
				float sinPhi = sin(phi);
				float cosPhi = cos(phi);

				VERTEX vs;

				vs.textureCoord.x = (longNumber / longitudeBands); // u
				vs.textureCoord.y = (latNumber / latitudeBands);   // v

				vs.normal.x = cosPhi * sinTheta;   // normal x
				vs.normal.y = cosTheta;            // normal y
				vs.normal.z = sinPhi * sinTheta;   // normal z

				vs.color.r = vs.normal.x;
				vs.color.g = vs.normal.y;
				vs.color.b = vs.normal.z;
				vs.color.a = 1.0f;

				vs.pos.x = radius * vs.normal.x; // x
				vs.pos.y = radius * vs.normal.y; // y
				vs.pos.z = radius * vs.normal.z; // z

				_vertices.push_back(vs);
			}
		}

		for (uint32_t latNumber = 0; latNumber < latitudeBands; latNumber++) {
			for (uint32_t longNumber = 0; longNumber < longitudeBands; longNumber++) {
				uint32_t first = (latNumber * ((uint32_t)longitudeBands + 1)) + longNumber;
				uint32_t second = first + (uint32_t)longitudeBands + 1;

				_indices.push_back(first);
				_indices.push_back(second);
				_indices.push_back(first + 1);

				_indices.push_back(second);
				_indices.push_back(second + 1);
				_indices.push_back(first + 1);
			}
		}

		vertices.clear(); indices.clear();
		vertices = _vertices;
		indices = _indices;
	}

	static void LoadVoxelsVertices(std::vector<VERTEX>& vertices, std::vector<uint32_t>& indices, vec4 color, float size, float distance, unsigned Xs, unsigned Ys, unsigned Zs) {

		//for (int x = 0; x < Xs; x++) {
		//	for (int y = 0; y < Ys; y++) {
		//		for (int z = 0; z < Zs; z++) {
		//			voxels[x][y][z] = new GAME_OBJECT("", vec3((float)(x)*dist, (float)(z)*dist, (float)(y)*dist)/*, vec3(size, size, size)*/);
		//			voxels[x][y][z]->SetVertex(MESH_TYPE::Voxels, col, size);
		//			voxels[x][y][z]->SetDefaultColor(flatShaderProgram);
		//			//voxels[x][y][z]->SetColor(flatShaderProgram, vec4(0.0f, 0.0f, 1.0f, 1.0f));
		//		}
		//	}
		//}

		vec4 col{ 0.0f, 0.0f, 0.0f, 0.0f };

		vec2 coorT = vec2(0.0, 0.0);

		vec3 norm = {0.0f, 0.0f, 0.0f};

		float s = size / 2;
		float d = distance;
		float Dx = Xs*d/2.0f;
		float Dy = Ys*d/2.0f;

		std::vector<VERTEX> _vertices;

		for (int x = 0; x < Xs; x++) {
			for (int y = 0; y < Ys; y++) {
				for (int z = 0; z < Zs; z++) {
					if (rand() % 2) col = { 0.0f, 1.0f, 0.0f, 0.0f }; // Color of voxels
					else col = { 0.0f, 0.0f, 1.0f, 0.0f }; // Color of voxels
					std::vector<VERTEX> cube = {

						//front
						{ { -s + d * x - Dx, -s + d * z, s + d * y - Dy}, norm, col, coorT }, //0
						{ { -s + d * x - Dx, s + d * z, s + d * y - Dy}, norm, col, coorT }, //1
						{ { s + d * x - Dx, s + d * z, s + d * y - Dy}, norm, col, coorT }, //2
						{ { s + d * x - Dx, -s + d * z, s + d * y - Dy}, norm, col, coorT }, //3
						// back 
						{ { s + d * x - Dx, -s + d * z, -s + d * y - Dy}, norm, col, coorT }, //4
						{ { s + d * x - Dx, s + d * z, -s + d * y - Dy}, norm, col, coorT }, //5
						{ { -s + d * x - Dx, s + d * z, -s + d * y - Dy}, norm, col, coorT }, //6
						{ { -s + d * x - Dx, -s + d * z, -s + d * y - Dy}, norm, col, coorT }, //7
						//left
						{ { -s + d * x - Dx, -s + d * z, -s + d * y - Dy}, norm, col, coorT }, //8
						{ { -s + d * x - Dx, s + d * z, -s + d * y - Dy}, norm, col, coorT }, //9
						{ { -s + d * x - Dx, s + d * z, s + d * y - Dy}, norm, col, coorT },   //10
						{ { -s + d * x - Dx, -s + d * z, s + d * y - Dy}, norm, col, coorT }, //11
						//right
						{ { s + d * x - Dx, -s + d * z, s + d * y - Dy}, norm, col, coorT }, // 12
						{ { s + d * x - Dx, s + d * z, s + d * y - Dy}, norm, col, coorT }, //13
						{ { s + d * x - Dx, s + d * z, -s + d * y - Dy}, norm, col, coorT }, //14
						{ { s + d * x - Dx, -s + d * z, -s + d * y - Dy}, norm, col, coorT }, //15
						//top
						{ { -s + d * x - Dx, s + d * z, s + d * y - Dy}, norm, col, coorT }, //16
						{ { -s + d * x - Dx, s + d * z, -s + d * y - Dy}, norm, col, coorT }, //17
						{ { s + d * x - Dx, s + d * z, -s + d * y - Dy}, norm, col, coorT }, //18
						{ { s + d * x - Dx, s + d * z, s + d * y - Dy}, norm, col, coorT }, //19
						//bottom 
						{ { -s + d * x - Dx, -s + d * z, -s + d * y - Dy}, norm, col, coorT }, //20
						{ { -s + d * x - Dx, -s + d * z, s + d * y - Dy}, norm, col, coorT }, //21
						{ { s + d * x - Dx, -s + d * z, s + d * y - Dy}, norm, col, coorT },  //22
						{ { s + d * x - Dx, -s + d * z, -s + d * y - Dy}, norm, col, coorT }, //23
					};
					_vertices.insert(_vertices.end(), cube.begin(), cube.end());
					cube.clear();
				}
			}
		}

		
		//std::vector<VERTEX> cube = {

		//	//front
		//	{ { -s, -s, s }, norm, color, coorT }, //0
		//	{ { -s, s, s }, norm, color, coorT }, //1
		//	{ { s, s, s }, norm, color, coorT }, //2
		//	{ { s, -s, s }, norm, color, coorT }, //3
		//	// back 
		//	{ { s, -s, -s }, norm, color, coorT }, //4
		//	{ { s, s, -s }, norm, color, coorT }, //5
		//	{ { -s, s, -s }, norm, color, coorT }, //6
		//	{ { -s, -s, -s }, norm, color, coorT }, //7
		//	//left
		//	{ { -s, -s, -s }, norm, color, coorT }, //8
		//	{ { -s, s, -s }, norm, color, coorT }, //9
		//	{ { -s, s, s }, norm, color, coorT },   //10
		//	{ { -s, -s, s }, norm, color, coorT }, //11
		//	//right
		//	{ { s, -s, s }, norm, color, coorT }, // 12
		//	{ { s, s, s }, norm, color, coorT }, //13
		//	{ { s, s, -s }, norm, color, coorT }, //14
		//	{ { s, -s, -s }, norm, color, coorT }, //15
		//	//top
		//	{ { -s, s, s }, norm, color, coorT }, //16
		//	{ { -s, s, -s }, norm, color, coorT }, //17
		//	{ { s, s, -s }, norm, color, coorT }, //18
		//	{ { s, s, s }, norm, color, coorT }, //19
		//	//bottom 
		//	{ { -s, -s, -s }, norm, color, coorT }, //20
		//	{ { -s, -s, s }, norm, color, coorT }, //21
		//	{ { s, -s, s }, norm, color, coorT },  //22
		//	{ { s, -s, -s }, norm, color, coorT }, //23
		//};
		//_vertices.insert(_vertices.end(), cube.begin(), cube.end());
		//cube.clear();

		std::vector<uint32_t> _indices;

		for (int x = 0; x < Xs; x++) {
			for (int y = 0; y < Ys; y++) {
				for (int z = 0; z < Zs; z++) {
					uint32_t inc = (x * Ys * Zs + y * Zs + z)*24;
					std::vector<uint32_t> indicesCube = {
						0 + inc, 1 + inc, 2 + inc,
						2 + inc, 3 + inc, 0 + inc,

						4 + inc, 5 + inc, 6 + inc,
						4 + inc, 6 + inc, 7 + inc,

						8 + inc, 9 + inc, 10 + inc,
						8 + inc, 10 + inc, 11 + inc,

						12 + inc, 13 + inc, 14 + inc,
						12 + inc, 14 + inc, 15 + inc,

						16 + inc, 17 + inc, 18 + inc,
						16 + inc, 18 + inc, 19 + inc,

						20 + inc, 21 + inc, 22 + inc,
						20 + inc, 22 + inc, 23 + inc
					};
					
					_indices.insert(_indices.end(), indicesCube.begin(), indicesCube.end());
					indicesCube.clear();

				}
			}
		}
		/*std::cout << _indices << std::endl;*/

		/*std::vector<uint32_t> _indices = {
			0, 1, 2,
			2, 3, 0,

			4, 5, 6,
			4, 6, 7,

			8, 9, 10,
			8, 10, 11,

			12, 13, 14,
			12, 14, 15,

			16, 17, 18,
			16, 18, 19,

			20, 21, 22,
			20, 22, 23
		};*/

		

		vertices.clear(); indices.clear();
		vertices = _vertices;
		indices = _indices;
	}
};