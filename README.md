# 🎨 RayTracer

A program able to generate an image from a file
describing the scene using the raytracing techinque,
which simulates the inverse path of light. This project
is part of the Object-Oriented Programming branch
at Epitech.

## 🚀 Getting Started

These instructions will get you a copy of the project up
and running on your local machine for development and
testing purposes.

### Prerequisites

To compile and run this project, you need to have the following
software installed on your computer:

- `GNU Make`
- `GCC`

### Installing

To install this project, clone the repository and generate
the binary file using CMake or Make:

```bash
git clone git@github.com:EpitechPromo2026/B-OOP-400-MPL-4-1-raytracer-thibault.bernuz.git

cd B-OOP-400-MPL-4-1-raytracer-thibault.bernuz

make
```

## 📝 Usage

To use the program, run the binary with a file describing the scene:

```bash
./raytracer configs/<SCENE_FILE>
```

## 🔥 Features added

- **Primitives**: Sphere, Plane, Cylinder, Cone
- **Materials**: Lambertian, Dielectric, Metal
- **Lights**: Directional, Ambient
- **Textures**: SolidColor

## 📄 Scene file format

The rendered scene is configured using an external file, following the libconfig++ library format. The file includes configuration for the camera, primitives, and lights in the scene.
