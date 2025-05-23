#define GLM_ENABLE_EXPERIMENTAL

#include <iostream>

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "shader_s_shader.h"
#include "shader_s.h"
#include "glm/gtc/matrix_transform.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST);

    float vertices[] = {
                // positions         // colors

               -0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  
                0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  
                0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  
                0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  
               -0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  
               -0.5f, -0.5f, -0.5f,  1.0f, 1.0f, 1.0f,  

               -0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f,
                0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f,
                0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f,
                0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f,
               -0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 0.0f,
               -0.5f, -0.5f,  0.5f,  1.0f, 1.0f, 0.0f,

               -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
               -0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
               -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
               -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
               -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,
               -0.5f,  0.5f,  0.5f,  1.0f, 0.0f, 0.0f,

                0.5f,  0.5f,  0.5f,  1.0f, 0.64f, 0.0f,
                0.5f,  0.5f, -0.5f,  1.0f, 0.64f, 0.0f,
                0.5f, -0.5f, -0.5f,  1.0f, 0.64f, 0.0f,
                0.5f, -0.5f, -0.5f,  1.0f, 0.64f, 0.0f,
                0.5f, -0.5f,  0.5f,  1.0f, 0.64f, 0.0f,
                0.5f,  0.5f,  0.5f,  1.0f, 0.64f, 0.0f,

               -0.5f, -0.5f, -0.5f,  0.0f, 0.5f, 0.0f,
                0.5f, -0.5f, -0.5f,  0.0f, 0.5f, 0.0f,
                0.5f, -0.5f,  0.5f,  0.0f, 0.5f, 0.0f,
                0.5f, -0.5f,  0.5f,  0.0f, 0.5f, 0.0f,
               -0.5f, -0.5f,  0.5f,  0.0f, 0.5f, 0.0f,
               -0.5f, -0.5f, -0.5f,  0.0f, 0.5f, 0.0f,

               -0.5f, 0.5f, -0.5f,   0.0f, 0.0f, 1.0f,
                0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,
                0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
                0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
               -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
               -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,


               //Lines

               //Square 1 yellow
               -0.5f, 0.5f, 0.5f,    0.0f, 0.0f, 0.0f,
                0.5f,  0.5f, 0.5f,   0.0f, 0.0f, 0.0f,

               -0.5f, 0.5f, 0.5f,   0.0f, 0.0f, 0.0f,
               -0.5f, -0.5f, 0.5f,   0.0f, 0.0f, 0.0f,

                0.5f, 0.5f, 0.5f,    0.0f, 0.0f, 0.0f,
                0.5f, -0.5f, 0.5f,   0.0f, 0.0f, 0.0f,

                0.5f, -0.5f, 0.5f,    0.0f, 0.0f, 0.0f,
               -0.5f, -0.5f, 0.5f,   0.0f, 0.0f, 0.0f,
            
               -0.5f,  0.5f - 0.33f, 0.5f,    0.0f, 0.0f, 0.0f,
                0.5f,  0.5f - 0.33f, 0.5f,   0.0f, 0.0f, 0.0f,

               -0.5f,  0.5f - 0.66f, 0.5f,    0.0f, 0.0f, 0.0f,
                0.5f,  0.5f - 0.66f, 0.5f,   0.0f, 0.0f, 0.0f,

                -0.5f + 0.33f, 0.5f, 0.5f,   0.0f, 0.0f, 0.0f,
                -0.5f + 0.33f, -0.5f, 0.5f,   0.0f, 0.0f, 0.0f,

                -0.5f + 0.66f, 0.5f, 0.5f,   0.0f, 0.0f, 0.0f,
                -0.5f + 0.66f, -0.5f, 0.5f,   0.0f, 0.0f, 0.0f,


               //Square 2 white
 

                -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 0.0f,
                -0.5f,  0.5f, -0.5f,   0.0f, 0.0f, 0.0f,

                -0.5f, -0.5f, -0.5f,   0.0f, 0.0f, 0.0f,
                0.5f, -0.5f, -0.5f,   0.0f, 0.0f, 0.0f,

                0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 0.0f,
                0.5f, 0.5f, -0.5f,   0.0f, 0.0f, 0.0f,

                0.5f, 0.5f, -0.5f,    0.0f, 0.0f, 0.0f,
                -0.5f, 0.5f, -0.5f,   0.0f, 0.0f, 0.0f,

                0.5f, 0.5f - 0.33f, -0.5f,    0.0f, 0.0f, 0.0f,
                -0.5f, 0.5f - 0.33f, -0.5f,   0.0f, 0.0f, 0.0f,

                0.5f, 0.5f - 0.66f, -0.5f,    0.0f, 0.0f, 0.0f,
                -0.5f, 0.5f - 0.66f, -0.5f,   0.0f, 0.0f, 0.0f,

                -0.5f + 0.33f, -0.5f, -0.5f,    0.0f, 0.0f, 0.0f,
                -0.5f + 0.33f,  0.5f, -0.5f,   0.0f, 0.0f, 0.0f,

                -0.5f + 0.66f, -0.5f, -0.5f,    0.0f, 0.0f, 0.0f,
                -0.5f + 0.66f,  0.5f, -0.5f,   0.0f, 0.0f, 0.0f,

               //Square 3

               -0.5f, -0.5f, -0.5f + 0.33f,    0.0f, 0.0f, 0.0f,
               -0.5f,  0.5f, -0.5f + 0.33f,   0.0f, 0.0f, 0.0f,

               -0.5f, -0.5f, -0.5f + 0.66f,    0.0f, 0.0f, 0.0f,
               -0.5f,  0.5f, -0.5f + 0.66f,   0.0f, 0.0f, 0.0f,

               0.5f, 0.5f, -0.5f + 0.33f,    0.0f, 0.0f, 0.0f,
               -0.5f, 0.5f, -0.5f + 0.33f,   0.0f, 0.0f, 0.0f,

               0.5f, 0.5f, -0.5f + 0.66f,    0.0f, 0.0f, 0.0f,
               -0.5f, 0.5f, -0.5f + 0.66f,   0.0f, 0.0f, 0.0f,


               -0.5f,  -0.5f, 0.5f - 0.33f,    0.0f, 0.0f, 0.0f,
               0.5f,  -0.5f, 0.5f - 0.33f,   0.0f, 0.0f, 0.0f,

              -0.5f,  -0.5f, 0.5f - 0.66f,    0.0f, 0.0f, 0.0f,
               0.5f,  -0.5f, 0.5f - 0.66f,   0.0f, 0.0f, 0.0f,

               0.5f, 0.5f, 0.5f - 0.33f,   0.0f, 0.0f, 0.0f,
               0.5f, -0.5f, 0.5f - 0.33f,   0.0f, 0.0f, 0.0f,

               0.5f, 0.5f, 0.5f - 0.66f,   0.0f, 0.0f, 0.0f,
               0.5f, -0.5f, 0.5f - 0.66f,   0.0f, 0.0f, 0.0f,


               
               -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 0.0f,
               -0.5f,  -0.5f, 0.5f,   0.0f, 0.0f, 0.0f,

               -0.5f, -0.5f + 0.33, -0.5f,    0.0f, 0.0f, 0.0f,
               -0.5f,  -0.5f + 0.33, 0.5f,   0.0f, 0.0f, 0.0f,

               -0.5f, -0.5f + 0.66, -0.5f,    0.0f, 0.0f, 0.0f,
               -0.5f,  -0.5f + 0.66, 0.5f,   0.0f, 0.0f, 0.0f,

               -0.5f, 0.5f, -0.5f,    0.0f, 0.0f, 0.0f,
               -0.5f, 0.5f, 0.5f,   0.0f, 0.0f, 0.0f,


               0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 0.0f,
               0.5f,  -0.5f, 0.5f,   0.0f, 0.0f, 0.0f,

               0.5f, -0.5f + 0.33, -0.5f,    0.0f, 0.0f, 0.0f,
               0.5f,  -0.5f + 0.33, 0.5f,   0.0f, 0.0f, 0.0f,

               0.5f, -0.5f + 0.66, -0.5f,    0.0f, 0.0f, 0.0f,
               0.5f,  -0.5f + 0.66, 0.5f,   0.0f, 0.0f, 0.0f,
               
               0.5f, 0.5f, -0.5f,    0.0f, 0.0f, 0.0f,
               0.5f, 0.5f, 0.5f,   0.0f, 0.0f, 0.0f,

         

               -0.5f + 0.33f, 0.5f, -0.5f,    0.0f, 0.0f, 0.0f,
               -0.5f + 0.33f,  0.5f, 0.5f,   0.0f, 0.0f, 0.0f,

               -0.5f + 0.66f, 0.5f, -0.5f,    0.0f, 0.0f, 0.0f,
               -0.5f + 0.66f,  0.5f, 0.5f,   0.0f, 0.0f, 0.0f,


               -0.5f + 0.33f, -0.5f, -0.5f,    0.0f, 0.0f, 0.0f,
               -0.5f + 0.33f,  -0.5f, 0.5f,   0.0f, 0.0f, 0.0f,

               -0.5f + 0.66f, -0.5f, -0.5f,    0.0f, 0.0f, 0.0f,
               -0.5f + 0.66f,  -0.5f, 0.5f,   0.0f, 0.0f, 0.0f,

            };


            unsigned int VBO, VAO;
            glGenVertexArrays(1, &VAO);
            glGenBuffers(1, &VBO);
            // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
            glBindVertexArray(VAO);
        
            glBindBuffer(GL_ARRAY_BUFFER, VBO);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        
            // position attribute
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);

            // color attribute
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);

            
        
            // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
            // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
            // glBindVertexArray(0);
        
            Shader ourShader = Shader("3.3.shader.vs","3.3.shader.fs");

             //float offset = 0.5f;
             //ourShader.setFloat("xOffset", offset);
        
            // render loop
            // -----------
            while (!glfwWindowShouldClose(window))
            {
                // input
                // -----
                processInput(window);
        
                // render
                // ------
                glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        

                //set mvp
                glm::mat4 model = glm::mat4(1.0f);
                model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));

                glm::mat4 projection = glm::mat4(1.0f);
                projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
                
                glm::mat4 view = glm::mat4(1.0f);
                view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f)); 


                ourShader.use();
                ourShader.SetUniformMat4f("v",projection * view * model);

                // render the triangle
                ourShader.use();
                glBindVertexArray(VAO);

                glDrawArrays(GL_TRIANGLES, 0, 36);

                glLineWidth(5.0f);
                glDrawArrays(GL_LINES, 36, 16 *  6);
        
                // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
                // -------------------------------------------------------------------------------
                glfwSwapBuffers(window);
                glfwPollEvents();
            }
        
            // optional: de-allocate all resources once they've outlived their purpose:
            // ------------------------------------------------------------------------
            glDeleteVertexArrays(1, &VAO);
            glDeleteBuffers(1, &VBO);
        
            // glfw: terminate, clearing all previously allocated GLFW resources.
            // ------------------------------------------------------------------
            glfwTerminate();
            return 0;
}


