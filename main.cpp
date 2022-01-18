/* main.cc */

#include <iostream>


/* Be sure to include GLAD before GLFW. The include file for GLAD includes the required OpenGL headers
   behind the scenes (like GL/gl.h) so be sure to include GLAD before other header files that require
   OpenGL (like GLFW).  */
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define WIDTH 800
#define HEIGHT 600

void framebuffer_size_callback(GLFWwindow *window, int width , int height) {
  glViewport(0, 0, width, height);
}

void processesInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

int main() {  
  glfwInit();

  /* Use OpenGL 3 */
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  /* Next we are required to create a window object */
  GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "helloGL", nullptr, nullptr);
  if (window == nullptr)
    {
      std::cout << "Failed to create GLFW window" << std::endl;
      glfwTerminate();
      return -1;
    }
  glfwMakeContextCurrent(window);


  /* GLAD manages function pointers for OpenGL so we want to initialize GLAD before we
   call any OpenGL function */
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
      std::cout << "Failed to initialize GLAD" << std::endl;
      return -1;
    }
  

  /* before we start to rendering we have to tell opengl the size of the rendering window */
  glViewport(0, 0, WIDTH, HEIGHT);

  
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


  /* start the engine */
  while(!glfwWindowShouldClose(window))
    {
      processesInput(window);

      /* Render command: Since we want to execute all the rendering commands each
       iteration or frame of the loop */

      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);
      
      glfwSwapBuffers(window);
      glfwPollEvents();
    }

  /* as soon as we exit the render loop we would like to properly clean / delete all of GLFW's resources*/
  glfwTerminate();
  
  return 0;
}
