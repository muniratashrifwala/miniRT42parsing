#include "../../inc/minirt.h"

int check_ambient(char *str, t_objects *objects) //this is correct 
{
    char    **split_result;
    float   ambient_lighting;
    float   rgb[3];
    int u;

    // t_objects	*obj;
    // obj = objects;
    split_result = ft_split(str, ' ', 0);
    if(split_result[1])
        ambient_lighting = atof(split_result[1]);
    if (check_lighting_range(ambient_lighting) != 0)
        return (1);
    if (split_result[2])
        if (parse_rgb(split_result[2], rgb))
            return (1);
    if (check_rgb_range(rgb) != 0)
        return (1);

    // printf("Ambient Lighting %f \n", ambient_lighting);
    // print_array_float(rgb);

    // obj = add_to_list(obj, set_light(create_v3(0, 0, 0), ambient_lighting, create_trgb(0, rgb[0], rgb[1], rgb[2])), A_LIGHT, 5);
}

int check_light(char *str, t_objects *objects)
{
    char    **split_result;
    float   light_brightness;
    float   rgb[3];
    float   xyz[3];
    int u;

    // t_objects	*obj;
    // obj = objects;
    split_result = ft_split(str, ' ', 0);
    if (split_result[1])
        if (parse_xyz(split_result[1], xyz))
            return (1);
    if(split_result[2])
        light_brightness = atof(split_result[2]);
    if (check_lighting_range(light_brightness) != 0)
        return (1);
    if (split_result[3])
        if(parse_rgb(split_result[3], rgb))
            return (1);
    if (check_rgb_range(rgb) != 0)
        return (1);

    // print_array_float(xyz);
    // printf("Lighting %f \n", light_brightness);
    // print_array_float(rgb);

    // obj = add_to_list(obj, set_light(create_v3(xyz[0], xyz[1], xyz[2]), light_brightness, create_trgb(0, rgb[0], rgb[1], rgb[2])), P_LIGHT, 6);
}   

int check_camera(char *str, t_objects *objects)
{
    char    **split_result;
    float   fov;
    float   normal[3];
    float   xyz[3];
    int u;

    // t_objects	*obj;
    // obj = objects;
    split_result = ft_split(str, ' ', 0);
    if (split_result[1])
        if (parse_xyz(split_result[1], xyz))
            return (1);
    if (split_result[2])
         if (parse_normal(split_result[2], normal))
            return (1);
    if (check_normal_range(normal) != 0)
        return (1);
    if(split_result[3])
        fov = atof(split_result[3]);
    if (check_fov_range(fov) != 0)
        return (1);

    // print_array_float(xyz);
    // print_array_float(normal);
    // printf("FOV %f \n", fov);

    // set_cam(arr_xyz[0],arr_xyz[1],arr_xyz[2],arr_normal[0],arr_normal[1],arr_normal[2],fov);
}