// int main() {
    
//     glfwInit();
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

//     GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//     if (window == NULL)
//     {
//         std::cout << "Failed to create GLFW window" << std::endl;
//         glfwTerminate();
//         return -1;
//     }
//     glfwMakeContextCurrent(window);
//     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

//     // glad: load all OpenGL function pointers
//     // ---------------------------------------
//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//     {
//         std::cout << "Failed to initialize GLAD" << std::endl;
//         return -1;
//     }

//     unsigned int texture;
//     glGenTextures(0, &texture);
//     glBindTexture(GL_TEXTURE_2D_ARRAY, texture);
    
//     glTextureBuffer()

//     float vertices[] = {
//                 // positions         // colors
//                  0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
//                 -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
//                  0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
//             };
        
//             unsigned int VBO, VAO;
//             glGenVertexArrays(1, &VAO);
//             glGenBuffers(1, &VBO);
//             // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
//             glBindVertexArray(VAO);
        
//             glBindBuffer(GL_ARRAY_BUFFER, VBO);
//             glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        
//             // position attribute
//             glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//             glEnableVertexAttribArray(0);
//             // color attribute
//             glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//             glEnableVertexAttribArray(1);
        
//             // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//             // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//             // glBindVertexArray(0);
        
        
//              float offset = 0.5f;
//              ourShader.setFloat("xOffset", offset);
        
