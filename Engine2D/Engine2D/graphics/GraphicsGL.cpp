#include "GraphicsGL.h"
#include <glew.h>
#include <string.h>
#include <iostream>

namespace Graphics
{
	void GAPI_Init()
	{
		// check OpenGL error
		GLenum err;

		glewExperimental = true; // Needed in core profile
		if (glewInit() != GLEW_OK)
		{
			printf("gl device driver not initialized.");
		}

		glPointSize(5);
		glLineWidth(2);
		glClearColor(0, 0, 0, 1);
	}

	void GAPI_SetViewport(float w, float h)
	{
		glViewport(0, 0, w, h);
	}

	 void GAPI_Enable(GLcapability cap)
	{
		switch (cap)
		{
			case GLcapability::BLENDING:
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //will use it as initial option.
				break;
			case GLcapability::FACE_CULLING:
				glEnable(GL_CULL_FACE);
				break;
			case GLcapability::MULTISAMPLING:
				glEnable(GL_MULTISAMPLE);
				break;
			case GLcapability::DEPTH_TEST:
				glEnable(GL_DEPTH_TEST);
				break;
			case GLcapability::SCISSOR_TEST:
				glEnable(GL_SCISSOR_TEST);
				break;
			case GLcapability::STENCIL_TEST:
				glEnable(GL_STENCIL_TEST);
				break;
			default:
				printf("no option like that here.. \n");
				break;
		}
	}

