#include "Mesh.h"

namespace Mesher
{
	Mesh::Mesh(float* vertixes_tmp, GLint count_vertixes_tmp, unsigned int* indices, GLint count_indices_tmp)
	{
		this->vertixes = vertixes_tmp;
		this->count_vertixes = count_vertixes_tmp;
        this->count_indices = count_indices_tmp;
        this->vbo = 0;
        this->vao = 0;
        this->ebo = 0;

        int stride = 8 * sizeof(float);
        int c_v_tmp = stride * this->count_vertixes;
        int c_i_tmp = sizeof(unsigned int) * this->count_indices;

        glGenVertexArrays(1, &this->vao);
        glBindVertexArray(this->vao);

        glGenBuffers(1, &this->vbo);
        glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
        glBufferData(GL_ARRAY_BUFFER, c_v_tmp, this->vertixes, GL_STATIC_DRAW);

        glGenBuffers(1, &this->ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, c_i_tmp, indices, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, nullptr);

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float)*3));

        glEnableVertexAttribArray(2);
        glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride, (void*)(sizeof(float) * 6));
	}
    Mesh::~Mesh()
    {
        glDeleteBuffers(1, &this->vbo);
        glDeleteBuffers(1, &this->ebo);
        glDeleteVertexArrays(1, &vao);
    }

    void Mesh::MeshDraw()
    {
        glBindVertexArray(this->vao);
        glDrawElements(GL_TRIANGLES, count_indices, GL_UNSIGNED_INT, 0);
    }
}