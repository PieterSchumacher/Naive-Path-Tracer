# Path Tracer

A CPU-based, naive implementation of the classical path tracer in C++. This algorithm generates rendered images by calculating a solution to the rendering equation using Monte Carlo integration methods.
The renderer is capable of simulating specular reflection, refraction/transparency and uses BVH as an acceleration data structure. A report in Dutch is included.


Here are some interesting & relevant wikipedia pages:
https://en.wikipedia.org/wiki/Path_tracing
https://en.wikipedia.org/wiki/Monte_Carlo_integration
https://en.wikipedia.org/wiki/Rendering_equation
https://en.wikipedia.org/wiki/Bidirectional_reflectance_distribution_function


--- Images ---


![Refractive teapot with caustics](sample_images/teapot_1440p.png)


![Specular reflection](sample_images/Dragon_32ssp_reflectance.png)


![Specular reflection](sample_images/shiny_dragon.png)

This code base is still under development and contains bugs/missing features. It is not intended for commercial use.

