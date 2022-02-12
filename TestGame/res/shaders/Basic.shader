#shader vertex
#version 330 core  

layout(location = 0) in vec4 position;  
layout(location = 1) in vec4 color;

out vec4 v_Color;
uniform mat4 ml_matrix;
uniform mat4 vw_matrix;
uniform mat4 pr_matrix;

void main()  
{
    v_Color = color;
    gl_Position = pr_matrix * vw_matrix * ml_matrix * position;  
    
};


#shader fragment
#version 330 core  

layout(location = 0) out vec4 color;  

in vec4 v_Color;

void main()  
{  

    color = v_Color;

};
