#version 330 core
in vec4 vert;
in vec4 norm;
in vec3 color;
in vec3 lightDir;

uniform bool wireshade;
uniform float ambient_param;
uniform int rim_thickness;
uniform int toon_levels;
uniform bool toon_shading;
uniform bool specular_on;
//uniform vec4 world_cam_pos;

out  vec4 fragColor;

void main(void)
{

    vec3 light_color = vec3(0.99, 0.9, 0.44);
    if (!toon_shading) {
         fragColor = vec4((clamp(dot(norm.xyz, lightDir), 0, 1) * 0.7 +  0.3) * color, 1.0);

    } else {
        vec3 objColor = color;

//

    fragColor = vec4(vec3(0.3*color),1);
//    fragColor += vec4(0.1);
    float k_d = 0.5;
    float k_s = 0.5;
    float dot_prod = dot(lightDir, vec3(norm));

    //divide into dark and light bands
    float light_intensity = dot_prod > 0 ? 1 : 0;

    //smoothen the change between light and dark bands
    light_intensity = smoothstep(0, 0.01, dot_prod);

    vec3 diffuse = k_d*color;

    float toon_scale_factor = 1.0f/toon_levels;
    float diffuse_factor = 0;
//    if(dot_prod > 0){
//        float diffuse_factor = ceil(dot_prod * toon_levels) * toon_scale_factor;
//        diffuse_factor = smoothstep(0, 1, dot_prod);
////        vec3 diffuse = k_d*cDiffuse;
//        fragColor += vec4(diffuse_factor*diffuse, 1);

//    }
//    else{
//        fragColor += vec4(diffuse*(toon_scale_factor/4), 1);
//    }


    if(dot_prod > 0){
        if(toon_levels == 1){
            diffuse_factor = smoothstep(0, 0.01, dot_prod);
        }
        else{

            diffuse_factor = ceil(dot_prod * toon_levels) * toon_scale_factor;

        }

//                    diffuse_factor = smoothstep(diffuse_factor - toon_scale_factor, diffuse_factor-toon_scale_factor+0.2, dot_prod);
//        vec3 diffuse = k_d*cDiffuse;
        fragColor += vec4(diffuse_factor*diffuse, 1);
    }

    vec3 world_pos = vec3(vert);
    vec3 cam_pos = vec3(1);
        vec3 R = vec3(reflect(-lightDir, normalize(vec3(norm))));
        vec3 E =  normalize(cam_pos - world_pos);
        float dot1 = dot(R, E);
        dot1 = dot1 < 0 ? 0 : dot1;
        dot1 = dot1 > 1 ? 1 : dot1;

        if(specular_on){
            float shiny =5.f;
            /*intensity to zero if material is shiny?*/

            float spec_intens = shiny > 0 ? pow(dot1, shiny*shiny) : 0;

    //        /*Smoothstep makes specular lighting very toony - need to find way to calibrate correctly*/
    //        spec_intens = smoothstep(0, 0.9, spec_intens);

            vec3 cSpecular = vec3(1);
            vec3 specular = cSpecular*k_s;
            fragColor += vec4(spec_intens*specular,1);
        }

        float rim_amt = 1.0f - 0.05*rim_thickness;
        float rim_dot = 1 - dot(normalize(vec3(norm)), E);
        float rim_intens = rim_dot * pow(light_intensity, 0.01);
        rim_dot = smoothstep(rim_amt-0.01, rim_amt + 0.01, rim_intens);
        fragColor += vec4(diffuse*rim_dot,1);
    }
}