//             // render loop
//             // -----------
//             while (!glfwWindowShouldClose(window))
//             {
//                 // input
//                 // -----
//                 processInput(window);
        
//                 // render
//                 // ------
//                 glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//                 glClear(GL_COLOR_BUFFER_BIT);
        
//                 // render the triangle
//                 ourShader.use();
//                 glBindVertexArray(VAO);
//                 glDrawArrays(GL_TRIANGLES, 0, 3);
        
//                 // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//                 // -------------------------------------------------------------------------------
//                 glfwSwapBuffers(window);
//                 glfwPollEvents();
//             }
        
//             // optional: de-allocate all resources once they've outlived their purpose:
//             // ------------------------------------------------------------------------
//             glDeleteVertexArrays(1, &VAO);
//             glDeleteBuffers(1, &VBO);
        
//             // glfw: terminate, clearing all previously allocated GLFW resources.
//             // ------------------------------------------------------------------
//             glfwTerminate();
//             return 0;
//         }
// }



// #include "glad/glad.h"
// #include <GLFW/glfw3.h>

// #include <iostream>

// #include "shader_s_shader.h"
// #include "shader_s.h"


// void framebuffer_size_callback(GLFWwindow* window, int width, int height);
// void processInput(GLFWwindow *window);

// // settings
// const unsigned int SCR_WIDTH = 800;
// const unsigned int SCR_HEIGHT = 600;

