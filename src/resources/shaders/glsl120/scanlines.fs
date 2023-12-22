#version 120

// Input vertex attributes (from vertex shader)
varying vec2 fragTexCoord;
varying vec4 fragColor;

// Input uniform values
uniform sampler2D texture0;
uniform vec4 colDiffuse;

float offset = 0.0;
float frequency = 750.0/3.0;

void main()
{
    float globalPos = (fragTexCoord.y + offset) * frequency;
    float wavePos = cos((fract(globalPos) - 0.5)*3.14);

    vec4 color = texture2D(texture0, fragTexCoord);

    gl_FragColor = mix(vec4(0.0, 0.3, 0.0, 0.0), color, wavePos);
}