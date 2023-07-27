#include "Core.hpp"

int main(int ac, char **av)
{
    if (ac == 2 && std::string(av[1]) == "--help") {
        std::cout << "USAGE: " << av[0] << " <SCENE_FILE>\n  SCENE_FILE: scene configuration" << std::endl;
        return EXIT_SUCCESS;
    }

    try {
        std::unique_ptr<RayTracer::Core> core = std::make_unique<RayTracer::Core>(av[1]);
        core->launch();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return EXIT_SUCCESS;
}
