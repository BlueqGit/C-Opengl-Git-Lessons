#include "Mesh.h"

namespace Mesher
{
	Mesh::Mesh(float* vertixes_tmp, float* colors_tmp, GLint count_vertixes_tmp)
	{
		this->vertixes = vertixes_tmp;
		this->colors = colors_tmp;
		this->count_vertixes = count_vertixes_tmp;
        this->vertex_vbo = 0;
        this->colors_vbo = 0;
        this->vao = 0;

        int c_v_tmp = sizeof(float) * 3 * this->count_vertixes;

        glGenBuffers(1, &this->vertex_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, this->vertex_vbo);
        glBufferData(GL_ARRAY_BUFFER, c_v_tmp, this->vertixes, GL_STATIC_DRAW);

        glGenBuffers(1, &this->colors_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, this->colors_vbo);
        glBufferData(GL_ARRAY_BUFFER, c_v_tmp, this->colors, GL_STATIC_DRAW);

        glGenVertexArrays(1, &this->vao);
        glBindVertexArray(this->vao);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, this->vertex_vbo);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, this->colors_vbo);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	}
    Mesh::~Mesh()
    {
        glDeleteBuffers(1, &this->vertex_vbo);
        glDeleteBuffers(1, &this->colors_vbo);
        glDeleteVertexArrays(1, &vao);
    }

    void Mesh::MeshDraw()
    {
        glBindVertexArray(this->vao);
        glDrawArrays(GL_TRIANGLES, 0, count_vertixes);
    }
}