	 void GAPI_Disable(GLcapability cap)
	{
		switch (cap)
		{
			case GLcapability::BLENDING:
				glDisable(GL_BLEND);
				break;
			case GLcapability::FACE_CULLING:
				glDisable(GL_CULL_FACE);
				break;
			case GLcapability::MULTISAMPLING:
				glDisable(GL_MULTISAMPLE);
				break;
			case GLcapability::DEPTH_TEST:
				glDisable(GL_DEPTH_TEST);
				break;
			case GLcapability::SCISSOR_TEST:
				glDisable(GL_SCISSOR_TEST);
				break;
			case GLcapability::STENCIL_TEST:
				glDisable(GL_STENCIL_TEST);
				break;
			default:
				printf("no option like that here.. \n");
				break;
		}
	}

	 
	void GAPI_SetClearColor(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
	}

	 
	void GAPI_ClearBuffers()
	{
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
	}

	
	void GAPI_UpdateViewport(int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	 
	void GAPI_ApplyTextureFilters(TextureFilter filter, bool mipmap, unsigned int target)
	{
		switch (filter)
		{
			case TextureFilter::POINT:
				if (mipmap)
					glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
				else
					glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				break;
			case TextureFilter::LINEAR:
				if (mipmap)
					glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
				else
					glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				break;
			case TextureFilter::ANISOTROPIC:
				if (mipmap)
					glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
				else
					glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				break;
			case TextureFilter::LINEAR_MIP_POINT:
				if (mipmap)
					glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
				else
					glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				break;
			case TextureFilter::POINT_MIP_LINEAR:
				if (mipmap)
					glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
				else
					glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				break;
			case TextureFilter::MIN_LINEAR_MAG_POINT_MIP_LINEAR:
				if (mipmap)
					glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
				else
					glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				break;
			case TextureFilter::MIN_LINEAR_MAG_POINT_MIP_POINT:
				if (mipmap)
					glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
				else
					glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
				break;
			case TextureFilter::MIN_POINT_MAG_LINEAR_MIP_LINEAR:
				if (mipmap)
					glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
				else
					glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				break;
			case TextureFilter::MIN_POINT_MAG_LINEAR_MIP_POINT:
				if (mipmap)
					glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
				else
					glTexParameteri(target, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
				glTexParameteri(target, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				break;
			default: break;
		}
	}

	 
	int GAPI_GetAddressMode(TextureAddressMode mode)
	{
		switch (mode)
		{
			case TextureAddressMode::WRAP:
				return GL_REPEAT;
				break;
			case TextureAddressMode::CLAMP:
				return GL_CLAMP_TO_EDGE;
				break;
			case TextureAddressMode::MIRROR:
				return GL_MIRRORED_REPEAT;
				break;
			case TextureAddressMode::BORDER:
				return GL_CLAMP_TO_BORDER;
				break;
			default:
				return -1;
				break;
		}
	}

	 
	int GAPI_GetCompareFunc(ComparisonFunction func)
	{
		switch (func)
		{
			case ComparisonFunction::ALWAYS:
				return GL_ALWAYS;
				break;
			case ComparisonFunction::NEVER:
				return GL_NEVER;
				break;
			case ComparisonFunction::LESS:
				return GL_LESS;
				break;
			case ComparisonFunction::LESS_EQUAL:
				return GL_LEQUAL;
				break;
			case ComparisonFunction::EQUAL:
				return GL_EQUAL;
				break;
			case ComparisonFunction::GREATER_EQUAL:
				return GL_GEQUAL;
				break;
			case ComparisonFunction::GREATER:
				return GL_GREATER;
				break;
			case ComparisonFunction::NOT_EQUAL:
				return GL_NOTEQUAL;
				break;
			default:
				return -1;
				break;
		}
	}

	 
	unsigned int GAPI_CreateVertexBuffer(RenderType type, unsigned int size, void* data)
	{
		GLuint id = -1;
		glGenBuffers(1, &id);
		if (id == -1)
			printf("Cannot generate vertex buffer");

		glBindBuffer(GL_ARRAY_BUFFER, id);

		switch (type)
		{
			//static
			case RenderType::STATIC:
				glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
				break;

			//dynamic
			case RenderType::DYNAMIC:
				glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
				break;

			default:
				return -1;
				break;
		}
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		return id;
	}

	 
	void GAPI_UpdateVertexBuffer(unsigned int vertexbuffer, RenderType type, unsigned int size, void * data)
	{
		if (vertexbuffer == -1)
			printf("Cannot generate vertex buffer");

		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

		switch (type)
		{
			//static
			case RenderType::STATIC:
				glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
				break;

			//dynamic
			case RenderType::DYNAMIC:
				glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
				break;

			default:
				break;
		}
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	 
	unsigned int GAPI_CreateIndexBuffer(RenderType type, unsigned int size, void * data)
	{
		GLuint id = -1;
		glGenBuffers(1, &id);
		if (id == -1)
			printf("Cannot generate index buffer");

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);

		switch (type)
		{
			//static
			case RenderType::STATIC:
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
				break;

			//dynamic
			case RenderType::DYNAMIC:
				glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
				break;

			default:
				return -1;
				break;
		}
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		return id;
	}

	 
	void GAPI_MapVertexBuffer(unsigned int VBuf_id, unsigned int size, void * data)
	{
		//need to fix bug here...

		glBindBuffer(GL_ARRAY_BUFFER, VBuf_id);

		void* GPUPtr = NULL;
		GPUPtr = glMapBufferRange(GL_ARRAY_BUFFER, 0, size, GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_RANGE_BIT);

		if (GPUPtr == NULL)
			printf("Cannot Map Vertex Buffer: Failed to get buffer pointer");

		memcpy(GPUPtr, data, size);
		glUnmapBuffer(GL_ARRAY_BUFFER);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	 
	void GAPI_MapIndexBuffer(unsigned int IBuf_id, unsigned int size, void * data)
	{
		//need to fix bug here...

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBuf_id);

		void* GPUPtr = NULL;
		GPUPtr = glMapBufferRange(GL_ELEMENT_ARRAY_BUFFER, 0, size, GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_RANGE_BIT);

		if (GPUPtr == NULL)
			printf("Cannot Map Index Buffer: Failed to get buffer pointer");

		memcpy(GPUPtr, data, size);
		glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	 
	void GAPI_DeleteBuffer(const unsigned int buff_id)
	{
		glDeleteBuffers(1, &buff_id);
	}

	 
	void GAPI_BindVertexBuffer(unsigned int VBuf_id)
	{
		glBindBuffer(GL_ARRAY_BUFFER, VBuf_id);
	}

	 
	void GAPI_BindIndexBuffer(unsigned int IBuf_id)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBuf_id);
	}

	
	unsigned int GAPI_CreateProgram(char * vertex, char * pixel)
	{
		//vertex shader
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

		char* error = new char[1024];
		const GLchar* p[1];
		p[0] = vertex;
		glShaderSource(vertexShader, 1, p, NULL);
		glCompileShader(vertexShader);

		GLint res = 0;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &res);

		if (res == GL_FALSE) {
			glGetShaderInfoLog(vertexShader, 1024, NULL, error);
			printf("Cannot compile vertex shader");
		}

		GAPI_CheckCompileErrors(vertexShader, "VERTEX");

		//pixel shader
		unsigned int pixelShader = glCreateShader(GL_FRAGMENT_SHADER);

		p[0] = pixel;
		glShaderSource(pixelShader, 1, p, NULL);
		glCompileShader(pixelShader);

		glGetShaderiv(pixelShader, GL_COMPILE_STATUS, &res);

		if (res == GL_FALSE) {
			glGetShaderInfoLog(pixelShader, 1024, NULL, error);
			printf("Cannot compile pixel shader");
		}

		GAPI_CheckCompileErrors(pixelShader, "FRAGMENT");

		unsigned int program = glCreateProgram();

		glAttachShader(program, vertexShader);
		glAttachShader(program, pixelShader);

		glLinkProgram(program);
		glGetProgramiv(program, GL_LINK_STATUS, &res);

		if (res == GL_FALSE) {
			glGetProgramInfoLog(program, 1024, NULL, error);
			printf("Cannot link GPU program");
		}
		glValidateProgram(program);
		glGetProgramiv(program, GL_VALIDATE_STATUS, &res);

		if (res == GL_FALSE) {
			glGetProgramInfoLog(program, 1024, NULL, error);
			printf("GPU program validation error");
		}

		delete[] error;
		return program;
	}

	 
	unsigned int GAPI_CreateVertexShader(char * vertex)
	{
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

		char* error = new char[1024];
		const GLchar* p[1];
		p[0] = vertex;
		glShaderSource(vertexShader, 1, p, NULL);
		glCompileShader(vertexShader);

		GLint res = 0;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &res);

		if (res == GL_FALSE) {
			glGetShaderInfoLog(vertexShader, 1024, NULL, error);
			printf("Cannot compile vertex shader");
		}

		GAPI_CheckCompileErrors(vertexShader, "VERTEX");

		return vertexShader;
	}

	 
	unsigned int GAPI_CreatePixelShader(char * pixel)
	{
		unsigned int pixelShader = glCreateShader(GL_FRAGMENT_SHADER);

		GLint res = 0;
		const GLchar* p[1];
		char* error = new char[1024];
		p[0] = pixel;
		glShaderSource(pixelShader, 1, p, NULL);
		glCompileShader(pixelShader);

		glGetShaderiv(pixelShader, GL_COMPILE_STATUS, &res);

		if (res == GL_FALSE) {
			glGetShaderInfoLog(pixelShader, 1024, NULL, error);
			printf("Cannot compile pixel shader");
		}

		GAPI_CheckCompileErrors(pixelShader, "FRAGMENT");

		return pixelShader;
	}

	 
	unsigned int GAPI_CreateGeomtreyShader(char * GS)
	{
		//to implement here..
		return 0;
	}

	
	unsigned int GAPI_CreateComputeShader(char * CS)
	{
		//to implement here..
		return 0;
	}

	 
	void GAPI_CheckCompileErrors(unsigned int shader_id, std::string type)
	{
		GLint success;
		GLchar infoLog[1024];
		if (type != "PROGRAM")
		{
			glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader_id, 1024, NULL, infoLog);
				std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			}
		}
		else
		{
			glGetProgramiv(shader_id, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(shader_id, 1024, NULL, infoLog);
				std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			}
		}
	}

	 
	void GAPI_DeleteShader(unsigned int program_id, unsigned int shader_id)
	{
		glDeleteShader(shader_id);
		glDeleteProgram(program_id);
	}

	 
	void GAPI_BindShader(unsigned int program_id)
	{
		glUseProgram(program_id);
	}

	 
	void GAPI_SetUniform_int(unsigned int program_id, char * name, int val)
	{
		glUniform1i( glGetUniformLocation(program_id, name), val);
	}

	 
	void GAPI_SetUniform_float(unsigned int program_id, char * name, float val)
	{
		glUniform1f( glGetUniformLocation(program_id, name), val);
	}

	 
	void GAPI_SetUniform_vec2(unsigned int program_id, char * name, glm::vec2 & value)
	{
		glUniform2fv( glGetUniformLocation(program_id, name),1, &value[0]);
	}

	 
	void GAPI_SetUniform_vec3(unsigned int program_id, char * name, glm::vec3 & value)
	{
		glUniform3fv( glGetUniformLocation(program_id, name), 1, &value[0]);
	}

	 
	void GAPI_SetUniform_vec4(unsigned int program_id, char * name, glm::vec4 & value)
	{
		glUniform4fv( glGetUniformLocation(program_id, name), 1, &value[0]);
	}

	 
	void GAPI_SetUniform_mat2(unsigned int program_id, char * name, glm::mat2 & mat)
	{
		glUniformMatrix2fv( glGetUniformLocation(program_id, name), 1, GL_FALSE, &mat[0][0]);
	}

	 
	void GAPI_SetUniform_mat3(unsigned int program_id, char * name, glm::mat3 & mat)
	{
		glUniformMatrix3fv( glGetUniformLocation(program_id, name), 1, GL_FALSE, &mat[0][0]);
	}

	 
	void GAPI_SetUniform_mat4(unsigned int program_id, char * name, glm::mat4 & mat)
	{
		glUniformMatrix4fv( glGetUniformLocation(program_id, name), 1, GL_FALSE, &mat[0][0]);
	}

	
	unsigned int GAPI_CreateUniformBuffer(unsigned int size, void * data, unsigned int slot)
	{
		unsigned int ID;
		glGenBuffers(1, &ID);
		glBindBuffer(GL_UNIFORM_BUFFER, ID);
		glBufferData(GL_UNIFORM_BUFFER, size, data, GL_DYNAMIC_DRAW);

		glBindBufferBase(GL_UNIFORM_BUFFER, slot, ID);

		glBindBuffer(GL_UNIFORM_BUFFER, 0);

		return ID;
	}

	 
	void GAPI_MapUniformBuffer(unsigned int buff_id, unsigned int size, void * data)
	{
		//need to fix bug here..

		glBindBuffer(GL_UNIFORM_BUFFER, buff_id);

		void* GPUPtr = NULL;
		GPUPtr = glMapBufferRange(GL_UNIFORM_BUFFER, 0, size, GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_RANGE_BIT);

		if (GPUPtr == NULL)
			printf("Cannot Map Uniform Buffer: Failed to get buffer pointer");

		memcpy(GPUPtr, data, size);
		glUnmapBuffer(GL_UNIFORM_BUFFER);

		glBindBuffer(GL_UNIFORM_BUFFER, 0);
	}

	 
	void GAPI_BindUniformBuffer(unsigned int buff_id, unsigned int slot)
	{
		glBindBuffer(GL_UNIFORM_BUFFER, buff_id);
		glBindBufferBase(GL_UNIFORM_BUFFER, slot, buff_id);
	}

	 
	unsigned int GAPI_CreateTexture2D(int img_width, int img_height, void* img_data, bool mipmaps)
	{
		unsigned int ID;

		glGenTextures(1, &ID);
		glBindTexture(GL_TEXTURE_2D, ID);

		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img_width, img_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img_data);
		if (mipmaps)
			glGenerateMipmap(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, 0);
		return ID;
	}

	 
	void GAPI_MapTexture2D(unsigned int tex_id, int img_width, int img_height, void * img_data)
	{
		glBindTexture(GL_TEXTURE_2D, tex_id);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img_width, img_height, 0, GL_BGRA, GL_UNSIGNED_BYTE, img_data);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	
	void GAPI_DeleteTexture2D(unsigned int tex_id)
	{
		glDeleteTextures(1, &tex_id);
	}

	 
	void GAPI_BindTexture2D(unsigned int tex_id, unsigned int unit)
	{
		glActiveTexture(GL_TEXTURE0 + unit);
		glBindTexture(GL_TEXTURE_2D, tex_id);
	}

	 
	void GAPI_ApplySamplerTex2D(unsigned int texture_id, bool mipmap, TextureAddressMode U,
		TextureAddressMode V, TextureFilter filter, ComparisonFunction func,
		float red, float green, float blue, float alpha)
	{
		glBindTexture(GL_TEXTURE_2D, texture_id);
		GAPI_ApplyTextureFilters(filter, mipmap, GL_TEXTURE_2D);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GAPI_GetAddressMode(U));
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GAPI_GetAddressMode(V));
		float border[4] = { red,green,blue,alpha };
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border);

		if (func != ComparisonFunction::NEVER)
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GAPI_GetCompareFunc(func));
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	 
	unsigned int GAPI_CreateVertexArray(unsigned int VBuf_id, unsigned int IBuf_id, MemoryLayout& input_layout)
	{
		unsigned int VAO;
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		GAPI_BindVertexBuffer(VBuf_id);

		for (int i = 0; i < input_layout.elements.size(); ++i)
		{
			glEnableVertexAttribArray(i);
			glVertexAttribPointer(i, input_layout.elements[i].components, GL_FLOAT, GL_FALSE, input_layout.size, (void*)(size_t)(input_layout.elements[i].offset));
		}

		//may cause erorr if ibuff == 0
		if (IBuf_id)
			GAPI_BindIndexBuffer(IBuf_id);

		glBindVertexArray(0);
		return VAO;
	}

	 
	void GAPI_Draw(Primitive type, unsigned int VAOBuf_id, unsigned int VBuf_id, unsigned int Vert_count)
	{
		glBindVertexArray(VAOBuf_id);

		GAPI_BindVertexBuffer(VBuf_id);

		switch (type)
		{
			case Primitive::POINTS:
				glDrawArrays(GL_POINTS, 0, Vert_count);
				break;
			case Primitive::LINES:
				glDrawArrays(GL_LINE_STRIP, 0, Vert_count);
				break;
			case Primitive::LINE_STRIP:
				glDrawArrays(GL_LINE_LOOP, 0, Vert_count);
				break;
			case Primitive::LINE_LOOP:
				glDrawArrays(GL_TRIANGLES, 0, Vert_count);
				break;
			case Primitive::TRIANGLES:
				glDrawArrays(GL_TRIANGLES, 0, Vert_count);
				break;
			case Primitive::TRIANGLE_STRIP:
				glDrawArrays(GL_TRIANGLE_STRIP, 0, Vert_count);
				break;
			case Primitive::TRIANGLE_VAN:
				glDrawArrays(GL_TRIANGLE_FAN, 0, Vert_count);
				break;
			default:
				printf("Cannot identify primitive type");
				break;
		}
	}

	 
	void GAPI_DrawIndexed(Primitive type, unsigned int VAOBuf_id, unsigned int VBuf_id, unsigned int IBuf_id, unsigned int Vert_count)
	{
		glBindVertexArray(VAOBuf_id);

		GAPI_BindVertexBuffer(VBuf_id);
		GAPI_BindIndexBuffer(IBuf_id);

		switch (type)
		{
			case Primitive::POINTS:
				glDrawElements(GL_POINTS, Vert_count, GL_UNSIGNED_INT, (void*)0);
				break;
			case Primitive::LINES:
				glDrawElements(GL_LINE_STRIP, Vert_count, GL_UNSIGNED_INT, (void*)0);
				break;
			case Primitive::LINE_STRIP:
				glDrawElements(GL_LINE_LOOP, Vert_count, GL_UNSIGNED_INT, (void*)0);
				break;
			case Primitive::LINE_LOOP:
				glDrawElements(GL_TRIANGLES, Vert_count, GL_UNSIGNED_INT, (void*)0);
				break;
			case Primitive::TRIANGLES:
				glDrawElements(GL_TRIANGLES, Vert_count, GL_UNSIGNED_INT, (void*)0);
				break;
			case Primitive::TRIANGLE_STRIP:
				glDrawElements(GL_TRIANGLE_STRIP, Vert_count, GL_UNSIGNED_INT, (void*)0);
				break;
			case Primitive::TRIANGLE_VAN:
				glDrawElements(GL_TRIANGLE_FAN, Vert_count, GL_UNSIGNED_INT, (void*)0);
				break;
			default:
				printf("Cannot identify primitive type");
				break;
		}
	}

	
	void GAPI_DeleteVertexArray(unsigned int VAO_id)
	{
		glDeleteVertexArrays(1, &VAO_id);
	}

}