// int main()
// {
//     // glfw: initialize and configure
//     // ------------------------------
//     glfwInit();
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

// #ifdef __APPLE__
//     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
// #endif

//     // glfw window creation
//     // --------------------
//     GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//     if (window == NULL)
//     {
//         std::cout << "Failed to create GLFW window" << std::endl;
//         glfwTerminate();
//         return -1;
//     }
//     glfwMakeContextCurrent(window);
//     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

//     // glad: load all OpenGL function pointers
//     // ---------------------------------------
//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//     {
//         std::cout << "Failed to initialize GLAD" << std::endl;
//         return -1;
//     }

//     // build and compile our shader program
//     // ------------------------------------
//     Shader ourShader("3.3.shader.vs", "3.3.shader.fs"); // you can name your shader files however you like

//     // set up vertex data (and buffer(s)) and configure vertex attributes
//     // ------------------------------------------------------------------
//     float vertices[] = {
//         // positions         // colors
//          0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // bottom right
//         -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // bottom left
//          0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // top 
//     };

//     unsigned int VBO, VAO;
//     glGenVertexArrays(1, &VAO);
//     glGenBuffers(1, &VBO);
//     // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
//     glBindVertexArray(VAO);

//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//     // position attribute
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//     glEnableVertexAttribArray(0);
//     // color attribute
//     glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//     glEnableVertexAttribArray(1);

//     // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//     // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//     // glBindVertexArray(0);


//      float offset = 0.5f;
//      ourShader.setFloat("xOffset", offset);

//     // render loop
//     // -----------
//     while (!glfwWindowShouldClose(window))
//     {
//         // input
//         // -----
//         processInput(window);

//         // render
//         // ------
//         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT);

//         // render the triangle
//         ourShader.use();
//         glBindVertexArray(VAO);
//         glDrawArrays(GL_TRIANGLES, 0, 3);

//         // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//         // -------------------------------------------------------------------------------
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }

//     // optional: de-allocate all resources once they've outlived their purpose:
//     // ------------------------------------------------------------------------
//     glDeleteVertexArrays(1, &VAO);
//     glDeleteBuffers(1, &VBO);

//     // glfw: terminate, clearing all previously allocated GLFW resources.
//     // ------------------------------------------------------------------
//     glfwTerminate();
//     return 0;
// }


// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}








// #include "glad/glad.h"
// #include <GLFW/glfw3.h>

// #include <iostream>

// void framebuffer_size_callback(GLFWwindow* window, int width, int height);
// void processInput(GLFWwindow *window);

// // settings
// const unsigned int SCR_WIDTH = 800;
// const unsigned int SCR_HEIGHT = 600;

