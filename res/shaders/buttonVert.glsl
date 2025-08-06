#version 330 core
layout(location = 0) in vec2 aPos;
out vec3 ourColor;

uniform vec3 uColor;
uniform vec2 uPosition;
uniform vec2 uSize;
uniform mat4 uProjection;

void main() {
    vec2 trans = (aPos * uSize) + uPosition;
    gl_Position = uProjection * vec4(trans, 0.0, 1.0);
    ourColor = uColor;
}
