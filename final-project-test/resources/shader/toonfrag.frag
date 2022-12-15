#version 330 core
in vec4 vert;
in vec4 norm;
in vec3 color;
in vec3 lightDir;

uniform bool wireshade;

out  vec4 fragColor;

void main(void)
{
    if (wireshade) {
        fragColor = vec4(color,1);
    } else {
        vec3 objColor = color;

        fragColor = vec4((clamp(dot(norm.xyz, lightDir), 0, 1) * 0.7 +  0.3) * objColor, 1.0);



    float k_d = 0.5;
    float k_s = 0.5;
    float amb = 0.5;
    vec3 test_ambient =  vec3(amb);
    float dot_prod = dot(lightDir, vec3(norm));

    //divide into dark and light bands
    float light_intensity = dot_prod > 0 ? 1 : 0;

    //smoothen the change between light and dark bands
    light_intensity = smoothstep(0, 0.05, dot_prod);

    vec3 amb_and_lightIntensity = light_intensity + test_ambient;

    vec3 diffuse = k_d*color;

    fragColor = vec4(diffuse*amb_and_lightIntensity, 1);

//        vec3 R = vec3(reflect(lightDir, normalize(norm)));
//        vec3 E =  normalize(vec3(world_cam_pos) - world_pos);
//        float dot1 = dot(R, E);
//        dot1 = dot1 < 0 ? 0 : dot1;
//        dot1 = dot1 > 1 ? 1 : dot1;

//        /*intensity to zero if material is shiny?*/
//        float spec_intens = shiny > 0 ? pow(dot1, shiny*shiny) : 0;

//        /*Smoothstep makes specular lighting very toony - need to find way to calibrate correctly*/
//        spec_intens = smoothstep(0, 0.01, spec_intens);
//        vec3 specular = cSpecular*k_s;
//        fragColor += vec4(spec_intens*(myLights[i].color*specular),1);

//        float rim_amt = 0.65;
//        float rim_dot = 1 - dot(normalize(world_norm), E);
//        float rim_intens = rim_dot * pow(light_intensity, 0.1);
//        rim_dot = smoothstep(rim_amt-0.01, rim_amt + 0.01, rim_intens);

//        fragColor += vec4(diffuse*rim_dot*myLights[i].color,1);
    }
}
