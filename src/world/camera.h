#include <primitive/color.h>
#include <world/scene.h>

class Camera
{
    public:

        Camera(int max_x, int max_y, int spp);

        const Color calculate_pixel(int x, int y, const Scene& scene);
    
    private:
    
        std::vector<Ray> get_pixel_samples(int x, int y);
    
        Ray get_ray(float s, float t);
    
        int max_x;
    
        int max_y;
    
        int spp;
};
