#ifndef VECTOR_VISUALIZER_3D_SRC_CORE_VBO_H_
#define VECTOR_VISUALIZER_3D_SRC_CORE_VBO_H_

namespace VertexBuffer {
#include "GL/glew.h"

class vbo {
 public:
  explicit vbo(int n_buffers);
  ~vbo() = default;

  void Bind() const;
  void UnBind();
  void setData(unsigned int size, void* data) const;

 private:
  GLuint m_vbo_id;
};

} // vbo

#endif //VECTOR_VISUALIZER_3D_SRC_CORE_VBO_H_