// const char *vertexShaderSource = "#version 330 core\n"
//     "layout (location = 0) in vec3 aPos;\n"
//     "void main()\n"
//     "{\n"
//     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//     "}\0";
// const char *fragmentShaderSource = "#version 330 core\n"
//     "out vec4 FragColor;\n"
//     "void main()\n"
//     "{\n"
//     "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//     "}\n\0";

// int main()
// {
//     // glfw: initialize and configure
//     // ------------------------------
//     glfwInit();
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

// #ifdef __APPLE__
//     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
// #endif

//     // glfw window creation
//     // --------------------
//     GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//     if (window == NULL)
//     {
//         std::cout << "Failed to create GLFW window" << std::endl;
//         glfwTerminate();
//         return -1;
//     }
//     glfwMakeContextCurrent(window);
//     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); //still dunno what this line is

//     // glad: load all OpenGL function pointers
//     // ---------------------------------------
//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//     {
//         std::cout << "Failed to initialize GLAD" << std::endl;
//         return -1;
//     }


//     // build and compile our shader program
//     // ------------------------------------
//     // vertex shader
//     unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//     glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//     glCompileShader(vertexShader);
//     // check for shader compile errors
//     int success;
//     char infoLog[512];
//     glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//     if (!success)
//     {
//         glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//         std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//     }
//     // fragment shader
//     unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//     glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//     glCompileShader(fragmentShader);
//     // check for shader compile errors
//     glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//     if (!success)
//     {
//         glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//         std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//     }
//     // link shaders
//     unsigned int shaderProgram = glCreateProgram();
//     glAttachShader(shaderProgram, vertexShader);
//     glAttachShader(shaderProgram, fragmentShader);
//     glLinkProgram(shaderProgram);
//     // check for linking errors
//     glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//     if (!success) {
//         glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//         std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//     }
//     glDeleteShader(vertexShader);
//     glDeleteShader(fragmentShader);

//     // set up vertex data (and buffer(s)) and configure vertex attributes
//     // ------------------------------------------------------------------
//     float vertices[] = {
//         -0.5f, -0.5f, 0.0f, // left  
//          0.5f, -0.5f, 0.0f, // right 
//          0.0f,  0.5f, 0.0f  // top   
//     }; 

//     unsigned int VBO, VAO;
//     glGenVertexArrays(1, &VAO);
//     glGenBuffers(1, &VBO);
//     // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
//     glBindVertexArray(VAO);

//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//     glEnableVertexAttribArray(0);

//     // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//     glBindBuffer(GL_ARRAY_BUFFER, 0); 

//     // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//     // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//     glBindVertexArray(0); 


//     // uncomment this call to draw in wireframe polygons.
//     //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

//     // render loop
//     // -----------
//     while (!glfwWindowShouldClose(window))
//     {
//         // input
//         // -----
//         processInput(window);

//         // render
//         // ------
//         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT);

//         // draw our first triangle
//         glUseProgram(shaderProgram);
//         glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//         glDrawArrays(GL_TRIANGLES, 0, 3);
        
//         // glBindVertexArray(0); // no need to unbind it every time 
 
//         // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//         // -------------------------------------------------------------------------------
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }

//     // optional: de-allocate all resources once they've outlived their purpose:
//     // ------------------------------------------------------------------------
//     glDeleteVertexArrays(1, &VAO);
//     glDeleteBuffers(1, &VBO);
//     glDeleteProgram(shaderProgram);

//     // glfw: terminate, clearing all previously allocated GLFW resources.
//     // ------------------------------------------------------------------
//     glfwTerminate();
//     return 0;
// }

// // process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// // ---------------------------------------------------------------------------------------------------------
// void processInput(GLFWwindow *window)
// {
//     if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//         glfwSetWindowShouldClose(window, true);
// }

// // glfw: whenever the window size changed (by OS or user resize) this callback function executes
// // ---------------------------------------------------------------------------------------------
// void framebuffer_size_callback(GLFWwindow* window, int width, int height)
// {
//     // make sure the viewport matches the new window dimensions; note that width and 
//     // height will be significantly larger than specified on retina displays.
//     glViewport(0, 0, width, height);
// }