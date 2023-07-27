# ✨ Le contenu des fichiers 

## 📝 Pré-requis

- Avoir lu la page [Introduction](./Introduction.md)
- Avoir lu la page [Comment utiliser l'arcade ?](./How_to_use.md)

## 🆕 Le contenu des Interfaces


L'ensemble des fonctions disponibles dans le `IPtimitive.hpp` regroupe toutes les fonctions essentielles au bon fonctionnement du rendement 3D de chaque forme et des interactions tel que la reflection, la refraction de la lumière.

::: warning <ins> Qu'est ce que l'interface IDisplayModule ? </ins>

L'interface `IDisplayModule` est une interface qui contient des méthodes qui doivent être implémentées dans votre classe. 

Cette interface permet d'apporter un côté générique au code et de proposer un rendu bien plus compréhensible.
:::


A présent, rendez vous `sources/abstract`, où vous allez remarquer *l'interface* `IPrimitive` ainsi que la *structure* `hitRecord`.

```cpp
namespace RayTracer {
    struct hitRecord {
        Math::Point<3> p;
        Math::Vector<3> normal;
        double t;
        double u;
        double v;
        bool frontFace;
        std::shared_ptr<RayTracer::IMaterial> matPtr;

        inline void setFaceNormal(const Math::Ray& r, const Math::Vector<3>& outwardNormal) {
            frontFace = r.direction.dot(outwardNormal) < 0;
            normal = frontFace ? outwardNormal : -outwardNormal;
        }
    };

    class IPrimitive {
    public:
        virtual ~IPrimitive() = default;
        virtual bool hits(const Math::Ray& r, double Tmin, double Tmax, RayTracer::hitRecord& rec) = 0;
        virtual bool boundingBox(double time0, double time1, AABB& outputBox) const = 0;
        virtual void translate(Math::Vector<3> direction) = 0;
        virtual void rotation() = 0;
        virtual void getUv(const Math::Point<3>& p, double& u, double& v) = 0;
    };
}
```

Cette interface regroupe l'ensemble des fonctions utilisées au sein des fichiers présents dans le dossier *primitive*. Toutes ces fonctions possèdent donc le même prototypage.

::: warning <ins> Qu'est ce que cela signifie ? </ins>

Tout les fichiers possédant des classes dans le dossier *primitves* héritent de l'interface `IPrimitive`.

>  class Box : public RayTracer::IPrimitive {

>  class Cone : public RayTracer::IPrimitive {

>  class Cylinder : public RayTracer::IPrimitive {

>  class Sphere : public RayTracer::IPrimitive {

Cette interface permet d'apporter un côté générique au code et de proposer un rendu bien plus compréhensible.
:::

Une fois que vous avez implémenté les méthodes de l'interface `IDisplayModule`, vous pouvez maintenant compiler votre librairie. Pour ce faire vous allez devoir créer un `Makefile` dans votre répertoire courant.


## 🔧 Les fonctions principales

Toutes les formes possèdes une fonction `hits` cette fonction est utilisée pour déterminer si un rayon intersecte une forme dans un système de ray tracing. Voici les grandes étapes de son fonctionnement :

Cette fonction est utilisée pour déterminer si un rayon intersecte une sphère dans un système de ray tracing. Voici les grandes étapes de son fonctionnement.

# hits
Voci le `hits` de la Sphère:
```cpp
    bool Sphere::hits(const Math::Ray &r, double Tmin, double Tmax, RayTracer::hitRecord &rec) {
        Math::Vector<3> oc = r.origin - center;
        auto a = r.direction.lengthSquared();
        auto b = oc.dot(r.direction);
        auto c = oc.lengthSquared() - radius * radius;

        auto discriminant = b * b - a * c;
        if (discriminant < 0) return false;
        auto sqrtd = std::sqrt(discriminant);

        auto root = (-b - sqrtd) / a;
        if (root < Tmin || Tmax < root) {
            root = (-b + sqrtd) / a;
            if (root < Tmin || Tmax < root)
                return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        Math::Vector<3> outwardNormal = (rec.p - center) / radius;
        rec.setFaceNormal(r, outwardNormal);
        getSphereUv(outwardNormal, rec.u, rec.v);
        rec.matPtr = matPtr;

        return true;
    }

    bool Sphere::boundingBox(double time0, double time1, AABB& outputBox) const {
        outputBox = AABB{
            center - Math::Vector<3> {radius, radius, radius},
            center + Math::Vector<3> {radius, radius, radius}};
    return true;
    }
```
::: warning <ins> Voici les grandes étapes de son fonctionnement </ins>
> 1- Calcul des paramètres initiaux

> 2- Calcul du discriminant

> 3- Calcul des racines

> 4- Vérification des limites

> 5- Attribution des valeurs à la structure de données

> 6- Renvoi du résultat
:::

En résumé, cette fonction effectue les calculs nécessaires pour déterminer si un **rayon intersecte** une forme et fournit les informations nécessaires sur le point d'intersection, la normale et les coordonnées UV de la forme en question.

# getUv

Cette fonction, appelée "getUv", est utilisée pour calculer les coordonnées de texture UV d'un point sur une sphère.


Voci le `getUv` de la Sphère:
```cpp
    void Sphere::getUv(const Math::Point<3>& p, double& u, double& v) {

        auto theta = acos(-p._points[1]);
        auto phi = atan2(-p._points[2], p._points[0]) + Math::pi;

        u = phi / (2 * Math::pi);
        v = theta / Math::pi;
    }

```
::: warning <ins> Voici les grandes étapes de son fonctionnement </ins>

> 1- Calcul de l'angle theta

> 2- Calcul de l'angle phi

> 3- Calcul des coordonnées de texture UV
:::

En résumé, cette fonction prend un point sur une sphère et calcule les coordonnées de texture UV correspondantes. Ces coordonnées peuvent ensuite être utilisées pour appliquer une texture ou une couleur spécifique à ce point lors du rendu de la forme en question.


# boudingBox

Cette fonction, appelée "boundingBox", est utilisée pour calculer la boîte englobante (bounding box) de la sphère sur une période de 

Voci le `boudingBox` de la Sphère:

```cpp
    bool Sphere::boundingBox(double time0, double time1, AABB& outputBox) const {
        outputBox = AABB{
            center - Math::Vector<3> {radius, radius, radius},
            center + Math::Vector<3> {radius, radius, radius}};
    return true;
    }
 ```
 
 ::: warning <ins> Voici les grandes étapes de son fonctionnement </ins>
> 1- Calcul des coins de la boîte englobante 

> 2- Attribution des valeurs à l'objet de sortie 

> 3- Renvoi du résultat 
:::

En résumé, cette fonction calcule la boîte englobante d'une sphère en utilisant son centre et son rayon, puis attribue les valeurs calculées à la boîte englobante de sortie. La boîte englobante est utilisée pour optimiser les calculs dans le cadre d'un algorithme de rendu ou de détection de collisions.

## ⚙️ Le Fichier de configration 

Le fichier Configuration.cpp est le core de la configuration. Il permet de savoir la primitive qui va avec son matériau et sa texture. Le tout est pensé pour qu'il soit facilement extensible.
En effet, le design pattern de la factory est utilisée pour les primitives, les matériaux, les textures et les boxes.
C'est un design pattern qui définit une interface pour créer des objets dans une classe mère, mais délègue le choix des types d’objets à créer aux sous-classes.

Voici un exemple de factory pour les primitives:

```cpp
_factory = {
    {"spheres", [this]() -> std::vector<std::shared_ptr<IPrimitive>> { return createSpheres(); }},
    {"planes", [this]() -> std::vector<std::shared_ptr<IPrimitive>> { return createPlanes(); }},
    {"cylinders", [this]() -> std::vector<std::shared_ptr<IPrimitive>> { return createCylinders(); }},
    {"cones", [this]() -> std::vector<std::shared_ptr<IPrimitive>> { return createCones(); }},
    {"boxes", [this]() -> std::vector<std::shared_ptr<IPrimitive>> { return createBoxes(); }}
};
```
On utilise pour cela une `std::unordered_map` qui contient une `std::string` pour la clé et une `std::function` pour la valeur.

Pour l'utiliser c'est très simple, il suffit de l'appeler comme ceci:

```cpp
if (_factory.find(type) == _factory.end()) {
    throw RayTracerException("Component " + type + " not found");
}
tmp = _factory.find(type)->second();
```

On a notre variable `type` comme `std::string` et qui contient le nom de notre primitive. Si le nom de la primitive dans `type` n'est pas dans la factory, alors on lève une exception. Sinon, dans le cas contraire, on appelle la fonction associée au nom de la primitive.

::: tip
Pour rajouter facilement des primitives, des matériaux, des textures ou des boxes, c'est très simple, il suffit de rajouter une ligne dans la factory de votre choix ainsi qu'une fonction pour son implémentation et le tour est joué !
:::

## 🧭 Le Makefile

::: warning <ins> Qu'est ce que le Makefile ? </ins>

Le Makefile est un fichier qui permet de compiler un programme. Il contient des règles qui permettent de compiler un programme.
:::

```Makefile
##
## EPITECH PROJECT, 2023
## B-OOP-400-MPL-4-1-raytracer-thibault.bernuz
## File description:
## Makefile
##

CXX			=	g++ -std=c++17 \
				-I./sources/abstract \
				-I./sources/interfaces \
				-I./sources/material \
				-I./sources/math \
				-I./sources/primitives \
				-I./sources/utils \

CXXFLAGS	=	-Wall -Wextra -floop-parallelize-all -g3

LDFLAGS		=	-lconfig++

SRC			=	$(shell find -name "*.cpp")

OBJ			=	$(SRC:.cpp=.o)

BIN			=	raytracer

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) -o $(BIN) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(BIN)
	$(RM) *.ppm

re: fclean all
```

Une fois que vous avez créé votre `Makefile`, vous pouvez maintenant compiler votre librairie.

```bash
$ make
```

Il existe également d'autres commandes comme :

```bash
$ make re
```

Qui vous permet de recompiler la totalité du projet, mais encore :

```bash
$ make fclean
```
Qui elle vous permet de nettoyer l'ensemble du projet.


Une fois `make` utilisé vous pouvez maitenant lancer votre programme avec une scène afin de voir le résultat.
