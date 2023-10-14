#include "VertexArrayBuffer.h"

namespace VertexArrayBuffer {
vao::vao(int n_buffers) : m_vao_id(0){
  glGenVertexArrays(n_buffers, &m_vao_id);
  glBindVertexArray(m_vao_id);
}
void vao::Bind() const {
  glBindVertexArray(m_vao_id);
}
void vao::UnBind() const {
}
void vao::setData() {
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
}
} // VertexArrayBuffer