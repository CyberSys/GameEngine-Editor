#pragma once

#include "MemoryLayout.h"
#include "GLcapability.h"
#include "TextureFilter.h"
#include "TextureAddressMode.h"
#include "ComparisonFunction.h"
#include "RenderType.h"
#include "Primitive.h"
#include <glm.hpp>

namespace Graphics
{
	void GAPI_Init();

	void GAPI_SetViewport(float w, float h);

	void GAPI_Enable(GLcapability cap);

	void GAPI_Disable(GLcapability cap);

	void GAPI_SetClearColor(float r, float g, float b, float a);

	void GAPI_ClearBuffers();

	void GAPI_UpdateViewport(int width, int height);

	void GAPI_ApplyTextureFilters(TextureFilter filter, bool mipmap, unsigned int target);

	int GAPI_GetAddressMode(TextureAddressMode mode);

	int GAPI_GetCompareFunc(ComparisonFunction func);

	unsigned int GAPI_CreateVertexBuffer(RenderType type, unsigned int size, void* data);

	void GAPI_UpdateVertexBuffer(unsigned int vertexbuffer, RenderType type, unsigned int size, void* data);

	unsigned int GAPI_CreateIndexBuffer(RenderType type, unsigned int size, void* data);

	void GAPI_MapVertexBuffer(unsigned int VBuf_id, unsigned int size, void* data);

	void GAPI_MapIndexBuffer(unsigned int IBuf_id, unsigned int size, void* data);

	void GAPI_DeleteBuffer(unsigned int buff_id);

	void GAPI_BindVertexBuffer(unsigned int VBuf_id);

	void GAPI_BindIndexBuffer(unsigned int IBuf_id);

	unsigned int GAPI_CreateProgram(char* vertex, char* pixel);

	unsigned int GAPI_CreateVertexShader(char* vertex);

	unsigned int GAPI_CreatePixelShader(char* pixel);

	unsigned int GAPI_CreateGeomtreyShader(char* GS);

	unsigned int GAPI_CreateComputeShader(char* CS);

	void GAPI_CheckCompileErrors(unsigned int shader_id, std::string type);

	void GAPI_DeleteShader(unsigned int program_id, unsigned int shader_id);

	void GAPI_BindShader(unsigned int program_id);

	void GAPI_SetUniform_int(unsigned int program_id, char* name, int val);

	void GAPI_SetUniform_float(unsigned int program_id, char* name, float val);

	void GAPI_SetUniform_vec2(unsigned int program_id, char* name, glm::vec2 &value);

	void GAPI_SetUniform_vec3(unsigned int program_id, char* name, glm::vec3 &value);

	void GAPI_SetUniform_vec4(unsigned int program_id, char* name, glm::vec4 &value);

	void GAPI_SetUniform_mat2(unsigned int program_id, char* name, glm::mat2 &mat);

	void GAPI_SetUniform_mat3(unsigned int program_id, char* name, glm::mat3 &mat);

	void GAPI_SetUniform_mat4(unsigned int program_id, char* name, glm::mat4 &mat);

	unsigned int GAPI_CreateUniformBuffer(unsigned int size, void* data, unsigned int slot);

	void GAPI_MapUniformBuffer(unsigned int buff_id, unsigned int size, void* data);

	void GAPI_BindUniformBuffer(unsigned int buff_id, unsigned int slot);

	unsigned int GAPI_CreateTexture2D(int img_width, int img_height, void* img_data, bool mipmaps);

	void GAPI_MapTexture2D(unsigned int tex_id, int img_width, int img_height, void* img_data);

	void GAPI_DeleteTexture2D(unsigned int tex_id);

	void GAPI_BindTexture2D(unsigned int tex_id, unsigned int unit);

	void GAPI_ApplySamplerTex2D(unsigned int texture_id, bool mipmap, TextureAddressMode U,
								TextureAddressMode V, TextureFilter filter, ComparisonFunction func,
								float red, float green, float blue, float alpha);

	unsigned int GAPI_CreateVertexArray(unsigned int VBuf_id, unsigned int IBuf_id, MemoryLayout& input_layout);

	void GAPI_Draw(Primitive type, unsigned int VAOBuf_id, unsigned int VBuf_id, unsigned int Vert_count);

	void GAPI_DrawIndexed(Primitive type, unsigned int VAOBuf_id, unsigned int VBuf_id, unsigned int IBuf_id, unsigned int Vert_count);

	void GAPI_DeleteVertexArray(unsigned int VAO_id);
}