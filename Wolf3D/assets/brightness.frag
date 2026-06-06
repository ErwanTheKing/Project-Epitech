#version 120

uniform sampler2D texture;
uniform float brightness;
uniform float flashlight_on;
uniform float flashlight_radius;
uniform float flashlight_softness;
uniform float flashlight_intensity;

void main()
{
    vec2 uv = gl_TexCoord[0].xy;
    vec4 color = texture2D(texture, uv);
    float base_gain = 0.2;
    float gain = base_gain;
    float dist = 0.0;
    float spot = 0.0;

    if (flashlight_on > 0.5) {
        dist = distance(uv, vec2(0.5, 0.5));
        spot = smoothstep(flashlight_radius,
            flashlight_radius - flashlight_softness, dist);
        gain = mix(base_gain, flashlight_intensity, spot);
    }
    color.rgb = clamp(color.rgb * brightness * gain, 0.0, 1.0);
    gl_FragColor = color;
}
