#ifndef VECTOR_VISUALIZER_3D_SRC_CORE_VERTEXARRAYBUFFER_H_
#define VECTOR_VISUALIZER_3D_SRC_CORE_VERTEXARRAYBUFFER_H_

namespace VertexArrayBuffer {
#include "GL/glew.h"

class vao {
 public:
  explicit vao(int n_buffers);
  ~vao() = default;

  void Bind() const;
  void UnBind() const;

  void setData();
 private:
  GLuint m_vao_id;
};

} // VertexArrayBuffer

#endif //VECTOR_VISUALIZER_3D_SRC_CORE_VERTEXARRAYBUFFER_H_
