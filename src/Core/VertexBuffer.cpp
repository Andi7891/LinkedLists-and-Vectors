#include "VertexBuffer.h"

namespace VertexBuffer {
vbo::vbo(int n_buffers) : m_vbo_id(0){
  glGenBuffers(n_buffers, &m_vbo_id);
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo_id);
}
void vbo::Bind() const {
  glBindBuffer(GL_ARRAY_BUFFER, m_vbo_id);
}
void vbo::UnBind() {

}
void vbo::setData(unsigned int size, void* data) const {
  Bind();
  glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

} // vbo